// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

class UBillboardComponent;

/**
 * One enemy option the spawner can pick: which class to spawn, how likely it is
 * to be picked relative to the other options in the same tier, and how many to spawn at once.
 */
USTRUCT(BlueprintType)
struct FEnemySpawnEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<ABaseEnemy> EnemyClass;

	// Relative weight within the tier. Two entries at 1 and 1 = 50/50; 3 and 1 = 75/25.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (ClampMin = "0.0"))
	float SelectionWeight = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (ClampMin = "1"))
	int32 MinGroupSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (ClampMin = "1"))
	int32 MaxGroupSize = 1;
};

/**
 * Everything about one tier: how likely this tier is to be picked on each spawn,
 * and the list of enemy options inside it.
 */
USTRUCT(BlueprintType)
struct FEnemyTierConfig
{
	GENERATED_BODY()

	// Relative chance versus the other tiers. GDD ratio: Fodder 60, Mid 30, Elite 10 = 60% / 30% / 10%.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (ClampMin = "0.0"))
	float SpawnChance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TArray<FEnemySpawnEntry> EnemyEntries;
};

UCLASS()
class LECTURE18552_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

public:
	AEnemySpawner();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USceneComponent> Root;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UBillboardComponent> Billboard;
#endif

	// The spawn pool, one tier per GDD role (Fodder / Mid-Tier / Elite).
	// Spawn chances default to the GDD's 60/30/10 split; add the enemy classes in the BP.
	// EditDefaultsOnly: set it once in BP_EnemySpawner and every placed spawner
	// shares it. It can't be overridden per spawner in the level, so they can't drift out of sync.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawning|Fodder Tier")
	FEnemyTierConfig FodderTier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawning|Mid Tier")
	FEnemyTierConfig MidTier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawning|Elite Tier")
	FEnemyTierConfig EliteTier;

	// Group members are scattered randomly within this radius (cm) around the spawner.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (ClampMin = "0.0"))
	float GroupSpawnRadius = 300.0f;

	// Spawn automatically when the spawner loads in (i.e. when the room loads).
	// Turn off to trigger it yourself with SpawnEnemy() instead.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	bool bSpawnOnBeginPlay = true;

	virtual void BeginPlay() override;

	// Spawns this spawner's enemies one time: picks a tier, then an enemy in that tier,
	// then a group of it. Does nothing if this spawner has already spawned.
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnEnemy();

	UFUNCTION(BlueprintPure, Category = "Spawning")
	bool HasSpawned() const { return bHasSpawned; }

	// Returns the tier picked by SpawnChance, or nullptr if no tier can spawn anything.
	const FEnemyTierConfig* PickTier() const;

	// Returns an entry picked by SelectionWeight, or nullptr if the tier has no valid entries.
	static const FEnemySpawnEntry* PickEntry(const FEnemyTierConfig& Tier);

	ABaseEnemy* SpawnEnemyAtTransform(TSubclassOf<ABaseEnemy> EnemyClass, const FTransform& SpawnTransform);

private:
	bool bHasSpawned = false;
};

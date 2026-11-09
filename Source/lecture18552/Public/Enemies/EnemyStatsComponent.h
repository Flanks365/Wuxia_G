// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enemies/EnemyStats.h"
#include "EnemyStatsComponent.generated.h"

/**
 * Holds an enemy's stats. Set BaseStats per enemy in its Blueprint (Grunt / Enforcer / Brutalizer);
 * on BeginPlay they're copied into CurrentStats, health is filled, and MoveSpeed is applied.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LECTURE18552_API UEnemyStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemyStatsComponent();

	// Configured per enemy type
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Stats")
	FEnemyStats BaseStats;

	// Each spawned enemy gets a random scale in this range, so a group doesn't look identical.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Stats", meta = (ClampMin = "0.01"))
	float MinSize = 0.8f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Stats", meta = (ClampMin = "0.01"))
	float MaxSize = 1.2f;

	// Live values during play. Start as a copy of BaseStats; buffs/scaling change these, not BaseStats.
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Enemy Stats")
	FEnemyStats CurrentStats;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Enemy Stats")
	float CurrentHealth = 0.0f;

	// Copies BaseStats into CurrentStats
	UFUNCTION(BlueprintCallable, Category = "Enemy Stats")
	void InitializeStats();

protected:
	virtual void BeginPlay() override;
};

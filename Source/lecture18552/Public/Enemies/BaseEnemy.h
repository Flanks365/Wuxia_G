// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemy.generated.h"

class UEnemyStatsComponent;

/**
 * Root of every enemy. The spawner's EnemyClass is TSubclassOf<ABaseEnemy>,
 * so anything the spawner can spawn must inherit from this.
 */
UCLASS(Abstract)
class LECTURE18552_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseEnemy();

	UFUNCTION(BlueprintPure, Category = "Enemy")
	UEnemyStatsComponent* GetEnemyStats() const { return EnemyStats; }

protected:
	virtual void BeginPlay() override;

	// Every enemy has stats; set the values per enemy in its Blueprint.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UEnemyStatsComponent> EnemyStats;
};

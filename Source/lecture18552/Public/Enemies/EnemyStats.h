// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyStats.generated.h"

/**
 * One enemy's stat block. GDD 3.1.1.6 lists each enemy's stats as HP, DEF, ATK, SPD;
 * the rest are the extra combat values carried over from Final_Corpse_2.
 * Used twice in UEnemyStatsComponent: once for the values set in the BP (BaseStats)
 * and once for the live values during play (CurrentStats).
 */
USTRUCT(BlueprintType)
struct LECTURE18552_API FEnemyStats
{
	GENERATED_BODY()

	// HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats", meta = (ClampMin = "1.0"))
	float MaxHealth = 100.0f;

	// DEF
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats", meta = (ClampMin = "0.0"))
	float Defense = 0.0f;

	// ATK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats", meta = (ClampMin = "0.0"))
	float Attack = 10.0f;

	// SPD - movement speed in cm/s, applied to the character's Max Walk Speed.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats", meta = (ClampMin = "0.0"))
	float MoveSpeed = 300.0f;

	// Attacks per second.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats", meta = (ClampMin = "0.0"))
	float AttackSpeed = 1.0f;

	// How close (cm) the enemy needs to be to attack.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats", meta = (ClampMin = "0.0"))
	float AttackRange = 150.0f;

	// Health regenerated per second.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats", meta = (ClampMin = "0.0"))
	float HpRegenRate = 0.0f;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/MidTierEnem.h"
#include "Enforcer.generated.h"

/**
 * Enforcer - Role: Mid-Tier.
 * Attack pattern: mid-speed attacks, fairly slow projectiles. Appears after the second floor.
 */
UCLASS()
class LECTURE18552_API AEnforcer : public AMidTierEnem
{
	GENERATED_BODY()

public:
	AEnforcer();

protected:
	virtual void BeginPlay() override;
};

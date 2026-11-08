// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "MidTierEnem.generated.h"

/**
 * Mid-Tier (GDD 3.1.1.6). Mid-speed attackers that also throw projectiles (30% of encounters).
 */
UCLASS(Abstract)
class LECTURE18552_API AMidTierEnem : public ABaseEnemy
{
	GENERATED_BODY()

public:
	AMidTierEnem();

protected:
	virtual void BeginPlay() override;
};

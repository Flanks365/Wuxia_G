// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "EliteEnem.generated.h"

/**
 * Elite tier (GDD 3.1.1.6). Slow, heavy-hitting "boss before the boss" (10% of encounters).
 */
UCLASS(Abstract)
class LECTURE18552_API AEliteEnem : public ABaseEnemy
{
	GENERATED_BODY()

public:
	AEliteEnem();

protected:
	virtual void BeginPlay() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "LowTierEnem.generated.h"

UCLASS(Abstract)
class LECTURE18552_API ALowTierEnem : public ABaseEnemy
{
	GENERATED_BODY()

public:
	ALowTierEnem();

protected:
	virtual void BeginPlay() override;
};

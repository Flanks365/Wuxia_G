// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "MidTierEnem.generated.h"

UCLASS(Abstract)
class LECTURE18552_API AMidTierEnem : public ABaseEnemy
{
	GENERATED_BODY()

public:
	AMidTierEnem();

protected:
	virtual void BeginPlay() override;
};

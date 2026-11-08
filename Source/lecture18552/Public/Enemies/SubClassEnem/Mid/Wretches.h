// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/MidTierEnem.h"
#include "Wretches.generated.h"

UCLASS()
class LECTURE18552_API AWretches : public AMidTierEnem
{
	GENERATED_BODY()

public:
	AWretches();

protected:
	virtual void BeginPlay() override;
};

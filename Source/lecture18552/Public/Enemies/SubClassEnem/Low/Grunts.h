// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/LowTierEnem.h"
#include "Grunts.generated.h"

UCLASS()
class LECTURE18552_API AGrunts : public ALowTierEnem
{
	GENERATED_BODY()

public:
	AGrunts();

protected:
	virtual void BeginPlay() override;
};

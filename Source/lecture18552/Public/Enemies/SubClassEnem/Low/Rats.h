// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/LowTierEnem.h"
#include "Rats.generated.h"

UCLASS()
class LECTURE18552_API ARats : public ALowTierEnem
{
	GENERATED_BODY()

public:
	ARats();

protected:
	virtual void BeginPlay() override;
};

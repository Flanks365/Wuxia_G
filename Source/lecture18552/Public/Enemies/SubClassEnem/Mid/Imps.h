// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/MidTierEnem.h"
#include "Imps.generated.h"

UCLASS()
class LECTURE18552_API AImps : public AMidTierEnem
{
	GENERATED_BODY()

public:
	AImps();

protected:
	virtual void BeginPlay() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/EliteEnem.h"
#include "Brutes.generated.h"

UCLASS()
class LECTURE18552_API ABrutes : public AEliteEnem
{
	GENERATED_BODY()

public:
	ABrutes();

protected:
	virtual void BeginPlay() override;
};

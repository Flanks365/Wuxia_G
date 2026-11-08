// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/EliteEnem.h"
#include "Burrowers.generated.h"

UCLASS()
class LECTURE18552_API ABurrowers : public AEliteEnem
{
	GENERATED_BODY()

public:
	ABurrowers();

protected:
	virtual void BeginPlay() override;
};

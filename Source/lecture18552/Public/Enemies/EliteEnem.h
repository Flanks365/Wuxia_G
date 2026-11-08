// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "EliteEnem.generated.h"

UCLASS(Abstract)
class LECTURE18552_API AEliteEnem : public ABaseEnemy
{
	GENERATED_BODY()

public:
	AEliteEnem();

protected:
	virtual void BeginPlay() override;
};

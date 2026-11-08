// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/BaseEnemy.h"
#include "FodderEnem.generated.h"

/**
 * Fodder tier (GDD 3.1.1.6). Quick, fast-attacking enemies that make up most encounters (60%).
 */
UCLASS(Abstract)
class LECTURE18552_API AFodderEnem : public ABaseEnemy
{
	GENERATED_BODY()

public:
	AFodderEnem();

protected:
	virtual void BeginPlay() override;
};

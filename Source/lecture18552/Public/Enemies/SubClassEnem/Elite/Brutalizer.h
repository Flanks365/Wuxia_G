// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/EliteEnem.h"
#include "Brutalizer.generated.h"

/**
 * Brutalizer - Role: Elite.
 * Attack pattern: slow attacks, large projectiles. Appears every fourth floor.
 */
UCLASS()
class LECTURE18552_API ABrutalizer : public AEliteEnem
{
	GENERATED_BODY()

public:
	ABrutalizer();

protected:
	virtual void BeginPlay() override;
};

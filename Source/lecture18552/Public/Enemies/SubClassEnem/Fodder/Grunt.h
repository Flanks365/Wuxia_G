// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/FodderEnem.h"
#include "Grunt.generated.h"

/**
 * Grunt - Role: Fodder.
 * Attack pattern: quick melee swipes. Appears on all floors in varying amounts.
 */
UCLASS()
class LECTURE18552_API AGrunt : public AFodderEnem
{
	GENERATED_BODY()

public:
	AGrunt();

protected:
	virtual void BeginPlay() override;
};

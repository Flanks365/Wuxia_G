// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/NpcCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "lecture18552_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class LECTURE18552_API ALecture18552_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	ALecture18552_GameMode();
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnActors();
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<ANpcCharacter> NPCCharacterClass;
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
	TArray<FVector> DefaultSpawnPoints;
	
};

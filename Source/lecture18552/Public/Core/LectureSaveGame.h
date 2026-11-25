// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemDataAsset.h"
#include "GameFramework/SaveGame.h"
#include "LectureSaveGame.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FPlayerSaveData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	FTransform PlayerTransform;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	FRotator PlayerRotation;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	float Energy;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	TArray<UItemDataAsset*> Items;
	
};

UCLASS()
class LECTURE18552_API ULectureSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	FPlayerSaveData PlayerData;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	TArray<FTransform> NPCTransforms;
	
};

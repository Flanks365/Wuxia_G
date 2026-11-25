// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Core/LectureSaveGame.h"
#include "LectureGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LECTURE18552_API ULectureGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SavePlayerData(FPlayerSaveData SaveData);
	
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SaveNPCdata();
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	TObjectPtr<ULectureSaveGame> SaveGame;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SaveGame")
	FString Slot = TEXT("Save_Slot01");
};

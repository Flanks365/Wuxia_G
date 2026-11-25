// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/LectureGameInstance.h"

#include "Character/NpcCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void ULectureGameInstance::SavePlayerData(FPlayerSaveData SaveData)
{
	
	if (!IsValid(SaveGame))
	{
		return;
	}
	
	SaveGame->PlayerData = SaveData;
}

void ULectureGameInstance::SaveNPCdata()
{
	
	if (!IsValid(SaveGame))
	{
		return;
	}
	
	SaveGame->NPCTransforms.Empty();
	
	TArray<AActor*> foundNpcs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANpcCharacter::StaticClass(), foundNpcs);
	
	for (AActor* npc : foundNpcs)
	{
		if (IsValid(npc))
		{
			SaveGame->NPCTransforms.Add(npc->GetActorTransform());
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "./Core/lecture18552_GameMode.h"
#include "./Character/BaseCharacter.h"
#include "Core/LectureGameInstance.h"
#include "Engine/World.h"

ALecture18552_GameMode::ALecture18552_GameMode()
{
	
	DefaultPawnClass = ABaseCharacter::StaticClass();
}

void ALecture18552_GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnActors();
}

void ALecture18552_GameMode::SpawnActors()
{
	ULectureGameInstance* GI = Cast<ULectureGameInstance>(GetGameInstance());
	
	if (!GetWorld() || !GI || !GI->SaveGame) return;
	
	FActorSpawnParameters SpawnInfo;
	
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;
	
	const TArray<FTransform>& TransformsToUse = GI->SaveGame->NPCTransforms;
	
	if (TransformsToUse.Num() > 0)
	{
		for (const FTransform& SpawnTransform : TransformsToUse)
		{
			GetWorld()->SpawnActor<ANpcCharacter>(NPCCharacterClass, SpawnTransform, SpawnInfo);
		} 
	} else
	{
		for (FVector locations : DefaultSpawnPoints)
		{
			const FTransform firstSpawnTransform(FRotator::ZeroRotator, locations, FVector(1.0f, 1.0f, 1.0f));
			
			GetWorld()->SpawnActor<ANpcCharacter>(NPCCharacterClass,firstSpawnTransform, SpawnInfo);
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGeneration/Rooms/BaseRoom.h"

#include "Components/ArrowComponent.h"


// Sets default values
ABaseRoom::ABaseRoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	PlayerStart = CreateDefaultSubobject<UArrowComponent>(TEXT("PlayerStart"));
	PlayerStart->SetupAttachment(RootComponent);
}

void ABaseRoom::Activate()
{
	
	if (RoomState != ERoomState::Inactive)
		return;
	
	RoomState = ERoomState::Active;
	OnActivated();
}


void ABaseRoom::ClearRoom()
{
}




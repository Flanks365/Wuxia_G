// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGeneration/Rooms/Types/Mystery.h"


// Sets default values
AMystery::AMystery()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMystery::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMystery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


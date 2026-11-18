// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGeneration/Doors/Doors.h"


// Sets default values
ADoors::ADoors()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ADoors::Interact(AActor* Interactor, UPrimitiveComponent* HitComponent)
{
}



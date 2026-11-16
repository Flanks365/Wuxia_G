// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable/Interactable.h"
#include "RoomGeneration/RoomTypes.h"
#include "Doors.generated.h"


UCLASS()
class LECTURE18552_API ADoors : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Doors");
	ERoomType Dest;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Doors")
	void OnDestinationSet();
	
	// Sets default values for this actor's properties
	ADoors();
	
};

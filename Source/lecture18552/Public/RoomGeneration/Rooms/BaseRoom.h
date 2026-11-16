// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomGeneration/RoomTypes.h"
#include "RoomGeneration/Doors/Doors.h"
#include "BaseRoom.generated.h"

class ABaseRoom;
class UArrowComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomCleared, ABaseRoom*, Room);

UENUM(BlueprintType)
enum class ERoomState : uint8 { Inactive, Active, Cleared };

UCLASS(Abstract)
class LECTURE18552_API ABaseRoom : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseRoom();
	
	UFUNCTION(BlueprintCallable, Category = "Room")
	void Activate();
	
	UArrowComponent* GetPlayerStart() const { return PlayerStart; }
	
	UPROPERTY(BlueprintAssignable, Category = "Room")
	FOnRoomCleared OnRoomCleared;

protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Room")
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(VisibleAnywhere, Category = "Room")
	TObjectPtr<UArrowComponent> PlayerStart;
	
	UPROPERTY(editAnywhere, Category = "Room",meta = (MakeEditWidget))
	TArray<FTransform> DoorSpawnPoints;
	
	UPROPERTY(EditDefaultsOnly, Category = "Room")
	TSubclassOf<ADoors> DoorClass;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Room")
	ERoomState RoomState = ERoomState::Inactive;
	
	UPROPERTY()
	TArray<TObjectPtr<ADoors>> SpawnedDoors;
	
	virtual void OnActivated();
	
	void spawnDoors();
	
	UFUNCTION(BlueprintCallable, Category = "Room")
	void ClearRoom();
	
};

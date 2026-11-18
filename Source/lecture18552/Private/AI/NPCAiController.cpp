// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NPCAiController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Character/PlayerCharacter.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense_Sight.h"


// Sets default values
ANPCAiController::ANPCAiController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPCAiController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPCAiController::HandleSightSense(AActor* Actor, FAIStimulus Stimulus)
{
	FAISenseID SightSenseID = UAISense::GetSenseID<UAISense_Sight>();
	if (Stimulus.Type != SightSenseID)
	{
		return;
	}
	
	APlayerCharacter* Player = Cast<APlayerCharacter>(Actor);
	if (!Player)
	{
		return;
	}
	
	UBlackboardComponent* BB = GetBlackboardComponent();
	if (!BB)
	{
		return;
	}
	
	if (Stimulus.WasSuccessfullySensed())
	{
		//gained sight of the player
		BB->SetValueAsObject("TargetActor", Player);
		BB->SetValueAsVector("LastKnownLocation", Stimulus.StimulusLocation);
	} else
	{
		//lost sight of the player
		BB->SetValueAsVector("LastKnownLocation", Stimulus.StimulusLocation);
		BB->ClearValue("TargetActor");
	}
}

// Called every frame
void ANPCAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


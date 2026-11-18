// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAiController.h"
#include "NPCAiController.generated.h"

struct FAIStimulus;

UCLASS()
class LECTURE18552_API ANPCAiController : public ABaseAiController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANPCAiController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "AI")
	void HandleSightSense(AActor* Actor, FAIStimulus Stimulus);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

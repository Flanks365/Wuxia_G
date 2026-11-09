// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/EnemyStatsComponent.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


UEnemyStatsComponent::UEnemyStatsComponent()
{
	// Stats are only read/changed on events, so no per-frame work is needed.
	PrimaryComponentTick.bCanEverTick = false;
}

void UEnemyStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeStats();
}

void UEnemyStatsComponent::InitializeStats()
{
	CurrentStats = BaseStats;
	CurrentHealth = CurrentStats.MaxHealth;

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter)
	{
		return;
	}

	// SPD drives the movement component, so tuning MoveSpeed in the BP actually changes how fast it moves.
	if (UCharacterMovementComponent* Movement = OwnerCharacter->GetCharacterMovement())
	{
		Movement->MaxWalkSpeed = CurrentStats.MoveSpeed;
	}

	// Random size within MinSize..MaxSize (guards against them being entered the wrong way round).
	const float Scale = FMath::FRandRange(FMath::Min(MinSize, MaxSize), FMath::Max(MinSize, MaxSize));
	OwnerCharacter->SetActorScale3D(FVector(Scale));
}

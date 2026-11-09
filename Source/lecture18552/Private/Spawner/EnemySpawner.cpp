// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/EnemySpawner.h"

#include "Components/BillboardComponent.h"
#include "Engine/World.h"


namespace
{
	// An entry is usable if it has a class set and a non-zero weight.
	bool IsEntryValid(const FEnemySpawnEntry& Entry)
	{
		return Entry.EnemyClass != nullptr && Entry.SelectionWeight > 0.0f;
	}

	// A tier can be picked only if its chance is above zero and it has at least one usable entry,
	// so an empty tier never "eats" a spawn wave.
	bool CanTierSpawn(const FEnemyTierConfig& Tier)
	{
		if (Tier.SpawnChance <= 0.0f)
		{
			return false;
		}

		for (const FEnemySpawnEntry& Entry : Tier.EnemyEntries)
		{
			if (IsEntryValid(Entry))
			{
				return true;
			}
		}
		return false;
	}
}


AEnemySpawner::AEnemySpawner()
{
	
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

#if WITH_EDITORONLY_DATA
	// Editor-only icon so the spawner is visible in the viewport;
	Billboard = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	if (Billboard)
	{
		Billboard->SetupAttachment(Root);
	}
#endif

	// GDD 3.1.1.6 encounter ratio: 60% fodder, 30% Enforcer, 10% Brutalizer.
	FodderTier.SpawnChance = 60.0f;
	MidTier.SpawnChance = 30.0f;
	EliteTier.SpawnChance = 10.0f;
}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	// One spawn per room load. The room is cleared, the next room loads its own spawners.
	if (bSpawnOnBeginPlay)
	{
		SpawnEnemy();
	}
}

const FEnemyTierConfig* AEnemySpawner::PickTier() const
{
	const FEnemyTierConfig* Tiers[] = { &FodderTier, &MidTier, &EliteTier };

	float TotalChance = 0.0f;
	for (const FEnemyTierConfig* Tier : Tiers)
	{
		if (CanTierSpawn(*Tier))
		{
			TotalChance += Tier->SpawnChance;
		}
	}

	if (TotalChance <= 0.0f)
	{
		return nullptr;
	}

	// Roll once, then walk the tiers subtracting each chance until the roll lands inside one.
	float Roll = FMath::FRandRange(0.0f, TotalChance);
	const FEnemyTierConfig* LastValid = nullptr;

	for (const FEnemyTierConfig* Tier : Tiers)
	{
		if (!CanTierSpawn(*Tier))
		{
			continue;
		}

		LastValid = Tier;
		if (Roll < Tier->SpawnChance)
		{
			return Tier;
		}
		Roll -= Tier->SpawnChance;
	}

	// a roll of exactly TotalChance falls through the loop.
	return LastValid;
}

const FEnemySpawnEntry* AEnemySpawner::PickEntry(const FEnemyTierConfig& Tier)
{
	float TotalWeight = 0.0f;
	for (const FEnemySpawnEntry& Entry : Tier.EnemyEntries)
	{
		if (IsEntryValid(Entry))
		{
			TotalWeight += Entry.SelectionWeight;
		}
	}

	if (TotalWeight <= 0.0f)
	{
		return nullptr;
	}

	// Same weighted roll as PickTier, but across the entries in this tier.
	float Roll = FMath::FRandRange(0.0f, TotalWeight);
	const FEnemySpawnEntry* LastValid = nullptr;

	for (const FEnemySpawnEntry& Entry : Tier.EnemyEntries)
	{
		if (!IsEntryValid(Entry))
		{
			continue;
		}

		LastValid = &Entry;
		if (Roll < Entry.SelectionWeight)
		{
			return &Entry;
		}
		Roll -= Entry.SelectionWeight;
	}

	return LastValid;
}

void AEnemySpawner::SpawnEnemy()
{
	if (bHasSpawned)
	{
		return;
	}
	bHasSpawned = true;

	const FEnemyTierConfig* Tier = PickTier();
	if (!Tier)
	{
		return;
	}

	const FEnemySpawnEntry* Entry = PickEntry(*Tier);
	if (!Entry)
	{
		return;
	}

	// Guard against Min > Max being typed into the details panel.
	const int32 MinSize = FMath::Min(Entry->MinGroupSize, Entry->MaxGroupSize);
	const int32 MaxSize = FMath::Max(Entry->MinGroupSize, Entry->MaxGroupSize);
	const int32 GroupSize = FMath::RandRange(MinSize, MaxSize);

	const FVector Center = GetActorLocation();
	const FRotator Facing = GetActorRotation();

	for (int32 i = 0; i < GroupSize; ++i)
	{
		// Scatter each member on a flat circle around the spawner so they don't stack.
		const FVector2D Offset = FMath::RandPointInCircle(GroupSpawnRadius);
		const FVector Location = Center + FVector(Offset.X, Offset.Y, 0.0f);

		SpawnEnemyAtTransform(Entry->EnemyClass, FTransform(Facing, Location));
	}
}

ABaseEnemy* AEnemySpawner::SpawnEnemyAtTransform(TSubclassOf<ABaseEnemy> EnemyClass, const FTransform& SpawnTransform)
{
	UWorld* World = GetWorld();
	if (!World || !EnemyClass)
	{
		return nullptr;
	}

	FActorSpawnParameters Params;
	Params.Owner = this;
	// If the spot overlaps something, nudge the enemy to a free spot
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	return World->SpawnActor<ABaseEnemy>(EnemyClass, SpawnTransform, Params);
}

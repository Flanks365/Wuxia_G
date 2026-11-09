// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy.h"

#include "Enemies/EnemyStatsComponent.h"


ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	// Spawned enemies only get an AI controller if this is set; the default
	// (PlacedInWorld) leaves spawner-created enemies with no controller.
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	EnemyStats = CreateDefaultSubobject<UEnemyStatsComponent>(TEXT("EnemyStats"));
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
}

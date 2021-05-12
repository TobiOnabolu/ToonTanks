// Fill out your copyright notice in the Description page of Project Settings.
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "PawnTurret.h"

	// Called when the game starts or when spawned
void APawnTurret::BeginPlay() 
{
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);			//Setting timer to call the checkfirecondition every 2 seconds

}


APawnTurret::APawnTurret() 
{

}

// Called every frame
void APawnTurret::Tick(float DeltaTime)			//if not implemented in base CUT and paste in child class!
{
	Super::Tick(DeltaTime);
}

void CheckFireCondition()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing"));

}


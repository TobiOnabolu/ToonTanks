// Fill out your copyright notice in the Description page of Project Settings.
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Vector.h"
#include "PawnTurret.h"

	// Called when the game starts or when spawned
void APawnTurret::BeginPlay() 
{
	//assiging player in game to our var
	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));	//we know have reference to the player tank in our game and can use it to check if we are dead
	
	//Setting Timer
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

void APawnTurret::CheckFireCondition()
{
//	UE_LOG(LogTemp, Warning, TEXT("Firing"));

	//checking if player exists(i.e not dead)
	if (!PlayerTank)	//if no player dont shoot
	{
		return;
	}
	//checking if player in distance to fire
	if (GetDistanceFromTank() < FiringDistance) 
	{
		//fire
	}

}

float APawnTurret::GetDistanceFromTank()
{
	//getting distance btwn player and turret
	return FVector::Dist(PlayerTank->GetActorLocation(), GetActorLocation()); // return the distance between points

}


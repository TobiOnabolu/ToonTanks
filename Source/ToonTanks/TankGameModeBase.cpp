// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerControllerBase.h"
#include "TankGameModeBase.h"

void ATankGameModeBase::HandleGameStart()
{
	//Retrieving all the turret actor in the world
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
	TargetTurrets = TurretActors.Num();

	//retrieve the player in world
	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	//retrieving player  controller
	PlayerControllerRef = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	GameStart();
}
void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	GameOver(PlayerWon);
}
void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	//UE_LOG(LogTemp, Warning, TEXT("An Actor died"));

	if (DeadActor == PlayerTank) {
		PlayerTank->HandleDestruction();
		HandleGameOver(false); //player didnt win

		//disable player controller 
		if (PlayerControllerRef)
		{
			PlayerControllerRef->SetPlayerEnabledState(false);
			

		}
	}
	//Check if turret got destroyed
	else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))	//if this cast doesnt return null then it was a turret that was destroyed
	{
		DestroyedTurret->HandleDestruction();
		TargetTurrets -= 1;
		//check if all turrets destroyed
		if (TargetTurrets <= 0) {
			HandleGameOver(true);		//player won
		}
	}
}

void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	//handling start for game mode so we can change game over and game start
	HandleGameStart();
}
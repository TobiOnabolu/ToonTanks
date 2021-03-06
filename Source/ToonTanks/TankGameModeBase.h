// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"


/**
 * 
 */
class APlayerControllerBase;
class APawnTurret;
class APawnTank;
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);
	APawnTank* PlayerTank;
	//APawnTurret* PlayerTurret;
	int32 TargetTurrets = 0;
	APlayerControllerBase* PlayerControllerRef;

public:
	void ActorDied(AActor* DeadActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 3;

	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)		//remember those event you can add function too, this makes it so these functions are events and cant be implemented in c++
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};

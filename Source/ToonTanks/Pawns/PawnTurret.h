// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

/**
 * 
 */
class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private: 
	void CheckFireCondition();
	float GetDistanceFromTank();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle", meta = (AllowPrivateAccess = "true"))
	float FiringDistance = 500.0f;

	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerTank;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:
	APawnTurret();
	virtual void HandleDestruction() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;			//if not implemented in base CUT and paste in child class!

	
};

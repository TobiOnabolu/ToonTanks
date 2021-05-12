// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;


/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()
	
public:
	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;			//if not implemented in base CUT and paste in child class!

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; //if not implemented in base CUT and paste in child class!


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void HandleDestruction() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera = nullptr;

	APlayerController* PlayerController;
	FVector MoveDirection;
	FQuat RotationDirection;

	void CalculateMoveInput(float Value); //value represent the direction where to go, forward is 1.0, backward is -1.0
	void CalculateRotateInput(float Value); //value to represent where to rotate

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 500.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = 500.f;

	void Move();		//will go in tick and this is where we actually move
	void Rotate();
};

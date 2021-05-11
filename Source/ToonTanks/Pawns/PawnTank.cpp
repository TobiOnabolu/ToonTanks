// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Math/Rotator.h"
#include "Math/Quat.h"
#include "PawnTank.h"

APawnTank::APawnTank() 
{
	//Super::APawnBase(); //call constructor set up components in parent class
	
	//Setting Up camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent); 

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);


	//Testing
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
	Rotate();
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Assigning Our Key Binds.
	Super::SetupPlayerInputComponent(PlayerInputComponent);		//already given to us 
	PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);			//similiar to when we are setting up the input key for building escape, just using bindaxis now to give functionality to analog users as well
																									//Note this bind axis will send a float value to the function we have addressed
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);	

}

//This functions will run after the correct key is pressed due to binding in setupplayercomponent
void APawnTank::CalculateMoveInput(float Value)
{
	//Need to set our move vector with float value. This vector will be used when move is called
	MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0); //Create the FVector for move direction using where to go * how fast * making it fram independent
}

//These functions will run after the correct key is pressed due to binding in setupplayercomponent
void APawnTank::CalculateRotateInput(float Value)
{
	//this FQuat will be called when move is called
	float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;	//get the rotate speed direction and frames
	FRotator rotation = FRotator(0, RotateAmount, 0);		//Rotating on Z axis so we are only changing yaw value
	RotationDirection = FQuat(rotation);		//Can make an fquat from an FRotator
}

//Called In tick, doesnt move all the time because Move direction will have 0 vector when key is not pressed
void APawnTank::Move()
{
	AddActorLocalOffset(MoveDirection, true); //Set Bsweep to true so that it wont phase thru floor or walls
}

//Called In tick, doesnt move all the time because rotate direction will have 0 vector when key is not pressed
void APawnTank::Rotate()
{
	AddActorLocalRotation(RotationDirection, true); //Set sweep to true again
}

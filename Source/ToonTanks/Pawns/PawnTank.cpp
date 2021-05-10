// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "PawnTank.h"

APawnTank::APawnTank() 
{
	//Super::APawnBase(); //call constructor set up components in parent class
	
	//Setting Up camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent); 

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);


	
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

void APawnTank::CalculateMoveInput(float Value)
{
	//Need to set our move vector with float value
}

void APawnTank::CalculateRotateInput(float Value)
{

}

void APawnTank::Move()
{

}

void APawnTank::Rotate()
{

}

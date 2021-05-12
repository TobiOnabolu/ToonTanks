// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanks/Pawns/PawnBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetUpComponents();					//SetUp All our components for our derived class, so that they actually represent something for our actor
	
	
}

void APawnBase::SetUpComponents()
{
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision Component"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh Component"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh Component"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Component"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget)		//look at target is the location of where the target is
{
	//update turretmesh rotation to face toward the target passed from child class
	//gonna need to use tURRETMESH->Setworldrotation

	//get variables needed for calc
	FVector LookAtTargetXY = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);		//Get the location of the target you will be firing it so it can be converted to rotation. We dont want updown rotation, so we dont include the z of target
	FVector TurretMeshLocation = TurretMesh->GetComponentLocation();

	//calculate the frotator for the turretmesh
	FRotator TurretRotator = FVector(LookAtTargetXY - TurretMeshLocation).Rotation();

	//set the turret mesh rotation
	TurretMesh->SetWorldRotation(TurretRotator);
	//UE_LOG(LogTemp, Warning, TEXT("Finding"));

}
void APawnBase::Fire()
{
	//get projectilespawnpoint

}
void APawnBase::HandleDestruction()			//this is the only function that needs to be overriden by our child classes.
{

}

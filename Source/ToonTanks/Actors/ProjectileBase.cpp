// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Components/StaticMeshComponent.h"
#include  "Kismet/GameplayStatics.h"
#include "ProjectileBase.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement")); //dont set up attachment with this becuase it doesnt go in that hiearchy
	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;				//use ur projectile movement! set the speed of projectile
	
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	AActor* MyOwner = GetOwner();  //we are able to get the owner of the projectile, which is the tank or turret, because set ownere when creating the fire function
	if (!MyOwner) { return; }

	if (OtherActor && OtherActor != this && OtherActor != MyOwner) {	//these check confirm we hit a valid actor, i.e not ourselve and not the thing that shot us
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwner->GetInstigatorController(), this, DamageType);	//this is what applies damage to other actor
		
	}

	Destroy(); //Destroy Acto on hit.
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
	//these need to go in Begin play cause the BP may override them if theyre in constructor
	InitialLifeSpan = LifeSpan;
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);		//used to delegate what happens when collision happens on projectile mesh //check events in blue print for a lot of other methods like this	
}




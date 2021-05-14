// Fill out your copyright notice in the Description page of Project Settings.
#include "TankGameModeBase.h"
#include  "Kismet/GameplayStatics.h"
#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
	//assign the delegate function for take damage
	GameModeRef = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);

	
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	//take damage form character
	if (Damage == 0 || Health <= 0) {
		return;
	}
	//update health of health value
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	//check if actor died
	if (Health <= 0) {
		if (GameModeRef) {
			GameModeRef->ActorDied(GetOwner());	//call actor died function of actor 
		}
	}
}



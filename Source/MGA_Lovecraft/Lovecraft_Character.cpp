// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Lovecraft_PlayerController.h"
#include "Lovecraft_Character.h"

// Sets default values
ALovecraft_Character::ALovecraft_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALovecraft_Character::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALovecraft_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALovecraft_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ALovecraft_Character::MoveToLocation(FVector TargetLocation)
{
    UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
    if (NavSystem)
    {
        FVector NavLocation;
        if (NavSystem->K2_ProjectPointToNavigation(GetWorld(), TargetLocation, NavLocation))
        {
            UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), NavLocation);
        }
    }
}


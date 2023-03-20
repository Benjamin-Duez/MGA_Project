// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NavigationSystem.h"
#include "Lovecraft_Character.h"
#include "Lovecraft_PlayerController.h"



ALovecraft_PlayerController::ALovecraft_PlayerController() 
{
	// Enable mouse cursor by default
	bShowMouseCursor = true;

	// Create instances of the three character classes
	Character1 = GetWorld()->SpawnActor<ALovecraft_Character>();
	Character2 = GetWorld()->SpawnActor<ALovecraft_Character>();
	Character3 = GetWorld()->SpawnActor<ALovecraft_Character>();

	// Set the first character as the active character
	ActiveCharacter = Character1;    

}

void ALovecraft_PlayerController::SwitchToCharacter1()
{
    ActiveCharacter = Character1;
}

void ALovecraft_PlayerController::SwitchToCharacter2()
{
    ActiveCharacter = Character2;
}

void ALovecraft_PlayerController::SwitchToCharacter3()
{
    ActiveCharacter = Character3;
}

void ALovecraft_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    

    // Bind input axes for movement and look
    /*
    InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
    InputComponent->BindAxis("LookUp", this, &AMyPlayerController::LookUp);
    InputComponent->BindAxis("LookRight", this, &AMyPlayerController::LookRight);
    */

    // Bind input actions for switching characters
    InputComponent->BindAction("SwitchToCharacter1", IE_Pressed, this, &ALovecraft_PlayerController::SwitchToCharacter1);
    InputComponent->BindAction("SwitchToCharacter2", IE_Pressed, this, &ALovecraft_PlayerController::SwitchToCharacter2);
    InputComponent->BindAction("SwitchToCharacter3", IE_Pressed, this, &ALovecraft_PlayerController::SwitchToCharacter3);

    // Bind input actions for movement
    InputComponent->BindAction("MoveToMouseCursor", IE_Pressed, this, &ALovecraft_PlayerController::OnMoveToMouseCursor);
}

/*
void ALovecraft_PlayerController::OnMoveToMouseCursor()
{
    if (ActiveCharacter != nullptr)
    {
        // Trace to see what is under the mouse cursor
        FHitResult HitResult;
        GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

        // Move the active character to the location on the navigation mesh that was clicked
        UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
        if (NavSystem != nullptr)
        {
            //FVector NavLocation = NavSystem->GetRandomPointInNavigableRadius(HitResult.Location, 100.0f);
            FVector NavLocation = NavSystem->GetRandomPointInNavigableRadius(GetWorld(),)
            ActiveCharacter->MoveToLocation(NavLocation);
        }
    }
}*/


/*
void ALovecraft_PlayerController::OnMoveToMouseCursor()
{
    // Get the location that was clicked on the screen
    FVector DestinationLocation;
    if (GetHitResultUnderCursor(ECC_Visibility, true, DestinationLocation))
    {
        // Find a path to the destination location using the navigation mesh
        UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
        if (NavSystem)
        {
            FNavLocation NavLocation;
            NavSystem->ProjectPointToNavigation(DestinationLocation, NavLocation);
            MoveToLocation(NavLocation.Location);
        }
    }
}
*/


float ALovecraft_PlayerController::computeCost(AController* Controller, FVector start, FVector end) {
	UNavigationSystemV1* NavSys = Controller ? FNavigationSystem::GetCurrent<UNavigationSystemV1>(Controller->GetWorld()) : nullptr;
	float cost;
	if (NavSys != nullptr) {
		NavSys->GetPathCost(start, end, cost);
	}
	return ((float)((int) cost))/100;
}
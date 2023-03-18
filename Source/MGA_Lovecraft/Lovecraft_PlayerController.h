// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NavigationSystem.h"
#include "Lovecraft_Character.h"
#include "Lovecraft_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MGA_LOVECRAFT_API ALovecraft_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ALovecraft_Character*> character_List;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ALovecraft_Character* possessed;

	/*
	UFUNCTION()
		void OnMoveToMouseCursor();
	*/

	



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ALovecraft_Character* Character1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ALovecraft_Character* Character2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ALovecraft_Character* Character3;




	UPROPERTY()
	ALovecraft_Character* ActiveCharacter;


	
	UFUNCTION(EditAnywhere, BlueprintReadWrite)
	void SwitchToCharacter1();

	UFUNCTION(EditAnywhere, BlueprintReadWrite)
	void SwitchToCharacter2();

	UFUNCTION(EditAnywhere, BlueprintReadWrite)
	void SwitchToCharacter3();

	

	UFUNCTION()
	void SetupInputComponent();

	UFUNCTION()
	void OnMoveToMouseCursor();

	UFUNCTION(BlueprintCallable)
	float computeCost(AController* Controller, FVector start, FVector end);


	ALovecraft_PlayerController(); // constructor

	
};

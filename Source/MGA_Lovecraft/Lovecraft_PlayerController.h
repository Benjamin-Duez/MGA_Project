// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NavigationSystem.h"

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
		TArray<ACharacter*> character_List;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ACharacter* possessed;

	UFUNCTION(BlueprintCallable)
		float computeCost(AController* Controller, FVector start, FVector end);
	
};

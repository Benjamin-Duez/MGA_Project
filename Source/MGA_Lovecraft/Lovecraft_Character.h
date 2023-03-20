// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
//#include "Lovecraft_PlayerController.h"
#include "Lovecraft_Character.generated.h"

UCLASS()
class MGA_LOVECRAFT_API ALovecraft_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALovecraft_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UFUNCTION(BlueprintCallable)
	//virtual void MoveToLocation(FVector TargetLocation);

};

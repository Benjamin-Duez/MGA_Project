// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/SkeletalMesh.h"
#include "DA_PlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MGA_LOVECRAFT_API UDA_PlayableCharacter : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Character Data")
		FName name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Character Data")
		float health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Character Data")
		float armor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Character Data")
		float speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Character Data")
		float attackDamage;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Character Data")
		USkeletalMesh* CharacterMesh;	
	*/


	




};

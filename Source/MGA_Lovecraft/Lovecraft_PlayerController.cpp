// Fill out your copyright notice in the Description page of Project Settings.


#include "Lovecraft_PlayerController.h"


float ALovecraft_PlayerController::computeCost(AController* Controller, FVector start, FVector end) {
	UNavigationSystemV1* NavSys = Controller ? FNavigationSystem::GetCurrent<UNavigationSystemV1>(Controller->GetWorld()) : nullptr;
	float cost;
	if (NavSys != nullptr) {
		NavSys->GetPathCost(start, end, cost);
	}
	return ((float)((int) cost))/100;
}
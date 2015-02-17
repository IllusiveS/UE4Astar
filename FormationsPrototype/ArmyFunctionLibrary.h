// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Army/CodeArmy.h"
#include "ArmyFunctionLibrary.generated.h"

class ACodeArmy;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API UArmyFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "Army Functions")
		static void SelectUnit(ACodeArmy* armyToSelect);

	UFUNCTION(BlueprintCallable, Category = "Army Functions")
		static ACodeArmy* GetSelectedUnit();
	
};

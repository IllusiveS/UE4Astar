// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "UnitContainer.generated.h"

class ACodeUnit;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API UUnitContainer : public UActorComponent
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Units")
		TArray<ACodeUnit*> Units;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Units")
		void AddUnit(ACodeUnit* unitToAdd);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Units")
		void RemoveUnit(ACodeUnit* unitToRemove);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Units")
		TArray<TSubclassOf<ACodeUnit>> UnitsToCreate;

	void SpawnUnits();
};

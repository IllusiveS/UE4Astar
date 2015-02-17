// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UnitDisplayerActor.generated.h"

class UUnitContainer;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API AUnitDisplayerActor : public AActor
{
	GENERATED_UCLASS_BODY()

	UUnitContainer* unitContainerToDisplay;

	UFUNCTION(BlueprintCallable, Category = "Unit display")
		void DisplayUnits(UUnitContainer * unitContainer);

	UFUNCTION(BlueprintCallable, Category = "Unit display")
		void StopDisplayUnits();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display units")
		float XCoordinate;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display units")
		float YCoordinate;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display units")
		float XOffset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display units")
		float YOffset;


	virtual void BeginPlay() override;
	void SetUp();
	FVector2D GetSizeOfViewport();
private:
	void Display();
};

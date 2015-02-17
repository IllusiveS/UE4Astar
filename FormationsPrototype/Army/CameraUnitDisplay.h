// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "CameraUnitDisplay.generated.h"

class ACodeArmy;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class FORMATIONSPROTOTYPE_API UCameraUnitDisplay : public USceneComponent
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Display units")
		ACodeArmy* ArmyToDisplay;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Display units")
		float XCoordinate;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Display units")
		float YCoordinate;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Display units")
		void displayUnitsOfArmy(ACodeArmy* armyForDisplay);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Display units")
		void displayUnits();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	virtual void OnRegister() override;

private:
	void SetUp();
	FVector2D GetSizeOfViewport();
};

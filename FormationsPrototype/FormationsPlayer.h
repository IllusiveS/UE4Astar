// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "FormationsPlayer.generated.h"

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API UFormationsPlayer : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "")
		int32 playerNumber;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Players")
		TArray<ACodeArmy*> Armies;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Armies")
		void AddArmy(ACodeArmy* addArmy);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Turn")
		void PassTurn(bool activate);
	
};

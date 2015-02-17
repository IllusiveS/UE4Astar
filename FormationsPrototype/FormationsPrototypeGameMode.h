// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "FormationsPrototypeGameMode.generated.h"

class UFormationsPlayer;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API AFormationsPrototypeGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Players")
		TArray<UFormationsPlayer*> Players;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Players")
		int32 MaxPlayers;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Turn")
		int32 CurrentTurn;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Turn")
		int32 CurrentPlayer;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Turn")
		void PassTurn();

	virtual void BeginPlay() override;
	
};

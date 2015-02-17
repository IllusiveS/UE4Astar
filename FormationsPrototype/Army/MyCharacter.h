// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API AMyCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "display units")
		TSubobjectPtr<UChildActorComponent> UnitDisplayer;

	virtual void BeginPlay() override;

protected:
	void MoveRight(float Value);
	void MoveForward(float Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface
};

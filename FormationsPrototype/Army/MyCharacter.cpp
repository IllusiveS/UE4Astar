// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "MyCharacter.h"
#include "UnitDisplayerActor.h"


AMyCharacter::AMyCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	UnitDisplayer = PCIP.CreateDefaultSubobject<UChildActorComponent>(this, "Unit Displayer");
	UnitDisplayer->ChildActorClass = AUnitDisplayerActor::StaticClass();
}
//////////////////////////////////////////////////////////////////////////
// Input

void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
}

void AMyCharacter::MoveForward(float Value)
{
	AddMovementInput(this->GetActorForwardVector(), Value);
}

void AMyCharacter::MoveRight(float Value)
{
	AddMovementInput(this->GetActorRightVector(), Value);
}

void AMyCharacter::BeginPlay()
{
}

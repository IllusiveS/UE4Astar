// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "UnitDisplayerActor.h"
#include "Army/UnitContainer.h"
#include "Army/Units/CodeUnit.h"
#include "Army/MyCharacter.h"

AUnitDisplayerActor::AUnitDisplayerActor(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}

void AUnitDisplayerActor::DisplayUnits(UUnitContainer* unitContainer)
{
	StopDisplayUnits();
	unitContainerToDisplay = unitContainer;
	for (int i = 0; i < unitContainerToDisplay->Units.Num(); i++)
	{
		ACodeUnit* processedUnit = unitContainer->Units[i];
		FVector trans = this->GetTransform().GetLocation();
		processedUnit->SetActorLocation(trans+GetActorLocation());
		processedUnit->SetActorRotation(GetActorRotation());
		processedUnit->AttachRootComponentToActor(this, NAME_None, EAttachLocation::KeepRelativeOffset);
		processedUnit->SetActorRelativeLocation(FVector(50, 10, 500));
	}
	Display();
}

void AUnitDisplayerActor::StopDisplayUnits()
{
	if (unitContainerToDisplay)
	{
		for (int i = 0; i < unitContainerToDisplay->Units.Num(); i++)
		{
			ACodeUnit* processedUnit = unitContainerToDisplay->Units[i];
			processedUnit->DetachRootComponentFromParent(false);
		}
	}

	unitContainerToDisplay = nullptr;

	//for (int i = 0; i < TheUnitsBeingDisplayed.Num(); i++)
	//{
	//	TheUnitsBeingDisplayed[i]->UnregisterComponent();
	//}

	for (TObjectIterator<ACodeUnit> Itr; Itr; ++Itr)
	{
		Itr->SetActorLocation(FVector(900, 900, 900));
	}
}

void AUnitDisplayerActor::BeginPlay()
{
	SetUp();
}
void AUnitDisplayerActor::SetUp()
{
	for (TObjectIterator<AMyCharacter> Itr; Itr; ++Itr)
	{
		AttachRootComponentToActor(*Itr, NAME_None, EAttachLocation::SnapToTarget);
	}

	FVector2D ViewportSize = GetSizeOfViewport();
	FVector2D NewPosition = FVector2D(ViewportSize.X * XCoordinate, ViewportSize.Y * YCoordinate);
	FVector Rotation = GetActorRotation().Vector();
	FVector Location = GetActorLocation();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectScreenPositionToWorld(NewPosition.X, NewPosition.Y, Location, Rotation);
}
FVector2D AUnitDisplayerActor::GetSizeOfViewport()
{
	UWorld* World = GEngine->GetWorldFromContextObject(this);
	if (World && World->IsGameWorld())
	{
		if (UGameViewportClient* ViewportClient = World->GetGameViewport())
		{
			FVector2D ViewportSize;
			ViewportClient->GetViewportSize(ViewportSize);
			return ViewportSize;
		}
	}

	return FVector2D(1, 1);
}

void AUnitDisplayerActor::Display()
{
	for (int i = 0; i < unitContainerToDisplay->Units.Num(); i++)
	{
		ACodeUnit* processedUnit = unitContainerToDisplay->Units[i];
	}
}
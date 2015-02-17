// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "CameraUnitDisplay.h"
#include "CodeArmy.h"
#include "Units/CodeUnit.h"
#include "UnitContainer.h"


UCameraUnitDisplay::UCameraUnitDisplay(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}

void UCameraUnitDisplay::displayUnitsOfArmy_Implementation(ACodeArmy* armyForDisplay)
{
	ArmyToDisplay = armyForDisplay;
}

void UCameraUnitDisplay::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	
}

void UCameraUnitDisplay::displayUnits_Implementation()
{
	if (!ArmyToDisplay)
	{
		return;
	}
	for (int i = 0; i < ArmyToDisplay->UnitContainer->Units.Num(); i++)
	{
		ACodeUnit* unit = ArmyToDisplay->UnitContainer->Units[i];
		unit->SetActorLocation(this->GetComponentLocation());
	}
}

void UCameraUnitDisplay::OnRegister()
{
	Super::OnRegister();
	SetUp();
}

void UCameraUnitDisplay::SetUp()
{
	FVector2D ViewportSize = GetSizeOfViewport();
	FVector2D NewPosition = FVector2D(ViewportSize.X * XCoordinate, ViewportSize.Y * YCoordinate);
	FVector Rotation = this->GetComponentRotation().Vector();
	FVector Location = this->GetComponentLocation();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectScreenPositionToWorld(NewPosition.X, NewPosition.Y, Location, Rotation);
}

FVector2D UCameraUnitDisplay::GetSizeOfViewport()
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
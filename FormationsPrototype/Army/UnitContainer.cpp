// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "UnitContainer.h"
#include "Units/CodeUnit.h"

UUnitContainer::UUnitContainer(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void UUnitContainer::AddUnit_Implementation(ACodeUnit* unitToAdd)
{
	Units.Add(unitToAdd);
}

void UUnitContainer::RemoveUnit_Implementation(ACodeUnit* unitToRemove)
{
	Units.Add(unitToRemove);
}
void UUnitContainer::SpawnUnits()
{
	for (int i = 0; i < UnitsToCreate.Num(); i++)
	{
		ACodeUnit* unit = Cast<ACodeUnit>((GetWorld()->SpawnActor(UnitsToCreate[i])));
		Units.Add(unit);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "Army/MovingAlgorithm.h"
#include "ArmyFunctionLibrary.h"
#include "Army/UnitContainer.h"
#include "UnitDisplayerActor.h"


UArmyFunctionLibrary::UArmyFunctionLibrary(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void UArmyFunctionLibrary::SelectUnit(ACodeArmy* armyToSelect)
{
	UObject* worldContext;
	for (TObjectIterator<ACodeArmy> Itr; Itr; ++Itr)
	{
		Itr->isSelected = false;
		worldContext = *Itr;
	}
	if (armyToSelect)
	{
		for (TObjectIterator<AUnitDisplayerActor> Itr; Itr; ++Itr)
		{
			Itr->DisplayUnits(armyToSelect->UnitContainer);
		}
		armyToSelect->isSelected = true;
		armyToSelect->MovingAlgorithm->GenerateGrid(armyToSelect->MovingAlgorithm->Location, armyToSelect->MovingAlgorithm->moveLeft);
	}
	
}

ACodeArmy* UArmyFunctionLibrary::GetSelectedUnit()
{
	ACodeArmy* army = nullptr;
	for (TObjectIterator<ACodeArmy> Itr; Itr; ++Itr)
	{
		if (Itr->isSelected)
		{
			army = *(Itr);
		}
	}
	return army;
}



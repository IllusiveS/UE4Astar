// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "FormationsPlayer.h"
#include "Army/CodeArmy.h"


UFormationsPlayer::UFormationsPlayer(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


void UFormationsPlayer::AddArmy_Implementation(ACodeArmy* addArmy)
{
	Armies.Add(addArmy);
}

void UFormationsPlayer::PassTurn_Implementation(bool activate)
{
	for (int i = 0; i < Armies.Num(); i++)
	{
		Armies[0]->isItsTurn = activate;
	}
}

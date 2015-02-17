// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "FormationsPrototypeGameMode.h"
#include "FormationsPlayer.h"
#include "Army/CodeArmy.h"

AFormationsPrototypeGameMode::AFormationsPrototypeGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}

void AFormationsPrototypeGameMode::BeginPlay()
{
	for (int i = 1; i <= MaxPlayers; i++)
	{
		Players.Add(NewObject<UFormationsPlayer>());
		Players[i - 1]->playerNumber = i;
	}

	for (TObjectIterator<ACodeArmy> Itr; Itr; ++Itr)
	{
		Players[Itr->Player]->AddArmy(*(Itr));
	}
}

void AFormationsPrototypeGameMode::PassTurn_Implementation()
{
	CurrentTurn++;
	CurrentPlayer++;
	if (CurrentPlayer > MaxPlayers)
		CurrentPlayer = 0;
	for (int i = 0; i < MaxPlayers; i++)
	{
		bool isHisTurn = false;
		if (i == CurrentPlayer)
			isHisTurn = true;
		Players[i]->PassTurn(isHisTurn);
	}
}

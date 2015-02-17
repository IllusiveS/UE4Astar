// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "FormationsPlayerController.h"


AFormationsPlayerController::AFormationsPlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
}



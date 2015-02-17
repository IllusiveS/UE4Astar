// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "CodeUnit.h"
#include "PaperSpriteComponent.h"


ACodeUnit::ACodeUnit(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	BoxCollider = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxCollider"));
	Sprite = PCIP.CreateDefaultSubobject<UPaperSpriteComponent>(this, TEXT("Sprite"));

	Sprite->AttachTo(BoxCollider);
	RootComponent = BoxCollider;

	BoxCollider->SetBoxExtent(FVector(0, 0, 0));
}



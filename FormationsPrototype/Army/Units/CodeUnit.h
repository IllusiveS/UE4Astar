// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "CodeUnit.generated.h"

class UPaperSpriteComponent;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API ACodeUnit : public APawn
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
		TSubobjectPtr<UBoxComponent> BoxCollider;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
		TSubobjectPtr<UPaperSpriteComponent> Sprite;
};

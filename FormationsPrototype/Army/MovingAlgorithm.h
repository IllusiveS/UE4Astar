// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "MovingAlgorithm.generated.h"


class AGridNode;
class ACodeArmy;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API UMovingAlgorithm : public UActorComponent
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Astar")
		int32 moveLeft;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Astar")
		int32 maxMove;

	ACodeArmy* owner;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Basic")
		TArray<AGridNode*> Route;

	UFUNCTION(BlueprintCallable, Category = "Astar")
		void GenerateGrid(AGridNode* start, int32 movement);
	UFUNCTION(BlueprintCallable, Category = "Astar")
		TArray<AGridNode*> GenerateRoute(AGridNode* start, AGridNode* end);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		AGridNode* Location;

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void MoveTo(TArray<AGridNode*> RouteToNode);
	UFUNCTION(BlueprintCallable, Category = "Movement")
		FRotator ChangeNodes();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Movement")
		bool IsNextNodeReached();

protected:
	AGridNode* TryNode(AGridNode* Start, AGridNode* End, int32 movement);
	bool IsFaster(AGridNode* Start, AGridNode* End, int32 movement);
	void FinishMovement();
};

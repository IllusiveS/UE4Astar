// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GridNode.generated.h"

class ACodeArmy;
class UMovingAlgorithm;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API AGridNode : public APawn
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
		TSubobjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Astar")
		AGridNode* prevNode;
	int32 moveLeft;
	bool WasVisited;
	TArray<AGridNode*> allNodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		TArray<AGridNode*> Neighbours;
	UPROPERTY(EditDefaultsOnly, Category = "Astar")
		int32 Cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		TArray<ACodeArmy*> UnitsOnNode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		bool IsActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		bool canBeAttacked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		bool bIsAttackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		bool bIsPassable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Astar")
		bool bIsEnterable;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Astar")
		virtual bool IsEnterable(UMovingAlgorithm* alg, AGridNode* prev);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Astar")
		virtual bool IsPassable(UMovingAlgorithm* alg, AGridNode* prev);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Astar")
		virtual bool IsAttackable(UMovingAlgorithm* alg, AGridNode* prev);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Astar")
		void Enter(ACodeArmy* EnteringUnit);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Astar")
		void Leave(ACodeArmy* LeavingUnit);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Visuals")
		void SetState(bool enter, bool attack, bool pass, bool Visited, int32 movePointsLeft, AGridNode* prev);

	virtual void BeginPlay() override;
	void ResetNodeEvent();
	void FindNeighbours();

private:
	void ResetNode();
	
};

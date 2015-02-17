// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "MovingAlgorithm.h"
#include "../GridNode.h"
#include "CodeArmy.h"
#include "Kismet/KismetMathLibrary.h"
#include "../ArmyFunctionLibrary.h"


UMovingAlgorithm::UMovingAlgorithm(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	owner = Cast<ACodeArmy>(GetOuter());
}
void UMovingAlgorithm::GenerateGrid(AGridNode* start, int32 movement)
{
	start->ResetNodeEvent();

	if (!start || movement < 0)
		return;

	TArray<AGridNode*> NodesToTest;
	NodesToTest.Add(start);

	start->SetState(true, false, false, true, movement, nullptr);

	while (NodesToTest.Num() > 0)
	{
		AGridNode* testedNode = NodesToTest[0];
		for (int i = 0; i < testedNode->Neighbours.Num(); i++)
		{
			AGridNode* nextNode = TryNode(testedNode, testedNode->Neighbours[i], testedNode->moveLeft);
			if (nextNode != nullptr)
			{
				NodesToTest.Add(nextNode);
				nextNode->WasVisited = true;
			}
		}
		NodesToTest.RemoveAt(0);
	}
}
AGridNode* UMovingAlgorithm::TryNode(AGridNode* Start, AGridNode* End, int32 movement)
{
	if (End->IsAttackable(this, Start) && IsFaster(Start, End, movement) && Start->IsActive)
	{
		End->SetState(false, true, true, true, movement - End->Cost, Start);
	}
	else
		if (End->IsEnterable(this, Start) && IsFaster(Start, End, movement))
		{
			End->SetState(true, false, false, true, movement - End->Cost, Start);
			return End;
		}
		else
		if (End->IsPassable(this, Start) && IsFaster(Start, End, movement))
		{
			End->SetState(false, false, true, true, movement - End->Cost, Start);
			return End;
		}
	return nullptr;
}
bool UMovingAlgorithm::IsFaster(AGridNode* Start, AGridNode* End, int32 movement)
{
	return End->Cost <= movement && End->moveLeft < movement - End->Cost;
}
TArray<AGridNode*> UMovingAlgorithm::GenerateRoute(AGridNode* start, AGridNode* end)
{
	TArray<AGridNode*> Route;

	AGridNode* testedNode = end;

	do
	{
		Route.Insert(end, 0);
		end = end->prevNode;
	} while (end != nullptr);

	return Route;
}

void UMovingAlgorithm::MoveTo(TArray<AGridNode*> RouteToNode)
{
	Route.Empty();
	Route = RouteToNode;
	owner->SetActorRotation(ChangeNodes());
}
FRotator UMovingAlgorithm::ChangeNodes()
{
	FRotator rotator;

	if (Route.Num() == 1)
	{
		Route.RemoveAt(0);
		FinishMovement();
	}
	if (Route.Num() > 1)
	{
		owner->ConsumeMovementInputVector();
		FVector newPosition = FVector(Route[0]->GetActorLocation().X, Route[0]->GetActorLocation().Y, owner->GetActorLocation().Z);
		owner->SetActorLocation(newPosition);
		rotator = FRotationMatrix::MakeFromX(Route[1]->GetActorLocation() - Route[0]->GetActorLocation()).Rotator();
		Route[0]->Leave(owner);
		Route[1]->Enter(owner);
		Route.RemoveAt(0);
	}

	return rotator;
}
bool UMovingAlgorithm::IsNextNodeReached()
{
	return owner->GetHorizontalDistanceTo(Route[0]) < owner->maxDistance;
}

void UMovingAlgorithm::FinishMovement()
{
	GenerateGrid(Location, -1);
	FVector newPosition = FVector(Location->GetActorLocation().X, Location->GetActorLocation().Y, owner->GetActorLocation().Z);
	owner->SetActorLocation(newPosition);
	UArmyFunctionLibrary::SelectUnit(nullptr);
}



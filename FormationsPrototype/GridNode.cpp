// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "GridNode.h"
#include "Army/CodeArmy.h"
#include "Army/MovingAlgorithm.h"
#include "Kismet/KismetSystemLibrary.h"

AGridNode::AGridNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	Mesh = PCIP.CreateDefaultSubobject<class UStaticMeshComponent>(this, TEXT("Mesh"));
	RootComponent = Mesh;
}

void AGridNode::BeginPlay()
{ 
	Super::BeginPlay();
	FindNeighbours();
}

void AGridNode::ResetNodeEvent()
{
	for (TActorIterator<AGridNode> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ActorItr->ResetNode();
	}
}
void AGridNode::ResetNode()
{
	SetState(false, false, false, false, -1, nullptr);
}



void AGridNode::Enter_Implementation(ACodeArmy* EnteringUnit)
{
	UnitsOnNode.Add(EnteringUnit);
	EnteringUnit->MovingAlgorithm->Location = this;
	EnteringUnit->MovingAlgorithm->moveLeft -= Cost;
}

void AGridNode::Leave_Implementation(ACodeArmy* LeavingUnit)
{
	UnitsOnNode.Remove(LeavingUnit);
}



void AGridNode::FindNeighbours()
{
	int directions[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	float Offset = 50.0f;

	TArray<AGridNode*> foundNeighbours;
	AActor* MyOwnerActor = Cast<AGridNode>(GetOuter());

	FVector Start;
	Start = GetActorLocation();

	FVector End;

	float Radius = 10.0f;
	float HalfHeight = 10.0f;

	TArray<TEnumAsByte<enum EObjectTypeQuery> > arrayTraceTypeAsByte;
	arrayTraceTypeAsByte.Add(EObjectTypeQuery::ObjectTypeQuery1);

	bool traceComplex = false;

	TArray<AActor*> IgnoredActors;

	EDrawDebugTrace::Type debugType = EDrawDebugTrace::None;

	TArray <FHitResult> hitResults;

	bool ignoreSelf = true;

	for (int i = 0; i < 4; i++)
	{
		End = FVector(Start.X + (Offset * directions[i][0]), Start.Y + (Offset * directions[i][1]), Start.Z);
		hitResults.Empty();

		UKismetSystemLibrary::CapsuleTraceMultiForObjects(
			GetWorld(),
			Start,
			End,
			Radius,
			HalfHeight,
			arrayTraceTypeAsByte,
			traceComplex,
			IgnoredActors,
			debugType,
			hitResults,
			ignoreSelf
			);
		for (int i = 0; i < hitResults.Num(); i++)
		{
			AGridNode* hit = Cast<AGridNode>(hitResults[i].GetActor());
			if (hit)
			{
				if (!foundNeighbours.Contains(hit) && this != hit)
					foundNeighbours.Add(hit);
			}
		}
	}
	Neighbours = foundNeighbours;
}

void AGridNode::SetState_Implementation(bool enter, bool attack, bool pass, bool Visited, int32 movePointsLeft, AGridNode* prev)
{
	bIsEnterable = enter;
	bIsAttackable = attack;
	bIsPassable = pass;
	WasVisited = Visited;
	moveLeft = movePointsLeft;
	prevNode = prev;
}



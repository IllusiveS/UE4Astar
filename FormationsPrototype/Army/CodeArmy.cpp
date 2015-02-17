// Fill out your copyright notice in the Description page of Project Settings.

#include "FormationsPrototype.h"
#include "CodeArmy.h"
#include "../GridNode.h"
#include "MovingAlgorithm.h"
#include "../ArmyFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UnitContainer.h"


ACodeArmy::ACodeArmy(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	UnitContainer = PCIP.CreateDefaultSubobject<UUnitContainer>(this, TEXT("Unit container"));
	MovingAlgorithm = PCIP.CreateDefaultSubobject<UMovingAlgorithm>(this, TEXT("Algorithm"));
	SelectionMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Selection Mesh"));
	SelectionMesh->AttachTo(Mesh);
}
void ACodeArmy::BeginPlay()
{
	Super::BeginPlay();
	FindNodeLocation();
	UnitContainer->SpawnUnits();
}
void ACodeArmy::FindNodeLocation()
{
	float Offset = 100.0f;

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
		End = FVector(Start.X, Start.Y, Start.Z - Offset);
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
		for (int32 i = 0; i < hitResults.Num(); i++)
		{
			AGridNode* location = Cast<AGridNode>(hitResults[i].GetActor());
			if (location && MovingAlgorithm->Location == nullptr)
			{
				MovingAlgorithm->Location = location;
				location->UnitsOnNode.Add(this);
			}
		}
	}
}
void ACodeArmy::Select_Implementation()
{
	UArmyFunctionLibrary::SelectUnit(this);
}
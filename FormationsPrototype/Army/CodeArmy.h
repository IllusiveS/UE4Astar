// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CodeArmy.generated.h"

class UMovingAlgorithm;
class AGridNode;
class UUnitContainer;

/**
 * 
 */
UCLASS()
class FORMATIONSPROTOTYPE_API ACodeArmy : public ACharacter
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
		bool isSelectable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
		bool isItsTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
		bool isSelected;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Basic")
		TSubobjectPtr<UMovingAlgorithm> MovingAlgorithm;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Basic")
		TSubobjectPtr<UStaticMeshComponent> SelectionMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Basic")
		TSubobjectPtr<UUnitContainer> UnitContainer;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Basic")
		int32 Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
		float maxDistance;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Basic")
		void Select();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Combat")
		virtual void Attack(ACodeArmy* defender);

	virtual void BeginPlay() override;
protected:
	void FindNodeLocation();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DiceTable.generated.h"

UCLASS()
class INVADER_API ADiceTable : public AInteractable
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UMaterialInstanceDynamic* _materialPtr;

	UPROPERTY(EditDefaultsOnly)
	float _distanceInteraction_touching;
	UPROPERTY(EditDefaultsOnly)
	float _distanceInteraction_near;

	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_touching;
	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_near;
	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_far;

public:
	// Sets default values for this actor's properties
	ADiceTable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Used to not repeat unnecessary operation every Tick update
	enum distanceType
	{
		touching,
		near,
		far
	};

	distanceType _distanceType;
};
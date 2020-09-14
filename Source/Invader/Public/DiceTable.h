// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "DiceTable.generated.h"

UCLASS()
class INVADER_API ADiceTable : public AInteractable
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	UMaterialInstanceDynamic* _materialPtr;

	UPROPERTY(EditDefaultsOnly)
	float _distanceInteraction_close;
	UPROPERTY(EditDefaultsOnly)
	float _distanceInteraction_near;
	UPROPERTY(EditDefaultsOnly)
	float _distanceInteraction_far;

	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_close;
	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_near;
	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_far;
	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_away;

public:
	// Sets default values for this actor's properties
	ADiceTable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
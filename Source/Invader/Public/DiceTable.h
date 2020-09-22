// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Math/Vector2D.h"
#include "DiceTable.generated.h"

/// This class can be assigned to every Dice Table object in the level
/// It makes the table change color in relation to the proximity of the player to this object
/// Since there are no other information given to the gameplay, this class can be further improved (some parts can be changed to override functions of AInteractable)
UCLASS()
class INVADER_API ADiceTable : public AInteractable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* _modelMeshPtr; /** The table model which has the material */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient)
	UMaterialInstanceDynamic* _materialPtr; /** The new material (generated at runtime during BeginPlay) to use to control the shader variables*/

private:
	/** The X and Y coordinates of where it stands, we save it since it's a static object (we don't create this variable in Interactable.h in case there will be moving interactable objects */
	FVector2D _xyLocation;
	/** The distances (in meters) assigned through Blueprint Editor that decide if a player is enough closer to this object */
	UPROPERTY(EditDefaultsOnly)
	float _distanceInteraction_touching;
	UPROPERTY(EditDefaultsOnly)
	float _distanceInteraction_near;

public:
	/** The colors assigned through Blueprint Editor that will change visually the apparence of the Dice Table */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FLinearColor _distanceColor_touching; // The color for when the player can interact with this object
	UPROPERTY(EditDefaultsOnly)
	FLinearColor _distanceColor_near; // The color for when the player is close enough to give them the information that this object is interactable, but not too close to interact with
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FLinearColor _distanceColor_far; // This color should be a grey close to a black or maybe, instead of changing color, this var could be replaced with a boolean (and and equivalent should be created in the shader)

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
	/** Enum used to not repeat unnecessary operation every Tick update */
	enum distanceType
	{
		touching,
		near,
		far
	};

	distanceType _distanceType;
};
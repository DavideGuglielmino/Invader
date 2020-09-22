// Fill out your copyright notice in the Description page of Project Settings.

#include "DiceTable.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "Containers/Array.h"
#include "InvaderCharacter.h"

// Sets default values
ADiceTable::ADiceTable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADiceTable::BeginPlay()
{
	Super::BeginPlay();

	// We create a dynamic copy of the material attached to model so that we can modify the shader variables at runtime via code
	_materialPtr = UMaterialInstanceDynamic::Create(_modelMeshPtr->GetMaterial(0), this);
	// We assign the new material to the model
	_modelMeshPtr->SetMaterial(0, _materialPtr);
}

// Called every frame
void ADiceTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Calculates the distance between this Actor and the player
	float distance = FGenericPlatformMath::Sqrt(FGenericPlatformMath::Pow(_playerPtr->GetActorLocation().X - this->GetActorLocation().X, 2) + FGenericPlatformMath::Pow(_playerPtr->GetActorLocation().Y - this->GetActorLocation().Y, 2));

	if (distance < _distanceInteraction_touching) // If the player is in range to interact with the object
	{
		if (_distanceType != touching)
		{
			_playerPtr->SetInteractable(this); // If the player gets in the interactable range, this object becomes the Interactable the player will activate if they will press the Interact Key, overriding any previous Interactable object
			OnTouchingBehaviour(true); // Make visible any added information created by the designer to the player
			_distanceType = touching;
			_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_touching);
		}
	}
	else if (distance < _distanceInteraction_near) // If the player is near this object but not to close to interact with it
	{
		if (_distanceType != near)
		{
			if (_distanceType == touching && _playerPtr->GetInteractable() == this) // If and only if the player is going away from this object and this was the Interactable object assigned to the player
			{
				_playerPtr->SetInteractable(nullptr); // Remove from the player the ppossibility to interact with this object
				OnTouchingBehaviour(false); // Make invisible any added information created by the designer to the player
			}
			_distanceType = near;
			_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_near);
		}
	}
	else // If the player isn't near this object
	{
		if (_distanceType != far)
		{
			_distanceType = far;
			_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_far);
		}
	}
}
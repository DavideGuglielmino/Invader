// Fill out your copyright notice in the Description page of Project Settings.

#include "GenericPlatform/GenericPlatformMath.h"
#include "DiceTable.h"
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

	UStaticMeshComponent* mesh = this->FindComponentByClass<UStaticMeshComponent>();
	_materialPtr = UMaterialInstanceDynamic::Create(mesh->GetMaterial(0), this);
	mesh->SetMaterial(0, _materialPtr);
}

// Called every frame
void ADiceTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float distance = FGenericPlatformMath::Sqrt(FGenericPlatformMath::Pow(_playerPtr->GetActorLocation().X - this->GetActorLocation().X, 2) + FGenericPlatformMath::Pow(_playerPtr->GetActorLocation().Y - this->GetActorLocation().Y, 2));

	if (distance < _distanceInteraction_touching)
	{
		if (_distanceType != touching)
		{
			_playerPtr->SetInteractable(this);
			_distanceType = touching;
			_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_touching);
			UE_LOG(LogTemp, Warning, TEXT("touching"));
		}
	}
	else if (distance < _distanceInteraction_near)
	{
		if (_distanceType != near)
		{
			if (_distanceType == touching && _playerPtr->GetInteractable() == this)
			{
				_playerPtr->SetInteractable(nullptr);
			}
			_distanceType = near;
			_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_near);
			UE_LOG(LogTemp, Warning, TEXT("near"));
		}
	}
	else
	{
		if (_distanceType != far)
		{
			_distanceType = far;
			_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_far);
			UE_LOG(LogTemp, Warning, TEXT("far"));
		}
	}
}
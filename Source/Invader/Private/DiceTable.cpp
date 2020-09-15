// Fill out your copyright notice in the Description page of Project Settings.

//#include "Kismet/KismetMathLibrary.h"
#include "Containers/Array.h"
#include "DiceTable.h"

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

	float tablePosition = this->GetActorLocation().X;
	float playerPosition = _playerPtr->GetActorLocation().X;

	float distance = _playerPtr->GetActorLocation().X - this->GetActorLocation().X;

	if (distance < _distanceInteraction_touching)
	{
		_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_touching);
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, FString::Printf(TEXT("close")));
	}
	else if (distance < _distanceInteraction_near)
	{
		_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_near);
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, FString::Printf(TEXT("near")));
	}
	else
	{
		_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_far);
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, FString::Printf(TEXT("away")));
	}
}
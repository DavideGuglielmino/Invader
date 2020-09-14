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

	//UStaticMeshComponent*
	//TArray<UStaticMeshComponent*> Components;
	//GetComponents<UStaticMeshComponent>(Components);

	//_materialPtr = this->FindComponentByClass<UStaticMeshComponent>()->GetMaterial(0);

	//_materialPtr = UMaterialInstanceDynamic::Create(sphere->GetMaterial(0), NULL);

	/* Create a dynamic material instance from our mesh's material 0 */
	//_materialPtr = UMaterialInstanceDynamic::Create(this->FindComponentByClass<UStaticMeshComponent>()->GetMaterial(0), this);
	TArray<UStaticMeshComponent*> Comps;

	GetComponents(Comps);
	if (Comps.Num() > 0)
	{
		UStaticMeshComponent* FoundComp = Comps[0];
		//do stuff with FoundComp
		_materialPtr = UMaterialInstanceDynamic::Create(FoundComp->GetMaterial(0), this);
	}
	
	rand();
}

// Called every frame
void ADiceTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float tablePosition = this->GetActorLocation().X;
	float playerPosition = _playerPtr->GetActorLocation().X;

	float distance = _playerPtr->GetActorLocation().X - this->GetActorLocation().X;

	if (distance < _distanceInteraction_close)
	{
		_materialPtr->SetVectorParameterValue("_InteractColor", _distanceColor_close);
		/* Set the mesh's material to the new one */
		//GetMesh()->SetMaterial(0, DynamicMaterial);
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, FString::Printf(TEXT("close")));
	}
	else if (distance < _distanceInteraction_near)
	{
		_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_near);
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, FString::Printf(TEXT("near")));
	}
	else if (distance < _distanceInteraction_far)
	{
		_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_far);
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, FString::Printf(TEXT("far")));
	}
	else
	{
		_materialPtr->SetVectorParameterValue("_DistanceColor", _distanceColor_away);
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, FString::Printf(TEXT("away")));
	}
}
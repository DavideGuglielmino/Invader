// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "InvaderCharacter.h" // needs to be included to make the compiler do the static_cast function
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();

	_playerPtr = static_cast<AInvaderCharacter*>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}
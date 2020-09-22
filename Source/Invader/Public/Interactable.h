// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvaderCharacter.h"
#include "Interactable.generated.h"

/// This class serve the purpose of giving to an object the InteractBehaviour and OnTouchingBehaviour functions
/// Since there are no other information given to the gameplay, this abstract class is used as a parent for any interactable object
/// Can be changed to not derive to AActor (Engine limitations) or to be an interface in the future if needed
UCLASS()
class INVADER_API AInteractable : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient)
	AInvaderCharacter* _playerPtr; // Assuming it's a single player game, we save the player ptr instead of asking to some manager for it every Tick update ( Can be changed )
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called via Blueprint so that every interactable object can have their personal type of response to the player
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interactable")
	void InteractBehaviour();

	// Called via Blueprint so that every interactable object can have give to the player their different prompts and informations
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interactable")
	void OnTouchingBehaviour(bool activate);
};
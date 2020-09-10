// Fill out your copyright notice in the Description page of Project Settings.


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
	
}

// Called every frame
void ADiceTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
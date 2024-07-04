// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemParentClass.h"

// Sets default values
AItemParentClass::AItemParentClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemParentClass::BeginPlay()
{
	Super::BeginPlay();
	
}
FName AItemParentClass::ReturnDesignatedSocket() {
	return ItemData.BackpackSocketName;
}
// Called every frame
void AItemParentClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


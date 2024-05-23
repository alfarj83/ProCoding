// Fill out your copyright notice in the Description page of Project Settings.

#include "MouseControlComponent.h"

// Sets default values for this component's properties
UMouseControlComponent::UMouseControlComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMouseControlComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}
FRotator UMouseControlComponent::ReturnMouseData()
{
	additive = additive + temp;
	additive.Y = FMath::Clamp(additive.Y, -90, 90);
	return {additive.Y, additive.X, 0};
	// ...
}
// Called every frame
void UMouseControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	APlayerController* Owner = Cast<APlayerController>(GetOwner());

	if (Owner) {
		Owner->GetInputMouseDelta(temp.X, temp.Y);	
	}	
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "PropCollisionInputComponent.h"

// Sets default values for this component's properties
UPropCollisionInputComponent::UPropCollisionInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}
void UPropCollisionInputComponent::SetCollisionReference(UPrimitiveComponent* Object){
	CollisionObject = Object;
	if (CollisionObject){
		CollisionObject->OnComponentBeginOverlap.AddDynamic(this, &UPropCollisionInputComponent::BeginOverlap);
		CollisionObject->OnComponentEndOverlap.AddDynamic(this, &UPropCollisionInputComponent::EndOverlap);
	}
}
bool UPropCollisionInputComponent::IsPlayerNear(){
	return IsNear;
}
void UPropCollisionInputComponent::BeginOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult){
	IsNear = true;
	CharacterNear = Cast<APlayerParentClass>(OtherActor);
}
void UPropCollisionInputComponent::EndOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex){
	IsNear = false;
	CharacterNear = nullptr;
}
// Called when the game starts
void UPropCollisionInputComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
}
// Called every frame
void UPropCollisionInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


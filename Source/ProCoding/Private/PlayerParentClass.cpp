// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerParentClass.h"
// Sets default values
APlayerParentClass::APlayerParentClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerParentClass::BeginPlay()
{
	Super::BeginPlay();
	//InventoryArray.Init(nullptr, 0); //Populate Inventory Array with a null pointer to avoid error when trying to reference array before anything added.
	HandMesh = Cast<USkeletalMeshComponent>(FindComponentByTag(USkeletalMeshComponent::StaticClass(), TEXT("HandTag")));
	BicepMesh = Cast<USkeletalMeshComponent>(FindComponentByTag(USkeletalMeshComponent::StaticClass(), TEXT("BicepTag")));
	SpringComponent = Cast<USpringArmComponent>(FindComponentByTag(USpringArmComponent::StaticClass(), TEXT("CameraSpring")));

}
void APlayerParentClass::SetCurrentItem(AItemParentClass* Item) {
	ItemInHand = Item;
	ItemInHand->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	ItemInHand->AttachToComponent(HandMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("HandSocket"));
}
void APlayerParentClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (HandMesh) {
		HandSocketLocation = HandMesh->GetSocketLocation("HandSocket");
		HandSocketRotation = HandMesh->GetSocketRotation("HandSocket");	//THIS IS A FIRST PERSON EXCLUSIVE THING, WONT WORK WITH THIRD PERSON
			
		if (ItemInHand) {
			//ItemInHand->SetActorLocationAndRotation(HandSocketLocation, HandSocketRotation, false, 0, ETeleportType::None);
		}
	}
	if (BicepMesh) {
		BicepSocketLocation = BicepMesh->GetSocketLocation("BicepSocket");
		BicepSocketRotation = BicepMesh->GetSocketRotation("BicepSocket");

		if (ItemInHand) {

			//ItemInHand->SetActorLocationAndRotation(BicepSocketLocation, BicepSocketRotation, false, 0, ETeleportType::None);

		}
	}
	*/
}
// Called to bind functionality to input
void APlayerParentClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/*
	if (Input) {
		Input->BindAction(MovementButtons, ETriggerEvent::Triggered, this, &APlayerParentClass::ReadInputValues);
	}
	*/
}
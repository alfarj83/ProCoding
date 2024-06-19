// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerParentClass.h"
// Sets default values
APlayerParentClass::APlayerParentClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//Not used for anything in particular, but could still be useful.
void APlayerParentClass::ReadInputValues(const FInputActionInstance& Instance) {
	ScaleValueVector = Instance.GetValue().Get<FVector2D>();
	IsPressed = true;
}

void APlayerParentClass::CycleThroughInvetory(){



}

void APlayerParentClass::AddItem(class AItemParentClass* Item) {
	isEmpty = false;
	InventoryArray[0] = Item;
}

TArray<AItemParentClass*> APlayerParentClass::ReturnInventory(){
	return InventoryArray;
}

void APlayerParentClass::BeginPlay()
{
	Super::BeginPlay();
	InventoryArray.Init(nullptr, 1); //Populate Inventory Array with a null pointer to avoid error when trying to reference array before anything added.
	HandMesh = Cast<USkeletalMeshComponent>(FindComponentByTag(USkeletalMeshComponent::StaticClass(), TEXT("HandTag")));
	SpringComponent = Cast<USpringArmComponent>(FindComponentByTag(USpringArmComponent::StaticClass(), TEXT("CameraSpring")));

}

void APlayerParentClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HandMesh) {
		HandSocketLocation = HandMesh->GetSocketLocation("HandSocket");
		HandSocketRotation = SpringComponent->GetComponentRotation();
			
		if (InventoryArray[CurrentItem]) {

			InventoryArray[CurrentItem]->SetActorLocationAndRotation(HandSocketLocation, HandSocketRotation, false, 0, ETeleportType::None);

		}
	}
	


}

// Called to bind functionality to input
void APlayerParentClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	/*
	if (Input) {
		Input->BindAction(MovementButtons, ETriggerEvent::Triggered, this, &APlayerParentClass::ReadInputValues);
	}
	*/
}
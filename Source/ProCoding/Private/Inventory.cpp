// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInventory::ToggleInventoryMenu() {

	if (AsUMG_Inventory) {

		if (InventoryShowing) {
			InventoryUIInstance->SetVisibility(ESlateVisibility::Hidden);
			InventoryShowing = false;
		}
		else {
			InventoryUIInstance->SetVisibility(ESlateVisibility::Visible);
			InventoryShowing = true;
		}

	}
}

void UInventory::ChangeInventoryItem(int32 Key) {
	if(Inventory.Num() > Key && Key >= 0) { //Each item has a specific key
		if (Player) {
			CurrentItemIndex = Key;
			APlayerParentClass* PlayerReference = Cast<APlayerParentClass>(Player);
			PlayerReference->SetCurrentItem(Inventory[Key]);
		}
	}
}

AItemParentClass* UInventory::ReturnCurrentItem() {
	return Inventory[CurrentItemIndex];
}

void UInventory::AddToInventory(AItemParentClass* ItemToAdd) {
	for (int32 i = 0; i != Inventory.Num(); i++) {
		if (Inventory[i] == nullptr) {
			Inventory.Insert(ItemToAdd, i);
			CurrentItemIndex = i;
			break;
		}
	}
	if (Player) {
		APlayerParentClass* PlayerReference = Cast<APlayerParentClass>(Player);
		PlayerReference->SetCurrentItem(Inventory[CurrentItemIndex]);
	}
}
// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();
	Inventory.Init(nullptr, 8);
	CurrentItemIndex = 0;

	if (GetOwner()) {
		Player = Cast<ACharacter>(GetOwner()); 

		if (Player->GetController()) { 

			APlayerController* Controller = Cast<APlayerController>(Player->GetController());
			if (AsUMG_Inventory) {

				if (!InventoryUIInstance) {

					InventoryUIInstance = CreateWidget<UUserWidget>(Controller, AsUMG_Inventory);
					InventoryUIInstance->AddToViewport();
					InventoryUIInstance->SetVisibility(ESlateVisibility::Hidden);

				}
			}
		}
	}
}

// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// ...
}


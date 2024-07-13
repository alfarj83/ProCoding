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

	if ((Inventory.Num() > Key && Key >= 0)) { //Failsafe is num too high or low for array.

		if (CurrentItemIndex != Key) { //Checks if we are hitting the same key as the one we have equipped.

			//Either it attaches to the backpack, or just gets disabled and is invisible (Only happens when backpack is not added).
			//Makes sure the item in our hand is a valid item.
			if (Inventory[CurrentItemIndex]) { 
				Inventory[CurrentItemIndex]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

				if (Backpack) {
					Inventory[CurrentItemIndex]->AttachToActor(Backpack, FAttachmentTransformRules::SnapToTargetNotIncludingScale, Inventory[CurrentItemIndex]->ReturnDesignatedSocket());
				}
				Inventory[CurrentItemIndex]->ItemIsActive = false;
			}
			//This part makes sure the item we are swapping to is a real item.
			//If we are swapping to an empty slot, no item, emptyhand becomes true.
			if (Inventory[Key]) {

				if (GEngine) {
					GEngine->AddOnScreenDebugMessage(-1, 120.0f, FColor::Yellow, FString::Printf(TEXT("Dog")));
				}
				Inventory[Key]->ItemIsActive = true;
				PlayerReference->SetCurrentItem(Inventory[Key]);
				EmptyHand = false;
				CurrentItemIndex = Key;
			}
			else {
				EmptyHand = true;
			}

			if (!EmptyHand) {
				GEngine->AddOnScreenDebugMessage(-1, 120.0f, FColor::Yellow, FString::Printf(TEXT("Cat")));
				PlayerReference->SetCurrentItem(Inventory[Key]);
			}
		}
		// Runs if our hand is empty, and our next item is valid.
		else if (EmptyHand && Inventory[Key]) { 
			GEngine->AddOnScreenDebugMessage(-1, 120.0f, FColor::Yellow, FString::Printf(TEXT("Frog")));
			PlayerReference->SetCurrentItem(Inventory[Key]);
			CurrentItemIndex = 0;
			EmptyHand = false;
		}
		//Hitting same key to un-equip item
		else if (!EmptyHand) {
			Inventory[Key]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			Inventory[Key]->AttachToActor(Backpack, FAttachmentTransformRules::SnapToTargetNotIncludingScale, Inventory[CurrentItemIndex]->ReturnDesignatedSocket());
			EmptyHand = true;
		}
		
	}
}

AItemParentClass* UInventory::ReturnCurrentItem() {
	return Inventory[CurrentItemIndex];
}

void UInventory::AddToInventory(AItemParentClass* ItemToAdd) {
	for (int32 i = 0; i != Inventory.Num(); i++) {	//Finds the next empty spot in inventory, and places it there.
		if (Inventory[i] == nullptr) {
			Inventory[i] = ItemToAdd;
			Inventory[i]->AttachToActor(Backpack, FAttachmentTransformRules::SnapToTargetNotIncludingScale, ItemToAdd->ReturnDesignatedSocket());
			break;
		} 
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
		PlayerReference = Cast<APlayerParentClass>(Player);

		if (PlayerReference && Player) {

			APlayerController* Controller = Cast<APlayerController>(GetOwner());

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

	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Yellow, FString::Printf(TEXT("%p"), PlayerReference->ItemInHand));
	// ...
}


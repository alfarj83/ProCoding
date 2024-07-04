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
	if((Inventory.Num() > Key && Key >= 0) && CurrentItemIndex != Key && Inventory[Key]) { //Can be tied to numbers, operated based on array placement [0], [1], etcetera
		if (Player) {
			//Either it attaches to the backpack, or just gets disabled and is invisible (Only happens when backpack is not added).
			Inventory[CurrentItemIndex]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			if (Backpack){
				Inventory[CurrentItemIndex]->AttachToActor(Backpack, FAttachmentTransformRules::SnapToTargetNotIncludingScale, Inventory[CurrentItemIndex]->ReturnDesignatedSocket());
			}
			else {
				Inventory[CurrentItemIndex]->SetActorTickEnabled(false);	//Disables previous item;
				Inventory[CurrentItemIndex]->SetActorHiddenInGame(true);

				Inventory[Key]->SetActorTickEnabled(true);	//Re-Enables new item;
				Inventory[Key]->SetActorHiddenInGame(false);
			}
			Inventory[CurrentItemIndex]->ItemIsActive = false;
			CurrentItemIndex = Key;
			Inventory[Key]->ItemIsActive = true;
			PlayerReference->SetCurrentItem(Inventory[Key]);
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
			ItemToAdd->AttachToActor(Backpack, FAttachmentTransformRules::SnapToTargetNotIncludingScale, ItemToAdd->ReturnDesignatedSocket());
			//CurrentItemIndex = i; //causes desync between what is in hand vs when something is added
			break;
		}
	}
	if (isEmpty) {
		PlayerReference->SetCurrentItem(Inventory[CurrentItemIndex]);
		isEmpty = false;
	}
	float num = static_cast<float>(Inventory.Num());
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Yellow, FString::Printf(TEXT("%f"), num));
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

	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Yellow, FString::Printf(TEXT("%p"), PlayerReference->ItemInHand));
	// ...
}


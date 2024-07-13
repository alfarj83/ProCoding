// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentPlayerStateClass.h"

void AParentPlayerStateClass::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Add properties to replicate
	DOREPLIFETIME(AParentPlayerStateClass, IsInInventory);
	DOREPLIFETIME(AParentPlayerStateClass, IsInFirstPerson);
}

AParentPlayerStateClass::AParentPlayerStateClass() {

}
void AParentPlayerStateClass::SetInventoryState(bool State) {

	if (IsInInventory != State) {
		IsInInventory = State;
		OnRep_InventoryState();
	}

}
void AParentPlayerStateClass::SetPerspective(bool State) {

	if (IsInFirstPerson != State) {
		IsInFirstPerson = State;
		OnRep_PerspectiveState();
	}
}
bool AParentPlayerStateClass::GetInventoryState() {
	return IsInInventory;
}
bool AParentPlayerStateClass::GetPerspective() {
	return IsInFirstPerson;
}
void AParentPlayerStateClass::OnRep_InventoryState() {
	OnInventoryStateChange.Broadcast(IsInInventory);
}
void AParentPlayerStateClass::OnRep_PerspectiveState() {
	OnPerspectiveStateChange.Broadcast(IsInFirstPerson);
}
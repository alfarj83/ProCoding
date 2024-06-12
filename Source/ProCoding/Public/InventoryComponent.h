// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemParentClass.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCODING_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly)
	TArray<AItemParentClass*> InventoryArray;
	
	int CurrentItem = 0;
	bool isEmpty = true;
	void CycleThroughInvetory();

	UFUNCTION(BlueprintCallable)
	void AddItem(class AItemParentClass* Item);
	UFUNCTION(BlueprintCallable)
	TArray<AItemParentClass*> ReturnInventory();
};

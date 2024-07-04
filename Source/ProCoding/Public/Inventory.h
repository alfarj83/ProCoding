// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemParentClass.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "PlayerParentClass.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h" 
#include "Inventory.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCODING_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool InventoryShowing = false;
	bool isEmpty = true;
	UUserWidget* InventoryUIInstance;
	int32 CurrentItemIndex;
	APlayerParentClass* PlayerReference;
	ACharacter* Player;

public:	
	// Called every frame

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	TArray<AItemParentClass*> Inventory;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> AsUMG_Inventory;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Backpack;

	UFUNCTION(BlueprintCallable)
	void ToggleInventoryMenu();	

	UFUNCTION(BlueprintCallable)
	void AddToInventory(AItemParentClass* ItemToAdd);

	UFUNCTION(BlueprintCallable)
	void ChangeInventoryItem(int32 Key);
	
	UFUNCTION(BlueprintCallable)
	AItemParentClass* ReturnCurrentItem();

	/*
	UPROPERTY(EditAnywhere, Category = "Inventory Variables")
	int MaxSize;
	UPROPERTY(EditAnywhere, Category = "Inventory Variables")
	bool AllowDuplicates;
	*/

};

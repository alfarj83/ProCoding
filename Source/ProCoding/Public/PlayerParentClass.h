// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ItemParentClass.h"
#include "EnhancedInputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerParentClass.generated.h"

UCLASS()
class PROCODING_API APlayerParentClass : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerParentClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ReadInputValues(const FInputActionInstance& Instance);
	void CycleThroughInvetory();

	bool IsPressed = false;
	int CurrentItem = 0;
	bool isEmpty = true;

	USkeletalMeshComponent* HandMesh;
	USpringArmComponent* SpringComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//The Array that represents references to each item
	UPROPERTY(BlueprintReadOnly)
	TArray<AItemParentClass*> InventoryArray;
	
	UPROPERTY(BlueprintReadOnly)
	FVector HandSocketLocation;

	UPROPERTY(BlueprintReadOnly)
	FRotator HandSocketRotation;

	//Function that allows you to add an item to the array
	UFUNCTION(BlueprintCallable)
	void AddItem(class AItemParentClass* Item);

	UFUNCTION(BlueprintCallable)
	TArray<AItemParentClass*> ReturnInventory();
	
	FVector2D ScaleValueVector{ 0.0f, 0.0f };

	//Can be possibly be referenced by components that require player input
	UEnhancedInputComponent* Input;
};

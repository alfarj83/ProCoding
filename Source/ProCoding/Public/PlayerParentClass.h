// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ItemParentClass.h"
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

	USkeletalMeshComponent* HandMesh;
	USkeletalMeshComponent* BicepMesh;
	USpringArmComponent* SpringComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetCurrentItem(AItemParentClass* Item);

	//The Array that represents references to each item
	UPROPERTY(BlueprintReadOnly)
	AItemParentClass* ItemInHand;
	
	UPROPERTY(BlueprintReadOnly)
	FVector HandSocketLocation;

	UPROPERTY(BlueprintReadOnly)
	FRotator HandSocketRotation;

	UPROPERTY(BlueprintReadOnly)
	FVector BicepSocketLocation;

	UPROPERTY(BlueprintReadOnly)
	FRotator BicepSocketRotation;

	//Function that allows you to add an item to the array
};

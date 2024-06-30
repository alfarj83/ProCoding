// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefaultItemDataStruct.h"
#include "ItemParentClass.generated.h"

UCLASS()
class PROCODING_API AItemParentClass : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AItemParentClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDEfaultsOnly, BlueprintReadWrite, Category = "Item Variables")
	FDefaultItemDataStruct ItemData;

};

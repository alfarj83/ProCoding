// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DefaultItemDataStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROCODING_API FItemDataStruct
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName Name;
	UPROPERTY(EditAnywhere)
	FName BackpackSocketName;

	FItemDataStruct();
	~FItemDataStruct();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DefaultItemDataStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROCODING_API FDefaultItemDataStruct
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FName Name;

	FDefaultItemDataStruct();
	~FDefaultItemDataStruct();
};

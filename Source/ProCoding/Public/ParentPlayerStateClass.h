// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "ParentPlayerStateClass.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryStateChangeSignature, bool, IsInInventory);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerspectiveStateChangeSignature, bool, IsInFirstPerson);

UCLASS()
class PROCODING_API AParentPlayerStateClass : public APlayerState
{
	GENERATED_BODY()	
	
public:

	AParentPlayerStateClass();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_InventoryState, Category = "Player State")
	bool IsInInventory = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_PerspectiveState, Category = "Player State")
	bool IsInFirstPerson = false;

	UPROPERTY(BlueprintAssignable)
	FOnInventoryStateChangeSignature OnInventoryStateChange;

	UPROPERTY(BlueprintAssignable)
	FOnPerspectiveStateChangeSignature OnPerspectiveStateChange;

	UFUNCTION(BlueprintCallable)
	void SetPerspective(bool State);

	UFUNCTION(BlueprintCallable)
	void SetInventoryState(bool State);

	UFUNCTION(BlueprintCallable)
	bool GetPerspective();

	UFUNCTION(BlueprintCallable)
	bool GetInventoryState(); 


protected:

	UFUNCTION()
	void OnRep_InventoryState();

	UFUNCTION()
	void OnRep_PerspectiveState();
};

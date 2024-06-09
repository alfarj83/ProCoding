// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ItemParentClass.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
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

	FVector2D MovementVector{0.0f, 0.0f};
	void ReadInputValues(const FInputActionInstance& Instance);
	bool IsPressed = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* MovementButtons;
	
	UPROPERTY(BlueprintReadOnly)
	float ScaleFactor = 0.11f;

	UFUNCTION(BlueprintCallable)
	FVector2D ReturnScaleFactor();

	UPROPERTY(EditAnywhere)
	float ScaleAdditive = 0.11f;

	UPROPERTY(BlueprintReadOnly)
	FVector2D ScaleFactorVector{0.0f, 0.0f};

	//Can be possibly be referenced by components that require player input
	UEnhancedInputComponent* Input;


};

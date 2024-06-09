// Fill out your copyright notice in the Description page of Project Settings.

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/PlayerController.h"
#include "PlayerParentClass.h"

// Sets default values
APlayerParentClass::APlayerParentClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerParentClass::BeginPlay()
{
	Super::BeginPlay();

	//UNECCESSARY CODE FROM COMPONENT
		//Finds the controller reference using the Character Reference, which already contains a pointer/reference to the controller, named just Controller.
	//APlayerController* ControllerRef = Cast<APlayerController>(CharacterRef->Controller); 
	/*	THIS CODE IS ALREADY ACCOMPLISHED IN THE CONTROLLER BLUEPRINT, SO UNNECESSARY.
	if (ControllerRef){
		//Accesses the ULocalPlayer Subsystem, sets it equal to the variable Subsystem, and sees if its NOT NULL, so its a null check.
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(ControllerRef->GetLocalPlayer())) {
			Subsystem->AddMappingContext(InputMapping, 0);	//this actually accomplishes what the Controller Blueprint already does.
		}
	}
	*/
}

void APlayerParentClass::ReadInputValues(const FInputActionInstance& Instance) {
	MovementVector = Instance.GetValue().Get<FVector2D>();
	IsPressed = true;
}
FVector2D APlayerParentClass::ReturnScaleFactor(){
	float Siner = sin(FMath::Min(ScaleFactor, 3.14/2));

	return {MovementVector.X * Siner, MovementVector.Y * Siner};
}
// Called every frame
void APlayerParentClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ScaleFactor = IsPressed ? FMath::Lerp(ScaleFactor, 3.14/2, ScaleAdditive): FMath::Lerp(ScaleFactor, 0.0f, ScaleAdditive);

	float Siner = sin(FMath::Min(ScaleFactor, 3.14/2));

	ScaleFactorVector = {MovementVector.X * Siner, MovementVector.Y * Siner};

	IsPressed = false;	
}

// Called to bind functionality to input
void APlayerParentClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	if (Input) {
		Input->BindAction(MovementButtons, ETriggerEvent::Triggered, this, &APlayerParentClass::ReadInputValues);
	}
}
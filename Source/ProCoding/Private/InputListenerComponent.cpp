// Fill out your copyright notice in the Description page of Project Settings.


#include "InputListenerComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"



// Sets default values for this component's properties
UInputListenerComponent::UInputListenerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
// Called when the game starts
void UInputListenerComponent::BeginPlay()
{
	Super::BeginPlay();

	//Finds the character we need
	CharacterRef = Cast<ACharacter>(GetOwner());

	APlayerController* ControllerRef = Cast<APlayerController>(CharacterRef->Controller); 

	if (ControllerRef){
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(ControllerRef->GetLocalPlayer())) {
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}
void UInputListenerComponent::Dog(){
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, "What the dog doing doe");
}
// Called every frame
void UInputListenerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Fetches the overall input component of the player, which contains the EnhancedInputData
	UInputComponent* PlayerInputComponent = CharacterRef->InputComponent;	
	
	//IMPORTANT::
	//The single = sign not only compares, but creates a variable that stores the UEnhancedInputComponent of Input.
	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//this passes the reference of the InputListener Component, which is required to find the function of Dog for the specific instance that contains it
		Input->BindAction(MoveButtonAction, ETriggerEvent::Triggered, this, &UInputListenerComponent::Dog);
	}

}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PlayerParentClass.h"
#include "PropCollisionInputComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCODING_API UPropCollisionInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPropCollisionInputComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void BeginOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void EndOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void SetCollisionReference(UPrimitiveComponent* Object);

	UFUNCTION(BlueprintCallable)
	bool IsPlayerNear();

	UFUNCTION(BlueprintCallable)
	class APlayerParentClass* ReturnCharacterReference();

	UPROPERTY(BlueprintReadOnly)
	bool IsNear = false;

	UPrimitiveComponent* CollisionObject;

	UPROPERTY(BlueprintReadOnly)
	class APlayerParentClass* CharacterNear;

};	

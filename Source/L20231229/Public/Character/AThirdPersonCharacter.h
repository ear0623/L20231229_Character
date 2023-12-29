// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AThirdPersonCharacter.generated.h"

class UInputAction;
class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class L20231229_API AAThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAThirdPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
private:
	//Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* IA_Move;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,  Category="Input",  meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Jump;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Fire;
	//Component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;

	//Action
	

public:
	//Input
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Fire(const FInputActionValue& Value);


};

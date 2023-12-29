// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AThirdPersonController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class L20231229_API AAThirdPersonController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAThirdPersonController();

	virtual void BeginPlay() override;

private:
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Data",meta=(AllowPrivateAccess ="true"))
	TObjectPtr<UInputMappingContext> ThirdPerson_IMC;
	
};

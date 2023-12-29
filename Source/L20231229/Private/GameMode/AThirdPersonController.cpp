// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/AThirdPersonController.h"
#include "EnhancedInputSubsystems.h"

AAThirdPersonController::AAThirdPersonController()
{
}

void AAThirdPersonController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	SubSystem->AddMappingContext(ThirdPerson_IMC, 0);
}

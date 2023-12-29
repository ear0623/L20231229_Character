// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/UThirdPersonAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework//CharacterMovementComponent.h"

void UUThirdPersonAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* PlayerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(PlayerCharacter))
	{
		Speed = PlayerCharacter->GetCharacterMovement()->Velocity.Size2D();
	}
}

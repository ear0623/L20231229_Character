// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/UThirdPersonAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/AThirdPersonCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void UUThirdPersonAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* PlayerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(PlayerCharacter))
	{
		Speed = PlayerCharacter->GetCharacterMovement()->Velocity.Size2D();
		//UKismetMathLibrary::NotEqual_VectorVector(PlayerCharacter->GetCharacterMovement()->GetCurrentAcceleration(), FVector::ZeroVector,0);
		bShouldMove =(Speed>3.0f) && PlayerCharacter->GetCharacterMovement()->GetCurrentAcceleration() != FVector::ZeroVector;
		bIsFalling = PlayerCharacter->GetCharacterMovement()->IsFalling();
		Velocity = PlayerCharacter->GetCharacterMovement()->Velocity;
	}
	AAThirdPersonCharacter* MyCharacter = Cast<AAThirdPersonCharacter>(PlayerCharacter);
	if (IsValid(PlayerCharacter) && IsValid(MyCharacter))
	{
			
		bJumping = MyCharacter->GetCharacterMovement()->IsFalling();
		//UE_LOG(LogTemp, Warnning,FString::Printf(TEXT("bJump = %s"), bJumping));
		
	}
	
}

void UUThirdPersonAnimInstance::Debug()
{
}

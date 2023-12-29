// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AThirdPersonCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AAThirdPersonCharacter::AAThirdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("ArmCompo"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraCompo"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f ,-GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

}

// Called when the game starts or when spawned
void AAThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* InputCompo = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (InputCompo)
	{
		InputCompo->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AAThirdPersonCharacter::Move);
		InputCompo->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AAThirdPersonCharacter::Look);
		InputCompo->BindAction(IA_Jump, ETriggerEvent::Started, this, &AAThirdPersonCharacter::Jump);
		InputCompo->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AAThirdPersonCharacter::StopJumping);
	}


}

void AAThirdPersonCharacter::Move(const FInputActionValue & Value) 
{
	FVector2D Dir = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator Yaw = FRotator(0.0f, Rotation.Yaw, 0.0f);

		FVector ForwardVector = UKismetMathLibrary::GetForwardVector(Yaw);
		FVector RightVector = UKismetMathLibrary::GetRightVector(Yaw);

		AddMovementInput(ForwardVector, Dir.Y);
		AddMovementInput(RightVector, Dir.X);
	}

}

void AAThirdPersonCharacter::Look(const FInputActionValue & Value) 
{
	FVector2D Dir = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		AddControllerYawInput(Dir.X);
		AddControllerPitchInput(Dir.Y);
	}
}


void AAThirdPersonCharacter::Fire(const FInputActionValue& Value)
{

}


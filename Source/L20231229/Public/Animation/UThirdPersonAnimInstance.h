// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UThirdPersonAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class L20231229_API UUThirdPersonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	virtual void NativeUpdateAnimation(float DeltaSeconds)override;

private:

	UPROPERTY(BlueprintReadOnly,Editanywhere,Category="Stat",meta=(AllowPrivateAccess ="true"))
	float Speed;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacter.h"
#include "MainCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class PERSPECTIVE_API AMainCharacterController : public APlayerController
{
	GENERATED_BODY()

private:
	AMainCharacter* GetMainCharacter();
	void HandleJumpPressed();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
	void SetupInputComponent() override;

};

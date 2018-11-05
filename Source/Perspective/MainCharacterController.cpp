// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacterController.h"
#include "Components/InputComponent.h"

AMainCharacter* AMainCharacterController::GetMainCharacter()
{
	return Cast<AMainCharacter>(GetPawn());
}

void AMainCharacterController::HandleJumpPressed() 
{
	GetMainCharacter()->Jump();
}

void AMainCharacterController::BeginPlay()
{
	Super::BeginPlay();
}

void AMainCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!InputComponent)
		return;
	float h = InputComponent->GetAxisValue("Horizontal");
	FVector direction(0, h, 0);
	GetMainCharacter()->AddMovementInput(direction);
}

// Called to bind functionality to input
void AMainCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("Horizontal");
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMainCharacterController::HandleJumpPressed);

}

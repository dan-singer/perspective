// Fill out your copyright notice in the Description page of Project Settings.

#include "FPPlayerController.h"

AMainCharacter* AFPPlayerController::GetMainCharacter()
{
	return Cast<AMainCharacter>(GetPawn());
}

void AFPPlayerController::HandleJumpPressed()
{
	GetMainCharacter()->Jump();
}

void AFPPlayerController::HandleAzimuth(float val)
{
	AddYawInput(val);
}

void AFPPlayerController::HandleAltitude(float val)
{
	AddPitchInput(val);
}

void AFPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//TODO: Move this to whenever it gets possessed
	auto* arm = GetMainCharacter()->GetSpringArm();
	arm->TargetArmLength = 0;
}

void AFPPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!InputComponent)
		return;
	float azimuth = InputComponent->GetAxisValue("Azimuth");
	float altitude = InputComponent->GetAxisValue("Altitude");
}

// Called to bind functionality to input
void AFPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("Azimuth", this, &AFPPlayerController::HandleAzimuth);
	InputComponent->BindAxis("Altitude", this, &AFPPlayerController::HandleAltitude);
}




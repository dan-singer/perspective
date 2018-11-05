// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "Components/InputComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMainCharacter::HandleJump()
{
	Jump();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!InputComponent)
		return;
	float h = InputComponent->GetAxisValue("Horizontal");
	FVector direction(h, 0, 0);
	AddMovementInput(direction);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal");
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMainCharacter::HandleJump);

}


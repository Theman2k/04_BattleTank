// Copyright Shalom Aloni

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Reporting: %s"), *GetControlledTank()->GetName())
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //Get the controlled pawn which is of a "Tank" type
}

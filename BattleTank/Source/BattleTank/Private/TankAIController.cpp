// Copyright Shalom Aloni

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //Get the controlled pawn which is of a "Tank" type
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); //Get the PLAYER controlled pawn which is of a "Tank" type
}



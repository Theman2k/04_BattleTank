// Copyright Shalom Aloni

#include "TankPlayerController.h"
#include "Engine/World.h"

ATankPlayerController::ATankPlayerController()
{
	CrosshairXLocation = 0.5f;
	CrosshairYLocation = 0.333333f;
	TraceReach = 100000.f;
	HitLocation = FVector(0.f, 0.f, 0.f);
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //Get the controlled pawn which is of a "Tank" type
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetRayTraceHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}

	return;
}

bool ATankPlayerController::GetRayTraceHitLocation(FVector &HitLocation) const
{
	//Get viewport size
	int32 SizeX, SizeY;
	GetViewportSize(SizeX, SizeY);
	//Calculate crosshair position
	FVector2D CrosshairPosition = FVector2D(SizeX*CrosshairXLocation, SizeY*CrosshairYLocation);
	//Deproject it to 3D space
	FVector WorldLocation,WorldDirection; //Ignore the WorldLocation, because the origin is the deproject and not the camera
	DeprojectScreenPositionToWorld(CrosshairPosition.X, CrosshairPosition.Y, WorldLocation, WorldDirection);
	//Line trace it and get location if visible
	FHitResult ActorThatGotHit;
	WorldLocation = PlayerCameraManager->GetCameraLocation(); //Now we assign the correct origin before the trace is done
	//If the trace is good then save the end location
	if (
			GetWorld()->LineTraceSingleByChannel(
			ActorThatGotHit,
			WorldLocation,
			WorldLocation + (WorldDirection*TraceReach),
			ECollisionChannel(ECollisionChannel::ECC_Visibility)
												)
		)
	{
		HitLocation = ActorThatGotHit.Location;
		return true;
	}
	return false;
}

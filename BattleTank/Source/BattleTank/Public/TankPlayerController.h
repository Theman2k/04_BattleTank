// Copyright Shalom Aloni

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	ATankPlayerController();
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetRayTraceHitLocation(FVector &HitLocation) const;
	FVector HitLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Tank UI")
		float CrosshairXLocation;
	UPROPERTY(EditDefaultsOnly, Category = "Tank UI")
		float CrosshairYLocation;
	UPROPERTY(EditDefaultsOnly, Category = "Tank UI")
		float TraceReach;
};

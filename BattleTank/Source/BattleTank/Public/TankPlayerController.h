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
	//UPROPERTY(VisiableAnywhere, Category="Setup Player Controller")
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
};

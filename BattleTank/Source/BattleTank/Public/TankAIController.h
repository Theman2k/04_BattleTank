// Copyright Shalom Aloni

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

private:
	virtual void Tick(float DeltaSeconds) override;
	ATank * GetAITank() const;
	ATank* GetPlayerTank() const;
	TWeakObjectPtr<ATank> PlayerControlledTank;
};

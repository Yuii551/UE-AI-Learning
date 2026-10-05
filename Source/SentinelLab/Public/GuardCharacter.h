// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GuardCharacter.generated.h"

UCLASS()
class SENTINELLAB_API AGuardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGuardCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure, Category = "Patrol")
	UPatrolComponent* GetPatrolComponent() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Patrol")
	TObjectPtr<UPatrolComponent> PatrolComponent;
};

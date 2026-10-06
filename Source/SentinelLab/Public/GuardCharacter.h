// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GuardCharacter.generated.h"

class UPatrolComponent;

UCLASS()
class SENTINELLAB_API AGuardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGuardCharacter();

	UFUNCTION(BlueprintPure, Category = "Patrol")
	UPatrolComponent* GetPatrolComponent() const;

private:
	UPROPERTY(VisibleAnywhere, Category = "Patrol")
	TObjectPtr<UPatrolComponent> PatrolComponent;
};

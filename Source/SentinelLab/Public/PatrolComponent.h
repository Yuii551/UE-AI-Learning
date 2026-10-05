// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolComponent.generated.h"

class APatrolRoute;
class ATargetPoint;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SENTINELLAB_API UPatrolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPatrolComponent();

	UFUNCTION(BlueprintPure, Category = "Patrol")
	ATargetPoint* GetCurrentPatrolPoint() const;

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	ATargetPoint* AdvancePatrolPoint();

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Patrol", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<APatrolRoute> PatrolRoute;

	UPROPERTY(Transient)
	int32 CurrentPatrolIndex = 0;
};

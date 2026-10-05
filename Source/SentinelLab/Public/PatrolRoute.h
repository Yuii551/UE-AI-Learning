// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolRoute.generated.h"

class ATargetPoint;

UCLASS()
class SENTINELLAB_API APatrolRoute : public AActor
{
	GENERATED_BODY()
	
public:	
	APatrolRoute();

	UFUNCTION(BlueprintPure, Category = "Patrol")
	int32 GetNumPatrolPoints() const;

	UFUNCTION(BlueprintPure, Category = "Patrol")
	ATargetPoint* GetPatrolPoint(int32 Index) const;

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Patrol", meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<ATargetPoint>> PatrolPoints;
	
};

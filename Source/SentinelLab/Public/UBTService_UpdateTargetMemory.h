// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "UBTService_UpdateTargetMemory.generated.h"

/**
 * 
 */
UCLASS()
class SENTINELLAB_API UUBTService_UpdateTargetMemory : public UBTService
{
	GENERATED_BODY()

public:
	UUBTService_UpdateTargetMemory();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

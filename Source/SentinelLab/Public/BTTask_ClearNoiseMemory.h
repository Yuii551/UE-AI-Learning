// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ClearNoiseMemory.generated.h"

/**
 * 
 */
UCLASS()
class SENTINELLAB_API UBTTask_ClearNoiseMemory : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_ClearNoiseMemory();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

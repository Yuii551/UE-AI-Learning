// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "UBTTask_AdvancePatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class SENTINELLAB_API UUBTTask_AdvancePatrolPoint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UUBTTask_AdvancePatrolPoint();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

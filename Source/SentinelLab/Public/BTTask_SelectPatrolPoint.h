// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_SelectPatrolPoint.generated.h"

/**
 * 
 */

UCLASS()
class SENTINELLAB_API UBTTask_SelectPatrolPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTask_SelectPatrolPoint();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

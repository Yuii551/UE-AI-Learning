// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ClearTargetMemory.generated.h"

/**
 * 
 */
UCLASS()
class SENTINELLAB_API UBTTask_ClearTargetMemory : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_ClearTargetMemory();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

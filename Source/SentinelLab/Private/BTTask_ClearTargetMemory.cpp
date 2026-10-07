// Copyright 2026 Yuii551. All Rights Reserved.


#include "BTTask_ClearTargetMemory.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearTargetMemory::UBTTask_ClearTargetMemory()
{
	NodeName = TEXT("Clear Target Memory");
}

EBTNodeResult::Type UBTTask_ClearTargetMemory::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	if (!IsValid(BlackboardComp))
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->ClearValue(TEXT("TargetActor"));
	BlackboardComp->ClearValue(TEXT("LastKnownTargetLocation"));
	BlackboardComp->SetValueAsBool(
		TEXT("HasLastKnownTargetLocation"),
		false
	);
	return EBTNodeResult::Succeeded;
}

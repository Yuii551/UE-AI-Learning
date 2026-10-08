// Copyright 2026 Yuii551. All Rights Reserved.


#include "BTTask_ClearNoiseMemory.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearNoiseMemory::UBTTask_ClearNoiseMemory()
{
	NodeName = TEXT("Clear Noise Memory");
}

EBTNodeResult::Type UBTTask_ClearNoiseMemory::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	
	if (!IsValid(BlackboardComp))
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->ClearValue(TEXT("InvestigationLocation"));
	BlackboardComp->SetValueAsBool(
		TEXT("HasInvestigationLocation"),
		false
	);

	return EBTNodeResult::Succeeded;
}

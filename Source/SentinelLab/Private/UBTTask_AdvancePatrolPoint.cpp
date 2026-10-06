// Copyright 2026 Yuii551. All Rights Reserved.


#include "UBTTask_AdvancePatrolPoint.h"

#include "AIController.h"
#include "GuardCharacter.h"
#include "PatrolComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/TargetPoint.h"

UUBTTask_AdvancePatrolPoint::UUBTTask_AdvancePatrolPoint()
{
	NodeName = "Advance Patrol Point";
	
}

EBTNodeResult::Type UUBTTask_AdvancePatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (!IsValid(AIController))
	{
		return EBTNodeResult::Failed;
	}

	AGuardCharacter* Guard =
		Cast<AGuardCharacter>(AIController->GetPawn());

	if (!IsValid(Guard))
	{
		return EBTNodeResult::Failed;
	}
	
	UPatrolComponent* PatrolComponent =
		Guard->GetPatrolComponent();

	if (!IsValid(PatrolComponent))
	{
		return EBTNodeResult::Failed;
	}

	PatrolComponent->AdvancePatrolPoint();
	return EBTNodeResult::Succeeded;
}

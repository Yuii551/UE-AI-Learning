// Copyright 2026 Yuii551. All Rights Reserved.


#include "BTTask_SelectPatrolPoint.h"

#include "AIController.h"
#include "GuardCharacter.h"
#include "PatrolComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/TargetPoint.h"

UBTTask_SelectPatrolPoint::UBTTask_SelectPatrolPoint()
{
	NodeName = TEXT("Select Patrol Point");

	BlackboardKey.AddObjectFilter(
		this,
		GET_MEMBER_NAME_CHECKED(UBTTask_SelectPatrolPoint, BlackboardKey),
		AActor::StaticClass()
	);
}

EBTNodeResult::Type UBTTask_SelectPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	
	if (!IsValid(Blackboard))
	{
		return EBTNodeResult::Failed;
	}

	Blackboard->ClearValue(GetSelectedBlackboardKey());

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
	
	UPatrolComponent* GuardPatrolComponent =
		Guard->GetPatrolComponent();
	
	if (!IsValid(GuardPatrolComponent))
	{
		return EBTNodeResult::Failed;
	}
	
	ATargetPoint* TargetPoint = 
		GuardPatrolComponent->FindValidPatrolPoint();
	
	if (!IsValid(TargetPoint))
	{
		return EBTNodeResult::Failed;
	}
	
	Blackboard->SetValueAsObject(GetSelectedBlackboardKey(), TargetPoint);
	return EBTNodeResult::Succeeded;
}


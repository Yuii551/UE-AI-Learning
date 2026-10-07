// Copyright 2026 Yuii551. All Rights Reserved.


#include "UBTService_UpdateTargetMemory.h"

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Actor.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"

UUBTService_UpdateTargetMemory::UUBTService_UpdateTargetMemory()
{
	NodeName = TEXT("Update Target Memory");

	bNotifyTick = true;
	Interval = 0.2f;
	RandomDeviation = 0.02f;
}

void UUBTService_UpdateTargetMemory::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	AAIController* AIController = OwnerComp.GetAIOwner();
	UBlackboardComponent* BlackboardComp =
		OwnerComp.GetBlackboardComponent();

	if (!IsValid(AIController) || !IsValid(BlackboardComp))
	{
		return;
	}

	AActor* TargetActor = Cast<AActor>(
		BlackboardComp->GetValueAsObject(TEXT("TargetActor"))
	);
	
	if (!IsValid(TargetActor))
	{
		return;
	}

	UAIPerceptionComponent* PerceptionComp =
		AIController->GetPerceptionComponent();

	if (!IsValid(PerceptionComp))
	{
		return;
	}

	FActorPerceptionBlueprintInfo PerceptionInfo;

	if (!PerceptionComp->GetActorsPerception(TargetActor, PerceptionInfo))
	{
		return;
	}

	for (const FAIStimulus& Stimulus: PerceptionInfo.LastSensedStimuli)
	{
		const bool bIsSight =
			Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>();

		if (bIsSight && Stimulus.WasSuccessfullySensed())
		{
			BlackboardComp->SetValueAsVector(
				TEXT("LastKnownTargetLocation"),
				TargetActor->GetActorLocation()
			);

			BlackboardComp->SetValueAsBool(
				TEXT("HasLastKnownTargetLocation"),
				true
			);

			return;
		}
	}
}

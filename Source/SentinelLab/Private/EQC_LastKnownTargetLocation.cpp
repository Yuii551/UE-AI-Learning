// Copyright 2026 Yuii551. All Rights Reserved.


#include "EQC_LastKnownTargetLocation.h"

#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Point.h"

void UEQC_LastKnownTargetLocation::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	APawn* QueryPawn =
		Cast<APawn>(QueryInstance.Owner.Get());

	if (!IsValid(QueryPawn))
	{
		return;
	}

	AAIController* AIController =
		Cast<AAIController>(QueryPawn->GetController());

	if (!IsValid(AIController))
	{
		return;
	}

	UBlackboardComponent* BlackboardComp =
		AIController->GetBlackboardComponent();

	if (!IsValid(BlackboardComp))
	{
		return;
	}

	if (!BlackboardComp->GetValueAsBool(TEXT("HasLastKnownTargetLocation")))
	{
		return;
	}

	const FVector SearchCentre =
		BlackboardComp->GetValueAsVector(TEXT("LastKnownTargetLocation"));

	UEnvQueryItemType_Point::SetContextHelper(
		ContextData, SearchCentre
	);
}

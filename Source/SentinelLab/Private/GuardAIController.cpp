// Copyright 2026 Yuii551. All Rights Reserved.


#include "GuardAIController.h"

#include "GuardCharacter.h"
#include "BehaviorTree/BehaviorTree.h"

void AGuardAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AGuardCharacter* Guard =
		Cast<AGuardCharacter>(InPawn);
	
	if (!IsValid(Guard))
	{
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("%s cannot control Pawn %s because it is not an AGuardCharacter."),
			*GetName(),
			*GetNameSafe(InPawn)
		);

		return;
	}

	if (!IsValid(BehaviorTreeAsset))
	{
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("%s has no Behavior Tree assigned."),
			*GetName()
		);
		
		return;
	}
	
	if (!RunBehaviorTree(BehaviorTreeAsset))
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT("%s failed to start Behavior Tree %s."),
			*GetName(),
			*GetNameSafe(BehaviorTreeAsset)
		);
	}
}

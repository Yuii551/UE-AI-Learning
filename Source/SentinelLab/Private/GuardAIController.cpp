// Copyright 2026 Yuii551. All Rights Reserved.


#include "GuardAIController.h"

#include "GuardCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Pawn.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"

AGuardAIController::AGuardAIController()
{
	GuardPerception =
		CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("GuardPerception"));

	SetPerceptionComponent(*GuardPerception);

	SightConfig =
		CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	SightConfig->SightRadius = 1500.0f;
	SightConfig->LoseSightRadius = 1800.0f;
	SightConfig->PeripheralVisionAngleDegrees = 60.0f;

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GuardPerception->ConfigureSense(*SightConfig);
	GuardPerception->SetDominantSense(UAISense_Sight::StaticClass());
}

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

void AGuardAIController::BeginPlay()
{
	Super::BeginPlay();
	
	GuardPerception->OnTargetPerceptionUpdated.AddUniqueDynamic(
		this,
		&AGuardAIController::HandleTargetPerceptionUpdated
	);
}

void AGuardAIController::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.Type != UAISense::GetSenseID<UAISense_Sight>())
	{
		return;
	}

	APawn* SensedPawn = Cast<APawn>(Actor);

	if (!IsValid(SensedPawn) || !SensedPawn->IsPlayerControlled())
	{
		return;
	}

	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(
			LogTemp,
			Log,
			TEXT("%s sees %s at %s"),
			*GetName(),
			*GetNameSafe(SensedPawn),
			*Stimulus.StimulusLocation.ToString()
		);
	}
	else
	{
		UE_LOG(
			LogTemp,
			Log,
			TEXT("%s lost sight of %s"),
			*GetName(),
			*GetNameSafe(SensedPawn)
		);
	}

	UBlackboardComponent* BlackboardComp = GetBlackboardComponent();

	if (!IsValid(BlackboardComp))
	{
		return;
	}

	if (Stimulus.WasSuccessfullySensed())
	{
		BlackboardComp->SetValueAsObject(TEXT("TargetActor"), SensedPawn);
		BlackboardComp->SetValueAsVector(
			TEXT("LastKnownTargetLocation"),
			Stimulus.StimulusLocation);

		BlackboardComp->SetValueAsBool(TEXT("HasLineOfSight"), true);
	}
	else
	{
		BlackboardComp->SetValueAsBool(TEXT("HasLineOfSight"), false);
	}
}

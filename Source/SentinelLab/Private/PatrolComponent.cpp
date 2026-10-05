// Copyright 2026 Yuii551. All Rights Reserved.


#include "PatrolComponent.h"
#include "PatrolRoute.h"
#include "Engine/TargetPoint.h"

UPatrolComponent::UPatrolComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ATargetPoint* UPatrolComponent::GetCurrentPatrolPoint() const
{
	if (!IsValid(PatrolRoute))
	{
		return nullptr;
	}
	
	ATargetPoint* CurrentPoint =
		PatrolRoute->GetPatrolPoint(CurrentPatrolIndex);
	
	return IsValid(CurrentPoint) ? CurrentPoint : nullptr;
}

ATargetPoint* UPatrolComponent::AdvancePatrolPoint()
{
	if (!IsValid(PatrolRoute))
	{
		return nullptr;
	}
	
	const int32 NumPoints = PatrolRoute->GetNumPatrolPoints();
	
	if (NumPoints <= 0)
	{
		return nullptr;
	}
	
	for (int32 i = 0; i < NumPoints; i++)
	{
		CurrentPatrolIndex = (CurrentPatrolIndex + 1) % NumPoints;
		
		ATargetPoint* Candidate =
			PatrolRoute->GetPatrolPoint(CurrentPatrolIndex);
		
		if (IsValid(Candidate))
		{
			return Candidate;
		}
	}

	return nullptr;
}

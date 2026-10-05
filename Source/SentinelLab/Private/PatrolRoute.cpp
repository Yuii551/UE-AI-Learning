// Copyright 2026 Yuii551. All Rights Reserved.


#include "PatrolRoute.h"

APatrolRoute::APatrolRoute()
{
	PrimaryActorTick.bCanEverTick = false;
}

int32 APatrolRoute::GetNumPatrolPoints() const
{
	return PatrolPoints.Num();
}

ATargetPoint* APatrolRoute::GetPatrolPoint(int32 Index) const
{
	if (!PatrolPoints.IsValidIndex(Index))
	{
		return nullptr;
	}

	return PatrolPoints[Index].Get();
}

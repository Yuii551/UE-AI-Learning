// Copyright 2026 Yuii551. All Rights Reserved.


#include "GuardCharacter.h"

#include "PatrolComponent.h"

AGuardCharacter::AGuardCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	PatrolComponent =
		CreateDefaultSubobject<UPatrolComponent>(TEXT("PatrolComponent"));
}

UPatrolComponent* AGuardCharacter::GetPatrolComponent() const
{
	return PatrolComponent;
}

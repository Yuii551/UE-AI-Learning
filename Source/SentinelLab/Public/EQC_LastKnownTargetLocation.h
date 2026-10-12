// Copyright 2026 Yuii551. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EQC_LastKnownTargetLocation.generated.h"

/**
 * 
 */
UCLASS()
class SENTINELLAB_API UEQC_LastKnownTargetLocation : public UEnvQueryContext
{
	GENERATED_BODY()

protected:
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "TraceTestActor.h"

float ATraceTestActor::TestEnvironment()
{
	if (TraceTestTarget)
	{
		FHitResult f(ForceInit);
		FCollisionQueryParams  params = FCollisionQueryParams(FName(TEXT("EnvironmentTestTrace")), true, NULL);
		params.bTraceAsyncScene = true;

		GetWorld()->LineTraceSingleByChannel(f, GetActorLocation(), TraceTestTarget->GetActorLocation(), ECC_Visibility, params);

		if (bShowLineTraceDebug)
		{
			GetWorld()->DebugDrawTraceTag = "EnvironmentTestTrace";
		}

		if (f.Actor == TraceTestTarget)
		{
			return 0.f;
		}
		else
		{
			return 1.f;
		}
	}
	else
	{
		return 1.f;
	}
}

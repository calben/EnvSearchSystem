// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SearchSystems/EnvironmentTesters/EnvironmentTestActor.h"
#include "TraceTestActor.generated.h"

/**
 *
 */
UCLASS()
class ENVSEARCHER_API ATraceTestActor : public AEnvironmentTestActor
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* TraceTestTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector TraceLocationOverride;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AActor* BlockingActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShowLineTraceDebug;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bTraceToLocationOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<ECollisionChannel> TraceChannel;

	FCollisionQueryParams Params;

	FCollisionResponseParams ResponseParam;

	// 0 for successful trace to target, 1 otherwise
	float TestEnvironment() override;


};

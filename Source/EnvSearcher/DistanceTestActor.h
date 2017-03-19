// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SearchSystems/EnvironmentTestActor.h"
#include "DistanceTestActor.generated.h"

/**
 * 
 */
UCLASS()
class ENVSEARCHER_API ADistanceTestActor : public AEnvironmentTestActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* DistanceTestTarget;

	float TestEnvironment() override;
	
	
};

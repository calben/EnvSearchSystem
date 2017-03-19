// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "DistanceTestActor.h"

float ADistanceTestActor::TestEnvironment()
{
	return FVector::Dist(this->GetActorLocation(), DistanceTestTarget->GetActorLocation());
}

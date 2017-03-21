// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "EnvironmentSearchSystem.h"
#include "SearchSystems/EnvironmentTesters/EnvironmentTestActor.h"
#include "Actors/ValueIndicatorBox.h"


// Sets default values
AEnvironmentSearchSystem::AEnvironmentSearchSystem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
}

// Called when the game starts or when spawned
void AEnvironmentSearchSystem::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEnvironmentSearchSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnvironmentSearchSystem::PerformSearch()
{
	const clock_t begin_time = clock();
	PointToScoreMap.empty();
	ScoreToPointMap.empty();
	for (FVector point : SearchPoints)
	{
		float score = 0;
		for (AEnvironmentTestActor* test_actor : TestActors)
		{
			if (test_actor)
			{
				test_actor->SetActorLocation(point);
				float result = test_actor->GetScore();
				if (bDebugMode)
				{
					UE_LOG(LogTemp, Warning, TEXT("%s on point %s returned %f"), *test_actor->GetName(), *point.ToString(), result);
				}
				PointToTesterToScoreMap[point][test_actor] = result;
				score += result;
			}
		}
		if (bDebugMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("point %s scored %f"), *point.ToString(), score);
		}
		if (bShowIndicatorBoxes)
		{
			if (ValueIndicatorBoxClass != nullptr)
			{
				AValueIndicatorBox* SpawnedIndicatorBox = GetWorld()->SpawnActor<AValueIndicatorBox>(ValueIndicatorBoxClass, point, FRotator::ZeroRotator);
				PointToValueIndicatorMap[point] = SpawnedIndicatorBox;
				SpawnedIndicatorBox->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
				SpawnedIndicatorBox->SetValue(score);
			}
		}
		PointToScoreMap[point] = score;
		ScoreToPointMap[score] = point;
	}
	if (bShowIndicatorBoxes && bScaleIndicatorBoxValues)
	{
		ScaleIndicatorBoxValues();
	}
	if (bShowClockTime)
	{
		UE_LOG(LogTemp, Warning, TEXT("test finished in %f"), float(clock() - begin_time) / CLOCKS_PER_SEC);
	}
}

void AEnvironmentSearchSystem::ScaleIndicatorBoxValues()
{
	float max = -1.f;
	for (auto& pair : PointToValueIndicatorMap)
	{
		if (pair.second->Value > max)
		{
			max = pair.second->Value;
		}
	}
	if (bDebugMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Maximum value for scaling: %f"), max);
	}
	for (auto& pair : PointToValueIndicatorMap)
	{
		UE_LOG(LogTemp, Warning, TEXT("previously %f"), pair.second->Value);
		pair.second->SetValue(pair.second->Value / max);
		UE_LOG(LogTemp, Warning, TEXT("now %f"), pair.second->Value);
	}
}

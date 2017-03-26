// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "BestSubGridSearchSystem.h"


void ABestSubGridSearchSystem::PerformSearch()
{
	int iterations = 1;
	FVector search_origin = GetActorLocation();
	TArray<FVector> iteration_search_points;
	while (true)
	{
		if (bDebugMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s iteration %d at %s"), *GetName(), iterations, *search_origin.ToString());
		}
		EnvSearchSystemUtils::GenerateGrid(GridShape, GetActorLocation(), GridXCount, GridYCount, GridZCount, GridXSpacing, GridYSpacing, GridZSpacing, &iteration_search_points);
		for (FVector v : iteration_search_points)
		{
			SearchPoints.Add(v);
		}
		ScorePoints(&TestActors, &iteration_search_points, &PointToTesterToScoreMap, &PointToScoreMap, &ScoreToPointMap, bDebugMode);
		if (iterations >= MaximumIterations)
		{
			break;
		}
		if (bScoreIsError)
		{
			GetLowestScoringPoint(search_origin);
		}
		else
		{
			GetHighestScoringPoint(search_origin);
		}
		iterations++;
	}
	if (bShowIndicatorBoxes)
	{
		SpawnIndicatorBoxes(this, &SearchPoints, ValueIndicatorBoxClass, &PointToValueIndicatorMap, &PointToScoreMap);
	}
	if (bShowIndicatorBoxes && bScaleIndicatorBoxValues)
	{
		ScaleIndicatorBoxValues();
	}
}

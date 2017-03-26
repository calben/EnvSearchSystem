// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "BestSubGridSearchSystem.h"


void ABestSubGridSearchSystem::PerformIterativeSearch()
{
	int iterations = 1;
	while (true)
	{
		EnvSearchSystemUtils::GenerateGrid(GridShape, GetActorLocation(), GridXCount, GridYCount, GridZCount, GridXSpacing, GridYSpacing, GridZSpacing, &SearchPoints);
		FVector new_search_position;
		if (bScoreIsError)
		{
			GetLowestScoringPoint(new_search_position);
		}
		else
		{
			GetHighestScoringPoint(new_search_position);
		}
		SetActorLocation(new_search_position);
		if (bDebugMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s iteration %d at %s"), *GetName(), iterations, *new_search_position.ToString());
		}
		if (iterations >= MaximumIterations)
		{
			break;
		}
		iterations++;
	}
}

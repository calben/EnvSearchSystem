// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "GridSearchSystem.h"

void AGridSearchSystem::PerformSearch()
{
	EnvSearchSystemUtils::GenerateGrid(GridShape, GetActorLocation(), GridXCount, GridYCount, GridZCount, GridXSpacing, GridYSpacing, GridZSpacing, &SearchPoints);
	Super::PerformSearch();
}
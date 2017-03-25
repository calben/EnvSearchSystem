// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "EnvSearchSystemUtils.h"

EnvSearchSystemUtils::EnvSearchSystemUtils()
{
}

EnvSearchSystemUtils::~EnvSearchSystemUtils()
{
}

void EnvSearchSystemUtils::GenerateGrid(EGridShape GridShape, FVector Origin, int GridXCount, int GridYCount, int GridZCount, float GridXSpacing, float GridYSpacing, float GridZSpacing, TArray<FVector>* GridPoints)
{
	float XMax = GridXCount * GridXSpacing * 0.5f;
	float YMax = GridYCount * GridYSpacing * 0.5f;
	float ZMax = GridZCount * GridZSpacing * 0.5f;
	if (GridShape == EGridShape::Square)
	{
		for (auto i = 0; i < GridXCount; i++)
		{
			for (auto j = 0; j < GridYCount; j++)
			{
				for (auto k = 0; k < GridZCount; k++)
				{
					auto XOffset = (-1 * XMax) + (i * GridXSpacing);
					auto YOffset = (-1 * YMax) + (j * GridYSpacing);
					auto ZOffset = (-1 * ZMax) + (k * GridZSpacing);
					GridPoints->Add(FVector(Origin.X + XOffset,
						Origin.Y + YOffset,
						Origin.Z + ZOffset));
				}
			}
		}
	}
}

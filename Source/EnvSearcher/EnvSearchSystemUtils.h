// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class EGridShape : uint8
{
	Square,
	Diamond,
	Circle
};

/**
 *
 */
class ENVSEARCHER_API EnvSearchSystemUtils
{
public:
	EnvSearchSystemUtils();
	~EnvSearchSystemUtils();

	static void EnvSearchSystemUtils::GenerateGrid(EGridShape GridShape, FVector Origin, int GridXCount, int GridYCount, int GridZCount, float GridXSpacing, float GridYSpacing, float GridZSpacing, TArray<FVector>* GridPoints);

};

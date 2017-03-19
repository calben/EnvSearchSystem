// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SearchSystems/EnvironmentSearchSystem.h"
#include "GridSearchSystem.generated.h"

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
UCLASS()
class ENVSEARCHER_API AGridSearchSystem : public AEnvironmentSearchSystem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EGridShape GridShape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GridXCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GridYCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GridZCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GridXSpacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GridYSpacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GridZSpacing;

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		void GenerateGridPoints();

};

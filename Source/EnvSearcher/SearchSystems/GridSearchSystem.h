// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SearchSystems/EnvironmentSearchSystem.h"
#include "EnvSearchSystemUtils.h"
#include "GridSearchSystem.generated.h"

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

	virtual void PerformSearch() override;

};

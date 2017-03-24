// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SearchSystems/GridSearchSystem.h"
#include "BestSubGridSearchSystem.generated.h"

/**
 * 
 */
UCLASS()
class ENVSEARCHER_API ABestSubGridSearchSystem : public AGridSearchSystem
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaximumIterations = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MinimumIterations = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bScoreIsError = true; //!< if your score is error, then 0 is perfect, else you want the highest score

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GoalScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bStopIfGoalReached; //!< stops if the goal is reached unless minimum iterations not reached

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		void PerformIterativeSearch();
	
};

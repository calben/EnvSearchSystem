// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include <map>
#include <ctime>

#include "EnvironmentSearchSystem.generated.h"

struct CompareByVectorString {
	bool operator()(const FVector a, const FVector b) const {
		return a.ToString() < b.ToString();
	}
};

UCLASS()
class ENVSEARCHER_API AEnvironmentSearchSystem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnvironmentSearchSystem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector> SearchPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bDebugMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShowClockTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShowIndicatorBoxes; //!< debugging only.  this will more than double runtime

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bScaleIndicatorBoxValues; //!< also increases runtime some, but useful unless your algorithm already normalises

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class AValueIndicatorBox> ValueIndicatorBoxClass;

	std::map<FVector, class AValueIndicatorBox*, CompareByVectorString> PointToValueIndicatorMap;

	std::map<FVector, std::map<class AEnvironmentTestActor*, float>, CompareByVectorString> PointToTesterToScoreMap;

	// there are two maps here for performance reasons
	std::map<FVector, float, CompareByVectorString> PointToScoreMap;

	std::map<float, FVector> ScoreToPointMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AEnvironmentTestActor*> TestActors;

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		virtual void PerformSearch(); //!< Performs a search at the current location

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		void ScaleIndicatorBoxValues();

	void GetLowestScoringPoint(FVector* Vector);

	void GetHighestScoringPoint(FVector* Vector);

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		void GetLowestScoringPoint(FVector& VectorOUT);

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		void GetHighestScoringPoint(FVector& VectorOUT);

	static void SpawnIndicatorBoxes(AActor* Parent, std::map<FVector, float, CompareByVectorString>* PointToScoreMap, TSubclassOf<class AValueIndicatorBox> ValueIndicatorBoxClass, std::map<FVector, class AValueIndicatorBox*, CompareByVectorString>* PointToValueIndicatorMap);

	static void ScorePoints(TArray<AEnvironmentTestActor*>* TestActors, TArray<FVector>* Points, std::map<FVector, std::map<class AEnvironmentTestActor*, float>, CompareByVectorString>* PointToTesterToScoreMap, std::map<FVector, float, CompareByVectorString>* PointToScoreMap, std::map<float, FVector>* ScoreToPointMap, bool bDebugMode);

};

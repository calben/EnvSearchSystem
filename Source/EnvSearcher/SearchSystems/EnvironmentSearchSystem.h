// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include <map>
#include <ctime>

#include "EnvironmentSearchSystem.generated.h"

struct CompareByVectorLength {
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

	std::map<FVector, class AValueIndicatorBox*, CompareByVectorLength> PointToValueIndicatorMap;

	std::map<FVector, std::map<class AEnvironmentTestActor*, float>, CompareByVectorLength> PointToTesterToScoreMap;

	// there are two maps here for performance reasons
	std::map<FVector, float, CompareByVectorLength> PointToScoreMap;

	std::map<float, FVector> ScoreToPointMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AEnvironmentTestActor*> TestActors;

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		virtual void PerformSearch(); //!< Performs a search at the current location

	UFUNCTION(BlueprintCallable, Category = "EnvironmentSearching")
		void ScaleIndicatorBoxValues();

};

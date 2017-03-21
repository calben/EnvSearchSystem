// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnvironmentTestActor.generated.h"

UCLASS()
class ENVSEARCHER_API AEnvironmentTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnvironmentTestActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual float TestEnvironment();

	float GetScore();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ResultMultiplier = 1.f;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ValueIndicatorBox.generated.h"

UCLASS()
class ENVSEARCHER_API AValueIndicatorBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AValueIndicatorBox();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


	UPROPERTY(EditAnywhere)
		USceneComponent* Scene;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseOpacity = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float OpacityMultiplier = 0.3f;

	UPROPERTY(VisibleAnywhere)
		UMaterialInstanceDynamic* DynamicMaterial = nullptr;

	UFUNCTION()
		void SetValue(float NewValue);

	void GetHeatMapColor(float HeatValue, float *red, float *green, float *blue);

};

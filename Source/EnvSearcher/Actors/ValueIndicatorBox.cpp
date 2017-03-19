// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "ValueIndicatorBox.h"

// Sets default values
AValueIndicatorBox::AValueIndicatorBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Scene);

}

// Called when the game starts or when spawned
void AValueIndicatorBox::BeginPlay()
{
	Super::BeginPlay();

	if (Mesh && !DynamicMaterial)
	{
		DynamicMaterial = Mesh->CreateAndSetMaterialInstanceDynamic(0);
		if (DynamicMaterial)
		{
			Mesh->SetMaterial(0, DynamicMaterial);
		}
	}
}

// Called every frame
void AValueIndicatorBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AValueIndicatorBox::SetValue(float NewValue)
{
	Value = NewValue;
	float r, g, b;
	GetHeatMapColor(NewValue, &r, &g, &b);
	
	// if you set value on same tick as spawning the box,
	// then ya need to do the dynamic material bit again :-)
	if (DynamicMaterial == nullptr)
	{
		if (Mesh)
		{
			DynamicMaterial = Mesh->CreateAndSetMaterialInstanceDynamic(0);
			if (DynamicMaterial)
			{
				Mesh->SetMaterial(0, DynamicMaterial);
			}
		}
	}
	if (DynamicMaterial != nullptr)
	{
		DynamicMaterial->SetScalarParameterValue(FName("OpacityParam"), BaseOpacity + (Value * OpacityMultiplier));
		DynamicMaterial->SetVectorParameterValue(FName("ColorParam"), FVector(r, g, b));
	}
}

// based on
// http://www.andrewnoske.com/wiki/Code_-_heatmaps_and_color_gradients
void AValueIndicatorBox::GetHeatMapColor(float HeatValue, float *red, float *green, float *blue)
{
	const int NUM_COLORS = 4;
	static float color[NUM_COLORS][3] = { { 0,0,1 },{ 0, 1, 0 },{ 1,1,0 },{ 1, 0, 0 } };

	int idx1;
	int idx2;
	float fractBetween = 0;

	if (HeatValue <= 0) { idx1 = idx2 = 0; }
	else if (HeatValue >= 1) { idx1 = idx2 = NUM_COLORS - 1; }
	else
	{
		HeatValue = HeatValue * (NUM_COLORS - 1);
		idx1 = floor(HeatValue);
		idx2 = idx1 + 1;
		fractBetween = HeatValue - float(idx1);
	}

	*red = (color[idx2][0] - color[idx1][0])*fractBetween + color[idx1][0];
	*green = (color[idx2][1] - color[idx1][1])*fractBetween + color[idx1][1];
	*blue = (color[idx2][2] - color[idx1][2])*fractBetween + color[idx1][2];
}

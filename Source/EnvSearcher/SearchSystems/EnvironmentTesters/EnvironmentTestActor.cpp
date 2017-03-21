// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvSearcher.h"
#include "EnvironmentTestActor.h"


// Sets default values
AEnvironmentTestActor::AEnvironmentTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
}

// Called when the game starts or when spawned
void AEnvironmentTestActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEnvironmentTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AEnvironmentTestActor::TestEnvironment()
{
	return (GetActorLocation().X + GetActorLocation().Y + GetActorLocation().Z);
}

float AEnvironmentTestActor::GetScore()
{
	return ResultMultiplier * TestEnvironment();
}

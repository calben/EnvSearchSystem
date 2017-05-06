# class `ABestSubGridSearchSystem` 

```
class ABestSubGridSearchSystem
  : public AGridSearchSystem
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int MaximumIterations` | 
`public int MinimumIterations` | 
`public bool bScoreIsError` | if your score is error, then 0 is perfect, else you want the highest score
`public float GoalScore` | 
`public bool bStopIfGoalReached` | stops if the goal is reached unless minimum iterations not reached
`public virtual void PerformSearch()` | Performs a search at the current location.

## Members

#### `public int MaximumIterations` 





#### `public int MinimumIterations` 





#### `public bool bScoreIsError` 

if your score is error, then 0 is perfect, else you want the highest score



#### `public float GoalScore` 





#### `public bool bStopIfGoalReached` 

stops if the goal is reached unless minimum iterations not reached



#### `public virtual void PerformSearch()` 

Performs a search at the current location.



# class `ADistanceTestActor` 

```
class ADistanceTestActor
  : public AEnvironmentTestActor
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public AActor * DistanceTestTarget` | 
`public virtual float TestEnvironment()` | 

## Members

#### `public AActor * DistanceTestTarget` 





#### `public virtual float TestEnvironment()` 





# class `AEnvironmentSearchSystem` 

```
class AEnvironmentSearchSystem
  : public AActor
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public USceneComponent * Scene` | 
`public TArray< FVector > SearchPoints` | 
`public bool bDebugMode` | 
`public bool bShowClockTime` | 
`public bool bShowIndicatorBoxes` | debugging only. this will more than double runtime
`public bool bScaleIndicatorBoxValues` | also increases runtime some, but useful unless your algorithm already normalises
`public TSubclassOf< class `[`AValueIndicatorBox`](#class_a_value_indicator_box)` > ValueIndicatorBoxClass` | 
`public std::map< FVector, class `[`AValueIndicatorBox](#class_a_value_indicator_box) *, [CompareByVectorString`](#struct_compare_by_vector_string)` > PointToValueIndicatorMap` | 
`public std::map< FVector, std::map< class `[`AEnvironmentTestActor](#class_a_environment_test_actor) *, float >, [CompareByVectorString`](#struct_compare_by_vector_string)` > PointToTesterToScoreMap` | 
`public std::map< FVector, float, `[`CompareByVectorString`](#struct_compare_by_vector_string)` > PointToScoreMap` | 
`public std::map< float, FVector > ScoreToPointMap` | 
`public TArray< class `[`AEnvironmentTestActor`](#class_a_environment_test_actor)` * > TestActors` | 
`public  AEnvironmentSearchSystem()` | 
`public virtual void BeginPlay()` | 
`public virtual void Tick(float DeltaSeconds)` | 
`public virtual void PerformSearch()` | Performs a search at the current location.
`public void ScaleIndicatorBoxValues()` | 
`public void GetLowestScoringPoint(FVector * Vector)` | 
`public void GetHighestScoringPoint(FVector * Vector)` | 
`public void GetLowestScoringPoint(FVector & VectorOUT)` | 
`public void GetHighestScoringPoint(FVector & VectorOUT)` | 

## Members

#### `public USceneComponent * Scene` 





#### `public TArray< FVector > SearchPoints` 





#### `public bool bDebugMode` 





#### `public bool bShowClockTime` 





#### `public bool bShowIndicatorBoxes` 

debugging only. this will more than double runtime



#### `public bool bScaleIndicatorBoxValues` 

also increases runtime some, but useful unless your algorithm already normalises



#### `public TSubclassOf< class `[`AValueIndicatorBox`](#class_a_value_indicator_box)` > ValueIndicatorBoxClass` 





#### `public std::map< FVector, class `[`AValueIndicatorBox](#class_a_value_indicator_box) *, [CompareByVectorString`](#struct_compare_by_vector_string)` > PointToValueIndicatorMap` 





#### `public std::map< FVector, std::map< class `[`AEnvironmentTestActor](#class_a_environment_test_actor) *, float >, [CompareByVectorString`](#struct_compare_by_vector_string)` > PointToTesterToScoreMap` 





#### `public std::map< FVector, float, `[`CompareByVectorString`](#struct_compare_by_vector_string)` > PointToScoreMap` 





#### `public std::map< float, FVector > ScoreToPointMap` 





#### `public TArray< class `[`AEnvironmentTestActor`](#class_a_environment_test_actor)` * > TestActors` 





#### `public  AEnvironmentSearchSystem()` 





#### `public virtual void BeginPlay()` 





#### `public virtual void Tick(float DeltaSeconds)` 





#### `public virtual void PerformSearch()` 

Performs a search at the current location.



#### `public void ScaleIndicatorBoxValues()` 





#### `public void GetLowestScoringPoint(FVector * Vector)` 





#### `public void GetHighestScoringPoint(FVector * Vector)` 





#### `public void GetLowestScoringPoint(FVector & VectorOUT)` 





#### `public void GetHighestScoringPoint(FVector & VectorOUT)` 





# class `AEnvironmentTestActor` 

```
class AEnvironmentTestActor
  : public AActor
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public USceneComponent * Scene` | 
`public float ResultMultiplier` | 
`public  AEnvironmentTestActor()` | 
`public virtual void BeginPlay()` | 
`public virtual void Tick(float DeltaSeconds)` | 
`public virtual float TestEnvironment()` | 
`public float GetScore()` | 

## Members

#### `public USceneComponent * Scene` 





#### `public float ResultMultiplier` 





#### `public  AEnvironmentTestActor()` 





#### `public virtual void BeginPlay()` 





#### `public virtual void Tick(float DeltaSeconds)` 





#### `public virtual float TestEnvironment()` 





#### `public float GetScore()` 





# class `AEnvSearcherGameModeBase` 

```
class AEnvSearcherGameModeBase
  : public AGameModeBase
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `AGridSearchSystem` 

```
class AGridSearchSystem
  : public AEnvironmentSearchSystem
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public EGridShape GridShape` | 
`public float GridXCount` | 
`public float GridYCount` | 
`public float GridZCount` | 
`public float GridXSpacing` | 
`public float GridYSpacing` | 
`public float GridZSpacing` | 
`public virtual void PerformSearch()` | Performs a search at the current location.

## Members

#### `public EGridShape GridShape` 





#### `public float GridXCount` 





#### `public float GridYCount` 





#### `public float GridZCount` 





#### `public float GridXSpacing` 





#### `public float GridYSpacing` 





#### `public float GridZSpacing` 





#### `public virtual void PerformSearch()` 

Performs a search at the current location.



# class `APointSearchSystem` 

```
class APointSearchSystem
  : public AEnvironmentSearchSystem
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `ATraceTestActor` 

```
class ATraceTestActor
  : public AEnvironmentTestActor
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public AActor * TraceTestTarget` | 
`public FVector TraceLocationOverride` | 
`public AActor * BlockingActor` | 
`public bool bShowLineTraceDebug` | 
`public bool bTraceToLocationOverride` | 
`public TEnumAsByte< ECollisionChannel > TraceChannel` | 
`public FCollisionQueryParams Params` | 
`public FCollisionResponseParams ResponseParam` | 
`public virtual float TestEnvironment()` | 

## Members

#### `public AActor * TraceTestTarget` 





#### `public FVector TraceLocationOverride` 





#### `public AActor * BlockingActor` 





#### `public bool bShowLineTraceDebug` 





#### `public bool bTraceToLocationOverride` 





#### `public TEnumAsByte< ECollisionChannel > TraceChannel` 





#### `public FCollisionQueryParams Params` 





#### `public FCollisionResponseParams ResponseParam` 





#### `public virtual float TestEnvironment()` 





# class `AValueIndicatorBox` 

```
class AValueIndicatorBox
  : public AActor
```  





## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public USceneComponent * Scene` | 
`public UStaticMeshComponent * Mesh` | 
`public float Value` | 
`public float BaseOpacity` | 
`public float OpacityMultiplier` | 
`public UMaterialInstanceDynamic * DynamicMaterial` | 
`public  AValueIndicatorBox()` | 
`public virtual void BeginPlay()` | 
`public virtual void Tick(float DeltaSeconds)` | 
`public void SetValue(float NewValue)` | 
`public void GetHeatMapColor(float HeatValue,float * red,float * green,float * blue)` | 

## Members

#### `public USceneComponent * Scene` 





#### `public UStaticMeshComponent * Mesh` 





#### `public float Value` 





#### `public float BaseOpacity` 





#### `public float OpacityMultiplier` 





#### `public UMaterialInstanceDynamic * DynamicMaterial` 





#### `public  AValueIndicatorBox()` 





#### `public virtual void BeginPlay()` 





#### `public virtual void Tick(float DeltaSeconds)` 





#### `public void SetValue(float NewValue)` 





#### `public void GetHeatMapColor(float HeatValue,float * red,float * green,float * blue)` 





# class `EnvSearchSystemUtils` 






## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  EnvSearchSystemUtils()` | 
`public  ~EnvSearchSystemUtils()` | 

## Members

#### `public  EnvSearchSystemUtils()` 





#### `public  ~EnvSearchSystemUtils()` 





# struct `CompareByVectorString` 






## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline bool operator()(const FVector a,const FVector b) const` | 

## Members

#### `public inline bool operator()(const FVector a,const FVector b) const` 






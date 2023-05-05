// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nexus.generated.h"

UCLASS()
class CLASSROOM_API ANexus : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANexus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UInstancedStaticMeshComponent *vertexMesh;

	UFUNCTION(BlueprintCallable, Category = "Nexus")
		void addNexus(int numVertices, int sphereRadius, float scale, UStaticMesh* mesh);

	UFUNCTION(BlueprintCallable, Category = "Nexus")
		bool shiftToLine(int sphereRadius, float scale, float elapsedTime, float duration);
	UFUNCTION(BlueprintCallable, Category = "Nexus")
		bool shiftToSphere1(int sphereRadius, float scale, float elapsedTime, float duration);

};

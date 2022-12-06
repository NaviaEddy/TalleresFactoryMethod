// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicCapsule.generated.h"

UCLASS()
class ARKANOID_API ABasicCapsule : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicCapsule();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class USceneComponent* Scene; //Component de escena

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_BasicCapsule; //Malla del brick

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision; //Colision

	//Nombre de la capsula
	FString CapsuleName;

	void HitMesh(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetCapsuleName();


	float x;
	float vc;

};
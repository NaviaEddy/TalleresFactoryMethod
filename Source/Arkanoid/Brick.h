// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicCapsule.h"
#include "Brick.generated.h"
UCLASS()
class ARKANOID_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick; //Ladrillo

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Collision;  //Caja Colision

	float SpeedModifierOnBounce = 1.01f;


	UFUNCTION() //Entra en la caja
		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	void DestroyBrick();

	void CreateCapsule(FVector Location);

private:

	bool HabilitadoCreacionCapsulas;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual ABasicCapsule* CreateCapsule(FString NameCapsule, FVector Location) PURE_VIRTUAL(ABrick::CreateCapsule, return nullptr;);

	ABasicCapsule* OrdenCapsule(FString Category, FVector Spawn);


};

// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCapsule.h"
#include "Paddle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABasicCapsule::ABasicCapsule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("StaticMesh'/Game/Assets/Meshes/Capsule.Capsule'"));
	SM_BasicCapsule = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BasicCapsule"));
	SM_BasicCapsule->SetStaticMesh(CapsuleMesh.Object);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(0.3f, 0.2f, 0.3f));

	SM_BasicCapsule->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	x = 1.0f;
	vc = 25;

}


// Called when the game starts or when spawned
void ABasicCapsule::BeginPlay()
{
	Super::BeginPlay();

	
}

void ABasicCapsule::HitMesh(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

// Called every frame
void ABasicCapsule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Creo la direccion y el vector movimiento
	const FVector MoveDirection = FVector(0.0f, 0.0f, -x);
	const FVector Movement = MoveDirection * vc * DeltaTime;

	if (Movement.SizeSquared() > 0.0f)
	{
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, FRotator::ZeroRotator, true, &Hit);

	}

}

FString ABasicCapsule::GetCapsuleName()
{
	return CapsuleName;
}


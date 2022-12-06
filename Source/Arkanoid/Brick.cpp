// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Ball.h"
#include "HelpCapsules.h"


// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Brick.SM_Brick'"));
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Collision->SetBoxExtent(FVector(25.5f, 12.0f, 12.0f));

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetStaticMesh(BrickMesh.Object);
	
	SM_Brick->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Collision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	HabilitadoCreacionCapsulas = false;

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABrick::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (HabilitadoCreacionCapsulas) {

		if (OtherActor->ActorHasTag("Ball")) {

			ABall* MyBall = Cast<ABall>(OtherActor);

			FVector BallVelocity = MyBall->GetVelocity();
			BallVelocity *= (SpeedModifierOnBounce - 1.0f);

			MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);

			FVector GetLocation = this->GetActorLocation();

			if (&ABrick::GetWorldTimerManager != false) {
				CreateCapsule(GetLocation);
			}

		}
	}

}


void ABrick::DestroyBrick()
{
	this->Destroy();
}

	

void ABrick::CreateCapsule(FVector Location)
{

	ABrick* CapsuleCreator = GetWorld()->SpawnActor<AHelpCapsules>(AHelpCapsules::StaticClass(), FVector(0.0f, 0.0f, -100.0f), FRotator::ZeroRotator);
	ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule("Bomb", Location);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Capsula de %s"), *Capsule->GetCapsuleName()));

}


// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	HabilitadoCreacionCapsulas = FMath::FRandRange(0, 9) >= 0 ? true : false;
	

}

ABasicCapsule* ABrick::OrdenCapsule(FString Category, FVector Spawn)
{
	ABasicCapsule* Capsules = CreateCapsule(Category, Spawn);
	return Capsules;
}

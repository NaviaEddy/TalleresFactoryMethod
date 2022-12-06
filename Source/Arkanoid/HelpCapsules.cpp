// Fill out your copyright notice in the Description page of Project Settings.


#include "HelpCapsules.h"
#include "AtomicBallCapsule.h"
#include "BallBombCapsule.h"
#include "ElongationCapsule.h"
#include "HealthCapsule.h"
#include "ShotCapsule.h"
#include "ReinforcedBallCapsule.h"
#include "ThreeBallCapsule.h"
#include "TwoBallCapsule.h"

ABasicCapsule* AHelpCapsules::CreateCapsule(FString NameCapsule, FVector Location)
{
    FVector Spawn = Location;
    FVector Spawn2(0.0f, 0.0f, -22.0f);

    if (NameCapsule.Equals("Atomic")) {
        return GetWorld()->SpawnActor<AAtomicBallCapsule>(AAtomicBallCapsule::StaticClass());
    }
    else if (NameCapsule.Equals("Bomb")) {
        return GetWorld()->SpawnActor<ABallBombCapsule>(Spawn+Spawn2, FRotator::ZeroRotator);
    }
    else if (NameCapsule.Equals("Elongation")) {
        return GetWorld()->SpawnActor<AElongationCapsule>(AElongationCapsule::StaticClass());
    }
    else if (NameCapsule.Equals("Health")) {
        return GetWorld()->SpawnActor<AHealthCapsule>(AHealthCapsule::StaticClass());
    }
    else if (NameCapsule.Equals("Shot")) {
        return GetWorld()->SpawnActor<AShotCapsule>(AShotCapsule::StaticClass());
    }
    else if (NameCapsule.Equals("Reinforced")) {
        return GetWorld()->SpawnActor<AReinforcedBallCapsule>(AReinforcedBallCapsule::StaticClass());
    }
    else if (NameCapsule.Equals("Three")) {
        return GetWorld()->SpawnActor<AThreeBallCapsule>(AThreeBallCapsule::StaticClass());
    }
    else if (NameCapsule.Equals("Two")) {
        return GetWorld()->SpawnActor<ATwoBallCapsule>(ATwoBallCapsule::StaticClass());
    }
    else return nullptr; //Devuelve nada si el nombre de la capsula no existe
}

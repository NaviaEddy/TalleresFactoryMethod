// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "ThreeBallCapsule.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AThreeBallCapsule : public ABasicCapsule
{
	GENERATED_BODY()
	


protected:

	virtual void BeginPlay() override;

};

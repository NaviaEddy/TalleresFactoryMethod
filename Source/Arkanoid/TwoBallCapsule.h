// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "TwoBallCapsule.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ATwoBallCapsule : public ABasicCapsule
{
	GENERATED_BODY()
	


protected:

	virtual void BeginPlay() override;
};

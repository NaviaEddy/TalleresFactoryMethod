// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Brick.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AArkanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	TArray<ABrick*> LineBricks;

	UPROPERTY()
		class ABrick* Brick;

public:
	virtual void Tick(float DeltaTime) override;
	
};

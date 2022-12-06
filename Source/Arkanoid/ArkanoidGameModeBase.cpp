// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidGameModeBase.h"
//#include "HelpCapsules.h"


void AArkanoidGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FVector Sl1 (-150.0f, 0.0f, 200.0f);
	FVector SL2(50.0f, 0.0f, 0.0f);
	
	for (int i = 1; i <= 4; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl1, FRotator::ZeroRotator);

		Sl1 = Sl1 + SL2;
	}
	


	//FVector Sl1 (-125.0f, 0.0f, 405.0f);
	//FVector Spawn2(50.0f, 0.0f, 0.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl1, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 1")));
	//	}

	//	Sl1 = Sl1 + Spawn2;
	//}

	//FVector Sl2(-125.0f, 0.0f, 385.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl2, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 2")));
	//	}

	//	Sl2 = Sl2 + Spawn2;
	//}

	//FVector Sl3(-125.0f, 0.0f, 365.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl3, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 3")));
	//	}

	//	Sl3 = Sl3 + Spawn2;
	//}

	//FVector Sl4(-125.0f, 0.0f, 345.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl4, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 4")));
	//	}

	//	Sl4 = Sl4 + Spawn2;
	//}

	//FVector Sl5(-125.0f, 0.0f, 325.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl5, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 5")));
	//	}

	//	Sl5 = Sl5 + Spawn2;
	//}

	//FVector Sl6(-125.0f, 0.0f, 305.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl6, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 6")));
	//	}

	//	Sl6 = Sl6 + Spawn2;
	//}

	//FVector Sl7(-125.0f, 0.0f, 285.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl7, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 7")));
	//	}

	//	Sl7 = Sl7 + Spawn2;
	//}

	//FVector Sl8(-125.0f, 0.0f, 265.0f);

	//for (int i = 0; i <= 5; i++) {
	//	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl8, FRotator::ZeroRotator);

	//	if (Brick != NULL) {
	//		LineBricks.Add(Brick);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se han ingresado correctamente los bricks de la linea 8")));
	//	}

	//	Sl8 = Sl8 + Spawn2;
	//}



	/*int32 ta = LineBricks.Num();

	if (ta == 48) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El tamaño del array es: 48")));
	}
	else {
		return;
	}*/

	//ACapsuleCreator* CapsuleCreator = GetWorld()->SpawnActor<AHelpCapsules>(AHelpCapsules::StaticClass());


}

void AArkanoidGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

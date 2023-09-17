// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "OnlineGameModeBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TRANSFORMOGUS_API AOnlineGameModeBase : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId,
		FString& ErrorMessage) override;
};

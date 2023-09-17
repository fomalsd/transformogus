// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "OnlinePlayerStateBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class TRANSFORMOGUS_API AOnlinePlayerStateBase : public APlayerState
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	virtual void SetPlayerName(const FString& S) override
	{
		Super::SetPlayerName(S);
	}
};

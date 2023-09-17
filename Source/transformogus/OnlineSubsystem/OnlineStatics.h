// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OnlineStatics.generated.h"

/**
 * 
 */
UCLASS()
class TRANSFORMOGUS_API UOnlineStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category="Sessions")
	static void GetRoomName(const FBlueprintSessionResult& Session, FString& RoomName);
};

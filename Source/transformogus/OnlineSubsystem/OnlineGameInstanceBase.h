// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "Engine/GameInstance.h"
#include "OnlineGameInstanceBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateRoomComplete, bool, Successful);

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class TRANSFORMOGUS_API UOnlineGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HostRoom(int32 PlayerCount, FString RoomName);

	UPROPERTY(BlueprintAssignable)
	FOnCreateRoomComplete OnCreateRoomCompleteEvent;

protected:

private:
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;
};

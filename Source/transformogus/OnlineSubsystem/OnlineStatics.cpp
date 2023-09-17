// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineStatics.h"

#include "FindSessionsCallbackProxy.h"

void UOnlineStatics::GetRoomName(const FBlueprintSessionResult& Session, FString& RoomName)
{
	RoomName = Session.OnlineResult.Session.OwningUserName;
	if (Session.OnlineResult.Session.SessionSettings.Settings.Contains(NAME_GameSession))
	{
		Session.OnlineResult.Session.SessionSettings.Settings[NAME_GameSession].Data.GetValue(RoomName);
	}
}

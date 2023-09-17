// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstanceBase.h"

#include "OnlineSessionSettings.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineSessionInterface.h"



void UOnlineGameInstanceBase::HostRoom(int32 PlayerCount, FString RoomName)
{
	const IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(GetWorld());
	if (!sessionInterface.IsValid())
	{
		OnCreateRoomCompleteEvent.Broadcast(false);
		return;
	}
	
	LastSessionSettings = MakeShareable(new FOnlineSessionSettings());
	LastSessionSettings->NumPrivateConnections = 0;
	LastSessionSettings->NumPublicConnections = PlayerCount;
	LastSessionSettings->bAllowInvites = true;
	LastSessionSettings->bAllowJoinInProgress = false;
	LastSessionSettings->bAllowJoinViaPresence = true;
	LastSessionSettings->bAllowJoinViaPresenceFriendsOnly = true;
	LastSessionSettings->bIsDedicated = false;
	LastSessionSettings->bUsesPresence = true;
	LastSessionSettings->bIsLANMatch = false;
	LastSessionSettings->bShouldAdvertise = true;
	LastSessionSettings->Set(NAME_GameSession, RoomName, EOnlineDataAdvertisementType::ViaOnlineService);

	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	const bool success = localPlayer && sessionInterface->CreateSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *LastSessionSettings);
	
	OnCreateRoomCompleteEvent.Broadcast(success);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameModeBase.h"

#include "GameFramework/GameSession.h"

void AOnlineGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId,
                                   FString& ErrorMessage)
{
	//Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	// For SteamSubsystem on client
	ErrorMessage = GameSession->ApproveLogin(Options);
	FGameModeEvents::GameModePreLoginEvent.Broadcast(this, UniqueId, ErrorMessage);
}

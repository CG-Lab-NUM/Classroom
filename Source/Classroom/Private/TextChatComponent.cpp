// Fill out your copyright notice in the Description page of Project Settings.


#include "TextChatComponent.h"

// Sets default values for this component's properties
UTextChatComponent::UTextChatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UTextChatComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UTextChatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTextChatComponent::sendChatMessage(const FString& message) {

}
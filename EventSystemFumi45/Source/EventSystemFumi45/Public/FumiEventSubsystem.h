// Copyright (C) 2024 Meidozuki
//
// This file is part of EventSystemFumi45.
//
// EventSystemFumi45 is free software: you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 2.1 of the License, or (at your option) any later version.
//
// EventSystemFumi45 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License along with EventSystemFumi45. If not, see <https://www.gnu.org/licenses/>.


#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "FumiEventType.h"
#include "FumiEventSubscriberInterface.h"

#include "FumiEventSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UFumiEventSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
protected:
	
	// UInterface和IInterface都无法直接作为参数，需要使用TScriptInterface
	UFUNCTION(BlueprintCallable, meta=(Keywords = "event", Category = "FumiEventSystem|Native"))
	bool Subscribe(TScriptInterface<IFumiEventSubscriber> Subscriber, FFumiEventType const& SubscribingEvent);

	UFUNCTION(BlueprintCallable, meta=(Keywords = "event", Category = "FumiEventSystem|Native"))
	void Publish(FFumiEventType const& Event);

private:
	TMap<FFumiEventType, TArray<TScriptInterface<IFumiEventSubscriber>>> SubscriberMapping;
};

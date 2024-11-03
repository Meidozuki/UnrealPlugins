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



#include "FumiEventSubsystem.h"

#include "FumiEventLog.h"
#include "FumiEventSubscriberInterface.h"

bool UFumiEventSubsystem::Subscribe(TScriptInterface<IFumiEventSubscriber> Subscriber, FFumiEventType const& SubscribingEvent)
{
	if (Subscriber.GetObject() == nullptr)
	{
		return false;
	}
	
	// If none exists, adds a value using the default constructor.
	auto &Array = SubscriberMapping.FindOrAdd(SubscribingEvent);
	// Adds unique element to array if it doesn't exist.
	Array.AddUnique(Subscriber);
	
	return true;
}

void UFumiEventSubsystem::Publish(FFumiEventType const& Event)
{
	auto *Array = SubscriberMapping.Find(Event);
	if (Array == nullptr)
	{
		UE_LOG(LogFumiEventSystem, Error, TEXT("Called publish with unknown event type (%d)"), Event.Value);
		return;
	}

	UE_LOG(LogFumiEventSystem, Display, TEXT("Event %d publish to %d subscribers"), Event.Value, Array->Num());
	for (const auto& Interface: *Array)
	{
		auto Object = Interface.GetObject();
		// maybe destroyed
		if (IsValid(Object))
		{
			IFumiEventSubscriber::Execute_OnReceiveEvent(Object, Event);
		}
	}
}

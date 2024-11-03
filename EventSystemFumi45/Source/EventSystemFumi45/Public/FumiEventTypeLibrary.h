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
#include "Kismet/BlueprintFunctionLibrary.h"

#include "FumiEventType.h"
#include "FumiEventTypelibrary.generated.h"

UCLASS()
class UFumiEventTypeBPLibrary:public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, meta=(DisplayName = "To FumiEventType (Integer)", CompactNodeTitle = "->", BlueprintAutocast, Category = "FumiEventSystem"))
	static FFumiEventType Conv_IntToEventType(int InValue)
	{
		FFumiEventType Ret;
		Ret.Value = InValue;
		return Ret;
	}

	// This is OK for small BP enum class
	UFUNCTION(BlueprintPure, meta=(DisplayName = "To FumiEventType (Byte)", CompactNodeTitle = "->", BlueprintAutocast, Category = "FumiEventSystem"))
	static FFumiEventType Conv_ByteToEventType(uint8 InValue)
	{
		FFumiEventType Ret;
		Ret.Value = InValue;
		return Ret;
	}

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Equal (FumiEventType)", CompactNodeTitle = "==", Category = "FumiEventSystem"))
	static bool Equal_EventType(const FFumiEventType& Lhs, const FFumiEventType& Rhs)
	{
		return Lhs == Rhs;
	}
};
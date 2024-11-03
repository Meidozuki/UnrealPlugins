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
#include "FumiEventType.generated.h"


USTRUCT(BlueprintType)
struct FFumiEventType
{
	GENERATED_BODY()

	using InnerType = uint16;

	InnerType Value;

	// ctor
	FFumiEventType() = default;
	FFumiEventType(InnerType InValue):Value(InValue) {}

	// compare
	FORCEINLINE bool operator==(const FFumiEventType& Rhs) const {return Value == Rhs.Value;}

	// conversion
	operator InnerType() const {return Value;}
	bool operator==(InnerType Rhs) const {return Value == Rhs;}
};


inline uint32 GetTypeHash(FFumiEventType Event)
{
	return GetTypeHash(Event.Value);
}

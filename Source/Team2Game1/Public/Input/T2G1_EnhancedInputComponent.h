// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "T2G1_InputConfig.h"
#include "T2G1_EnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class TEAM2GAME1_API UT2G1_EnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
	void BindAbilityActions(const UT2G1_InputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc);
	
	
};

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType>
void UT2G1_EnhancedInputComponent::BindAbilityActions(const UT2G1_InputConfig* InputConfig, UserClass* Object,
	PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc)
{
	UE_LOG(LogTemp, Warning, TEXT("Binding Ability Actions"));
	check(InputConfig);
	for (const FT2G1_InputAction& Action : InputConfig->AbilityInputActions)
	{
		
		if(Action.InputAction && Action.InputTag.IsValid())
		{
			if (PressedFunc)
			{
				UE_LOG(LogTemp, Warning, TEXT("Binding Pressed Func: "));
				UE_LOG(LogTemp, Warning, TEXT("Tag input: %s"), *Action.InputTag.ToString());
				UE_LOG(LogTemp, Warning, TEXT("Action input: %s"), *Action.InputAction->GetName());
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, PressedFunc, Action.InputTag);
				UE_LOG(LogTemp,Warning, TEXT("Object: %s"), *Object->GetName());
			}

			if (ReleasedFunc)
			{
				UE_LOG(LogTemp, Warning, TEXT("Binding Released Func: "));
				UE_LOG(LogTemp, Warning, TEXT("Tag input: %s"), *Action.InputTag.ToString());
				UE_LOG(LogTemp, Warning, TEXT("Action input: %s"), *Action.InputAction->GetName());
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag);
				UE_LOG(LogTemp,Warning, TEXT("Object: %s"), *Object->GetName());
			}
		}
	}
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/EffectActor/T2G1_EffectActor.h"

#include "AbilitySystemInterface.h"
#include "Attributes/T2G1_AttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AT2G1_EffectActor::AT2G1_EffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AT2G1_EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UT2G1_AttributeSet* T2G1_AttributeSet = Cast<UT2G1_AttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UT2G1_AttributeSet::StaticClass()));

		UT2G1_AttributeSet* MutableAttributeSet = const_cast<UT2G1_AttributeSet*>(T2G1_AttributeSet);
		MutableAttributeSet->SetHealth(T2G1_AttributeSet->GetHealth() + 25.f);
		Destroy();
	}
	
}

void AT2G1_EffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

// Called when the game starts or when spawned
void AT2G1_EffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::EndOverlap);
}


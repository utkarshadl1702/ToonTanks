// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();

	// UPROPERTY(VisibleInstanceOnly)
	// int32 VisibleInstanceOnlyIn = 14;

	// UPROPERTY(VisibleDefaultsOnly)
	// int32 VisibleDefaultsOnlyIn = 89;

	// UPROPERTY(EditDefaultsOnly)
	// int32 EditDefaultsOnlyIn=4;

	// UPROPERTY(EditInstanceOnly)
	// int32 EditInstanceOnlyIn=12;

	// UPROPERTY(EditAnywhere,BlueprintReadWrite)
	// float Speed = 400.f;
protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent *CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent *ProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Super Duper Variables", meta = (AllowPrivateAccess = "true")) // BlueprintReadwrite is used for Event graph properties
	int32 VisibleAnywhereIn = 12;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Super Duper Variables", meta = (AllowPrivateAccess = "true")) // to only read and not edit in event graph ofc
	int32 EditAnywhereIn = 11;
	// meta=allowprivate access is used to access variables in private section in unreal
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	
	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem *DeathParticles;


	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase *DeathSound;
    UPROPERTY(EditAnywhere, Category = "Combat") 
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
};

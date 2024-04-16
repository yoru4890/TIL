# 목차

- [총 발사 표현(LineTraceSingleByChannel)](#총-발사-표현linetracesinglebychannel)

## 총 발사 표현(LineTraceSingleByChannel)

```cpp
FVector startPos{ mpTpsCamComp->GetComponentLocation() };
FVector endPos{ mpTpsCamComp->GetComponentLocation() + mpTpsCamComp->GetForwardVector() * 5000 };
FHitResult hitInfo;
FCollisionQueryParams params;
params.AddIgnoredActor(this);

bool bHit{ GetWorld()->LineTraceSingleByChannel(hitInfo, startPos, endPos,ECC_Visibility, params) };

if (bHit)
{
	FTransform bulletTrans;
	bulletTrans.SetLocation(hitInfo.ImpactPoint);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), mpBulletEffectFactory, bulletTrans);

	// FHitReulst의 Component라는 변수가 있고 그 변수의 타입은 UPrimitiveComponent이다.
	auto hitComp{ hitInfo.GetComponent() };

	if (hitComp && hitComp->IsSimulatingPhysics())
	{
		FVector force = -hitInfo.ImpactNormal * hitComp->GetMass() * 500000;

		hitComp->AddForce(force);
	}
}
```

```cpp
// GetDefaultSubobjectByName의 반환값은 UObject 따라서 Cast를 해줘야한다.
auto enemy = hitInfo.GetActor()->GetDefaultSubobjectByName(TEXT("FSM"));
if (enemy)
{
	auto enemyFSM = Cast<UEnemyFSM>(enemy);
	enemyFSM->OnDamageProcess();
}
```
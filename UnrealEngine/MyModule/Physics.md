# 목차

- [물체 날리기](#물체-날리기)

## 물체 날리기

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


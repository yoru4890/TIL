# 목차

- [총알 파편 표현](#총알-파편-표현)

## 총알 파편 표현

```cpp
#include <Kismet/GameplayStatics.h>
```

```cpp
UPROPERTY(EditAnywhere, Category=BulletEffect)
TObjectPtr<class UParticleSystem> mpBulletEffectFactory;
```

```cpp
bool bHit{ GetWorld()->LineTraceSingleByChannel(hitInfo, startPos, endPos,ECC_Visibility, params) };

if (bHit)
{
	FTransform bulletTrans;
	bulletTrans.SetLocation(hitInfo.ImpactPoint);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), mpBulletEffectFactory, bulletTrans);
}
```

# 목차

- [SkeletalMesh 설정](#skeletalmesh-설정)

## SkeletalMesh 설정

```cpp
ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple'"));
if (TempMesh.Succeeded())
{
	GetMesh()->SetSkeletalMesh(TempMesh.Object);

    GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
}
```


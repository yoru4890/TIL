## Class

Actor
- Can be placed in the world
- Can have a visual representation(Mesh, etc.)

Pawn
- Can be possessed by a Controller
- Handles movement input

Character
- Has Character specific stuff(Character Movement Component, etc.)
- Movement modes(flying), 2족보행


## Components

USceneComponent
- Has a transform
- Supports attachment
- No visual representation

UCapsuleComponent
- Handles collision

UStaticMeshComponent
- Visual representation

RootComponent

## Forward Declaration

가능한 헤더파일에 포함시키지말고 cpp파일에 포함시켜서 계속 쌓이지 않게 해주자.

## UPROPERTY

- VisibleAnywhere
- VisibleInstanceOnly
- VisibleDefaultsOnly

- EditAnywhere
- EditDefaultsOnly
- EditInstanceOnly

- BlueprintReadOnly
- BlueprintReadWrite

- meta = (AllowPrivateAccess = "true")
- Category = "Category Name"

----------------------

- Sweeping
- AddActorLocalOffset
- AddActorLocalRotation
- GetHitResultUnderCursor
- DrawDebugSphere
- SewWorldRotation
- FMath::RInterpTo
- GetWorldTimerManager
- TSubclassOf
- SpawnActor
- UClass

## Hit Events

- OnComponentHit
- Invocation list
- OnTankeAnyDamage
- ApplyDamage
- GameMode

-----------------------------

- Widget
- UFUNCTION
- BlueprintImplementableEvent
- SpawnEmitterAtLocation
- CameraShake

Pawn, Character

Character는 Pawn에서 파생된 클래스

- AddMovementInput()
- AddControllerPitchInput()
- AddControllerYawInput()
- Jump()

컨트롤러는 마우스와는 화면전환방식을 달리 해줘야한다

Spring Arm 과 Camera

Skeletal Mesh, Animation

Animation Blueprint

AnimGraph, Blend

Blend Space, 애니메이션 연결

Inverse Tranform Direction

Rotation From X Vector

애니메이션 속도 계산하고 Blend Space에 적용시키기

런타임에 Actor spawning

안보이게 하기
```
GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
```

소켓달고 소켓에 붙이기
```
Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));

Gun->SetOwner(this);
```

```
UGameplayStatics::SpawnEmitterAttached
```
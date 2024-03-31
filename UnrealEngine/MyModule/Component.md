# 목차

- [Compoent 붙이기](#component-붙이기)

- [Compoent 설정접근](#component-설정접근)

## Component 붙이기


```cpp
	UPROPERTY(VisibleAnywhere, Category=Camera)
	class USpringArmComponent* springArmComp;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* tpsCamComp;
```

```cpp
	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	springArmComp->SetupAttachment(RootComponent);

    tpsCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TpsCamComp"));
	tpsCamComp->SetupAttachment(springArmComp);
```

## Compoent 설정접근

```cpp
	springArmComp->SetRelativeLocation(FVector(0, 70, 90));
	springArmComp->TargetArmLength = 400;
	springArmComp->bUsePawnControlRotation = true;

    tpsCamComp->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = true;

```
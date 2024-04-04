# 목차

- [스나이퍼 확대 조준](#스나이퍼-확대-조준)

## 스나이퍼 확대 조준

https://www.notion.so/1052e2f83f544626bfdef460c8fdee13

```cpp
UPROPERTY(EditDefaultsOnly, Category = UISniper)
TSubclassOf<class UUserWidget> mSniperUIFactory;

TObjectPtr<class UUserWidget> mpUISniper;
```

```cpp
#include <Blueprint/UserWidget.h>

void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	mpUISniper = CreateWidget(GetWorld(), mSniperUIFactory);

	ChangeToSniperGun();

}
```

```cpp
void ATPSPlayer::AimBySniper()
{
	if (!mbUsingSniper)
	{
		return;
	}

	if (!mbSniperAim)
	{
		mbSniperAim = true;
		mpUISniper->AddToViewport();
		mpTpsCamComp->SetFieldOfView(45.0f);
	}
	else
	{
		mbSniperAim = false;
		mpUISniper->RemoveFromParent();
		mpTpsCamComp->SetFieldOfView(90.0f);
	}
}
```
```cpp
	PlayerInputComponent->BindAction(TEXT("SniperZoom"),IE_Pressed,  this, &ATPSPlayer::AimBySniper);
	PlayerInputComponent->BindAction(TEXT("SniperZoom"),IE_Released, this, &ATPSPlayer::AimBySniper);
```
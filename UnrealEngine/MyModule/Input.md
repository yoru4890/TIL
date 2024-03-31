# 목차

- [Old Input](#old-input)
- [이동거리, 화면회전, 점프](#이동거리-화면회전-점프)

## Old Input

프로젝트 설정에서 Input 항목에서 이름과 키를 설정해준다.

```cpp
void ATPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATPSPlayer::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATPSPlayer::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ATPSPlayer::InputHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ATPSPlayer::InputVertical);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ATPSPlayer::InputJump);
}
```

## 이동거리, 화면회전, 점프

```cpp
void ATPSPlayer::InputHorizontal(float value)
{
	direction.Y = value;
}

void ATPSPlayer::InputVertical(float value)
{
	direction.X = value;
}

void ATPSPlayer::Move()
{
	direction = FTransform(GetControlRotation()).TransformVector(direction);

	//SetActorLocation(GetActorLocation() + direction * walkSpeed * DeltaTime);
	AddMovementInput(direction);

	direction = FVector::ZeroVector;
}
```

```cpp
void ATPSPlayer::Turn(float value)
{
	AddControllerYawInput(value);
}

void ATPSPlayer::LookUp(float value)
{
	AddControllerPitchInput(value);
}
```

```cpp
void ATPSPlayer::InputJump()
{
	Jump();
}
```


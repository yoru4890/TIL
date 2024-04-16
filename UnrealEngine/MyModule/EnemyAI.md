# 목차

- [FSM(Finite State Machine)](#fsmfinite-state-machine)

## FSM(Finite State Machine)

Actor Component or Scene Component

Scene Component는 Actor Component + transform 이다. 컴포넌트의 트랜스폼까지 구현하여 조작할거라면 Scene Component. 아니라면 Actor Component.

```cpp
EnemyFSM.h

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Idle,
	Move,
	Attack,
	Damage,
	Die,

	UNKNOWN = 255
};


...
{
    ...
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = FSM)
	EEnemyState mState = EEnemyState::Idle;
    ...
}

```

```cpp
EnemyFSM.cpp

void UEnemyFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (mState)
	{
		case EEnemyState::Idle:
			IdleState();
			break;
		case EEnemyState::Move:
			MoveState();
			break;
		case EEnemyState::Attack:
			AttackState();
			break;
		case EEnemyState::Damage:
			DamageState();
			break;
		case EEnemyState::Die:
			DieState();
			break;
		case EEnemyState::UNKNOWN:
			break;
		default:
			break;
	}

}
```

```cpp
	UPROPERTY(EditDefaultsOnly, Category = FSM)
	float mIdleDelayTime;

	float mCurrentTime;
```

```cpp
void UEnemyFSM::IdleState()
{
	mCurrentTime += GetWorld()->DeltaTimeSeconds;

	if (mCurrentTime > mIdleDelayTime)
	{
		mState = EEnemyState::Move;
		mCurrentTime = 0;
	}
}
```

```cpp
void UEnemyFSM::BeginPlay()
{
	Super::BeginPlay();

	auto actor{ UGameplayStatics::GetActorOfClass(GetWorld(), ATPSPlayer::StaticClass()) };
	mpTarget = Cast<ATPSPlayer>(actor);
	mpMe = Cast<AEnemy>(GetOwner());
}
```

```cpp
void UEnemyFSM::MoveState()
{
	FVector destination{ mpTarget->GetActorLocation() };
	FVector dir{ destination - mpMe->GetActorLocation() };
	mpMe->AddMovementInput(dir.GetSafeNormal());

	if (dir.Size() < mAttackRange)
	{
		mState = EEnemyState::Attack;
	}
}
```

```cpp
void UEnemyFSM::AttackState()
{
	mCurrentTime += GetWorld()->DeltaTimeSeconds;

	if (mCurrentTime > mAttackDelayTime)
	{
		PRINT_LOG(TEXT("Attack!!!!!"));

		mCurrentTime = 0;
	}

	float distance{ FVector::Distance(mpTarget->GetActorLocation(), mpMe->GetActorLocation()) };

	if (distance > mAttackRange)
	{
		mState = EEnemyState::Move;
	}

}
```

```cpp
// Player가 Linetrace로 때리는 상황
auto enemy = hitInfo.GetActor()->GetDefaultSubobjectByName(TEXT("FSM"));
if (enemy)
{
	auto enemyFSM = Cast<UEnemyFSM>(enemy);
	enemyFSM->OnDamageProcess();
}
```

```cpp
void UEnemyFSM::OnDamageProcess()
{
	--mHP;

	if (mHP > 0)
	{
		mState = EEnemyState::Damage;
	}
	else
	{
		mState = EEnemyState::Die;
	}
}
```
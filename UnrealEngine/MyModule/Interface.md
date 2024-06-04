# 목차

- [C++에서 블루프린트구현 인터페이스이벤트함수 호출](#c에서-블루프린트구현-인터페이스이벤트함수-호출)

## C++에서 블루프린트구현 인터페이스이벤트함수 호출

```cpp
else if (hitResult.GetActor()->GetClass()->ImplementsInterface(UHitEffectInterface::StaticClass()) && !hitActors.Contains(hitResult.GetActor()))
{
	hitActors.Add(hitResult.GetActor());
	IHitEffectInterface::Execute_ReactToEffect(hitResult.GetActor());
}
```

ImplementsInterface로 확인하고 Execute_로 실행
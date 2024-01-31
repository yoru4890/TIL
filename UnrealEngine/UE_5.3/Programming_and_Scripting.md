## 목차

<details>
<summary> Programming with C++ </summary>

- Unreal Engine Reflection System
    - Objects
    - Interfaces

</details>

## Programming with C++

### Unreal Engine Reflection System

Reflection System : 런타임 중에 타입 및 구조를 검사하고 조작할 수 있는 기능을 제공하는 시스템

- Objects
    - UCLASS 매크로

        UCLASS는 클래스를 정의할 때 사용되는 매크로, 해당 클래스에 대해 여러 특성을 지정할 수 있다.
        `GetClass()` 로 접근 가능하다. UCLASS 생성시 CDO도 만들어진다.

        CDO(Class Default Object) : 클래스의 템플릿 오브젝트, 클래스 생성시 CDO가 초기화되며 클래스의 모든 인스턴스는 이 초기 상태기반으로 생성된다. CDO는 생성된 후 변경되지 않는다. 클래스의 기본 속성과 동작을 나타낸다.

        [Class Specifiers](https://docs.unrealengine.com/5.3/en-US/gameplay-classes-in-unreal-engine/)
    
    - Properties and Function Types

        UPROPERTY() : 멤버 변수를 정의할때 사용되는 매크로, 리플렉션 시스템에 인식된다.

        UFUNCTION() : 멤버 함수를 정의할때 사용되는 매크로, 리플렉션 시스템에 인식된다.

        [Property Specifiers](https://docs.unrealengine.com/5.3/en-US/unreal-engine-uproperties/)

        [Function Specifiers](https://docs.unrealengine.com/5.3/en-US/ufunctions-in-unreal-engine/)

    - UObject 생성

        UObject는 생성자에 인자를 전달하는 방법이 지원되지 않는다. 기본생성자를 호출한다. Actor, Actor Components 인 경우에는 초기화 함수 기능을 BeginPlay() 에 넣어야한다.

        NewObject 또는 CreateDefaultSubObject를 사용해서 생성해야한다.

        NewObject는 런타임중에 사용한다.

        ```cpp

        template<class TReturnType>
        TReturnType* CreateDefaultSubobject(UObject* Outer, FName SubobjectName, bool bTransient = false) const
        {
	        UClass* ReturnType = TReturnType::StaticClass();
	        return static_cast<TReturnType*>(CreateDefaultSubobject(Outer, SubobjectName, ReturnType, ReturnType, /*bIsRequired =*/ true, bTransient));
        }

        ```

        ```cpp
        
        UObject* UObject::CreateDefaultSubobject(FName SubobjectFName, UClass* ReturnType, UClass* ClassToCreateByDefault, bool bIsRequired, bool bIsTransient)
        {
	        FObjectInitializer* CurrentInitializer = FUObjectThreadContext::Get().TopInitializer();
	        UE_CLOG(!CurrentInitializer, LogObj, Fatal, TEXT("No object initializer found during construction."));
	        UE_CLOG(CurrentInitializer->Obj != this, LogObj, Fatal, TEXT("Using incorrect object initializer."));
	        return CurrentInitializer->CreateDefaultSubobject(this, SubobjectFName, ReturnType, ClassToCreateByDefault, bIsRequired, bIsTransient);
        }

        ```
        CreateDefaultSubObject는 UObject를 상속받은 클래스에서 사용할 수 있고, FObjectInitializer를 가져와서 템플릿 함수를 통해 간접적으로 호출한다. 이것은 객체의 초기화 과정 중에만 해당 함수가 호출될 수 있도록 하기 위함이다.

        * 초기화 과정 중에만 특정 메서드가 호출되도록 하는 것은 오류방지, 안정성을 높일 수 있다.
    

        UObject는 절대로 New 연산자를 사용하면 안된다. UObject는 메모리가 알아서 관리되기에 수동으로 관리하면 메모리가 손상될 수 있다.

        https://docs.unrealengine.com/5.3/en-US/creating-objects-in-unreal-engine/

    - UObject가 제공하는 기능

        - Garbage collection

            메모리 관리 자동화

        - Reference updating

            참조변경시 자동으로 해당 참조로 업데이트, 참조된 객체가 소멸시 해당 참조를 NULL로 설정

        - Reflection

            런타임에 객체에 접근할 수 있는 기능

        - Serialization(직렬화)

            데이터를 바이트 스트림으로 변환하는 과정이다. 게임 상태 저장, 네트워크 통신, 암호화, 버전 관리 용이하다.

            `FBufferArchive`, `FMemoryReader` 와 같은 클래스를 사용하여 데이터를 직렬화하고 역직렬화한다.

            객체의 상태를 저장하고 전송하는데 사용

        - Automatic updating of default property changes
        - Automatic property initialization
        - Automatic editor integration

            문자그대로 자동으로 기본 property 변화, property 초기화, 에디터 통합이 이루어진다.

        - Type information available at runtime

            런타임에 타입 정보 사용가능

        - Network replication

            멀티플레이어 게임에서 객체의 상태를 네트워크 상에서 동기화, 여러 플레이어가 동일한 게임 상태 공유가능

        https://docs.unrealengine.com/5.3/en-US/unreal-object-handling-in-unreal-engine/

    - The Unreal Header Tool

        빌드 도구 중 하나로, 코드 생성 및 리플렉션 시스템과 관련된 작업을 한다.

        헤더 파일 처리, 자동 코드 생성, 리플렉션 매크로 처리, PCH 생성, 모듈관리, 코드 스타일 가이드 준수 확인, 빌드 자동화 지원

    - 헤더 파일 형식

        ```cpp

        #pragma once

        #include 'object.h'
        #include 'MyObject.generated.h'

        UCLASS()
        class MYPROJECT_API UMyObject : public UObject
        {
            GENERATED_BODY()
        };

        ```

        `#include 'MyObject.generated.h'`는 #include 지시문 마지막에 두어야한다.

        `MYPROJECT_API` 클래스를 다른 모듈에 노출시키기 위해 지정해야한다.

        `GENERATED_BODY()` 매크로는 실행인자를 사용하지 않고 엔진에 필요한 인프라를 지원하기 위해 클래스를 구성한다.

        UCLASS의 일부를 커스텀`#ifdefs`매크로로 래핑할 때 UHT는 `WITH_EDITOR` or `WITHEDITORONLY_DATA`매크로를 포함하지 않는 매크로를 무시한다.

    - 오브젝트 업데이트하기

        Actor, Actor Components에는 Tick 함수가 있지만, UObjects 에는 기본 업데이트 기능이 없다. 프로젝트에 필요한 경우 상속 클래스 지정자를 사용해 `FTickableGameObject` 클래스에서 상속하여 추가할 수 있다.

    - 오브젝트 파괴하기

        오브젝트가 더 이상 참조되지 않을 때 가비지 컬렉션 시스템이 자동으로 오브젝트를 파괴한다.

        - weak pointer는 오브젝트가 가비지 컬렉션되는지 여부에 영향이 없다.

        - smart pointer는 UObject와 함께 사용하기 위한 것이 아니다.

        - 가비지 컬렉션은 프레임 간에만 실행되므로 strong pointer를 weak pointer로 교체하고 게임플레이 작업 중에 한번 역참조 할 수 있다.

- Interfaces
    - 인터페이스 선언

        UCLASS 매크로 대신 UINTERFACE 매크로 사용

        UObject 대신 Uinterface 상속

        UINTERFACE 클래스는 실제 인터페이스가 아니다. 리플렉션 시스템에 대한 가시성을 위한 빈 클래스이다. 다른 클래스에서 상속되는 실제 인터페이스는 클래스 이름이 동일하고 앞에 "U" 가 "I" 로 변경된다.

        ```cpp
        #pragma once

        #include "ReactToTriggerInterface.generated.h"

        UINTERFACE(MinimalAPI, Blueprintable)
        class UReactToTriggerInterface : public UInterface
        {
            GENERATED_BODY()
        };

        class IReactToTriggerInterface
        {
            GENERATED_BODY()

        public:
            /** Add interface function declarations here */
        };
        ```
        
        U 접두사가 붙은 클래스에는 생성자나 다른 함수가 필요없지만 I 접두사가 붙은 클래스에는 모든 인터페이스 함수를 포함하며 실제로 다른 클래스에서 상속된다.

        - 인터페이스 지정자

            BlueprintType

            DependsOn=(ClassName1, ClassName2, ...)

            MinimalAPI

            https://docs.unrealengine.com/5.3/en-US/interfaces-in-unreal-engine/

    - C++에서 인터페이스 구현하기

        (사용중인 UObject 기반 클래스 이외의) 새 클래스에서 인터페이스를 사용하려면 I 접두사가 붙은 인터페이스 클래스를 상속하면 된다. 

    - 인터페이스 함수 선언하기
        - C++ 전용 인터페이스 함수

            UFUNCTION 없이 인터페이스 헤더파일에서 가상함수를 선언할 수 있다. C++ 가상함수와 같다.

        - 블루프린트 호출 가능 인터페이스 함수

            UFUNCTION 매크로와 BlueprintCallable 지정자가 필요하다. 또한 BlueprintImplementableEvent 또는 BlueprintNativeEvent 지정자를 사용해야하고 virtual이 아니여야 한다.

            - BlueprintCallable

                C++ 또는 블루프린트 호출가능

            - BlueprintImplementableEvent

                C++ 오버라이드 못함

                블루프린트클래스 오버라이드 가능

            - BlueprintNativeEvent

                함수이름은 같고 끝에 _Implementation 접미사가 붙은 함수를 오버라이드하여 C++, 블루프린트에서 구현가능

    - 클래스가 인터페이스를 구현하는지 여부를 결정하기

        예 : OriginalObject가 UReactToTriggerInterface 구현되어 있는지 확인

        ```cpp
        bool bIsImplemented = OriginalObject->GetClass()->ImplementsInterface(UReactToTriggerInterface::StaticClass()); // bIsImplemented will be true if OriginalObject implements UReactToTriggerInterface.

        bIsImplemented = OriginalObject->Implements<UReactToTriggerInterface>(); // bIsImplemented will be true if OriginalObject implements UReactToTriggerInterfacce.

        IReactToTriggerInterface* ReactingObjectA = Cast<IReactToTriggerInterface>(OriginalObject); // ReactingObject will be non-null if OriginalObject implements UReactToTriggerInterface.
        ```

        StaticClass 함수가 I가 붙은 클래스에 구현되어 있지 않은 경우 U가 붙은 클래스에서 Cast를 사용하면 컴파일 되지 않는다.


    - 다른 언리얼 타입에 대한 형변환

        한 인터페이스에서 다른 인터페이스로 또는 언리얼 타입으로 형변환을 지원한다.

        ```cpp
        IReactToTriggerInterface* ReactingObject = Cast<IReactToTriggerInterface>(OriginalObject); // ReactingObject will be non-null if the interface is implemented.

        ISomeOtherInterface* DifferentInterface = Cast<ISomeOtherInterface>(ReactingObject); // DifferentInterface will be non-null if ReactingObject is non-null and also implements ISomeOtherInterface.

        AActor* Actor = Cast<AActor>(ReactingObject); // Actor will be non-null if ReactingObject is non-null and OriginalObject is an AActor or AActor-derived class.
        ```

        인터페이스가 다 구현되어 있고 AActor의 파생 클래스 OriginalObject에 구현되어 있는 IReactToTriggerInterface가 ISomeOtherInterface로 Cast될 수 있고, AActor로 형변환 가능하다. 

    - 블루프린트 구현 가능한 클래스

        블루프린트가 인터페이스를 구현할 수 있게 하려면 `Blueprintable` metadata 지정자가 필요하다.

        블루프린트 클래스가 오버라이드하려면 `BlueprintNativeEvent` or `BlueprintImplementableEvent`가 필요하다.

        `BlueprintCallable`는 호출할 수 있지만 오버라이드할 수 없다.

        다른 모든 함수는 블루프린트에서 접근할 수 없다.
## 목차

<details>
<summary> Input </summary>

- Enhanced Input


</details>

## Input

### Enhanced Input

- Dynamic and Contextual input mappings

    런타임 시 플레이어에 대한 매핑 컨텍스트(Mapping Contexts)를 추가하고 제거할 수 있다. 현재 스테이트에 따라 특정 입력 동작 방식을 변경가능.

    예를 들어 걷는 중에 CTRL 키를 누르면 웅크리거나, 달리는 중에 CTRL 키를 누르면 슬라이딩하거나, 엎드린 상태에서 CTRL 키를 누르면 다시 일어나게 할 수 있다.

- Creating Enhanced Input Assets

    콘텐츠 브라우저에서 Add(+)에서 Input 카테고리에서 입력 에셋을 생성가능.

- Core Concepts

    4가지 핵심 주요 컨셉이 있다.

    입력 액션(Input Actions), 입력 매핑 컨텍스트(Input Mapping Contexts), 입력 모디파이어(Input Modifiers), 입력 트리거(Input Triggers)

    - Input Actions

        입력 액션은 입력 시스템과 프로젝트 코드 간의 통신 링크이다. 데이터 에셋이라는 점이 다르고 Action, Axis mapping names랑 개념적으로 같다. 상태가 변경될 떄 블루프린트 또는 C++에 입력 리스너(Input Listeners) 를 추가할 수 있다.

        입력 액션은 여러 타입이 가능하다. 부울 액션은 bool, Axis1D는 float, Axis2D는 FVector2D, Axis3D는 전부 FVector

        예를 들어, '아이템 집기' 액션은 on/off 상태로 bool 액션이 필요하고, '걷기'액션은 속력과 방향을 설명하는 2D 축이 필요할 수 있다.

        - Trigger States

            액션의 현재 상태를 나타낸다. 'Triggered' 상태를 자주 사용할 것이다. C++과 블루프린트 모두에서 특정 상태에서 바인딩할 수 있다.

            - Triggered : 액션이 트리거되었다. 모든 트리거 요구 사항 평가 완료. 예를 들어, 키를 놓으면 '키 누르고 떼기(Press and Release)'트리거가 전송.
            - Started : 트리거 평가를 시작한 이벤트 발생. 예를 들어, '두번 탭(Double tap)' 트리거를 처음 누르면 'Started'상태가 한번 호출 된다.
            - Ongoing : 트리거를 여전히 처리 중. 예를 들어, 지정된 기간이 끝나기 전에 버튼을 누르고 있으면 '길게 누르기(Press and hold)' 액션이 진행 중. 이 이벤트는 트리거에 따라 입력 값을 수신하면 평가되는 동안 틱마다 발동.
            - Completed : 트리거 평가 과정 완료
            - Canceled : 트리거링이 취소. 예를 들어, '길게 누르기' 액션이 트리거되기 전에 버튼을 놓는 경우.

        - Adding Input Listeners

            블루프린트에서 입력 액션 리스너를 추가하려면 이벤트 그래프에서 우클릭하고 입력 액션 데이터 에셋 이름을 입력하면 된다.

            C++에서 입력 액션을 바인딩가능.
            ```cpp
            void AFooBar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
            {
                UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
                // 여기에서 'ETriggerEvent' 열거형 값을 변경하여 원하는 트리거 이벤트를 바인딩할 수 있습니다.
                Input->BindAction(AimingInputAction, ETriggerEvent::Triggered, this, &AFooBar::SomeCallbackFunc);
            }

            void AFooBar::SomeCallbackFunc(const FInputActionInstance& Instance)
            {
                // 여기에서 원하는 타입의 입력 액션 값을 가져옵니다...
                FVector VectorValue = Instance.GetValue().Get<FVector>();
                FVector2D 2DAxisValue = Instance.GetValue().Get<FVector2D>();
                float FloatValue = Instance.GetValue().Get<float>(); 
                bool BoolValue = Instance.GetValue().Get<bool>();

                // 여기서 멋진 작업을 수행하세요!
            } 
            ```

    - Input Mapping Contexts

        특정 컨텍스트를 나타내는 입력 액션 컬렉션으로, 주어진 입력 액션의 트리거 규칙을 설명한다.
        각 사용자에게 매핑 컨텍스트를 동적으로 추가하거나 제거하거나 우선순위를 지정할 수 있다.

        기본 구조는 최사위 레벨에 입력 액션 목록이 있는 계층구조. 아래에는 키, 버튼, 이동 축과 같이 각 입력 액션을 트리거할 수 있는 사용자 입력 목록이 있다.

        최하위 레벨에는 각 사용자 입력에 대한 입력 트리거와 입력 모디파이어 목록이 포함되어 있다. 이를 사용하여 입력 원시 값의 필터링 방식이나 처리방식, 최상위 계층구조에서 입력 액션을 구동하기 위해 충족해야 하는 제한 사항을 결정할 수 있다.

        향상된 입력 로컬 플레이어 서브시스템(Enhanced Input Local Player Subsystem)를 통해 컨텍스트를 하나 이상 로컬 플레이어에게 적용할 수 있고, 컨텍스트의 우선순위를 지정하여 같은 입력을 사용하려는 여러 액션 간의 충돌을 해결할 수 있다.

        입력 액션 바인딩에 대한 실제 키를 구현하고 각 액션에 대한 추가 트리거 또는 모디파이어를 지정한다. 향상된 입력 서브시스템에 입력 매핑 컨텍스트를 추가할 때 우선순위를 지정할 수 있다. 같은 입력 액션에 여러 컨텍스트를 매핑한 경우, 입력 액션이 트리거되면 가장 우선순위가 높은 컨텍스트가 고려되고 다른 컨텍스트는 무시된다.

        예를 들어, 수영하고 걷고 운전하는 캐릭터에 여러 입력 매핑 컨텍스트를 줄 수 있다. 항상 동일한 입력에 매핑되는 일반 액션 하나, 다른 하나는 각각의 개별 이동 모드에 대한 것.

        차량 관련 입력 액션을 별도의 입력 매핑 컨텍스트에 배치할 수 있고, 입력 매핑 컨텍스트는 차량에 탑승할 때 추가되고 내릴 때 제거된다.

        최적화에 도움이 되고 부적절한 입력 액션이 실행되지 않도록 버그방지할 수 있다. 상호 배타적인 입력 매핑 컨텍스트를 사용하는 것도 입력 충돌 방지에 도움이 되고, 사용자 입력이 다른 입력 액션에 사용될 때 그 입력이 실수로 잘못된 액션을 트리거하지 않기 때문이다.

        블루프린트나 C++에서 매핑 컨텍스트를 추가할 수 있다.

        ```cpp
        // 매핑 컨텍스트를 헤더 파일에 프로퍼티로 노출합니다...
        UPROPERTY(EditAnywhere, Category="Input")
        TSoftObjectPtr<UInputMappingContext> InputMapping;

     
        // cpp에서...
        if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
        {
            if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                if (!InputMapping.IsNull())
                {
                    InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), Priority);
                }
            }
        }
        ```

    - Input Modifiers

        입력 모디파이어는 입력 트리거로 보내기전에 UE 에서 받는 원시 입력 값을 변경하는 pre-processors이다. 축의 순서를 변경하고, '데드존'을 구현하고 축 입력을 월드 스페이스로 변환하는 등 다양한 작업을 수행하는 입력 모디파이어가 있다.

        민감도 세팅을 적용하거나 여러 프레임에 걸쳐 입력을 스무딩하거나 플레이어 상태에 따라 입력 동작 방식을 변경하는 데 유용하다. 자체 모디파이어를 만들 때 `UPlayerInput` 클래스에 액세스하므로 뵤유한 Player Controller에 액세스하고 원하는 게임 상태를 가져올 수 있다.

        C++나 블루프린트에서 `UInputModifier`클래스의 서브클래스를 만들고 `ModifyRaw_Implementation`함수를 오버라이드하여 자신만의 입력 모디파이어를 만들 수 있다.

        Input Modifier를 부모로 두고 Blueprint Child Class를 생성하여 자신만의 입력 모디파이어를 생성할 수 있다.

        - Directional Input

            입력 모디파이어의 좋은 사용 사례는 단일 입력 액션을 사용하는 2차원 방향 입력이다.

            'WASD'키 환경설정 같은 1차원 소스의 입력을 지원한다. 올바른 입력 모디파이어를 적용하여 이러한 컨트롤 체계를 완성할 수 있다. 부정(Negate)을 사용하여 일부 키를 음수로 등록하고 입력 축 값 스위즐(Swizzle Input Axis Values)을 사용하여 일부 키를 기본 X축 대신 Y축으로 등록한다.

    - Input Triggers

        - 명시(Explicit) 유형은 입력 트리거가 성공하면 입력이 성공한다.
        - 암시(Implicit) 유형은 입력 트리거와 모든 암시 유형 입력 트리거가 성공할 때만 입력이 성공한다.
        - 블로커(Blocker) 유형은 입력 트리거가 성공하면 입력이 실패한다.

        ```
        Implicits == 0, Explicits == 0 - 값이 0이 아닌 한 항상 발동됩니다.

        Implicits == 0, Explicits > 0 - 하나 이상의 명시가 발동되었습니다.

        Implicits > 0, Explicits == 0 - 모든 암시가 발동되었습니다.

        Implicits> 0, Explicits > 0 - 모든 암시와 하나 이상의 명시가 발동되었습니다.

        Blockers - 트리거를 강제로 실패시키기 위해 모든 다른 트리거를 오버라이드합니다.
        ```

        - None은 입력 트리거의 조건이 충족되지 않아 입력 트리거가 실패.
        - Ongoing은 조건이 부분적 충족, 처리중이고 아직 성공하지 않았다.
        - Triggered는 모든 입력 조건이 충족, 입력 트리거가 성공

        base Input Trigger class or Input Trigger Timed Base를 확장해서 자신만의 입력 트리거를 생성할 수 있다.

- Player Mappable Input Config (PMI)

    입력 매핑 컨텍스트 배열을 수동으로 추가하는 대신 , 우선순위를 미리 정의하여 한 번에 추가할 수 있다.
- Debug Commands

    `showdebug enhancedinput`을 사용하면 축 매핑과 입력 액션을 표시한다.

- Injecting Input

    블루프린트, C++ 또는 콘솔 커맨드에서 함수를 호출하여 입력을 시뮬레이션할 수 있다.

- Platform Settings

    플랫폼별 매핑 컨텍스트 리디렉트(Mapping Context Redirect)를 제공한다.
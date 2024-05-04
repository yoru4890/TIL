<details>
<summary>Chapter 1 친한 친구와의 대화</summary>

모스 부호의 간단한 소개

</details>

<details>
<summary>Chapter 2 부호와 조합</summary>

모스 부호의 조합

2의 중요성

</details>

<details>
<summary>Chapter 3 점자와 이진 부호</summary>

점자에도 적용되는 2(Binary)

</details>

<details>
<summary>Chapter 4 전등을 분해해 봅시다</summary>

전압, 저항, 전류, 전력에 대해 간단한 설명

전기회로와 이진부호의 유사성

</details>

<details>
<summary>Chapter 5 가까운 거리에서 이야기하기</summary>

전신 시스템

</details>

<details>
<summary>Chapter 6 논리와 스위치</summary>

불 대수

AND, OR 논리 연산

</details>

<details>
<summary>Chapter 7 전신과 릴레이</summary>

중계기 ( 릴레이 )

</details>

<details>
<summary>Chapter 8 릴레이와 논리 게이트</summary>

AND, OR, NAND, NOR 논리 게이트

</details>

<details>
<summary>Chapter 9 우리가 사용하는 열 개의 숫자들</summary>

십진수

</details>

<details>
<summary>Chapter 10 십진수 이외의 것</summary>

여러진수, 2진수

</details>

<details>
<summary>Chapter 11 비트, 비트, 비트</summary>

생활속에 담겨있는 비트

</details>

<details>
<summary>Chapter 12 바이트와 16진수</summary>

바이트의 등장이전에는 3비트씩 8진수로 컴퓨터를 다루었었다. 이후에 8비트, 바이트가 등장하고 16진수로 사용했다. 

</details>

<details>
<summary>Chapter 13 ASCII에서 유니코드까지</summary>

7비트 ASCII, 영어 이외의 문자를 위한 유니코드

유니코드 인코딩방식이 있다.
UTF-8,16,32

</details>

<details>
<summary>Chapter 14 논리 게이트로 덧셈하기</summary>

OR, NAND 를 합친 XOR

XOR, AND를 합친 반가산기

반가산기 2개와 OR를 합친 전가산기

이진수 덧셈을 표현할 수 있다.

</details>

<details>
<summary>Chapter 15 실제로도 그럴까?</summary>

릴레이-> 진공관 -> 트랜지스터로 발전해왔다.

</details>

<details>
<summary>Chapter 16 그렇다면 뺄셈은 어떨까요?</summary>

뺄셈은 보수를 이용해서 계산한다.

오버플로우현상

</details>

<details>
<summary>Chapter 17 피드백과 플립플롭<summary>

오실레이터 : 0과 1이 계속 바뀌는 회로

피드백 : 다른 쪽에 영향이 가는 형태

플립플롭 : 두 스위치가 있을때, 두개 열려있는 상태가 그 전상태를 기억해서 전구가 밝혀질때와 꺼질때가 있는 회로
정보를 기억해 둘 수 있다.

</details>

<details>
<summary>Chapter 18 시계를 만들어 봅시다<summary>

이진수4자리를 활용해 십진수표현하는 BCD
플립플롯을 활용해 0~9, 0~5 표현, 24시 12시 두가지 경우의 변화차이
디코더와 BCD를 결합한 BCD디코더
숫자의형태를 표현하는 다이오드 매트릭스

</details>

<details>
<summary>Chapter 19 메모리를 만들어 봅시다<summary>

플립플롭을 활요해서 1비트를 저장하는 메모리를 만들 수 있다.

8개를 이어 붙여 8비트, 1바이트 메모리를 만들 수 있다.

플립플롭, 디코더, 선택기를 이용해 읽기/쓰기 메모리, RAM을 만들 수 있다.

8 x 1 RAM 을 연결해서 8 x 8 RAM 을 만들 수 있다.

16 x 8 메모리에서 삼상 버퍼로 16개 바이트 중에 한 바이트를 선택하는 데 사용된다.

16개씩 계속 이어붙여 65536 x 8 RAM을 만들 수 있다.

2^16, 메모리 주소가 16비트로 구성되어서 정규적이고 읽기 쉬운 숫자이다.


</details>

<details>
<summary>Chapter 20 연산을 자동화시키기<summary>

여러 숫자를 더해보자 

누산기에다가 RAM을 추가 , 카운터 추가 -> 자동화된 누산기

제어 신호 필요 오실레이터와 플립플롭으로 구현

여러 바이트를 저장하는 방식 빅 엔디언, 리틀 엔디언

명령어 코드를 메모리의 넣어서 코드와 데이터로 구성시킨다

명령어 래치, 삼상 버퍼 : 명령어 코드

하드웨어 : 모든회로

소프트웨어 : 메모리에 저장된 명령어 코드, 데이터

</details>

<details>
<summary>Chapter 21 산술 논리 장치<summary>

CPU의 중요한 구성요소 ALU(산술 논리 장치)

자리올림 플래그, 제로 플래그, 부호 플래그


</details>

<details>
<summary>Chapter 22 레지스터와 버스<summary>

7개의 8비트 래치 -> 레지스터(CPU 명령 직접제어) : ALU 처리 바이트 저장

A(누산 레지스터) B C D E H(high) L(low)

간접 주소 지정 방식(Indirect Addressing) : 두 개 이상의 메모리 주소를 이용해서 간접적으로 접근

니모닉 (mnemonics) : 하나의 기억법 , 길게 풀어 쓴 동작의 약어 (Ex. ADD, XRA)

어셈블리어 명령 (Ex. ADD E, XRA M)

10FFFSSS : FFF(산술논리기능), SSS(어떤 레지스터, 메모리)


</details>
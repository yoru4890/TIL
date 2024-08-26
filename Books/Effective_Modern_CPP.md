- Chapter 1 형식 연역 (Type Deduction) (타입 추론)

규칙 두가지
- auto
- decltype

<details>
<summary>항목 1 : 템플릿 형식 연역 규칙을 숙지하라</summary>

auto는 템플릿에 대한 형식 연역 기반 작품

```cpp
template<typename T>
void f(ParamType param);
f(expr);
```

- 경우 1 : ParamType 이 포인터 또는 참조 형식이지만 보편 참조는 아님

```cpp
template<typename T>
void f(T& param);
int x = 27;
const int cx = x;
const int& rx = x;

f(x); // T : int, param : int&
f(cx); // T : const int, param : int&
f(rx); // T : const int, param : int&
```

```cpp
template<typename T>
void f(const T& param);
int x = 27;
const int cx = x;
const int& rx = x;

f(x); // T : int, param : int&
f(cx); // T : int, param : int&
f(rx); // T : int, param : int&
```

```cpp
template<typename T>
void f(T* param);
int x = 27;
const int* px = &x;

f(&x); // T : int, param : int*
f(px); // T : const int, param : const int*
```

경우 2 : ParamType이 보편참조임

```cpp
template<typename T>
void f(T&& param);
int x = 27;
const int cx = x;
const int& rx = x;

f(x); // T : int&, param : int&
f(cx); // T : const int&, param : int&
f(rx); // T : const int&, param : int&
f(27); // T : int, param : int&&
```

경우 3 : ParamType이 포인터도 아니고 참조도 아님

```cpp
template<typename T>
void f(T param);
int x = 27;
const int cx = x;
const int& rx = x;

f(x); // T : int, param : int
f(cx); // T : int, param : int
f(rx); // T : int, param : int

const char* const ptr = "string";
f(ptr) // const char*

```
배열 인수
```cpp
template<typename T>
void f(T& param);
f(name) // name은 배열

template<typename T, std::size_t N>
constexpr std::size_t arraySize ( T(&)[N]) noexcept
{
    return N;
}

```
함수 인수
```cpp
void someFunc(int, double);

template<typename T>
void f1(T param);

template<typename T>
void f2(T& param);
f1(someFunc); // void(*)(int, double)
f2(someFunc); // void(&)(int, double)

```

- 템플릿 형식 연역 도중에 참조 형식의 인수들은 비참조로 취급, 참조성 무시

- 보편 참조 매개변수에 대해 lvalue들은 특별하게 취급된다

- 값 전달 방식의 매개변수에 대한 형식 연역 과정에서 const 또는 volatile 인수는 비 const, 비 volatile 인수로 취급

- 템플릿 형식 연역과정에서 배열이나 함수 이름에 해당하는 인수는 포인터로 붕괴한다(decay). 단, 그런 인수가 참조를 초기화하는데 쓰이는 경우에는 포인터로 붕괴하지 않는다. 

</details>

<details>
<summary>항목 2 : auto의 형식 연역 규칙을 숙지하라</summary>

템플릿 타입추론과 동일, 하지만 유니폼 초기화에서 달라진다.

```cpp
int x3 = {27}
int x4{27} // 2014에서 int로 되게 고쳐짐
```
템플릿 타입추론과의 차이점은 `std::initializer_list`


함수 반환타입이나 람다 매개변수에 쓰인 auto는 템플릿 타입추론 규칙이 적용

</details>

<details>
<summary>항목 3 : decltype의 작동 방식을 숙지하라</summary>

`decltype(expresion)`

함수 반환타입이 매개변수 타입들에 의존하는 함수 템플릿을 선언할 때 주로 쓰임.

```cpp
template<typename Container, typename Index>
decltype(auto) authAndAccess(Container&& c, Index i)
{
    authenticateUser();
    return std::forward<Container>(c)[i];
}
```

- decltype(auto)인 이유 : index타입인 경우 왼값 참조 타입이여야하는데 auto인경우 그냥 타입으로 된다.
- std::forward<Container> : 오른값도 받아들일 수 있도록 했다.

괄호 하나 차이로 바뀔 수 있으므로 decltype(auto)는 주의깊게 사용하자

```cpp
decltype(auto) f1()
{
    int x = 0;
    return x;   // int
}

decltype(auto) f2()
{
    int x = 0;
    return (x); // int&
}
```

</details>

<details>
<summary>항목 4 : 연역된 형식을 파악하는 방법을 알아두라</summary>

컴파일러가 추론하는 타입을 IDE를 통해 파악하지만, 정확하지 않을 수 있기에 C++의 타입추론규칙들을 제대로 이해하자.


</details>

- Chapter 2 auto

<details>
<summary>항목 5 : 명시적 형식 선언보다는 auto를 선호하라</summary>

명시적으로 표현시 불일치가 일어 날 수 있는데(정확하게 알지 못하기 때문에),
auto는 형식 불일치가 발생하는 경우가 거의 없다. 타입추론에 대해 정확하게 알고 있다면 auto를 쓰면 리펙터링에도 편하다. 가독성이 좋아지고 타자도 적어진다.

단 정확하게 타입은 알고 쓰자.


</details>

<details>
<summary>항목 6 : auto가 원치 않은 형식으로 연역될 때에는 명시적 형식의 초기치를 사용하라</summary>

```cpp
double f();

auto a = static_cast<float>(f());
```
auto를 사용할때 대리자(proxy) 형식때문에 타입이 잘못 추론된다.

static_cast<>로 직접 타입을 바꿔주자.

</details>

</details>

<details>
<summary>항목 7 : 객체 생성시 괄호(())와 중괄호({})를 구분하라</summary>

중괄호 초기화시에는 std::initializer_list 를 생각해야한다.

예시 std::vector에서 괄호와 중괄호 선택의미가 차이가 있다.

템플릿안에서도 괄호와 중괄호의 차이를 유의하자.

</details>

<details>
<summary>항목 8 : 0 과 NULL보다 nullptr를 선호하라</summary>

pointer에 대한 건 nullptr로 확실하게 표현

정수 형식과 포인터 형식에 대한 오버로딩 조심


</details>

<details>
<summary>항목 9 : typedef보다 별칭 선언을 선호하라</summary>

typdef보다는 using을 쓰자

템플릿에서 차이가 생긴다.

C++14에서 별칭 템플릿 제공 (type trait)


</details>

<details>
<summary>항목 10 : 범위 없는 enum보다 범위 있는 enum을 선호하라</summary>

범위 있는 enum을 사용하자.

기본 바탕형식이 있다.

전방선언 가능 ( 범위 없는 enum은 바탕형식 필요)

</details>

<details>
<summary>항목 11 : 정의되지 않은 비공개 함수보다 삭제된 함수를 선호하라</summary>

= delete를 붙여서 함수를 삭제할수 있다.

비멤버함수와 템플릿 인스턴스를 비롯한 어떤 함수도 삭제할 수 있다.

</details>

<details>
<summary>항목 12 : 재정의 함수들을 override로 선언하라</summary>

재정의 함수는 override로 선언

멤버함수 참조 한정사를 이용하면 멤버 함수가 호출되는 객체의 왼값버전과 오른값버전을 다른 방식으로 처리가능

</details>

<details>
<summary>항목 13 : iterator 보다 const_iterator를 선호하라</summary>

iterator보다 const_iterator를 선호하라

최대한 일반적인 코드에서는 begin, end, rbegin 등의 비멤버 버전들을 해당 멤버 함수들보다 선호하라.

</details>

<details>
<summary>항목 14 : 예외를 방출하지 않을 함수는 noexcept로 선언하라</summary>

noexcept 함수는 비noexcept함수보다 최적화의 여지가 크다.

noexcept는 이동 연산들과 swap, 메모리 해제 함수들, 그리고 소멸자들에 특히나 유용하다.

대부분의 함수는 noexcept가 아니라 예외에 중립적이다.

</details>

<details>
<summary>항목 15 : 가능하면 항상 constexpr을 사용하라</summary>

constexpr 객체는 const이며, 컴파일 도중에 알려지는 값들로 초기화된다.

constexpr 함수는 그 값이 컴파일 도중에 알려지는 인수들로 호출하는 경우에는 컴파일 시점 결과를 산출한다.

constexpr 객체나 함수는 비constexpr 객체나 함수보다 광범위한 문맥에서 사용할 수 있다.

constexpr은 객체나 함수의 인터페이스의 일부이다.

</details>

<details>
<summary>항목 16 : const 멤버 함수를 스레드에 안전하게 작성하라</summary>

동시적 문맥에서 쓰이지 않을 것이 확실한 경우가 아니라면, const 멤버 함수는 스레드에 안전하게 작성하라.

std::atomic 변수는 뮤텍스에 비해 성능상의 이점이 있지만, 하나의 변수 또는 메모리 장소를 다룰 때에만 적합하다.

</details>

<details>
<summary>항목 17 : 특수 멤버 함수들의 자동 작성 조건을 숙지하라</summary>

컴파일러가 알아서 만드는 멤버 함수들, 기본 생성자와 소멸자, 복사 연산들, 이동 연산들을 가리켜 특수 멤버 함수라고 한다.

이동 연산들은 이동 연산들이나 복사 연산들, 소멸자가 명시적으로 선언되어 있지 않은 클래스에 대해서 자동으로 작성된다.

복사 생성자는 복사 생성자가 명시적으로 선언되어 있지 않은 클래스에 대해성만 자동으로 작성, 만일 이동연산이 하나라도 선언되어 있으면 삭제.

복사 대입 연산자는 명시적으로 선언되어 있지 않은 클래스에 대해서만 자동으로 작성, 만일 이동연산이 하나라도 선언되어 있으면 삭제.

소멸자가 명시적으로 선언된 클래스에서 복사 연산들이 자동 작성되는 기능은 비권장이다.

멤버 함수 템플릿 때문에 특수 멤버 함수의 자동 작성이 금지되는 경우는 전혀 없다.

</details>

<details>
<summary>항목 18 : 소유권 독점 자원의 관리에는 std::unique_ptr를 사용하라</summary>

std::unique_ptr는 독점 소유권 의미론을 가진 자원의  관리를 위한, 작고 빠른 이동 전용 똑똑한 포인터이다.

기본적으로 자원 파괴는 delete를 통해 일어나나, 커스텀 삭제자를 지정할 수도 있다. 상태 있는 삭제자나 함수 포인터를 사용하면 std::unique_ptr 객체의 크기가 커진다.

std::unique_ptr를 std::shared_ptr로 손쉽게 변환할 수 있다.

</details>

<details>
<summary>항목 19 : 소유권 공유 자원의 관리에는 std::shared_ptr를 사용하라</summary>

std::shared_ptr는 임의의 공유 자원의 수명을 편리하게 (쓰레기 수거에 맡길 때만큼이나) 관리할 수 있는 수단을 제공한다.

대체로 std::shared_ptr 객체는 그 크기가 std::unique_ptr 객체의 두 배이며, 제어 블록에 관련된 추가 부담을 유발하며, 원자적 참조 횟수 조작을 요구한다.

자원은 기본적으로 delete를 통해 파괴되나, 커스텀 삭제자도 지원된다. 삭제자의 형식은 std::shared_ptr의 형식에 아무런 영향도 미치지 않는다.

생 포인터 형식의 변수로부터 std::shared_ptr를 생성하는 일은 피해야 한다.

</details>

<details>
<summary>항목 20 : std::shared_ptr처럼 작동하되 대상을 잃을 수도 있는 포인터가 필요하면 std::weak_ptr를 사용하라</summary>

std::shared_ptr처럼 작동하되 대상을 잃을 수도 있는 포인터가 필요하면 std::weak_ptr를 사용하라

std::weak_ptr의 잠재적인 용도로는 캐싱, 관찰자 목록, 그리고 std::shared_ptr 순환 고리방지가 있다.

</details>


<details>
<summary>항목 21 : new를 직접 사용하는 것보다 std::make_unique와 std::make_shared를 선호하라</summary>

new를 사용하는 것보다 make 함수를 사용하면 소스코드 중복이 없어지고 예외 안전성도 올라간다.

make함수를 사용할 수 없는 경우 커스텀 삭제자를 지정하거나 중괄호 초기치를 전달해야 할 수 있다.

std::shared_ptr에 대해서는 make 함수가 부적합한 경우가 더 있는데, 커스텀 메모리 관리 기능을 가진 클래스를 다루어야 하는 경우, 메모리가 넉넉하지 않은 시스템에서 큭 객체를 자주 다루고 std::weak_ptr들이 해당 std::shared_ptr들보다 더 오래 살아남는 경우.

</details>

<details>
<summary>항목 22 : Pimpl 관용구를 사용할 때에는 특수 멤버 함수들을 구현 파일에서 정의하라</summary>

Pimpl 관용구는 클래스 구현과 클래스 클라이언트 사이의 컴파일 의존성을 줄여서 빌드 시간을 감소.

std::unique_ptr 형식의 pImpl 포인터를 사용할 때에는 특수 멤버 함수들을 클래스 헤더에 선언하고 구현 파일에서 구현해야한다. 컴파일러가 기본으로 작성하는 함수 구현들이 사용하기에 적합한 경우에도 그렇게 해야한다.

std::unique_ptr에 적용될 뿐, std::shared_ptr에는 적용되지 않는다.

</details>

<details>
<summary>항목 23 : std::move와 std::forward를 숙지하라</summary>

std::move는 오른값으로의 무조건 캐스팅 수행. std::move 자체는 아무것도 이동하지 않는다.

std::forward는 주어진 인수가 오른값에 묶인 경우에만 그것을 오른값으로 캐스팅한다.

std::move와 std::forward 둘 다, 실행시점에서는 아무 일도 하지 않는다.

</details>

<details>
<summary>항목 24 : 보편 참조와 오른값 참조를 구별하라</summary>

함수 템플릿 매개변수의 형식이 T&& 형태이고 T가 연역된다면, 또는 객체를 auto&&로 선언한다면, 그 매개변수나 객체는 보편 참조이다.

형식 선언의 형태가 정확히 형식&&가 아니면, 또는 형식 연역이 일어나지 않으면 형식&&는 오른값 참조를 뜻한다.

오른값으로 초기화되는 보편 참조는 오른값 참조에 해당한다. 왼값으로 초기화되는 보편 참조는 왼값 참조에 해당한다.


</details>

<details>
<summary>항목 25 : 오른값 참조에는 std::move를, 보편 참조에는 std::forward를 사용하라</summary>

오른값 참조나 보편 참조가 마지막으로 쓰이는 지점에서, 오른값 참조에는 std::move를 보편 참조에는 std::forward를 적용하라.

결과를 값 전달 방식으로 돌려주는 함수가 오른값 참조나 보편 참조를 돌려줄때에도 각각 std::move나 std::forward를 적용하라.

반환값 최적화의 대상이 될 수 있는 지역 객체에는 절대로 std::move나 std::forward를 적용하지 말아야 한다.

</details>

<details>
<summary>항목 26 : 보편 참조에 대한 중복적재를 피하라</summary>

보편 참조에 대한 오버로딩은 거의 항상 보편 참조 오버로딩버전이 예상보다 자주 호출되는 상황으로 이어진다.

완벽 전달 생성자들은 특히나 문제가 많다. 그런 생성자는 대체로 비const 왼값에 대한 복사 생성자보다 더 나은 부합이며, 기반 클래스 복사 및 이동 생성자들에 대한 파생 클래스의 호출들을 가로챌 수 있기 때문이다.

</details>
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
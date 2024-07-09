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

</details>
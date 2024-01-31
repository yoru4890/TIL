[std::accumulate](https://en.cppreference.com/w/cpp/algorithm/accumulate)
================

- `<numeric>` 안에 있다.

- 크게 두가지의 형태를 가지고 있다.

    1. T accumulate( InputIt 처음, InputIt 마지막, T 타입 요소);

    2. T accumulate( InputIt 처음, InputIt 마지막, T 타입 요소, 이항연산);


```cpp

template<class InputIt, class T>
constexpr T accumulate(InputIt first, InputIt last, T init)
{
    for (; first != last; ++first)
        init = std::move(init) + *first; 
 
    return init;
}
```
init에 계속 더한값을 리턴해준다.


```cpp

template<class InputIt, class T, class BinaryOperation>
constexpr T accumulate(InputIt first, InputIt last, T init, BinaryOperation op)
{
    for (; first != last; ++first)
        init = op(std::move(init), *first);
 
    return init;
}
```

init에 계속 이항연산한 값을 리턴해준다.

번외)
- `InputIt` 은 입력반복자로 읽기전용이다. 
- `constexpr` 은 컴파일 타임에 결정한다. `const`와는 차이가 있으므로 조심하자. 

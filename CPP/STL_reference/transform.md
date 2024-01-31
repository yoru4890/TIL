[std::transform](https://en.cppreference.com/w/cpp/algorithm/transform)
============================

- `<algorithm>` 안에 있다.

- 크게 2 가지 형태가 있고 execution policy가 추가될 수 있다.

    1. OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation Unary_op);
    
    2. ForwardIt2 transform(ExcutionPolicy&& policy, ForwardIt1 first1, ForwardIt1 last1, ForwardIt2, d_first, UnaryOperation unary_op);

    3. OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op);

    4. ForwardIt3 transform(ExcutionPolicy&& policy, ForwardIt1 first1, ForwardIt1 last1, ForwardIt2, first2, ForwardIt3 d_first, BinaryOperation binary_op);

```cpp
template<class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform(InputIt first1, InputIt last1,
                   OutputIt d_first, UnaryOperation unary_op)
{
    while (first1 != last1)
        *d_first++ = unary_op(*first1++);
 
    return d_first;
}
```
first1부터 last1까지의 단항계산을 OutputIt d_first부터 시작해서 각각 대입한다.

```cpp
template<class InputIt1, class InputIt2, 
         class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1,
                   InputIt2 first2, OutputIt d_first,
                   BinaryOperation binary_op)
{
    while (first1 != last1)
        *d_first++ = binary_op(*first1++, *first2++);
 
    return d_first;
}

```

first1부터 last1까지 first2부터 시작해서 이항계산한 결과를 OutputIt d_first부터 시작해서 각각 대입한다.

번외)

- ExcutionPolicy&& policy : std::execution::sequenced_policy(순차), parallel_policy(병렬), parallel_unsequenced_policy(병렬 비순차), unsequenced_policy(비순차)
    - `<execution>`이 필요하다.

- 이항 연산 크기가 다른경우 작은 사이즈를 기준으로 먼저 종료한다.
[std::pow](https://en.cppreference.com/w/cpp/numeric/math/pow)
================

- `<cmath>` 안에 있다.
- std::pow(float base, float exp);
- std::pow(double base, double exp);
- std::pow(long double base, long double exp);

예외의 경우를 제외하고 base^exp를 반환한다.

예외사항
-----------

base 가 유한음수, exp 가 유한 non-integer인 경우 : domain error, range error

base == 0, exp == 0 인 경우 : domain error

base == 0, exp < 0 인 경우 : domain error or pole error 

<IEEE floating-point arithmetic (IEC 60559)>
- pow(+0,exp) , exp 음의 홀수 : return +∞, FE_DIVBYZERO
- pow(-0,exp) , exp 음의 홀수 : return -∞, FE_DIVBYZERO
- pow(±0,exp) , exp 음수, 유한, 짝수 or non-integer인 경우 : return +∞, FE_DIVBYZERO
- pow(±0, -∞) : return +∞ , FE_DIVBYZERO
- pow(+0, exp) , exp 양의 홀수 : return +0
- pow(-0, exp), exp 양의 홀수 : return -0
- pow(±0, exp), exp 양의 non-integer or 양의 짝수 : return +0
- pow(-1, ±∞) : return 1
- pow(+1, exp) : return 1 exp가 NaN이여도 1을 반환
- pow(base, ±0) return 1 base가 NaN이여도 1을 반환
- pow(base, exp), base가 유한 and 음수 and exp 유한 and non-integer : return NaN, FE_INVALID
- pow(base, -∞), |base|<1 : return +∞ 
- pow(base, -∞), |base|>1 : return +0
- pow(base, +∞), |base|<1 : return +0
- pow(base, +∞), |base|>1 : return +∞
- pow(-∞, exp), exp가 음의 홀수 : return -0
- pow(-∞, exp), exp가 음의 짝수 or 음의 non-integer : return +0
- pow(-∞, exp), exp가 양의 홀수 : return -∞
- pow(-∞, exp), exp가 양의 짝수 or 양의 non-integer : return +∞
- pow(+∞, exp), exp가 음수 : return +0
- pow(+∞, exp), exp가 양수 : return +∞
- 위에 지정된 경우를 제외하고 인수가 NaN이면 NaN이 반환된다.
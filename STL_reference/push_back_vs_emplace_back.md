push_back 과 emplace_back 의 큰 차이점은 복사유무이다.

push_back은 복사가 이루어지고 emplace_back 은 forward를 사용한다.

forward는 remove_referense로 참조를 없애고 각각 좌측값, 우측값 참조형태로 매개변수를 받고 반환값으로 우측값 참조를 돌려준다.

우측값 참조, && 로 move semantics를 지원한다

결론적으로 push_back은 객체의 복사본이 생성되어 추가되고 emplace_back은 우측값 참조로 복사대신에 직접 객체를 생성되어 추가된다.

emplace_back은 vector, deque, list, forward_list에 있고 emplace는 set, multiset, map, multimap에 있다.
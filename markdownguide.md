[마크다운 가이드 사이트](https://www.markdownguide.org/basic-syntax/)

1.마크다운 사용법
=================

1.1. 헤더
---------

- 큰제목 : 문서 제목

        Heading level 1
        ===============
  
  Heading level 1
  ===============

- 작은제목 : 문서 부제목

      Heading level 2
      ----------------

- 글머리 1~6까지만 지원  
    
        # Heading level 1
        ## Heading level 2
        ### Heading level 3
        #### Heading level 4
        ##### Heading level 5
        ###### Heading level 6

# Heading level 1
## Heading level 2
### Heading level 3
#### Heading level 4
##### Heading level 5
###### Heading level 6

1.2. 글씨체
-----------

- 굵은 글꼴(Bold)

            I just love**bold text**.

            I just love __bold text__.

            Love**is**bold

I just love**bold text**.

I just love __bold text__.

Love**is**bold  


- 기울임체 (Italic)
  
        Italicized text is the *cat's meow*.

        Italicized text is the _cat's meow_.

        A*cat*meow

Italicized text is the *cat's meow*.

Italicized text is the _cat's meow_.

A*cat*meow  


- 굵은 글꼴 기울임체 (Bold and Italic)

        This text is ***really important***.

        this text is ___really important___.

        this text is __*really important*__.

        this text is **_really important_**.

        this is really***very important text.

This text is ***really important***.

this text is ___really important___.

this text is __*really important*__.

this text is **_really important_**.

this is really***very important text.


1.3. BlockQuote
----------------

'>' 블럭인용문자를 이용한다.

    > Dorothy followed her thorugh many of the beautiful rooms in her castle.

> Dorothy followed her thorugh many of the beautiful rooms in her castle.  

    > Dorothy followed her through many of the beautiful rooms in her castle.
    >
    > The witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.

> Dorothy followed her through many of the beautiful rooms in her castle.
>
> The witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.  


    > Dorothy followed her thorugh many of the beautiful rooms in her castle.
    >
    >> The witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.

> Dorothy followed her thorugh many of the beautiful rooms in her castle.
>
>> The witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood.


    > #### The quarterly results look great!
    >
    > - Revenue was off the chart.
    > - Profits were higher than ever.
    >
    >  *Everything* is going according to **plan**.

> #### The quarterly results look great!
>
> - Revenue was off the chart.
> - Profits were higher than ever.
>
>  *Everything* is going according to **plan**.

1.4. 목록
---------

- 순서있는 목록(번호)
순서있는 목록은 숫자와 점을 사용한다.

        1. First item
        2. Second item
        3. Third item
        4. Fourth item

1. First item
2. Second item
3. Third item
4. Fourth item

목록 안에 목록도 만들 수 있다.  

        1. First item
        2. Second item
        3. Third item
            1. Indented item
            2. Indented item
        4. Fourth item

1. First item
2. Second item
3. Third item
    1. Indented item
    2. Indented item
4. Fourth item

- 순서없는 목록

            - First item
            - Second item
            - Third item
            - Fourth item

- First item
- Second item
- Third item
- Fourth item


        - First item
        - Second item
        - Third item
            - Indented item
            - Indented item
        - Fourth item

- First item
- Second item
- Third item
    - Indented item
    - Indented item
- Fourth item

숫자가 앞이면 "\"를 붙여준다.

    - 1968\. A great year!
    - I think 1969 was second best.

- 1968\. A great year!
- I think 1969 was second best.

1.5. 코드
----------

4개의 공백 또는 하나의 탭으로 들여쓰기를 만나면 변환되기 시작하여 들여쓰지 않은 행을 만날때까지 변환이 게속된다.
목록 안에 있으면 8개의 공백 또는 2개의 탭이 필요하다.

    1. Open the file.
    2. Find the following code block on line 21:

            <html>
              <head>
                <title>Test</title>
              </head>

    3. Update the title to match the name of your website.

1. Open the file.
2. Find the following code block on line 21:

        <html>
          <head>
            <title>Test</title>
          </head>

3. Update the title to match the name of your website.

따옴표를 사용하면 부분적으로 코드블럭을 만들수 있다.

    At the command prompt, type `nano`.

At the command prompt, type `nano`.

코드로 나타내려고 하는데 이중 택틱을 사용하면 된다.

        ``Use `code` in your Markdown file.``

``Use `code` in your Markdown file.``

1.6. 수평선
-----------

***

---

_________________


1.7. 링크
-----------

    My favorite search engine is [Duck Duck Go](https://duckduckgo.com).

My favorite search engine is [Duck Duck Go](https://duckduckgo.com).
   

선택적으로 링크 제목을 추가할 수 있습니다. 링크 위에 마우스를 가져가면 툴팁으로 나타납니다.

    My favorite search engine is [Duck Duck Go](https://duckduckgo.com "The best search engine for privacy").

My favorite search engine is [Duck Duck Go](https://duckduckgo.com "The best search engine for privacy").

   
꺽쇠괄호를 사용하면 URL 혹은 이메일주소를 링크할수있다.

    <https://www.markdownguide.org>
    
    <fake@example.com>

<https://www.markdownguide.org>

<fake@example.com>


1.8. 이미지
------------

이미지를 추가하려면 느낌표를 추가하고 괄호 안에 대체 텍스트를 추가한다.

    ![임시](https://github.com/yoru4890/TIL/assets/137769028/058b77af-3e19-4469-9ba7-8c87a8c9a987)
    ![임시](https://github.com/yoru4890/TIL/assets/137769028/058b77af-3e19-4469-9ba7-8c87a8c9a987 "Optional title")

![임시](https://github.com/yoru4890/TIL/assets/137769028/058b77af-3e19-4469-9ba7-8c87a8c9a987)
![임시](https://github.com/yoru4890/TIL/assets/137769028/058b77af-3e19-4469-9ba7-8c87a8c9a987 "Optional title")

1.9. 줄바꿈
-----------

줄을 바꾸고 싶으면 문장 끝 공백을 2칸이상 해야한다.

    This is the first line.__
    And this is the second line.

This is the first line.  
And this is the second line.

1.10. 표 만들기
-------------

1. 줄의 양 끝의`|`는 생략 가능하다.
2. 헤더 셀을 구분하는 `---`는 반드시 넣어준다.
3. `---`에 `:`을 배치하여 해당 칼럼의 정렬이 가능하다.
   - `:---`:왼쪽 정렬
   - `:---:`:가운데 정렬
   - `---:`:오른쪽 정렬
  
###예시
```
| 값 | 의미 | 기본값 |
|---|:---:|---:|
| `static` | 유형(기준) 없음 / 배치 불가능 | `static` |
| `relative` | 요소 자신을 기준으로 배치 |  |
| `absolute` | 위치 상 부모(조상)요소를 기준으로 배치 |  |
| `fixed` | 브라우저 창을 기준으로 배치 |  |

or

 값 | 의미 | 기본값 
---|:---:|---:
 `static` | 유형(기준) 없음 / 배치 불가능 | `static` 
 `relative` | 요소 자신을 기준으로 배치 |  
 `absolute` | 위치 상 부모(조상)요소를 기준으로 배치 |  
 `fixed` | 브라우저 창을 기준으로 배치 |
```
| 값 | 의미 | 기본값 |
|---|:---:|---:|
| `static` | 유형(기준) 없음 / 배치 불가능 | `static` |
| `relative` | 요소 자신을 기준으로 배치 |  |
| `absolute` | 위치 상 부모(조상)요소를 기준으로 배치 |  |
| `fixed` | 브라우저 창을 기준으로 배치 |  |

1.11. 윗첨자와 아랫첨자
--------------

- 윗첨자는 `<sup>string</sup>` 으로 표현
- 아랫첨자는 `<sub>string</sub>` 으로 표현

string<sup>string</sup><sub>string</sub>

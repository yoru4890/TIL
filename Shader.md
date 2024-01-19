### Vertex Shader

```
for ( auto v : vertax)
{
    vertex_shader();
}
```

### Fragment Shader

```
for ( auto p : pixels)
{
    fragment_shader();
}
```

`+` : 밝아지는 경향

`*` : 어두워지는 경향

삼각함수를 이용해서 다양한 표현가능

-----------------------------

### Dissolve

조금씩 사라지는것처럼 보이는 효과

noise패턴을 활용해서 가능, (0~1)까지 랜덤으로 이루어져있는 2차배열패턴

외곽선만들기 : 기존패턴에서 두께만큼 차이를 낸 sub 패턴을 만들고 (기존패턴 - sub패턴)으로 만든다.

HDR+BLOOM 으로 뽀샤시효과

----------------------------
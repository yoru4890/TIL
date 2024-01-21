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

### Outline

알파값을 한쪽방향으로 움직여서 원래값에서 빼주면 한쪽방향에 외곽선으로 알파값이 남아진다.
그렇게 상하좌우를 해주고 그다음에는 대각선 방향도 해준다. 총 8방향

### Flag

surface shader

람베르트 반사율

삼각함수를 이용해서 엇비슷하게 만들수 있으나 실제와는 좀 다르다.

노이즈 패턴을 이용해서 랜덤섬을 더해준다.

uv좌표에서 깃발대 시작부분은 0 끝부분은 1을 곱해준다.

### Cartoon

Rim Light, Specular, Two Tone Shading

Blinn-Phong
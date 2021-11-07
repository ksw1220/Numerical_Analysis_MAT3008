# Get Machine Accuarcy

## 실행방법
* 1개의 main.c 와 1개의 header.h, 그리고 4개의 c파일로 구성되었습니다.
* gcc main.c macharFloat.c macharDouble.c getepsFloat.c getepsDouble.c
* 위 명령어를 통해 실행 파일 a.out를 생성한 뒤, a.out를 실행하여 결과 값을 볼 수 있습니다.

## method 
1. Method1
    - Method1 에 대해서 macharFloat.c, macharDouble.c 두 개의 파일을 만들었습니다.
    - machar 루틴을 사용하여 파라미터에 변수를 넘겨주었고, 루틴을 거쳐 파라미터 변수들에 값을 바꿉니다.
    - machar 루틴을 거친 값 중 eps를 출력하였습니다.
    - double의 경우 float로 선언된 변수들을 double로 선언하여 같은 방법을 사용하였습니다.

2. Method2
    - Method2 에 대해서 getepsFloat.c, getepsDouble.c 두 개의 파일을 만들었습니다.
    - get_eps_float() 함수를 만들어 1 + 2^(-it) = 1 의 조건을 만족하는 it의 값을 찾고, 그 직전의 값을 eps에 저장하였습니다.
    - 함수를 통해 바뀐 eps값을 출력합니다.
    - double의 경우는 float로 선언된 변수들을 double로 선언하여 같은 방법을 사용하였습니다.

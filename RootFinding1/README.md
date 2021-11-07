# Root Finding1

## 실행방법
- csv폴더가 존재하지 않으면 지정된 경로에 csv파일을 생성할 수 없기 때문에 csv라는 이름의 폴더가 존재하지 않으면 csv폴더를 추가해야 합니다.
- gcc main.c zbrak.c bessj0.c bessj1.c rtbis.c rtflsp.c rtsec.c rtnewt.c rtsafe.c muller.c functions.c nrutil.c
- 위 명령어를 실행한 후 ./a.out을 실행합니다.
- method 마다의 root finding 과정이 csv폴더 안에 "[method_name].csv"파일로 저장됩니다.

## 코드 설명
- main.c 에서 모든 함수의 실행이 이루어집니다.
- zbrak을 구간을 100개로 나누어 실행하였습니다.
- problem2
    - problem2의 수식을 정리하면 $$(x-e^{-x}))^2=0$$의 꼴로 나타낼 수 있으며 $$x-e^{-x}=0$$ 을 만족하는 x 값에서 x축에 접한다. 즉 모든 x에 대하여 x값이 항상 양수입니다. 
    - problem2의 수식을 그대로 rtsafe.c로 확인하면 구간이 너무 커 중근인 root를 찾지 못했습니다.
    - 완전제곱식의 성질을 이용하여, problem2의 root와 $$x-e^{-x}=0$$ 위 식의 root는 같은 값이므로, 위 수식을 활용하여 문제를 풀었습니다.
- problem3
    - problem2 역시 -sqrt(2) 값에서 중근을 갖습니다. 하지만 수식을 정리할 수 없습니다.
    - problem3는 초기 구간 정확하게 설정하는 것이 중요한 newtwon method의 한계점으로 인해 x축에 접하는 지점을 root로 찾지 못하고 잘못된 값을 향해 나아갑니다.

## 그래프
- matplotlib를 사용하였고, x축은 method내에서의 반복 횟수, y축은 현재까지 근사한 root값입니다.
- graph 폴더안에 method 마다 구분하여 저장합니다.

## Dicuss the convergence speed of the methods
- Bisection(16회): 반복마다 구간이 반으로 줄어들고, 수렴 속도가 느리다.
- Linear Interpolation(3~4회): bisection에 비해 수렴 속도가 빠르다.
- Secant(2~3회): linear interploation 보다 수렴 속도가 빠르다.
- Newton-Raphson(2회): 함수와 그 함수의 derivate을 이용한 방법으로 secant 보다 수렴 속도가 빠르다.
- Newton with Bracketing(2회): 초기 구간이 정확하지 않으면 root를 찾지 못하는 Newton을 보완한 방법으로 newton과 속도가 비슷하다.
- Muller(2회): 2개의 점과 일차함수를 사용하는 secant의 방식을 발전시킨 방법으로 세 개의 점과 이차함수를 이용한다. newton과 수렴 속도가 비슷하다. 
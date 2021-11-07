# Root Finding2

## 실행방법
- gcc main.c zbrak.c rtbis.c rtflsp.c rtsec.c rtnewt.c rtsafe.c muller.c functions.c nrutil.c
- 위 명령어를 실행한 후 ./a.out을 실행합니다.

## 코드 설명
- main.c 에서 모든 함수의 실행이 이루어집니다.
- zbrak을 구간을 100개로 나누어 실행하였습니다.
- problem F(R)
    - rtbis.c, rflsp.c, rtnewt.c, rtsafe.c, rtsec.c, muller.c 총 6가지의 method를 r.e 가 10^(-4)일 때,10^(-6)일 때 실행하였습니다.
    - 각각의 실행 결과와 iterations의 수는 a.out을 출력한 결과를 캡처하여 "Homework4.pdf" 3페이지에 올렸습니다.
    - 수렴 속도는  rtsafe.c = rtnewt.c > rtsec.c > muller.c > rflsp.c > rtbis.c 순서입니다.
- problem(연습문제) 8-32, 8-26
    - 두 문제의 풀이 유도과정은 필기어플로 필기한 것을 pdf로 변환하여 업로드하였습니다.
    - pdf는 모두 묶어 "Homework4.pdf" 1,2페이지에 올렸습니다.
    - 두 문제 모두 식 정리와 root를 구하기 위한 초기 bracket을 구하는 과정은 pdf에 담겨있고, root finding은 secant method를 통해 하였습니다.
    - root finding 과정은 main.c파일과 "Homework4.pdf" 3페이지에 있습니다.

## 그래프
- 이번 과제에서는 수렴 속도를 비교하는 내용이 없어 __그래프를 첨부하지 않았습니다__.

## "pointer to function"의 개념과 HW3에서의 사용 방법
- "Homework4.pdf"의 4페이지에 정리하여 올렸습니다.

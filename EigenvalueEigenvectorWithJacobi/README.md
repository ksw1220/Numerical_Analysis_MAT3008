# Eigenvalue and Eigenvector with Jacobi

## 실행방법
- main.c 에서 ran0.c ran1.c gasdev.c 를 사용하여 randome number generator를 구현하였습니다.
- ``` gcc -o main main.c ran1.c gasdev.c jacobi.c nrutil.c eigsrt.c```
- 위 명령어를 통해 c파일들을 컴파일하여 실행파일 "main"을 얻은 뒤
- ``` ./main ``` 을 실행하여 eigenvalue, eigenvector의 출력을 얻습니다.
---
## 코드 설명
- gasdev를 통해 mean = 0, deviation = 1.0 인 gaussian distribution를 PDF로 갖는 randomn number를 생성하여 symmetric matrix 'a'를 얻습니다.
- `jacobi()`를 실행하여 eigenvalue 'd'와 eigenvector 'v'를 얻습니다.
- `eigsrt()`를 실행하여 eigenvalue를 내림차순 eigenvector를 내림차순으로 정렬하고 그에 따라 eigenvector도 정령한다.
- eigenvalue와 eigenvector를 출력한다.




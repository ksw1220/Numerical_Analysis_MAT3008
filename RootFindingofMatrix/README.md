# Root Finding of Matrix

## 실행방법
- lineq1.dat, lineq2.dat, lineq3.dat 에 관한 문제 해결을 각각 problem1.c, problem2.c problem3.c 에서 구현하였습니다.
- gcc -o problem1 problem1.c gaussj.c ludcmp.c lubksb.c svdcmp.c pythag.c svdsol.c mprove.c nrutil.c
- gcc -o problem2 problem2.c gaussj.c ludcmp.c lubksb.c svdcmp.c pythag.c svdsol.c mprove.c nrutil.c
- gcc -o problem3 problem3.c gaussj.c ludcmp.c lubksb.c svdcmp.c pythag.c svdsol.c mprove.c nrutil.c
- problem 마닥 각각 컴파일하여 실행파일 problem1, problem2, problem3를 얻고 각각 실행하여 문제마다의 결과를 확인할 수 있습니다.

## 코드 설명
- file pointer를 통해 dat파일을 열고 solution 함수를 생성하여 함수 내에서 dat파일을 한 줄씩 읽어가며 문제를 풀기 위해 필요한 matrix들을 생성했습니다.
- lineq1.dat, lineq2.dat의 경우 데이터 파일의 숫자마다 탭 문자 '\t'로 구분이 되어 있고, lineq3.dat의 경우 공백 문자 ' '로 구분이 되어 있어 delimiter를 다르게 적용하여 문자열 토큰을 얻어냈습니다.
- 각 루틴마다 필요한 변수와 배열들을 따로 생성해 주고, 루틴마다 알맞게 넣어 결과를 얻어냈습니다.

### gaussj.c
``` gaussj(A_gau, N, B_gau, 1); ```
- A_gau에는 input인 A_gau의 inverse matrix가 output으로 저장된다.
- B_gau에는 input B_gau에서 solution matrix인 x로 output이 저장된다.
- 따라서 B_gau의 1번째 col을 출력하는 것이 solution이다.

- advantage
    - 한번의 루틴 사용만으로 solution을 얻을 수 있다.
    - 다른 루틴과는 다르게 한번의 루틴 사용으로 m개의 b[1..n] matrix를 묶은 b[1..n][1..m]에서 각각의 m개의 solution을 얻을 수 있다.
    - A의 inverse matrix를 얻을 수 있다.
- disadvantage
    - singular matrix에 적용할 수 없다.


### ludcmp.c

``` ludcmp(A_lud, N, indx_lud, &d_lud) ;```
- A_lud에는 decomposition된 output이 저장된다
- indx_lud에는 partial pivoting에 영향을 준 row들이 output으로 저장된다.
- d_lud에는 row interchanges가 even이라면 1이, odd라면 -1이 저장된다.

``` lubksb(A_lud, N, indx_lud, B_lud); ```
- ludcmp의 output으로 얻어낸 배열과 함수들을 lubksb에 넣어 solution을 구한다.
- B_lud에 solution matrix가 output으로 저장되고 B_lud를 출력한다.

- advantage
    - 루틴의 output인 A와 d를 이용해 determinant를 구할 수 있다.
    - pivoting에 대한 정보를 얻을 수 있다.

- disadvantage
    - singular matrix에 적용할 수 없다.
    - ludcmp와 lubksb 두 개의 루틴을 적용해야 한다.

### svdcmp.c
``` svdcmp(A_svd, N, N, W_svd, V_svd); ```

$$ A = U \cdot W \cdot V^T $$
- svdcmp 함수를 거쳐 A_svd가 decompostion된다.
- A_svd에는 U가 output으로 저장되고,
- W_svd에는 diagonal single matrix가 저장되고,
- V_svd에는 V matrix가 저장된다. 하지만 이는 transpose된 결과가 아니다.

``` svdsol(V_svd, N, W_svd, A_svd, B_svd); ```

$$ x = V \cdot [diag(1/w_j)] \cdot (U^T \cdot b) $$
- svdcmp를 통해 얻어낸 결과들로 solution을 구하기 위한 svdsol 함수를 정의하여 사용하였다.
- 위의 식처럼 x를 구하기 위한 과정을 함수에 구현하였다
- svdsol의 결과로 solution matrix가 B_svd에 저장된다.

- advantage
    - singular matrix에 적용할 수 있다.
- disadvantage
    - svdcmp 루틴 만으로는 solution matrix를 구할 수 없고

    $$ x = V \cdot [diag(1/w_j)] \cdot (U^T \cdot b) $$
    
    - 위 식의 연산을 실행하는 함수를 별도로 구현해야 한다.

### mprove.c
``` ludcmp(A_lud_mpr, N, indx_mpr, &d_mpr); ```
- 먼저 mprove 함수의 인자로 사용되기 위해 필요한 값들을 얻어내기 위해 ludcmp 함수를 실행한다.
- A_mpr에는 A 행렬이, A_lud_mpr에는 ludcmp를 통해 decompostion 된 행렬이 저장되어있다.

``` mprove(A_mpr, A_lud_mpr, N, indx_mpr, B_mpr, x_mpr);```
- mprove 함수의 실행 결과
- x_mpr에 solution matrix가 저장된다.

- #### mporve를 사용한 장점
    - 한정된 비트로 데이터를 표현함으로써 solution에 x는 실제 x와는 차이가 발생할 수 있다.
    - mprove를 한 번 또는 여러번 사용함으로써 x를 실제 solution x와 더욱 가깝게 얻을 수 있다.

### Inverse matrix of A
- gaussj 함수의 실행 결과로 A_gau에는 inverse matrix가 저장되므로 A_gau를 출력한다.

### Determinant of A 
``` ludcmp(A_lud, N, indx_lud, &d_lud) ;```
- ludcmp 함수에서 얻어낸 A_lud diagonal 성분과, d_lud의 값을 곱하여 determinant를 얻어낸다.
```    
for (int j = 1; j <= N; j++)
    d_lud *= A_lud[j][j];
```

### problem1
- determinant가 0이 나오는 singular matrix이다.
- inverse matrix를 구할 수 없어 루틴을 정상적으로 사용할 수 없다.
- 따라서 각 루틴을 실행한 값이 inf값으로 출력되거나 잘못된 값이 출력된다.

### problem2, problem3
- determinant가 0이 아니고, inversere matrix를 구할 수 있다.
- 성공적으로 solution matrix를 구할 수 있다.

##
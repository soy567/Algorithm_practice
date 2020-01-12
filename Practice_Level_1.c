//프로그래머스 코딩테스트 연습 - 연습문제
//문제 - 2016년
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) { // 2016년 기준
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i;
    int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (a == 2 && b > 29) //날짜 범위 검사
        return 0;
    else if (a == 4, 6, 9, 11 && b > 30)
        return 0;
    else if (a > 12 || b > 31)
        return 0;

    char** answer = (char**)malloc(sizeof(char*)*7); //7개 행 가진 포인터배열 선언
    for (i = 0; i < 7; i++)
        answer[i] = (char*)malloc(sizeof(char)*4); //각 행이 4바이트 공간 가지도록 메모리 동적할당(heap), 세로 열
    strcpy(answer[0], "FRI"); // 1월 1일이 금요일
    strcpy(answer[1], "SAT"); // 1월 1일이 금요일
    strcpy(answer[2], "SUN");
    strcpy(answer[3], "MON");
    strcpy(answer[4], "TUE");
    strcpy(answer[5], "WED");
    strcpy(answer[6], "THU");
    for (i = 0; i < a - 1; i++) { //month 배열은 0부터 시작하므로 마지막은 a-1월
        b += month[i];
    }
    return answer[(b - 1) % 7]; //배열은 0부터 시작하므로 합 b에서 1 빼줌
}

int main(void) {
    int a, b;
    printf("월과 일을 공백을 이용해서 구분하여 입력해 주세요: ");
    scanf("%d %d", &a, &b);
    printf("%s", solution(a, b));
    return 0;
}

//문제 - 두 정수 사이의 합
#include <stdio.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    int i = 0;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    for (i = a; i <= b; i++)
        answer += i;
    return answer;
}
//문제 - 수박수박수박수박수박수?
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i;
    if(n > 10000)
        return 0;
    char* answer = (char*)malloc(sizeof(char)*(3*n)); //한글 1개당 3바이트 할당
    if(n == 0)
        return 0;
    for(i = 0; i < n; i++) {
        if(i % 2 == 0) {
            strcat(answer, "수");
		}
        else {
            strcat(answer, "박");
		}
    }
    return answer;
}

//문제 - 약수의 합
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer, i = 0;
    if (n < 0 || n > 3000)
        return 0;
    for (i = 1; i <= n; i++) {
        if (n % i == 0)
            answer += i;
    }
    return answer;
}

//문제 - 자연수 뒤집어 배열로 만들기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* main(long long n) {
    n = 12345;
    if (n > 10000000000)
        return 0;
    int i, j;
    for (i = 1, j = 1; ; i = i * 10) {
        printf("%d \n", i);
        if ((n / i) == 0)
            break;
        j++; //자릿수 저장하는 변수 j
    }
    printf("%d", j);
    int* answer = (int*)malloc(sizeof(int));
    return answer;
}

//문제 - 정수 제곱근 판별
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

long long solution(long long n) {
    if (n < 1 || n > 50000000000000)
        return 0;
    long long answer = 0;
    long long a = sqrt(n);
    if (n == a * a)
        answer = (a + 1) * (a + 1);
    else
        answer = -1;
    return answer;
}

//문제 - 짝수와 홀수
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* solution(int num) {
    // 리턴할 값은 메모리를 동적 할당해주세요
    char* answer = NULL;
    if (num % 2 == 0) {
        answer = (char*)malloc(sizeof(char) * 5);
        strcpy(answer, "Even");
    }
    else {
        answer = (char*)malloc(sizeof(char) * 4);
        strcpy(answer, "Odd");
    }
    return answer;
}

//문제 - 콜라스 추측
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(long long num) {
    if (num < 1 || num >= 8000000)
        return 0;
    long long answer = 0;

    while (num != 1) {
        answer++;
        if ((num % 2) == 0)
            num = num / 2;
        else
            num = ((num * 3) + 1);
        //printf("num 값: %d i값: %d \n", num, answer);
        if (answer >= 500)
            break;
    }
    if (num != 1 && answer >= 500)
        answer = -1;
    return answer;
}

//문제 - 평균 구하기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
double solution(int arr[], size_t arr_len) {
    if (arr_len < 1 || arr_len > 100)
        return 0;
    double answer = 0;
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] > 10000 || arr[i] < -10000)
            return 0;
        answer += arr[i];
    }
    answer = answer / arr_len;
    return answer;
}

//문제 - 하샤드 수
#include <iostream>
using namespace std;

int main() {
    float f, c;

    cout << "화씨 온도를 입력하세요: ";
    cin >> f;
    c = 5 / 9 * (f - 32);
    cout << f << "의 섭씨 온도: " << c << endl;
    return 0;
}

//문제 - 직사각형 별 찍기
#include <stdio.h>

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    for(int i = 0; i < b; i++) {
        for(int j = 0; j < a; j++)
            printf("*");
        printf("\n");
        }
    return 0;
}

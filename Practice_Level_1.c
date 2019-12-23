//프로그래머스 코딩테스트 연습 - 연습문제
/*
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

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i;
    if(n > 10000)
        return 0;
    char* answer = (char*)malloc((sizeof(char)*2*n) + 1);
    for(i = 0; i < n; i++) {
        if(i % 2 == 0)
            strcat(answer, "수");
        else if(i % 2 == 1)
            strcat(answer, "박");
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
*/
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

//���α׷��ӽ� �ڵ��׽�Ʈ ���� - ��������
/*
//���� - 2016��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) { // 2016�� ����
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    int i;
    int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (a == 2 && b > 29) //��¥ ���� �˻�
        return 0;
    else if (a == 4, 6, 9, 11 && b > 30)
        return 0;
    else if (a > 12 || b > 31)
        return 0;

    char** answer = (char**)malloc(sizeof(char*)*7); //7�� �� ���� �����͹迭 ����
    for (i = 0; i < 7; i++)
        answer[i] = (char*)malloc(sizeof(char)*4); //�� ���� 4����Ʈ ���� �������� �޸� �����Ҵ�(heap), ���� ��
    strcpy(answer[0], "FRI"); // 1�� 1���� �ݿ���
    strcpy(answer[1], "SAT"); // 1�� 1���� �ݿ���
    strcpy(answer[2], "SUN");
    strcpy(answer[3], "MON");
    strcpy(answer[4], "TUE");
    strcpy(answer[5], "WED");
    strcpy(answer[6], "THU");
    for (i = 0; i < a - 1; i++) { //month �迭�� 0���� �����ϹǷ� �������� a-1��
        b += month[i];
    }
    return answer[(b - 1) % 7]; //�迭�� 0���� �����ϹǷ� �� b���� 1 ����
}

int main(void) {
    int a, b;
    printf("���� ���� ������ �̿��ؼ� �����Ͽ� �Է��� �ּ���: ");
    scanf("%d %d", &a, &b);
    printf("%s", solution(a, b));
    return 0;
}

//���� - �� ���� ������ ��
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
//���� - ���ڼ��ڼ��ڼ��ڼ��ڼ�?
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    int i;
    if(n > 10000)
        return 0;
    char* answer = (char*)malloc((sizeof(char)*2*n) + 1);
    for(i = 0; i < n; i++) {
        if(i % 2 == 0)
            strcat(answer, "��");
        else if(i % 2 == 1)
            strcat(answer, "��");
    }
    return answer;
}

//���� - ����� ��
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
//���� - �ڿ��� ������ �迭�� �����
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
        j++; //�ڸ��� �����ϴ� ���� j
    }
    printf("%d", j);
    int* answer = (int*)malloc(sizeof(int));
    return answer;
}

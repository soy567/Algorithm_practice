//���α׷��ӽ� �ڵ��׽�Ʈ ���� - ��������
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
#include <string.h>

char* solution(int n) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    int i;
    if(n > 10000)
        return 0;
    char* answer = (char*)malloc(sizeof(char)*(3*n)); //�ѱ� 1���� 3����Ʈ �Ҵ�
    if(n == 0)
        return 0;
    for(i = 0; i < n; i++) {
        if(i % 2 == 0) {
            strcat(answer, "��");
		}
        else {
            strcat(answer, "��");
		}
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

//���� - ���� ������ �Ǻ�
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

//���� - ¦���� Ȧ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* solution(int num) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���
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

//���� - �ݶ� ����
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
        //printf("num ��: %d i��: %d \n", num, answer);
        if (answer >= 500)
            break;
    }
    if (num != 1 && answer >= 500)
        answer = -1;
    return answer;
}

//���� - ��� ���ϱ�
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len�� �迭 arr�� �����Դϴ�.
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

//���� - �ϻ��� ��
#include <iostream>
using namespace std;

int main() {
    float f, c;

    cout << "ȭ�� �µ��� �Է��ϼ���: ";
    cin >> f;
    c = 5 / 9 * (f - 32);
    cout << f << "�� ���� �µ�: " << c << endl;
    return 0;
}

//���� - ���簢�� �� ���
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

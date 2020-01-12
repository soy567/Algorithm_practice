//문제 - 멀쩡한 사각형
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long get_gcd (long long a, long long b) {
    if(b == 0)
        return a;
    return get_gcd(b, a%b);
}

long long solution(long long w, long long h) {
    long long gcd = get_gcd(h, w);
    long long answer = (w * h) - (w + h - gcd);
    return answer;
}
//문제 - 피보나치 수
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int get_fibo(int x) {
    int fibo = 0;
    if(x == 1)
        return 1;
    else {
        int next = 1, pre = 0;
        for(int j = 1; j < x; j++) {
            fibo = (next + pre) % 1234567;
            pre = next;
            next = fibo;
        }
        return fibo;
    }
}

int solution(int n) {
    if(n < 1 || n > 100000)
        return 0;
    int answer = get_fibo(n);
    return answer;
}
//문제 - N개의 최소공배수
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int get_gcd(int a, int b) {
    int tmp, n;
    if(a > b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0) {
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = 1;
    int gcd = 0;

    answer = arr[0]*arr[1] / get_gcd(arr[0], arr[1]);
    for(int i = 2; i < arr_len; i++)
        answer = answer*arr[i] / get_gcd(answer, arr[i]);

    return answer;
}
//문제 - 소수 만들기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime_num(int x) {
    int i;
    for(i = 2; i <= x; i++)
        if(x%i == 0)
            break;
    if(x == i)
        return true;
    else
        return false;
}
// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;

    for(int i = 0; i < nums_len-2; i++)
        for(int j = i+1; j < nums_len-1; j++)
            for(int k = j+1; k < nums_len; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                printf("%d\n", sum);
                if(is_prime_num(sum))
                    answer++;
            }
    return answer;
}
//문제 - 스킬트리
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0;
    int n = 0;

    for(int i = 0; i < skill_trees_len; i++) {
        int n = 0, j;
        for(j = 0; j < strlen(skill_trees[i]); j++){
            printf("%c\n", skill_trees[i][j]);
            if(strchr(skill, skill_trees[i][j])) {
                if(skill[n] == skill_trees[i][j])
                    n++;
                else
                    break;
            }
        }
        if(j == strlen(skill_trees[i]))
                answer++;
    }
    return answer;
}

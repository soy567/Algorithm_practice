//문제 - 문자열 압축
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    int min_sub = s.size();

    for(int i = 1; i <= s.size()/2; i++){ //2중 반복 이용 각 길이별로 잘라 길이 구하기
        string a, b, ans = "";
        int sub_len = 1;
        a = s.substr(0, i); //기존 문자열

        for(int j = i; j < s.size(); j += i) {
            b = s.substr(j, i); //다음 문자열
            if(a == b) { //기존과 다음 문자열이 같을 경우
                sub_len++;
            }
            else {
                if(sub_len == 1)
                    ans = ans + a;
                else
                    ans = ans + to_string(sub_len) + a;
                sub_len = 1; //문자열 길이 초기화
                a = b; //비교위한 기존 문자열 다시설정
            }
            if(i + j >= s.size()) { //비교 범위가 문자열 길이 초과했을경우(비교가 불가능 하므로 기존 카운트와 뒤의 문자열만 뒤에 추가)
                if(sub_len != 1){
                    ans = ans + to_string(sub_len) + b;
                    break;
                }else{
                    ans = ans + s.substr(j);
                    break;
                }
            }
        }
        //cout << ans << endl;
        min_sub = (min_sub > ans.size()) ? ans.size() : min_sub; //각 길이로 자른 문자열 중 가장 짧은 문자열 길이 저장
    }
    answer = min_sub;
    return answer;
}
//문제 - 완주하지 못한 선수
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string>::iterator position1, position2;

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i = 0; i < participant.size(); i++)
        if(participant[i] != completion[i]) {
            answer = participant[i];
            return answer;
        }
    return answer;
}
//문제 - 모의고사
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr1[5] = {1, 2, 3, 4, 5};
int arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int max(int a, int b){
    return (a > b)? a : b;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer, score(3);
    int max_score = 0;

    for(int i = 0; i < answers.size(); i++) {
        if(arr1[i % 5] == answers[i]) score[0]++;
        if(arr2[i % 8] == answers[i]) score[1]++;
        if(arr3[i % 10] == answers[i]) score[2]++;
    }

    max_score = max(max(score[0], score[1]), score[2]);
    for(int j = 0; j < score.size(); j++) {
        if(max_score == score[j]) answer.push_back(j+1);
    }
    return answer;
}
//문제 - K번째 수
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;

    for(int n = 0; n < commands.size(); n++) {
        vector<int> tmp;
        i = commands[n][0];
        j = commands[n][1];
        k = commands[n][2];

        for(int a = i; a <= j; a++) {
            cout << array[a-1] << endl;
            tmp.push_back(array[a-1]);
        }

        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k-1]);
    }
    return answer;
}
//문제 - 가운데 글자 가져오기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int str_size = s.size();
    int half_size = str_size/2;
    if(str_size < 1 || str_size > 100)
        return 0;

    if(str_size%2 == 0) {
        answer = s[half_size-1];
        answer += s[half_size];
    }
    else
        answer = s[half_size];

    return answer;
}
//문제 - 같은 숫자는 싫어
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int arr_size = arr.size();
    vector<int> answer;

    answer.push_back(arr[0]);
    for(int i = 1; i < arr_size; i++)
        if(arr[i-1] != arr[i])
            answer.push_back(arr[i]);

    return answer;
}
//문제 - 나누어 떨어지는 숫자 배열
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int arr_size = arr.size();

    for(int i = 0; i < arr_size; i++) {
        if(arr[i] % divisor == 0)
            answer.push_back(arr[i]);
    }

    sort(answer.begin(), answer.end());

    if(answer.empty())
        answer.push_back(-1);

    return answer;
}
//문제 - 문자열 내 마음대로 정렬하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<char> index;
    vector<string>::iterator pos;
    int size = strings.size();

    for(int i = 0; i < strings.size(); i++)
        index.push_back((char)strings[i][n]);

    sort(index.begin(), index.end());
    sort(strings.begin(), strings.end()); //인덱스 같을경우 순서대로 출력하기위해 입력문자열도 정렬

    for(int k = 0; k < index.size(); k++) {
        pos = strings.begin();
        for(int j = 0; j < strings.size(); j++)
            if(index[k] == (char)strings[j][n]){
                answer.push_back(strings[j]);
                strings.erase(pos+j); //들어간 문자열 삭제
                break;
            }
    }
    return answer;
}
//문제 - 문자열 내 p와 y의 개수
#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int p = 0, y = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'p' || s[i] == 'P')
            p++;
        else if(s[i] == 'y' || s[i] == 'Y')
            y++;
    }
    if(p != y)
        answer = false;

    return answer;
}
//문제 - 문자열 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(char a, char b) {
    return a > b;
}

string solution(string s) {
    string answer = "";

    sort(s.begin(), s.end(), desc);
    answer = s;

    return answer;
}
//문제 - 소수 찾기
/* 시간초과 코드
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 2;

    for(int i = 4; i <= n; i++) {
        int tmp = 0;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                tmp = 1;
                break;
            }
        }
        if(tmp == 0)
            answer++;
    }
    return answer;
}
*/
//에라토스테네스이 체 이용
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int nums[1000000] = {0};

    for(int i = 2; i <= n; i++) {
        if(nums[i] == 1)
            continue;
        for(int j = i*2; j <= n; j += i) //j+=i -> 해당 수의 배수
            nums[j] = 1;
    }

    for(int i = 2; i <= n; i++)
        if(nums[i] == 0)
            answer++;

    return answer;
}
//문제 - 문자열을 정수로 바꾸기
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int nums[1000000] = {0};

    for(int i = 2; i <= n; i++) {
        if(nums[i] == 1)
            continue;
        for(int j = i*2; j <= n; j += i) //j+=i -> 해당 수의 배수
            nums[j] = 1;
    }

    for(int i = 2; i <= n; i++)
        if(nums[i] == 0)
            answer++;

    return answer;
}
//문제 - 시저 암호
#include <string>
using namespace std;
string solution(string s, int n){
    string answer = "";
    int len = s.length();
    for( int i = 0 ; i < len; i++) {
        if(s[i] != ' ') {
            char sta = ('A' <= s[i] && s[i] <= 'Z') ? 'A' : 'a';
            answer += (((s[i] - sta)+n)%26) + sta;
            continue;
        }
        answer += s[i];
    }
    return answer;
}
//문제 - 정수 내림차순으로 배치하기
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> nums;
    int i, j;

    while(n > 0) {
        cout << n%10 << endl;
        nums.push_back(n%10);
        n /= 10;
    }
    sort(nums.begin(), nums.end());

    i = 0;
    j = 1;
    while(i < nums.size()) {
        answer += nums[i]*j;
        i++;
        j *= 10;
    }

    return answer;
}
//문제 - 최대공약수와 최소공배수
#include <string>
#include <vector>

using namespace std;

void get_gcd_lcm(int a, int b, vector<int> &arr) {
    int tmp, n, ta = a, tb = b;

    if(ta > tb) {  //a보다 b가 커야함
        tmp = ta;
        ta = tb;
        tb = tmp;
    }

    while(tb != 0) {
        n = ta%tb;
        ta = tb;
        tb = n;
    }
    arr.push_back(ta);
    arr.push_back(a*b/ta);
}

vector<int> solution(int n, int m) {
    vector<int> answer;

    get_gcd_lcm(n, m, answer);

    return answer;
}
//문제 - 핸드폰 번호 가리기
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int size = phone_number.size();

    for(int i = 0; i < size; i++) {
        if(i < size-4)
            answer += '*';
        else
            answer += phone_number[i];
    }
    return answer;
}
//문제 - 행렬의 덧셈
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i = 0; i < arr1.size(); i++) {
        answer.push_back(arr1[i]); //벡터 공간할당
        for(int j = 0; j < arr1[i].size(); j++)
            answer[i][j] = arr1[i][j] + arr2[i][j];
    }
    return answer;
}
//문제 - x만큼 간격이 있는 n개의 숫자
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int i = 0, j = 0;

    while(i < n) {
        j += x;
        answer.push_back(j);
        i++;
    }
    return answer;
}
//문제 - 예산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    long sum = 0;
    sort(d.begin(), d.end());

    for(int i = 0; i < d.size(); i++) {
        sum += d[i];
        if(sum <= budget)
            answer++;
        else
            break;
    }
    return answer;
}

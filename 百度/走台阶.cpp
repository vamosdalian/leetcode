#include "include.h"

using namespace std;


//获取一维数组
template <typename T>
vector<T> getNums(char c = ' '){
    vector<T> result;
    string str;
    T tmp = 0;
    bool minus = false;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            result.push_back(tmp);
            tmp = 0;
            minus = false;
            continue;
        }
        if(str[i] == '-'){
            minus = true;
            continue;
        }
        tmp = minus? tmp*10 - str[i] + '0' : tmp*10 + str[i] - '0';
    }
    result.push_back(tmp);
    return result;
}

// long long zoutaijie(int n, int m){
//     if(n <= 2) return n;
//     vector<long long> dp(n,0);
//     queue<int> visited;
//     dp[0] = 1;
//     dp[1] = 1;
//     visited.push(1);
//     visited.push(2);
//     for (int i = 2; i < n; i++)
//     {
//         for (int j = 1; j <= m && i-j >= 0 && j != visited.front() && j != visited.back(); j++)
//         {
//             dp[i] += dp[i-j];
//             visited.pop();
//             visited.push(j);
//         }
        
//     }
//     return dp[dp.size() - 1] % 1000000007;
// }
void zoutaijie(int n, int m, int &sum, vector<int> &used, long long &result){
    if(sum+1 == n) result++;
    cout << sum << endl;
    for (int i = 1; i <= m; i++)
    {
        if(i != used[0] && i != used[1] && sum+i <= n){
            sum += i;
            int tmp = used[0];
            used[0] = used[1];
            used[1] = i;
            zoutaijie(n, m, sum, used, result);
            used[1] = used[0];
            used[0] = tmp;
            sum -= i;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nAm = getNums<int>(' ');
    int n = nAm[0];
    int m = nAm[1];
    if(n <= 2){
        cout << 1<<endl;
        return 0;
    }
    int sum = 0;
    vector<int> used(2,0);
    used[0] = 1;
    used[1] = 2;
    long long result = 0;
    zoutaijie(n, m, sum, used, result);
    cout << result;
    return 0;
}

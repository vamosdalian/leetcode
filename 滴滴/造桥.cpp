#include "include.h"

using namespace std;

//获取一个数字
template <typename T>
T getNum(){
    T result = 0;
    string str;
    bool isFushu = false;
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '-'){
            isFushu = true;
            continue;
        }
        if(str[i]>='0' && str[i] <= '9'){
            result = isFushu? result*10 - str[i] + '0' : result*10 + str[i] - '0';
        }
    }
    return result;
}

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

//获取二维数组
template <typename T>
vector< vector<T> > getNums2(int n, char c = ' '){
    vector< vector<T> > result;
    vector<T > tmpResult;
    while(n--){
        tmpResult = getNums<T>(c);
        if(tmpResult.size() == 0) break;
        result.push_back(tmpResult);
        tmpResult.clear();
    }
    return result;
}

bool couldBuild(vector<vector<int> > prices, int n, int m, int k){
    unordered_set<int> visited;
    unordered_set<int> used;
    for (int i = 0; i < prices.size(); i++)
    {
        int tmp = INT_MAX;
        int tmpIndex = -1;
        for (int j = 0; j < prices.size(); j++)
        {
            if(used.find(j) == used.end()){
                if(prices[j][2] <= tmp && prices[j][2] <= k){
                    tmp = prices[j][2];
                    tmpIndex = j;
                }
            }
        }
        if(tmpIndex != -1){
            // cout << tmpIndex << prices[tmpIndex][0] << prices[tmpIndex][1] << endl;
            used.insert(tmpIndex);
            visited.insert(prices[tmpIndex][0]);
            visited.insert(prices[tmpIndex][1]);
        }
        if(visited.size() >= n){
            break;
        }
    }
    // cout << visited.size();
    if(visited.size() == n){
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int N = getNum<int>();
    while (N--)
    {
        vector<int> nAmAk = getNums<int>();
        vector<vector<int> > prices = getNums2<int>(nAmAk[1]);
        bool result = couldBuild(prices, nAmAk[0], nAmAk[1], nAmAk[2]);
        if(result){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}


// 1
// 3 3 400
// 1 2 200
// 1 3 300
// 2 3 500


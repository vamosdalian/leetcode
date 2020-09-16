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

//获取多个数字
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

int beibao(int bagSize, vector<int> weights, vector<int> values){
    vector<vector<int> > dp(weights.size(), vector<int>(bagSize+1,0));
    for (int i = 1; i < weights.size(); i++) {
		for (int j = 1; j <= bagSize; j++) {
			if (j < weights[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
		}
	}
    return dp[weights.size()-1][bagSize];
}

int main(int argc, char const *argv[])
{
    // vector<int> mntmp = getNums<int>();
    int si = getNum<int>();
    vector<int> weight = getNums<int>();
    vector<int> value = getNums<int>();
    cout << beibao(si,weight,value);

    return 0;
}

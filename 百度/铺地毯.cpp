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
//输出一维vector
template <typename T>
void printVector(vector<T> input){
    for(int i = 0; i < input.size(); ++i){
        cout << input[i] << " ";
    }
    cout << endl;
}

vector<int> puditan(int N, vector<vector<int> > input){
    vector<int> result(N,0);
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = input[i][0]-1; j <= input[i][1]-1; j++)
        {
            result[j]++;
        }
        
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int inputCount = getNum<int>();
    for (int inputIndex = 0; inputIndex < inputCount; inputIndex++)
    {
        vector<int> nAm = getNums<int>(' ');
        int n = nAm[0];
        int m = nAm[1];
        vector<vector<int> > input = getNums2<int>(m, ' ');
        printVector(puditan(n, input));
    }
    return 0;
}

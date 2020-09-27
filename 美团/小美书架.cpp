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

void process(vector<int> shujia, vector<int> shu, vector<vector<int> > steps){
    for(auto step : steps){
        if(step[0] == 1){
            if(shu[step[1]] == 0 && shujia[step[2]] == 0){
                shu[step[1]] = step[2];
            }else if(shu[step[1]] > 0 && shujia[shu[step[1]]] == 0 && shujia[step[2]] == 0){
                shu[step[1]] = step[2];
            }
        }else if(step[0] == 2){
            shujia[step[1]] = 1;
        }else if(step[0] == 3){
            shujia[step[1]] = 0;
        }else if(step[0] == 4){
            if(shu[step[1]] && shujia[shu[step[1]]] == 0){
                cout << shu[step[1]] << endl;
                shu[step[1]] = -1;
            }else{
                cout << -1 << endl;
            }
        }else if(step[0] == 5){
            if(shu[step[1]] == -1){
                shu[step[1]] = 0;
            }
            
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> inputs = getNums<int>();
    vector<int> shujia(inputs[0]+1, 0);
    vector<int> shu(inputs[1]+1, 0);
    vector<vector<int> > steps = getNums2<int>(inputs[2]);
    process(shujia, shu, steps);
    return 0;
}

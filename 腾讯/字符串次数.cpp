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

//获取一维字符串组
//获取一个字符串
string getString(){
    string result;
    getline(cin, result);
    return result;
}

bool largeCompare(string str1, string str2){
    int i = 0, j = 0;
    while(i++ < str1.size() && j++ < str2.size()){
        if(str1[i] != str2[j]){
            return str1[i] > str2[i];
        }
        
    }
    if(i == str1.size()){
        return true;
    }else if(j == str2.size()){
        return false;
    }
    return false;
}
bool smallCompare(string str1, string str2){
    int i = 0, j = 0;
    while(i++ < str1.size() && j++ < str2.size()){
        if(str1[i] != str2[j]){
            return str1[i] < str2[i];
        }
        
    }
    if(i == str1.size()){
        return false;
    }else if(j == str2.size()){
        return true;
    }
    return false;
}

vector<pair<string, int> > getLargeList(vector<string> strs, int k){
    unordered_map<string,int> count;
    for(auto str : strs){
        if(count.find(str) == count.end()){
            count.insert(make_pair(str,1));
        }else{
            count[str]++;
        }
    }
    vector<vector<string> > largeVec(strs.size(), vector<string>());
    for(auto item : count){
        largeVec[item.second-1].push_back(item.first);
        sort(largeVec[item.second-1].begin(), largeVec[item.second-1].end(), smallCompare);
    }
    vector<pair<string, int> > result;
    
    for(int j = largeVec.size()-1; j >= 0 && k > 0; j--){
        if(largeVec[j].size() > 0){
            for(int i = largeVec[j].size()-1; i >= 0; i--){
                result.push_back(make_pair(largeVec[j][i],j));
                k--;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nAk = getNums<int>();
    int n = nAk[0];
    int k = nAk[1];
    vector<string> strs;
    while(n--){
        strs.push_back(getString());
    } 
    vector<pair<string, int> > result = getLargeList(strs, k);
    for (auto item : result){
        cout << item.first << " " << item.second << endl;
    }
    return 0;
}

#include "include.h"
#include "bits/stdc++.h"
using namespace std;

vector<string> getStrings(char c = ' ',string str = ""){
    vector<string> result;
    // string str;
    string tmpStr;
    // getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            if(!tmpStr.empty()){
                result.push_back(tmpStr);
                tmpStr.clear();
            }
            continue;
        }
        tmpStr.push_back(str[i]);
    }
    result.push_back(tmpStr);
    return result;
}
bool solution(string pat, string str){
    vector<string> strs = getStrings(' ',str);
    unordered_map<char, string> stmap;
    unordered_map<string, char> tsmap;
    bool result = true;
    for(int i = 0; i < pat.size();i++){
        auto item = stmap.find(pat[i]);
        auto item2 = tsmap.find(strs[i]);
        if(item == stmap.end()){
            stmap.insert(make_pair(pat[i], strs[i]));
        }else{
            if(item->second != strs[i]){
                result = false;
            }
        }
        if(item2 == tsmap.end()){
            tsmap.insert(make_pair(strs[i], pat[i]));
        }else{
            if(item2->second != pat[i]){
                result = false;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    cout << solution("effe","hh jj kk hh");
    return 0;
}

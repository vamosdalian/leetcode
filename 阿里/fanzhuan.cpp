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

//获取一个字符串
string getString(){
    string result;
    getline(cin, result);
    return result;
}

int minimumSwap(string s1, string s2) {
    int ans = 0, n = s1.size();
    int cnt1 = 0,cnt2 = 0;//统计有多少对x-y和y-x
    for(int i = 0; i < n; i++){
        if(s1[i]=='0'&&s2[i]=='1') cnt1++;
        else if(s1[i]=='1'&&s2[i]=='0') cnt2++;
    }
    //对于每一对 x-y 和 x-y 以及 y-x 和 y-x 都只需要一次操作即可完成匹配
    ans += cnt1/2+cnt2/2;//所需要的操作数
    cnt1%=2;//剩余未匹配的对数
    cnt2%=2;
    if(cnt1+cnt2==1) return -1;//只剩一个时无法匹配
    else if(cnt1+cnt2==2) ans+=2;//只剩了 x-y和y-x 需要两次匹配
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    string str1 = getString();
    string str2 = getString();
    int res1 = minimumSwap(str1,str2);
    cout << res1;
    string str3(str1);
    for(int i = 0; i< str3.size();i++){
        if(str3[i]== '0') str3[i]++;
        else str3[i]--;
    }
    int res2 = minimumSwap(str3,str2)+1;
    cout << res2;
    if(res1 == -1 && res2 == -1) cout << -1;
    else if(res1 == -1) cout << res2;
    else if(res2 == -1) cout << res1;
    else{
        cout << min(res1,res2);
    }
    return 0;
}

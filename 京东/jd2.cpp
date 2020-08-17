// 题目描述：
// 现有一个正整数，希望去掉这个数中某一个数字之后可以得到一个回文素数。

// 回文素数是指一个素数同时还是一个回文数（回文数即从左到右和从右到左均一样的数，例如12321）。【注意：一位数也被认为是回文数】

// 输入两个正整数N和M，满足N<M，请编写一个程序统计N和M之间存在多少个满足上述要求的数？



// 输入描述
// 单组输入。

// 输入一行，包含两个正整数N和M，1<=N<M<=1000000，两个数字之间用空格隔开。

// 输出描述
// 输出在N和M之间（包含N和M）满足要求的数的个数。


// 样例输入
// 110 120
// 样例输出
// 10

#include <bits/stdc++.h>

using namespace std;

//字符串转数字     to_string(int i);
//数字转字符串     atoi(str.c_str());

bool isSu(int num){
    if(num == 1) return false;
    int k = (int) sqrt((double)num);
    for(int i =2; i < k;i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

bool isHui(string str){
    int size = str.size();
    for(int i = 0;i < size/2;i++){
        if(str[i] != str[size - i - 1]){
            return false;
        }
    }
    return true;
}



int main(){
    int num1, num2;
    cin >> num1 >> num2;
    int count = 0;
    for(int i = num1;i <= num2;i++){
        string num = to_string(i);
        for(int j = 0;j < num.size();j++){
            string tmp1(num.begin(), num.begin() + j);
            string tmp2(num.begin()+j+1, num.end());
            string tmp = tmp1 + tmp2;
            if(isHui(tmp) && isSu(atoi(tmp.c_str()))){
                count++;
                break;
            }
        }
    }
    cout << count<<endl;
    return 0;
}

// vector<bool> result(num2,false);
// isSu(i) && isHui(i)
//     result[1-9 +i] =truea
//     result [i+ 0-9] =true

// for(i = num1 < num2 i++){
//     ifresult[i] == triue
//     count ++;

// }
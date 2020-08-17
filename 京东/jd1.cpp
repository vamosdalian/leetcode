// 题目描述：
// X星人的基因由A、B、C、D、E五种不同的结构组合而成。

// 如果两个性别不同的X星人的基因序列相似度大于50%，按照X星的法律他们是禁止结婚的，等于50%据说还是可以的。

// 那么基因的相似度怎么计算呢？分别从两个人身上取长度均为N的基因片段，如果它们的最长公共子序列（注意，最长公共子序列不需要连续）的长度为M，则相似度=M/N。是不是很简单呢？

// 现在给你两段X星人的基因序列片段，请你判断他们是不是可以结婚？


// 输入描述
// 单组输入。

// 每一组测试数据包含3行：

// 第1行数字N表示待比较基因序列片段的长度，N<=10^3。

// 第2行和第3行为两个长度为N的基因序列片段，中间以空格隔开。 

// 输出描述
// 先输出相似度，结果保留两位小数（四舍五入），然后输出判断结果（中间以空格隔开），如果可以输出”Yes“，如果不可以输出”No“。

// 样例输入
// 6
// A B C D E E
// A E D C B B
// 样例输出
// 0.33 Yes
#include <bits/stdc++.h>

using namespace std;

int find(vector<char> input1, vector<char> input2){
    int dp[input1.size() + 1][input2.size() + 1] = {0};
    for(int i = 0; i < input1.size();i++){
        for(int j = 0; j < input2.size();j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i < input1.size() + 1;i++){
        for(int j = 1; j < input2.size() + 1;j++){
            if(input1[i] == input2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[input1.size()][input2.size()];
}

int main(){
    int N;
    cin >> N;
    vector<char> input1;
    vector<char> input2;
    char tmp;
    for(int i = 0; i < N;i++){
        cin >> tmp;
        input1.push_back(tmp);
    }
    for(int i = 0; i < N;i++){
        cin >> tmp;
        input2.push_back(tmp);
    }
    double result = (double)find(input1,input2) / N;
    if(result <= 0.5){
        printf("%.2f Yes",result);
    }else{
        printf("%.2f No", result);
    }
    return 0;
}
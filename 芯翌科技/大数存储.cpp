#include "include.h"

using namespace std;

typedef struct Node{
    char val;
    struct Node * next;
}bigNum;

bigNum * init(string str){
    bigNum * result = nullptr;
    for(int i = 0; i < str.size(); i++){
        bigNum * node = new bigNum;
        node->val = str[i]-'0';
        node->next = result;
        result = node;
    }
    return result;
}

void show(bigNum * bignum){
    stack<int> mystk;
    bigNum * p = bignum;
    while(p){
        mystk.push(p->val);
        p = p->next;
    }
    while (!mystk.empty())
    {
        cout << mystk.top();
        mystk.pop();
    }
    cout << endl;
}

bigNum * add(bigNum * A, bigNum * B){
    int tmp = 0;
    stack<int> mystk;
    bigNum * p = A;
    bigNum * q = B;
    while (p&&q)
    {
        mystk.push((p->val+q->val+tmp)%10);
        tmp = (p->val+q->val+tmp)/10;
        p = p->next;
        q = q->next;
    }
    while(p){
        mystk.push((p->val+tmp)%10);
        tmp = (p->val+tmp)/10;
        p = p->next;
    }
    while(q){
        mystk.push((q->val+tmp)%10);
        tmp = (q->val+tmp)/10;
        q = q->next;
    }
    if(tmp){
        mystk.push(tmp);
    }
    bigNum * result = nullptr;
    while (!mystk.empty()) 
    {
        bigNum * node = new bigNum;
        node->val = mystk.top();
        node->next = result;
        result = node;
        mystk.pop();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    string str1, str2;
    cout<<"请输入两个数字以空格隔开:"<<endl;
    cin >> str1 >> str2;
    bigNum * num1 = init(str1);
    bigNum * num2 = init(str2);
    bigNum * result = add(num1, num2);
    show(result);
    return 0;
}

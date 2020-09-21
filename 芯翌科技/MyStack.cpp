#include "include.h"

using namespace std;

class MyStack{
private:
    queue<int> que1;
    queue<int> que2;
public:
    MyStack(/* args */);
    void Push(int num);
    void Pop();
    int Size();
    ~MyStack();
};

MyStack::MyStack(/* args */){
}

MyStack::~MyStack(){
}

void MyStack::Push(int num){
    if(que1.empty() && que2.empty()){
        que1.push(num);
        return;
    }
    if(!que1.empty()){
        que1.push(num);
    }else {
        que2.push(num);
    }
}
void MyStack::Pop(){
    if(que1.empty() && que2.empty()){
        return ;
    }
    if(!que1.empty()){
        while(que1.size() > 1){
            auto i = que1.front();
            que2.push(i);
            que1.pop();
        }
        que1.pop();
    }else{
        while(que2.size() > 1){
            auto i = que2.front();
            que1.push(i);
            que2.pop();
        }
        que2.pop();
    }
}

int MyStack::Size(){
    return max(que1.size(), que2.size());
}

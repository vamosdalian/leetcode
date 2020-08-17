#include "include.h"
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() == 0) return false;
        stack<int> myStack;
        int i = 1;
        int j = 0;
        myStack.push(pushed[0]);
        while(!myStack.empty()){
            auto item = myStack.top();
            cout << item << endl;
            if(item == popped[j]){
                myStack.pop();
                j++;
                if(j == popped.size()){
                    return true;
                }
                continue;
            }
            myStack.push(pushed[i]);
            i++;
            if(i == pushed.size()){
                break;
            }
        }
        while(!myStack.empty()){
            if(myStack.top() != popped[j]){
                return false;
            }
            myStack.pop();
            j++;
            if(j == popped.size()){
                return true;
            }
        }
        if(j == popped.size()){
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> push = {1,2,3,4,5};
    vector<int> pop = {4,5,3,2,1};
    Solution *method = new Solution();
    cout << method->validateStackSequences(push,pop);
    return 0;
}

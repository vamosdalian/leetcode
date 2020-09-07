#include "include.h"

using namespace std;

vector<int> qinaxu(node* root){
    stack<node *> mystk;
    if(root == nullptr ) return {};
    mystk.insert(root);
    vector<int> result;
    unordered_set<set*> visited;
    while(!mystk.empty()){
        auto item = mystk.top();
        // if(visited.find(item) == visited.end()){
            result.push_back(item->val);
            visited.insert(item);
            mystk.pop();
        // }
        if(item->right ){
            mystk.push(item->right);
        }
        if(item->left ){
            mystk.push(item->left);
        }

    }

}



// #include "method.h"
#include "include.h"

using namespace std;

//常用方法
/***
以下函数可以直接用（algorithm头文件）
求和函数         accumulate(vec.begin() , vec.end() , 0);//0初始变量
查找            find(vec.begin(), vec.end(), 30);//寻找myvector中等于30的元素
排序            sort(vec.begin() , vec.end());
逆转            reverse(vec.begin() , vec.end());
最大值           max(int a ,int b);
最小值           min(int a, int b);
绝对值           abs(int a, int b);

字符串相关
字符串转数字     to_string(int i);
数字转字符串     atoi(str.c_str());
***/
//-----------------------------
//获取素数列表(n > 1)
//返回vector<bool>代表该位是否为素数
vector<bool> countPrimes(int n) {
    //初始默认所有数为质数
    vector<bool> signs(n, true);
    signs[1] = false;
    for (int i = 2; i < n; i++) {
        if (signs[i]) {
            for (int j = i + i; j < n; j += i) {
                //排除不是质数的数
                signs[j] = false;
            }
        }
    }
    return signs;
}
//二分查找
//查找target值
int binary_search(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1; 
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] == target) {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}
//二分查找
//查找target区间的最左侧端点
int left_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定左侧边界
            right = mid - 1;
        }
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}
//二分查找
//查找target区间的最右侧端点
int right_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}
//素数
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
//回文字符串
bool isHui(string str){
    int size = str.size();
    for(int i = 0;i < size/2;i++){
        if(str[i] != str[size - i - 1]){
            return false;
        }
    }
    return true;
}
//二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//二叉树中序
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
            if (node->right) st.push(node->right); // 添加右节点

            st.push(node); // 添加中节点
            st.push(NULL); // 中节点访问过，但是还没有处理，需要做一下标记。

            if (node->left) st.push(node->left); // 添加左节点
        } else {
            st.pop(); // 将空节点弹出
            node = st.top(); // 重新取出栈中元素
            st.pop();
            result.push_back(node->val); // 加入到数组中
        }
    }
    return result;
}
//二叉树前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左
            st.push(node);                          // 中
            st.push(NULL);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}
//二叉树后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            st.push(node);                          // 中
            st.push(NULL);

            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左

        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}
//01背包问题
int beibao(int bagSize, vector<int> weights, vector<int> values){
    vector<vector<int> > dp(weights.size(), vector<int>(bagSize+1,0));
    for (int i = 1; i < weights.size(); i++) {
		for (int j = 1; j <= bagSize; j++) {
			if (j < weights[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
		}
	}
    return dp[weights.size()-1][bagSize];
}






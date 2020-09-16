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

//输出一维vector
template <typename T>
void printVector(vector<T> input, string str = "\t"){
    for(int i = 0; i < input.size(); ++i){
        cout << input[i] << str;
    }
    cout << endl;
}

//冒泡排序
vector<int> bubbleSort(vector<int> nums){
    int tmp = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = 0; j < nums.size() - 1 - i; j++){
            if(nums[j+1] < nums[j]){
                tmp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    return nums;
}

//选择排序
vector<int> choiceSort(vector<int> nums){
    int index = 0;
    int tmp = 0;
    for(int i = 0;i < nums.size(); i++){
        index = i;
        for(int j = i; j < nums.size(); j++){
            if(nums[j] < nums[index]){
                index = j;
            }
        }
        tmp = nums[i];
        nums[i] = nums[index];
        nums[index] = tmp;
    }
    return nums;
}

//插入排序
vector<int> insertSort(vector<int> nums){
    int tmp = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i;j > 0; j--){
            if(nums[j] < nums[j-1]){
                tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }else{
                break;
            }
        }
    }
    return nums;
}

//快排
int partSort(vector<int> &nums, int low, int high){
    int tmp = nums[low];
    bool front = false;
    while(low < high){
        if(front){
            if(nums[low] <= tmp){
                low++;
            }else{
                nums[high] = nums[low];
                front = false;
            }
        }else{
            if(nums[high] > tmp){
                high--;
            }else{
                nums[low] = nums[high];
                front = true;
            }
        }
    }
    nums[low] = tmp;
    return low;
}
vector<int> quickSort(vector<int> &nums, int low, int high){
    if(low < high){
        int index = partSort(nums, low, high);
        quickSort(nums, low, index-1);
        quickSort(nums, index+1,high);
    }
    return nums;
}


//堆排序
void heapAdjust(vector<int> &nums, int parent, int end){
    // int tmp = nums[parent];
    int child = parent * 2 + 1;
    while(child <= end){
        if(child + 1 <= end && nums[child + 1] > nums[child]){
            child++;
        }
        if(nums[parent] > nums[child]){
            break;
        }
        swap(nums[parent], nums[child]);
        parent = child;
        child = parent * 2 + 1;
    }
}
vector<int> heapSort(vector<int> nums){
    for(int i = (nums.size() - 1) / 2; i >= 0; i--){
        heapAdjust(nums, i, nums.size() - 1);
    }
    for (int i = nums.size() - 1; i >= 0; i--){
        swap(nums[0], nums[i]);
        heapAdjust(nums, 0, i-1);
    }
    return nums;
}

//希尔排序
void shellInsert(vector<int> &nums, int index, int step){
    int tmp = nums[index];
    for(int i = index; i >= 0; i-= step){
        if(i - step >= 0 && nums[i - step] > tmp){
            nums[i] = nums[i - step];
        }else{
            nums[i] = tmp;
            break;
        }
    }
}
vector<int> shellSort(vector<int> nums){
    for(int i = nums.size() / 2; i > 0; i /= 2){
        for(int j = i; j < nums.size(); j++){
            shellInsert(nums, j, i);
        }
    }
    return nums;
}

//归并排序
void merge(vector<int> &nums, int low, int mid, int high){
    int i = low, j = mid+1;
    vector<int> tmp;
    while(i <= mid && j <= high){
        if(nums[i] < nums[j]){
            tmp.push_back(nums[i]);
            i++;
        }else if(nums[i] > nums[j]){
            tmp.push_back(nums[j]);
            j++;
        }else{
            tmp.push_back(nums[i]);
            tmp.push_back(nums[j]);
            i++;
            j++;
        }
    }
    while(i <= mid){
        tmp.push_back(nums[i]);
        i++;
    }
    while(j <= high)
    {
        tmp.push_back(nums[j]);
        j++;
    }
    for(i = 0; i < tmp.size(); i++){
        nums[low + i] = tmp[i];
    }
}
vector<int> mergeSort(vector<int> &nums, int low, int high){
    int mid = (high - low) / 2 + low;
    if(low < high){
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    return nums;
}

//计数排序
vector<int> countSort(vector<int> nums){
    int max = 0;
    for(auto num : nums){
        max = num > max ? num : max;
    }
    vector<int> tmp(max + 1, 0);
    for(auto num : nums){
        tmp[num]++;
    }
    vector<int> result;
    for (int i = 0; i < tmp.size(); i++)
    {
        for(int j = 0; j < tmp[i];j++){
            result.push_back(i);
        }
    }
    return result;
}



int main(int argc, char const *argv[])
{
    vector<int> nums = getNums<int>();
    cout << "冒泡排序:" << endl;
    vector<int> result1 = bubbleSort(nums);
    printVector(result1, " ");
    cout << "选择排序:" << endl;
    vector<int> result2 = choiceSort(nums);
    printVector(result2, " ");
    cout << "插入排序:" << endl;
    vector<int> result3 = insertSort(nums);
    printVector(result3, " ");
    cout << "快速排序:" << endl;
    vector<int> tmp4(nums);
    vector<int> result4 = quickSort(tmp4, 0, tmp4.size()-1);
    printVector(result4, " ");
    cout << "堆排序:" << endl;
    vector<int> result5 = heapSort(nums);
    printVector(result5, " ");
    cout << "希尔排序:" << endl;
    vector<int> result6 = shellSort(nums);
    printVector(result6, " ");
    cout << "归并排序:" << endl;
    vector<int> tmp7(nums);
    vector<int> result7 = mergeSort(tmp7, 0, tmp7.size() - 1);
    printVector(result7, " ");
    cout << "计数排序:" << endl;
    vector<int> result8 = countSort(nums);
    printVector(result8, " ");
    return 0;
}

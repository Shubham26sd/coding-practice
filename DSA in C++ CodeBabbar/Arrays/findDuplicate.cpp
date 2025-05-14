
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr){
        bool sorted = false;
        int n = arr.size();
        for(int i = 1; i<n; i++){
            for(int j = 0; j<n-i; j++){
                if(arr[j]>arr[j+1]) {
                    swap(arr[j],arr[j+1]);
                    sorted = true;
                }
            }
            if(sorted == false){
                break;
            }
        }
    }

    int findDuplicate(vector<int>& nums) {
        bubbleSort(nums);
        int ans = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==nums[i+1])
                ans = nums[i];
        }
        return ans;
    }
    void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


int main() {
    vector<int> nums{5,2,3,1,2};
    int a = findDuplicate(nums);
    cout<<a<<endl;
    printArray(nums, nums.size());
    

    return 0;
}
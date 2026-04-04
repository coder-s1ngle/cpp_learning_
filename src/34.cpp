#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int middle = left + (right - left)/2;
            if(nums[middle]==target){
                return searchContinous(nums,middle);
            }else if(nums[middle] < target){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        return {-1,-1};
        
    }

    vector<int> searchContinous(vector<int>&nums,int middle){
        int left = searchLeft(nums,middle);
        int right = searchRight(nums,middle);
        vector<int> range;
        return {left,right};
    }
    int searchLeft(vector<int>&nums,int middle){
        int target = nums[middle];
        while(middle>0 && nums[middle - 1] == target){
            middle--;
        }
        return middle;
    }
    int searchRight(vector<int>&nums,int middle){
        int target = nums[middle];
        while(middle <= nums.size() &&nums[middle + 1] == target){
            middle++;
        }
        return middle;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    Solution s;
    vector<int> res = s.searchRange(nums,target);
    cout << res[0] << "," << res[1] << endl; 
    return 0;
}
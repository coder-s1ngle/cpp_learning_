#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        int n = nums.size()-1;
        vector<int> ref = nums;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                ref[n] = nums[i]*nums[i];
                i++;
                n--;
            }else{
                ref[n] = nums[j]*nums[j];
                j--;
                n--;
            }
        }
        return ref;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-7,-3,2,3,11};
    vector<int> ref = sol.sortedSquares(nums);
    for(int i =0;i<ref.size();i++){
        cout << ref[i];
    }
    return 0;
}
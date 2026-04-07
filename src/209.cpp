#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sums = 0;
        int length = 0;
        for(;j<nums.size();j++){
            sums += nums[j];
            // length = j - i + 1;
            while(sums>=target){
                if(!length || length > j - i + 1) length = j - i + 1; 
                sums -= nums[i];
                i++;
            }
        }
        return length; 
    }
};

int main() {
    Solution Sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout<<Sol.minSubArrayLen(target,nums);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int length = 1;
        int number_1 = fruits[0];
        
        int begin = 0;
        int end = 1;
        while(fruits[end]==number_1){
            if(end==fruits.size()-1) return end+1;
            end++;
        }
        // cout<<end<<std::endl;
        int number_2 = fruits[end];
        length = end - begin +1;
        for(;end<fruits.size();end++){
            if(fruits[end]==number_1 || fruits[end]==number_2){
                if(length < end - begin + 1) length = end - begin + 1;
            }else{
                begin = end - 1;
                int temp = fruits[begin];
                while (begin >= 0 && fruits[begin] == temp) {
                    begin--;
                }
                begin++;
                number_1 = fruits[begin];
                number_2 = fruits[end];
                if(length < end - begin + 1) length = end - begin + 1;
            }
        }
        return length;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<sol.totalFruit(fruits);
    return 0;
}
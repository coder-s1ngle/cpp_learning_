#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int mySqrt(int x){
        if (x == 1)  return 1;
        int left = 1;
        int right = x / 2;  
        while(left <= right){
            int middle = (left + right) /2;

            if(middle * middle > x){
                right = middle - 1; 
            }else if(middle * middle < x){
                left = middle + 1;
            }else{
                return middle;
            }
        }
        return right;
    }
};

int main() {
    int x = 1;
    Solution s;
    cout << s.mySqrt(x);
    return 0;
}
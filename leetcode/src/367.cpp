#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool isPerfectSquare(int num){
        if(num==1) return true;
        int l = 1;
        int r = num / 2;
        while(l<=r){
            int middle = (l+r)/2;
            //middle * middle 越界
            if(num % middle ==0 && (num / middle) == middle){
                return true;
            }else if(num / middle > middle){
                l = middle + 1;
            }else{
                r = middle - 1;
            }
        }
        return false;
    }
};

int main() {
    int num = 15;
    Solution s;
    cout << s.isPerfectSquare(num);
    return 0;
}
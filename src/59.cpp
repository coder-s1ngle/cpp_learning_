#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startx = 0;
        int starty = 0;
        int offset = 1;
        int loop = n/2;
        int mid = n/2;
        int num = 1;
        vector<vector<int>> Matrix(n,vector<int>(n,0));
        while(loop--){
            int i = 0;
            int j = 0;
            for(;j<n - offset;j++){
                Matrix[i][j] = num++;
            }
            for(;i <n - offset;i++){
                Matrix[i][j] = num++;
            }
            for(;j<startx;j--){
                Matrix[i][j] = num++;
            }
            for(;i<starty;i--){
                Matrix[i][j] = num++;
            }
            startx +=1;
            starty +=1;
            offset+=1;
            
        }
        if(n%2) Matrix[mid][mid] = num;
        return Matrix;
    }
};

int main() {
    Solution sol;
    sol.generateMatrix(5);
    return 0;
}
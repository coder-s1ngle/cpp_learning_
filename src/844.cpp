#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slowPtr_s = 0;
        int slowPtr_t = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i]!='#'){
                s[slowPtr_s] = s[i];
                slowPtr_s++;
            }else{
                if(slowPtr_s>0) slowPtr_s--;
            }
        }
        for(int i = 0;i<t.length();i++){
            if(t[i]!='#'){
                t[slowPtr_t] = t[i];
                slowPtr_t++;
            }else{
                if(slowPtr_t>0) slowPtr_t--;
            }
        }

        if(slowPtr_s!=slowPtr_t){
            return false;
        }else{
            for(int i = 0;i<slowPtr_s;i++){
                if(s[i]!=t[i]) return false;
            }
        }
        // for(int i = 0;i<slowPtr_s;i++){
        //     cout<<s[i];
        // }

        // for(int i = 0;i<slowPtr_t;i++){
        //     cout<<t[i];
        // }
        return true;
    }
};

int main() {
    string s = "ab#c";
    string t = "ad#c";
    Solution sol;
    cout<<sol.backspaceCompare(s,t);
    return 0;
}
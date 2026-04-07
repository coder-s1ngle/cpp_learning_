#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> isSame(26, 0);
        
        for(int i = 0; i < s.length(); i++){
            isSame[s[i] - 'a']--;
        }
        for(int i = 0; i < t.length(); i++){
            isSame[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(isSame[i] != 0) 
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout<<sol.isAnagram("abc","dbac");
    return 0;
}
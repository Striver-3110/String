#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

auto __init__ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

#pragma optimize("03");

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int len = s.length();
        int maxOdd = 0;
        for(int i = 0; i < len; i++){
            mp[s[i]]++;
        }

        int palLen = 0;
        bool odd = false;
        for(auto& pair : mp){
            if(pair.second % 2 == 0){
                palLen += pair.second;
            } else {
                palLen += pair.second - 1;
                odd = true;
            }
        }
        if(odd){
            palLen++;
        }
        return palLen;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = sol.longestPalindrome(s);
    cout << "The length of the longest palindrome that can be built is: " << result << endl;
    return 0;
}

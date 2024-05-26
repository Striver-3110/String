#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char,int> m1;
        
        int n = words.size();
        for(auto& ch: words[0]){
            m1[ch]++;
        }

        for(int i = 1; i < n; i++){
            map<char,int> m2;
            for(auto& ch: words[i]){
                m2[ch]++;
            }

            for(auto it1 = m1.begin(); it1 != m1.end(); it1++){
                if(m2.find(it1->first) != m2.end()){
                    it1->second = min(it1->second, m2[it1->first]);
                } else {
                    it1->second = 0;
                }
            }
        }

        vector<string> c;
        for(auto& pair : m1){
            while(pair.second--){
                c.push_back(string(1, pair.first));
            }
        }
        return c;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"bella", "label", "roller"};
    
    vector<string> commonCharacters = sol.commonChars(words);
    
    cout << "Common characters: ";
    for(const auto& ch : commonCharacters) {
        cout << ch << " ";
    }
    cout << endl;
    
    return 0;
}

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        
        int len = s.length();
        int i = len-1;
        while(s[i] == '1'){
            s[i] = '0';
            i--;
        }
        if(i == -1){
            s = '1' + s;
        }else{
            s[i] = '1';
        }
        string temp = "";
        i = 0;
        bool flg = false;
        while(s[i] == '0'){
            i++;
            flg = true;
        }
        if(flg){
            for(int j = i; j < len; j++){
                temp += s[j];
            }
        }else{
            temp = s;
        }
        
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
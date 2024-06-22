//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends


class Solution {
    private:
        std::vector<std::string> split(const std::string& str, char del){
            std::vector<std::string> tokens;
            std::string token;
            std::stringstream ss(str);
            while(getline(ss, token, del)){
                tokens.push_back(token);
            }
            return tokens;
        }

        // std::string trim(const std::string& str) {
        //     std::string temp = str;
        //     temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), [](unsigned char ch) {
        //         return !std::isspace(ch);
        //     }));
        //     temp.erase(std::find_if(temp.rbegin(), temp.rend(), [](unsigned char ch) {
        //         return !std::isspace(ch);
        //     }).base(), temp.end());
        //     return temp;
        // }

    public:
        std::string compareFrac(const std::string& str) {
            std::vector<std::string> fractions = split(str, ', ');
            std::vector<std::string> fraction1 = split(fractions[0], '/');
            std::vector<std::string> fraction2 = split(fractions[1], '/');

            int a = std::stoi(fraction1[0]);
            int b = std::stoi(fraction1[1]);
            int c = std::stoi(fraction2[0]);
            int d = std::stoi(fraction2[1]);

            if(static_cast<double>(a) / b > static_cast<double>(c) / d) {
                return std::to_string(a) + "/" + std::to_string(b);
            }
            if(static_cast<double>(a) / b < static_cast<double>(c) / d) {
                return std::to_string(c) + "/" + std::to_string(d);
            } else {
                return "equal";
            }
        }
};




//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
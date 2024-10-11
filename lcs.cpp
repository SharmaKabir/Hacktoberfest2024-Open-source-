#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the length of the Longest Common Subsequence
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    // Create a 2D DP table to store the lengths of LCS for subproblems
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                // If characters match, take the diagonal value and add 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // If characters don't match, take the maximum of either removing one character from text1 or text2
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // The length of LCS will be at dp[n][m]
    return dp[n][m];
}

int main() {
    string text1, text2;
    
    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;
    
    int lcsLength = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;
    
    return 0;
}

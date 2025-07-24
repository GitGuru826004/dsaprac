class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // dp[i] mein hum store karenge saare valid parentheses combinations with i pairs
        vector<vector<string>> dp(n + 1);

        // base case: agar koi pair nahi hai, toh ek hi combination hai — empty string
        dp[0] = {""};

        // loop from 1 to n to fill dp[i]
        for (int i = 1; i <= n; i++) {
            // dp[i] build karne ke liye, har j value try karenge
            // j = andar kitne pairs honge, bacha hua part bahar ka hoga
            for (int j = 0; j < i; j++) {
                // andar ka valid combination (j pairs)
                for (const string &inside : dp[j]) {
                    // bahar ka valid combination (i-1-j pairs)
                    for (const string &outside : dp[i - 1 - j]) {
                        // final string banegi: "(" + andar + ")" + bahar
                        dp[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }

        // finally dp[n] mein humein saare valid parentheses milenge
        return dp[n];
    }
};

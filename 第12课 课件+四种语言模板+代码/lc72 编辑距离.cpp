class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        word1 = " " + word1;
        word2 = " " + word2;
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) f[i][0] = i;  //abc->[]
        for (int j = 0; j <= m; j++) f[0][j] = j;  //[]->abc
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(
                    min(f[i - 1][j] + 1, f[i][j - 1] + 1),
                    f[i - 1][j - 1] + (word1[i] != word2[j]));
            }
        return f[n][m];
    }
};
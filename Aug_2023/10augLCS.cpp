// LCS - Longest Common Subsequence 
// Input - two strings, I have to find the longest common subsequence in both the string 
// eg. str1 = ABDKSHF str2 = ASWIWUHF  output - ASHF (4)

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string str1, string str2, int m, int n)
{
    if(m == 0 || n == 0){
        return 0;
    }
    if(str1[m-1] == str2[n-1]){
        return (1+longestCommonSubsequence(str1, str2, m-1, n-1));
    }
    else{
        return max(longestCommonSubsequence(str1, str2, m, n-1), longestCommonSubsequence(str1, str2, m-1, n));
    }
}
int main()
{
    string str1 = "ABNMSHF";
    string str2 = "AWURYONWOMSH";
    int m = str1.size();
    int n = str2.size();
    cout<<longestCommonSubsequence(str1, str2, m, n);
    return 0;
}

// Optimised Code 

// int n = text1.size();
//     int m = text2.size();
 
//     // initializing 2 vectors of size m
//     vector<int> prev(m + 1, 0), cur(m + 1, 0);
 
//     for (int idx2 = 0; idx2 < m + 1; idx2++)
//         cur[idx2] = 0;
 
//     for (int idx1 = 1; idx1 < n + 1; idx1++) {
//         for (int idx2 = 1; idx2 < m + 1; idx2++) {
//             // if matching
//             if (text1[idx1 - 1] == text2[idx2 - 1])
//                 cur[idx2] = 1 + prev[idx2 - 1];
 
//             // not matching
//             else
//                 cur[idx2]
//                     = 0 + max(cur[idx2 - 1], prev[idx2]);
//         }
//         prev = cur;
//     }
 
//     return cur[m];
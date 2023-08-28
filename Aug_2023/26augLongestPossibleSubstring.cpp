// Find the length of the longest possible substring made up of excatly k unique characters, if there is not any just return -1
// inputs - string and k

//User function template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int n=s.size();
    if(k<=0)
    {
        return -1;
    }
    int i=0,ans=-1,cnt=0;
    unordered_map<char,int> charCount;
    for(int j=0;j<n;j++)
    {
        charCount[s[j]]++;
        if(charCount[s[j]]==1)
        {
          cnt++;
        }
        while(cnt>k)
        {
            charCount[s[i]]--;
            if(charCount[s[i]]==0)
            {
                cnt--;
            }
            i++;
        }
        if(cnt==k)
        {
            ans=max(ans,j-i+1);
        }
    }
    return ans;
    }
};
int main()
{
    Solution obj;
    cout<<obj.longestKSubstr("ababcddedede", 3);
    return 0;
}
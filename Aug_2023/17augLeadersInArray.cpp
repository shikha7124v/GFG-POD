// Finding the leaders in the array. leader is the element of the array which is having all it's right hand side element smaller than itself
#include<bits/stdc++.h>
using namespace std;

vector<int> leader(vector<int> arr, int n)
{
    int mx = arr[n-2];
    vector<int> ans;
    ans.push_back(mx);

    for(int i=n-2; i>=0; i--){
        if(arr[i] < mx){
            continue;
        }
        mx = arr[i];
        ans.push_back(mx);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr{16, 17, 4, 3, 5, 2};
    int n = arr.size();
    vector<int> leaders = leader(arr, n);
    for(auto it: leaders){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
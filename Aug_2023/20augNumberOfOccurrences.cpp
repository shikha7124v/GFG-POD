#include<bits/stdc++.h>
using namespace std;

int noOfOccurrence(vector<int> arr, int x)
{
    int n = arr.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr{1,2,2,3,4,5,6};
    int x = 2;
    cout<<noOfOccurrence(arr, x);
    return 0;
}
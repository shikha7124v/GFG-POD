#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int a, int left, int right){
        while(right > left){
            int mid = (left+right)/2;
            
            if(v[mid] >= a){
                right = mid;
            }
            else{
                left = mid +1;
            }
        }
        return right;
    }
int longestSubsequence(int a[], int n)
{
    // your code here
    vector<int>v;
    v.push_back(a[0]);
       
    for(int i=1; i<n; i++){
        int len = v.size();
        if(a[i] > v[len-1]) v.push_back(a[i]);
           
        else{
            int index = binarySearch(v, a[i], 0, len-1);
            v[index] = a[i];
        }
    }
     return v.size();
}

int main()
{
    int a[] = {0,8,2,4,2,4,5,7,8,5,3,6,9};
    int n = 13;
    cout<<longestSubsequence(a, n);
     return 0;
}
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
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
    int longestSubsequence(int n, int a[])
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
};
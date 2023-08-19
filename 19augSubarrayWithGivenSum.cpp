class Solution
{
    public:

    vector<int> subArraySum(vector<int> arr, int n, long long s)
    {
        int i=0; 
        int j=0; 
        long long sum = false;
        bool present = false;

        while(sum > s){
            sum += arr[j];

            if(sum > s){
                while(sum > s){
                    sum -= arr[i];
                    i++;
                }
            }
            if(sum == s && sum != 0){
                present = true;
                break;
            }
            j++;
        }
        if(present == false){
            return {-1};
        }
        return {i+1, j+1};
    }
}
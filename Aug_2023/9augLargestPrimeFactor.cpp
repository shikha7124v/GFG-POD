#include<bits/stdc++.h>
using namespace std;

long long int largestPrimeFactor(int N)
{
    long long int maxPrime = -1;
    while(N%2 == 0){
        maxPrime = 2;
        N = N/2;
    }
    while(N%3 == 0){
        maxPrime = 3;
        N = N/3;
    }
    for(int i=5; i<=sqrt(N); i = i+6)
    {
        while(N%i == 0)
        {
            maxPrime = i;
            N = N/i;
        }
        while(N%(i+2) == 0){
            maxPrime = i+2;
            N = N/(i+2);
        }    
    }
    if(N>4){
        maxPrime = N;
    }
    return maxPrime;
}
int main()
{
    int N = 147;
    cout<<largestPrimeFactor(N);
    return 0;
}
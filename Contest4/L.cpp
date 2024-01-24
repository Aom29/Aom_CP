#include <bits/stdc++.h>
using namespace std;

long long sum(long long a, long long b)
{
    return (a + b) * (b - a + 1) / 2;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    k--;
    long long lo = 1;
    long long hi = k;
    long long mid;
    long long count = 1 + sum(lo, hi);

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    } else if (count < n)
    {
        cout << -1 << endl;
        return 0;
    }
    bool caso = true;
    // Binary search
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        count = 1 + sum(mid, k);
        if (count == n)
            break;
        else if (count < n){
            //cout << "A";
            caso = true;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
            caso = false;
            //cout << "B";
        }
    }
    if(caso){
        cout << k - lo + 1 << endl;
    }
    else{
        cout << k - lo + 2 << endl;
    }
    return 0;
}
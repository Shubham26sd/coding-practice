#include <bits/stdc++.h>
#include <math.h>
#include <vector>
// using std::vector;
using namespace std;

int prod(vector<int> arr, int size)
{
    int sum = 0;
    int j = 1;
    for(int i = 1; i< size; i++){
        j = j*10;
    }
    
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i] * j;
        j = j / 10;
    }
    return sum;
}
int count(int a)
{
    int digit = 0;

    while (a > 0)
    {
        digit++;
        a = a / 10;
    }
    return digit;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int as = a.size();
    int bs = b.size();
    int sum = prod(a,as ) + prod(b, bs);
    vector<int> ans(count(sum));
    int s = count(sum);
    for (int i = s-1; i >= 0; i--)
    {
        ans[i] = sum % 10 ;
        sum = sum / 10;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return ans;
}
int main()
{
    vector<int> a{9,9,9};
    vector<int> b{9,9,9};
    vector<int> ans;
    findArraySum(a, a.size(), b, b.size());

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {100, 200, 300, 400, 500};

    // vector<int>::iterator it = v.begin();
    //  cout << *(it);

    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it)<<" ";
    // }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    v.erase(v.begin() + 1, v.end() - 1);
    v.insert(v.begin(),300);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}
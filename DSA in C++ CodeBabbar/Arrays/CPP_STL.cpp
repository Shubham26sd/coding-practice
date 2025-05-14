#include <bits/stdc++.h>
using namespace std;


void explainPair()
{

    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second<<endl;

    pair<int, pair<int, int>> q = {1, {3, 4}};
    cout << q.first << " " << q.second.second << " " << q.second.first<<endl;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    cout << arr[1].second<<endl;
}

void explainVector(){
    
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>>vec;

    v.push_back({1,2});
    v.emplace_back(1,2);

    vector<int> v(5,100);

    vector<int> v(5);

    vector<int> v1(5,20);
    vector<int> v2(v1);

    
}

int main()
{
    // explainPair();
    explainVector();
    return 0;
}
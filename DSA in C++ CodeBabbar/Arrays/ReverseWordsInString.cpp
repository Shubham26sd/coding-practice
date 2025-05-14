#include <iostream>
using namespace std;

string reverseWords(string s)
{
    int i = 0;
    int start = i;
    int end;
    int j;
    while (i <= s.length())
    {
        if (s[i] == '\0' || s[i] == ' ')
        {
            j = i + 1;
            end = i-1;
            while (start <= end)
            {
                swap(s[start++], s[end--]);
            }
            start = i + 1;
        }
        i++;
    }
    return s;
}

int main()
{
    string temp = "My name is shubham";
    string ans = reverseWords(temp);
    cout << ans << endl;
    return 0;
}
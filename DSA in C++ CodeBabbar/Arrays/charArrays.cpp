#include <iostream>
using namespace std;

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(char s[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        if (toLowerCase(s[start]) != toLowerCase(s[end]))
            return 0;
        else
        {
            start++;
            end--;
        }
    }
    return 1;
}

char getMaxOccCharacter(string s)
{

    int arr[26] = {0};

    // create an array of count of characters
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
    }

    // find max occ character
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    return 'a' + ans;
}

string removeOccurrences(string s, string part) {
        while (s.length() != 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part),part.length());
        }
        return s;
    }

int main()
{
    // char name[20];
    // cout << "Enter your name: ";
    // cin >> name;
    // // name[2]='\0';
    // cout << "Your name is " << name << endl;

    // int len = getLength(name);
    // cout << "Length is : " << len << endl;

    // reverse(name, len);
    // cout << "Reversed name is : " << name << endl;

    // cout << "Palindrome : " << checkPalindrome(name, getLength(name)) << endl;
    string s;
    cin >> s;
    cout << getMaxOccCharacter(s);
    return 0;
}
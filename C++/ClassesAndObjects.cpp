#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
  string s;
  void chk_bin(void);

public:
  void read(void);
  void display(void);
  void ones_complement(void);
};

void binary ::read(void)
{
  cout << "Enter the binary number : " << endl;
  cin >> s;
}

void binary::chk_bin(void)
{
  for (int i = 0; i < s.length(); i++)
  {
    if (s.at(i) != '0' && s.at(i) != '1')
    {
      cout << "Incorrect Binary format" << endl;
      exit(0);
    }
  }
}

void binary::display(void)
{ 
  cout<<"Displayig your binary number"<<endl;
  for (int i = 0; i < s.length(); i++)
  {
    cout<<s.at(i);
  }
  cout<<endl;
}

void binary ::ones_complement(void)
{
  chk_bin();
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '0')
    {
      s[i] = '1';
    }
    else
    {
      s[i] = '0';
    }
  }
}

int main()
{
  binary obj;
  obj.read();
  // obj.chk_bin();
  obj.display();
  obj.ones_complement();
  obj.display();
  return 0;
}
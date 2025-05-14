#include <iostream>
using namespace std;

class Employee
{
  static int count;
  int id;

public:
  void setData(void);
  void getData(void);
  static void getCount(void)
  {
    cout << "The value of count is : " << count << endl;
  }
};

void Employee::setData(void)
{
  cout << "Enter the id" << endl;
  cin >> id;
  count++;
}

void Employee::getData(void)
{
  cout << "The id of the employee is " << id << " and the number is " << count << endl;
}
int Employee::count = 1000; // Default value is 0
int main()
{
  Employee shubh;
  shubh.setData();
  shubh.getData();
  Employee::getCount();
  shubh.setData();
  shubh.getData();
  Employee::getCount();
  shubh.setData();
  shubh.getData();
  Employee::getCount();
  return 0;
}
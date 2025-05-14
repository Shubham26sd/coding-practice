//Create a function to calculate distance between two p0ints 
#include<iostream>
#include<math.h>
using namespace std;
class point{

    public:
    int x,y;
    point(void);
    friend void distance(int, int);
    void input(int , int);
};

point :: point(void)
{
    x=0;
    y=0;
}
void point :: input(int a , int b)
{
    x=a;
    y=b;
}
void distance(point o1, point o2)
{
    float dist;
    dist = sqrt(pow((o1.x-o2.x),2)+pow((o1.y-o2.y),2));
    cout<<"Distance between both points is : "<<dist<<endl;
}
int main()
{
    point c1,c2;
    c1.input(-2,4);
    c2.input(2,1);
    distance(c1,c2);
    return 0;
}
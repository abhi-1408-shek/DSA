#include<iostream>
using namespace std;
class Car{
    public:
    int price;
    int seats;
    string type;
    string name;
};
void print(Car c){
    cout<<" "<<c.name<<" "<<c.price<<" "<<c.type<<" "<<c.seats<<endl;
}
int main()
{
    Car c1;
    cout<<"Enter the name of first car:";
    cin>>c1.name;
    cout<<"Enter the seats of first car:";
    cin>>c1.seats;
    cout<<"Enter the price of first car:";
    cin>>c1.price;
    cout<<"Enter the type of first car:";
    cin>>c1.type;
    print(c1);
 return 0;
}
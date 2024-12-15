#include<iostream>
using namespace std;
int main(){
    int numerator, denominator, result;
    cout<<"enter the numerator and denominator respectively";
    cin>>numerator>>denominator;
    try{
        if(denominator == 0){
            throw denominator;
        }
        
        result = numerator/denominator;
    }
    catch(int ex){
        cout<<"Divison by zero is not allowed";
    }
    cout<<"The result is :"<<result;
 return 0;
}
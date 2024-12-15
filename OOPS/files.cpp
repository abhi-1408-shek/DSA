#include<iostream>
#include<fstream>
using namespace std;
int main(){
ofstream out;
out.open("sample.txt");
out<<"This is me";
out.close();

ifstream in;
string str;
in.open("sample.txt");
getline(in,str);
cout<<"the data is :"+ str;
in.close();
 return 0;

}
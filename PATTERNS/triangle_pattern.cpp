
/*************************************************QUESTION-1************************************************/

// *
// **
// ***
// ****


// #include<iostream>
// using namespace std;
// int main()
// {
//     char c = '*';
//     int n = 1;
//     for(int i=0;i<4;i++){
//         for(int j=0;j<n;j++){
//             cout<<c;
//         }
//         cout<<endl;
//         n++;
//     }
//  return 0;
// }


/*************************************************QUESTION-2************************************************/

// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 


// #include<iostream>
// using namespace std;
// int main()
// {
//  int n = 1;
//  int l=4;
//  for(int i=0; i<l;i++){
//     for(int j=0; j<=i; j++){
//         cout<<n<<" ";
//     }
//     cout<<endl;
//     n++;
//  }
//  return 0;
// }


/*************************************************QUESTION-3************************************************/

// A 
// B B 
// C C C 
// D D D D 
// E E E E E 


// #include<iostream>
// using namespace std;
// int main()
// {
//     int n = 5;
//     char num = 'A';
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<num<<" ";
//         }
//         num++;
//         cout<<endl;
//     }
//  return 0;
// }


/*************************************************QUESTION-4************************************************/

// 1
// 12
// 123
// 1234

// #include<iostream>
// using namespace std;
// int main()
// {
//     int n=4;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<j+1;
//         }
//         cout<<endl;
//     }
//  return 0;
// }


/*************************************************QUESTION-5************************************************/

//REVERSE TRIANGLE PATTERN
// 1 
// 2 1 
// 3 2 1 
// 4 3 2 1 


// #include<iostream>
// using namespace std;
// int main()
// {int n=4;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j>0;j--){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//  return 0;
// }


/*************************************************QUESTION-6************************************************/

//FLOYD'S TRIANGLE PATTERN
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 


// #include<iostream>
// using namespace std;
// int main()
// {
//   int n=4;
//   int num =1;
//   for(int i=1;i<n+1;i++){
//     for(int j=0;j<i;j++){
//         cout<<num<<" ";
//         num++;
//     }
    
//     cout<<endl;
//   }
//  return 0;
// }


/*************************************************QUESTION-7************************************************/

//FLOYD'S TRIANGLE PATTERN(CHARACTER VERSION)
// A 
// B C 
// D E F 
// G H I J 

// #include<iostream>
// using namespace std;
// int main()
// {
//     char alpha = 'A';
//     int n = 4;
//     for(int i=0;i<n;i++){
//         for(int j=i;j>=0;j--){
//             cout<< alpha<<" ";
//             alpha++;
//         }
//         cout<<endl;
//     }
//  return 0;
// }

/*************************************************QUESTION-8************************************************/

//REVERSE TRIANGLE PATTERN(CHARACTER VERSION)
// A 
// B A 
// C B A 
// D C B A 

// #include<iostream>
// using namespace std;
// int main()
// {
//     char c='A';
//     int n = 4;
//     for(int i=0;i<n;i++){
//         for(char j=c;j>='A';j--){
//             cout<<j<<" ";
//         }
//         c++;
//         cout<<endl;
//     }
//  return 0;
// }


/*************************************************QUESTION-9************************************************/

//INVERTED TRIANGLE PATTERN

#include<iostream>
using namespace std;
int main()
{
    int n=4;
    for(int i=0;i<n;i++){
        for(int j=0; j<=i; j++ ){
            cout<<" ";
        }
        for(int j=n;j>i;j--){
            cout<<i+1;
        }
        cout<<endl;
    }
 return 0;
}
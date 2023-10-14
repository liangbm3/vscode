#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i,j;
    cin>>i;
    cin>>j;
    cout<<i<<" "<<j<<endl;
    cin.clear();
    cin.sync();
    char c1,c2,c3;
    cout<<"Enter you first,middle and last initials"<<endl;
    cin>>c1;
    cin.sync();
    cin>>c2;
    cin.sync();
    cin>>c3;
    cout<<"You entered "<<c1<<c2<<c3<<endl;
    string c4;
    cin>>c4;
    cout<<"You entered "<<c4<<endl;
    return 0;
}
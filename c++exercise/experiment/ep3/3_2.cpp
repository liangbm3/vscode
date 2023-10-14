#include <iostream>
#include <string>
using namespace std;
int main()
{
    string middleName,petName;
    string alterEgoName;
    cout<<"please enter your middle name and name of your pet.\n";
    getline(cin,middleName);
    getline(cin,petName);
    alterEgoName=petName+" "+middleName;
    cout<<"The name of your alter ego is ";
    cout<<alterEgoName<<"."<<endl;
}
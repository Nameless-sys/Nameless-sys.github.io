#include <iostream>
using namespace std;
#include<fstream>
#include <iomanip>
#include <algorithm>
#include <time.h>
const int MAX = 1e6 + 5;
int a[MAX];
int main(){
    ifstream Input("Data_1");
    if(Input.fail())
    {
        cout << "Failed to open this file!" << endl;
	return 0;
    }
    else
	{
	    clock_t start_t, end_t;
    for(int i=0;i<1000000;i++)
        Input>>a[i];
        start_t=clock();
     sort(a,a+1000000);
     end_t=clock();
     cout<<"Cost: "<<end_t-start_t<<" ms";
     for(int i=0;i<1000000;i++)
        cout<<a[i]<<" ";
    Input.close();}

}

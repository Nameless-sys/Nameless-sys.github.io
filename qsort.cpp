#include <iostream>
using namespace std;
#include<fstream>
#include <iomanip>
#include <algorithm>
#include <time.h>
const int MAX = 1e6 + 5;
int a[MAX];
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main(){
    ifstream Input("Data_3");
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
     qsort(a, 1000000, sizeof(float), cmpfunc);
     end_t=clock();
     cout<<"Cost: "<<(float)(end_t-start_t)<<" ms";
     for(int i=0;i<1000000;i++)
        cout<<a[i]<<" ";
    Input.close();}

}

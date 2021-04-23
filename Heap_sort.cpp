#include <iostream>
using namespace std;
#include<fstream>
#include <iomanip>
#include <algorithm>
#include <time.h>
const int MAX = 1e6 + 5;
float a[MAX];
void Heapify(float a[], int n, int i)
{
  int root = i;
  int l = 2*i + 1;  // vi tri trai = 2*i + 1
  int r = 2*i + 2;  // vi tri phai= 2*i + 2

  // con trai lon hon root
  if (l < n && a[l] > a[root])
    root = l;

  // con phai lon hon root
  if (r < n && a[r] > a[root])
    root = r;

  // neu root chưa phai vi tri lon nhat
  if (root != i)
  {
    swap(a[i], a[root]);
    Heapify(a, n, root);
  }
}

void HeapSort(float a[], int n)
{
    //chia mang thanh 2 nua roi bat dau heap trai
  for (int i = (n/2) - 1; i >= 0; i--)
    Heapify(a, n, i);
    //swap trai phai roi heap
  for (int i = n-1; i >= 0; i--)
  {
    swap(a[0], a[i]);
    Heapify(a, i, 0);
  }
}
int main(){
    ifstream Input("Data_10");
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
     HeapSort(a,1000000);
     end_t=clock();
     cout<<"Cost: "<<end_t-start_t<<" ms";
     for(int i=0;i<1000000;i++)
        cout<<a[i]<<" ";
    Input.close();}

}

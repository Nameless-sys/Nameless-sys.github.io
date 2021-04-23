#include <iostream>
using namespace std;
#include<fstream>
#include <iomanip>
#include <time.h>
const int MAX = 1e6 + 5;
int a[MAX];
void Partition(int A[], int left, int right)
{
    // Kiểm tra xem nếu mảng có 1 phần tử thì không cần sắp xếp
    if (left >= right)
        return;
    int pivot = A[(left + right) / 2]; // Chọn phần tử chính giữa dãy làm chốt
    // i là vị trí đầu và j là cuối đoạn
    int i = left, j = right;
    while (i < j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j)
        {
            if (i < j)
                swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    // Gọi đệ quy sắp xếp dãy bên trái pivot
    Partition(A, left, j);
    // Gọi đệ quy sắp xếp dãy bên phải pivot
    Partition(A, i, right);
}
void QuickSort(int A[], int n)
{
    Partition(A, 0, n);
}
int main(){
    ifstream Input("Data_5");
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
    QuickSort(a,1000000);
     end_t=clock();
     cout<<"Cost: "<<end_t-start_t<<" ms";
     for(int i=0;i<1000000;i++)
        cout<<a[i]<<" ";
    Input.close();}

}

#include<iostream>
#include<vector>
using namespace std;

bool Swap(vector<int>& arr,int size,int index1,int index2)
{
	if(index1<0 || index2<0 || index1>size-1 || index2>size-1)
		return false;
	else if(index1==index2)
		return true;
	int temp=arr.at(index1);
	arr[index1]=arr[index2];
	arr[index2]=temp;
	//cout<<arr[index1]<<" "<<arr[index2];
	return true;
}

void MaxHeap(vector<int>& arr,int num,int size)
{
	for(int i=num;i<(size/2)-2;i++)
	{
		if(arr[i]<arr[(i*2)+1])
			Swap(arr,size,i,(i*2)+1);
		if(arr[i]<arr[(i*2)+2])
			Swap(arr,size,i,(i*2)+2);
	}
}

void HeapSort(vector<int>& arr,int size)
{
	MaxHeap(arr,0,size);
	for(int i=size-1;i>size/2;i--)
	{
		//cout<<arr[i];
		Swap(arr,size,i,0);
		MaxHeap(arr,i,size);
	}


}
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
	
		if((num*2)+1<size && arr[num]<arr[(num*2)+1])
		{
			Swap(arr,size,num,(num*2)+1);
			MaxHeap(arr,(num*2)+1,size);
		}
		if((num*2)+2<size && arr[num]<arr[(num*2)+2])
		{
			Swap(arr,size,num,(num*2)+2);
			MaxHeap(arr,(num*2)+2,size);
		}
	
}

void HeapSort(vector<int>& arr,int size)
{
	for(int i=(size/2)-1;i>=0;i--)
		MaxHeap(arr,i,size);
	for(int i=size-1;i>0;i--)
	{
		//cout<<arr[i]<<"\n";
		Swap(arr,size,i,0);
		MaxHeap(arr,0,i);
	}


}
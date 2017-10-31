#include<bits/stdc++.h>
using namespace std;

void max_heapify(std::vector<int> &v, int index, int size){
	// Given an index and current heapsize. This function assumes that both left
	// and right subtrees for the given index follow max-heap property. It then 
	// moves the given index value to appropriate place.

	int left_child = 2*index + 1;
	int right_child = 2*index +2;
	int heap_size = size;
	int largest = index;

	if (left_child < heap_size && v[left_child] > v[index])
	{
		largest = left_child;
	}
	if (right_child < heap_size && v[right_child] > v[largest])
	{
		largest = right_child;
	}
	if (largest != index)
	{
		int temp = v[largest];
		v[largest] = v[index];
		v[index] = temp;
		max_heapify(v,largest,size);
	}
}

void convert_into_max_heap(std::vector<int> &v){
	// Converts a given array of elements into a array following max-heap property.
	int heap_size = v.size();
	for(int i = heap_size/2 - 1; i >= 0 ; --i) {
		max_heapify(v,i,heap_size);
	}
}

void heap_sort(std::vector<int> &v){
	// Sorts the elements. Keeps larger elements towards the end of the array and 
	// keeps decrementing heap_size 
	convert_into_max_heap(v);
	int heap_size = v.size();
	while(heap_size)
	{
		int temp = v[heap_size-1];
		v[heap_size-1] = v[0];
		v[0] = temp;

		heap_size--;
		max_heapify(v,0,heap_size);
	}
}

int main()
{
	std::vector<int> v;
	int n;
	cout<<"Enter no. of elements:\t";
	cin>>n;

	cout<<"\nEnter elements:\t";
	int input_count=0;
	int temp_input;
	while(input_count<n){
			cin>>temp_input;
			v.push_back(temp_input);
			input_count++;
	}
	// sorting starts here.
	heap_sort(v);
	cout<<"\nSorted output: \t";
	copy(v.begin(), v.end(),
			ostream_iterator<int>(cout," "));
	
	
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

void heapify_up(vector<int>&heap , int index)
{
    while(index > 0) {
        int parent_index = (index-1)/2;
        if(heap[parent_index] < heap[index]) {
            swap(heap[parent_index],heap[index]);
            index = parent_index;
        } else {
            break;
        }
    }
}

void heapify_down(vector<int>&heap,int index)
{
    while(index < heap.size()) 
    {
        int leftChild = 2*index+1;
        int rightChild = 2*index+2;
        int largest = index;
        if(leftChild < index and heap[leftChild] > heap[index]) {
            largest = leftChild;
        }
        if(rightChild < index and heap[rightChild] > heap[index]) {
            largest = rightChild;
        }
        if(largest!=index) {
            swap(heap[largest],heap[index]);
            index = largest;
        } else {
            break;
        }
    }
}

void push(vector<int>&heap,int value)
{
    heap.push_back(value);
    heapify_up(heap,heap.size()-1);
}

void pop(vector<int>&heap) {
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    heapify_down(heap,0);
}
int main()
{
    vector<int>heap;
    push(heap,10);
    push(heap,20);
    push(heap,15);
    push(heap,5);
    for(auto it:heap) {
        cout<<it<<" ";
    }
    cout<<endl;
    pop(heap);
    pop(heap);
    for(auto it:heap) {
        cout<<it<<" ";
    }
    return 0;
};
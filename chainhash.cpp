#include<iostream>
#include<vector>
using namespace std;

#define SIZE 10

struct Node {
    int val;
    struct Node* next;
    Node(int data) : val(data), next(nullptr) {}  
    Node() : next(nullptr) {}  
};

typedef struct Node* NODE;


int H(int key) 
{
    return key%SIZE;
}

void chain(int key , vector<NODE>&arr)
{
    int h_index = H(key);
    NODE temp = new Node(key);
    if(arr[h_index]->next == nullptr) {
        arr[h_index]->next = temp;
        return;
    }
    else {
        NODE temp = arr[h_index];
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(key);
        return;
    }
}

void print(vector<NODE>&arr)
{
    for(auto node:arr) {
        NODE temp = node;
        while(temp!= nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;  
    }
}

int main()
{
    vector<NODE>arr(SIZE);
    for(int i=0;i<SIZE;i++) {
        arr[i] = new Node();
    }
    vector<int>keys= {15, 18, 10, 2, 7, 12, 20, 13, 19, 5};
    for(auto key:keys) {
        chain(key,arr);
    };
    print(arr);
    for (auto node : arr) {
        NODE current = node;
        while (current != nullptr) {
            NODE next = current->next;
            delete current;
            current = next;
        }
    }
    return 0;
}

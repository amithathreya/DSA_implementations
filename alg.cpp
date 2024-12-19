#include<iostream>
using namespace std;

struct Node {
    int val;
    struct Node* next;
    Node():val(0) , next(nullptr){}
    Node(int x) : val(x) , next(nullptr){}
    Node(int x , Node* next) : val(x) , next(next){}
};

typedef struct Node* NODE;

NODE sorted(NODE left,NODE right) 
{
    if(left == nullptr) {return right;}
    if(right == nullptr) {return left;}
    NODE result;
    if(left->val <= right->val) {
        result = left;
        result->next = sorted(left->next, right);
    } else {
        result = right;
        result->next = sorted(left, right->next);
    }
    return result;
}
NODE merge(NODE head) {
    if(head == nullptr || head->next == nullptr) {return head;}
    NODE slow = head;
    NODE fast = head->next;
    while(fast!=nullptr and fast->next!=nullptr) {
        slow =slow->next;
        fast = fast->next->next;
    }
    NODE second_half = slow->next;
    slow->next = nullptr;

    NODE left = merge(head);
    NODE right = merge(second_half);

    return sorted(left, right);

}

void print(NODE head) {
    NODE temp = head;
    while(temp->next!=nullptr) {
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<temp->val<<endl;
}
int main()
{
    NODE head = nullptr;
    head = new Node(4);
    head->next = new Node(3);
    head->next->next =  new Node(3);
    head->next->next->next = new Node(1);
    NODE res = merge(head);
    cout<<"Sorted Linked List: ";
    print(res);
    return 0;
}

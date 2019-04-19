struct Node
{
    Node(int x) : val(x), next(nullptr), prev(nullptr) {};
    
    int val;
    Node* next;
    Node* prev;
};

class MyLinkedList {
    Node* Head;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() : size(0) 
    {
        Head = new Node(0);
        Head->prev = Head;
        Head->next = Head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {        
        if(size <= index || index < 0) return -1;
        auto r = Head;
        while(index--) r = r->next;
        return r->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto h = new Node(val);
        h->next = Head->next;
        h->prev = Head;
        Head->next->prev = h;
        Head->next = h;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto t = new Node(val);
        t->prev = Head->prev;
        t->next = Head;
        Head->prev->next = t;
        Head->prev = t;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size || index < -1) return;
        if(index == size) return addAtTail(val);
        if(index == -1) return addAtHead(val);
        
        auto r = Head;
        while(index--) r = r->next;
        
        auto n = new Node(val);
        n->prev = r;
        n->next = r->next;
        r->next->prev = n;
        r->next = n;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return;
        auto r = Head;
        ++index;
        while(index--) r = r->next;
        
        r->prev->next = r->next;
        r->next->prev = r->prev;
        delete r;
        --size;
    }
};

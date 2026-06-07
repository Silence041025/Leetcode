class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int val):val(val),next(nullptr){}
    };
    Node* dummyhead;
    int linkedList_size;
    MyLinkedList() {
        dummyhead = new Node(0);
        linkedList_size = 0;
    }

    int get(int index) {
        if (index>=linkedList_size||index<0) {
            return -1;
        }
        Node* cur = dummyhead -> next;
        while (index--) {
            cur = cur -> next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp -> next = dummyhead -> next;
        dummyhead -> next = temp;
        linkedList_size++;
    }

    void addAtTail(int val) {
        Node* cur = dummyhead;
        while (cur->next!=nullptr) {
            cur = cur->next;
        }
        Node* temp = new Node(val);
        temp->next = cur -> next;
        cur->next = temp;
        linkedList_size++;
    }

    void addAtIndex(int index, int val) {
        if (index<0||index>linkedList_size)return;
        if (index==linkedList_size) {
            addAtTail(val);
            return;
        }
        Node* cur = dummyhead;
        while (index--) {
            cur = cur -> next;
        }
        Node* temp = new Node(val);
        temp -> next = cur->next;
        cur->next = temp;
        linkedList_size++;
    }

    void deleteAtIndex(int index) {
        if (index<0||index>=linkedList_size)return;
        Node* cur = dummyhead;
        while (index--) {
            cur = cur -> next;
        }
        if (cur->next!=nullptr) {
            cur->next = cur->next->next;
            linkedList_size--;
        }
    }


};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
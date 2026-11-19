class MyLinkedList {
public:
    const int inf = INT_MAX;

    class Node{
    public:
        int val;
        Node *next = NULL;
        Node(int value){
            val = value;
        }
    };
    Node * dummyHead;
    void print(){

        // Node * curr = dummyHead;
        // while(curr){
        //     cout<<curr->val<<" ";
        //     curr = curr->next;
        // }
        // cout<<endl;
    }


    MyLinkedList() {
        dummyHead = new Node(inf);
    }
    
    int get(int index) {
        print();
        int i=0;
        Node * node = dummyHead->next;
        while(i<index && node){
            node = node->next;
            i++;
        }
        if(i==index && node) return node->val;
        return -1;
    }
    
    void addAtHead(int val) {
        print();
        Node *dummyHeadNext = dummyHead->next;
        dummyHead->next = new Node(val);
        dummyHead->next->next = dummyHeadNext;
    }
    
    void addAtTail(int val) {
        print();
        Node * node = dummyHead->next;
        while(node && node->next){
            node = node->next;
        }
        if(node) node->next = new Node(val);
        else dummyHead->next = new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        print();
        int i=0;
        Node * node = dummyHead->next;
        Node * prev = dummyHead;
        while(i<index && node){
            prev = node;
            node = node->next;
            i++;
        }
        if(i==index){
            prev->next = new Node(val);
            prev->next->next = node;
        }
    }
    
    void deleteAtIndex(int index) {
        print();
        int i=0;
        Node * node = dummyHead->next;
        Node * prev = dummyHead;
        while(i<index && node){
            prev = node;
            node = node->next;
            i++;
        }
        if(node && i==index) prev->next = node->next;
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
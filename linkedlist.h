using namespace std;

class List {
    struct Node {
        int data;
        Node* next;
    };
    typedef Node* nodePtr;
    
    nodePtr head, curr;
    nodePtr nodeAtIndex(int);
    void swap(List::nodePtr, List::nodePtr);
    
    public:
        List() {
            head = NULL;
            curr = NULL;
            length = 0;
        }
        int length; // contains the length of the linked list, public access
        void addNode(int);
        void selectionSort();
        void printList(); // dev function
        int dataAtIndex(int);
};

// Precondition: a linked list must exists
// Postcondition: adds the integer input into the linked list
void List::addNode(int addData) {
    
    // increments the length of the list
    length++;
    
    // creates a new pointer to Node
    // inserts addData and closes off the end with by setting next equal to NULL
    nodePtr n = new Node();
    n->data = addData;
    n->next = NULL;
    
    // algorithm to find the end of list, new node is added at the end
    if(head != NULL) {
        curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
    
    // if head is empty, the first node with be set to n
    else {
        head = n;
    }
}

// Note: function is private
// Precondition: a linked list must exists
// Postcondition: returns the node at any index in the linked list
List::nodePtr List::nodeAtIndex(int index) {
    
    // finds node at the current index
    curr = head;
    for(int i = 0; i < index; i++) {
        curr = curr->next;
    }
    
    // returns node at the given index in the list
    return curr;
}

// Precondition: a linked list must exists
// Postcondition: returns the value at any index in the linked list
int List::dataAtIndex(int index) {
    if(index >= length) {
        cout << "Out of bounds!\n";
        exit(2);
    }
    
    // finds value at the current index
    curr = head;
    for(int i = 0; i < index; i++) {
        curr = curr->next;
    }
    
    // returns value
    return curr->data;
    
}

// Note: function is private
// Precondition: a linked list exists with at least two nodes
// Postcondition: the data of the two nodes are swapped
void List::swap(nodePtr a, nodePtr b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Precondition: a linked list must exists
// Postcondition: prints the list
void List::printList() {
    curr = head;
    while(curr->next != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << curr-> data << endl;
}

// Precondition: a linked list must exists
// Postcondition: sorts the list in increasing order via selectionSort
void List::selectionSort() {
    
    // two node pointers are created for purpose of selection sort
    nodePtr currentMin, currentNode;
    
    // selection sort algorithm
    for(int i = 0; i < length; i++) {
        currentNode = nodeAtIndex(i);
        currentMin = currentNode;
        for(int j = i + 1; j < length; j++) {
            if(nodeAtIndex(j)->data < currentMin->data) {
                currentMin = nodeAtIndex(j);
            }
        }
        swap(currentNode, currentMin);
    }
}

/* creating a linked list class
https://www.youtube.com/watch?v=H5lkmKkfjD0&list=PLTxllHdfUq4fewZGVFPhzbmHTQC2UH7PJ&ab_channel=PaulProgramming
cannot use nodePtr as return type outside of scope, needed to define List::nodePtr
https://stackoverflow.com/questions/28114642/returning-a-pointer-to-struct-in-a-linked-list-class
needed to create a nodeAtIndex function */

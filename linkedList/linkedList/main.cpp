//
//  main.cpp
//  linkedList
//
//  Created by Zachary Miller on 4/3/25.
//

#include <iostream>

template <typename T>
class LinkedList
{
private:
    
    struct Node
    {
        T data; // some value
        Node* link; // memory address of NEXT item
    };

public:
    
    LinkedList() = default;
    ~LinkedList() {};
    
    void insert (T x)
    {
        Node* temp = new Node;
        temp->data = x;
        temp->link = head;
        head = temp;
    }
    
    /// Insert at specific index starting at n = 0.
    void insertAt (T x, size_t n)
    {
        Node* temp1 = new Node;
        temp1->data = x;
        temp1->link = NULL;
        
        /// Insert at head (in empty list).
        if (n == 0)
        {
            temp1->link = head;
            head = temp1;
            return;
        }
        
        Node* temp2 = head;
        for (size_t i = 0; i < n - 1; ++i)
            temp2 = temp2->link;
        
        /// Update previous index with new link pointer.
        temp1->link = temp2->link;
        temp2->link = temp1;
    }
    
    void print()
    {
        Node* temp = head; // head address
        
        /// If head pointer is NULL, list is empty.
        if (temp == NULL)
        {
            std::cout << "List is empty.\n";
            return;
        }

        std::cout << "List (from head to tail): \n";
        
        while (temp != NULL)
        {
            std::cout << temp->data << "\n";
            temp = temp->link;
        }
    }
    
    Node* head = NULL;
};

// ==============================================

int main(int argc, const char * argv[]) {

    LinkedList<int> linkedList;
        
    linkedList.insertAt(0, 0);
    linkedList.insertAt(1, 1);
    
    linkedList.print();
        
    return 0;
}

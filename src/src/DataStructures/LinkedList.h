//
//  linkedList.cpp
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
    
    /// Deconstructor version of `delete_at`
    void free_list()
    {
        while (listSize > 0)
        {
            Node* temp1 = head;

            head = temp1->link;
            delete temp1;
            --listSize;
        }
    }
    
    size_t listSize = 0;

public:
    
    LinkedList() = default;
    ~LinkedList() { free_list(); };
    
    /// Insert value at end of list.
    void insert (T x)
    {
        Node* temp = new Node;
        temp->data = x;
        temp->link = head;
        head = temp;
        
        ++listSize;
    }
    
    /// Insert value at specific index [0, n]
    void insert_at (T x, size_t n)
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
        
        ++listSize;
    }
    
    /// Break linking address and free memory at specific index [0, n]
    void delete_at (size_t n)
    {
        Node* temp1 = head;
        
        /// Delete last index.
        if (n == 0)
        {
            /// Point head to following node (break link).
            head = temp1->link;
            delete temp1;
            --listSize;
            return;
        }
        
        /// temp1 points to n-1th node
        for (size_t i = 0; i < n - 1; ++i)
            temp1 = temp1->link;
        
        Node* temp2 = temp1->link; //nth node
        temp1->link = temp2->link; //n+1th node
        
        delete temp2;
        --listSize;
    }
    
    size_t size() { return listSize; }
    
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

//
//  linkedList.cpp
//
//  Created by Zachary Miller on 4/3/25.
//

#include <iostream>

/**
 * The linked list data structure is the dynamic alternative to the static array,
 * utilizing a tree of nodes made of some input value and the memory address
 * (or "link") to the next connecting node to store data at non-contiguous memory
 * addresses. This type of heap storage has 0(1) lookup at the head of the list and
 * O(n) lookup elsewhere.
 *
 * @tparam T the type of data stored in the data structure
 */
template <typename T>
class LinkedList
{
private:
    
    struct Node
    {
        T data; // some value
        Node* link; // memory address of NEXT item
    };
    
    /// Free memory from remaining list nodes.
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
    
    /// Break linking node and free memory at specified index [0, listSize-1]
    void delete_at (size_t n)
    {
        Node* temp1 = head;

        /// If head pointer is NULL, list is empty.
        if (temp1 == NULL)
        {
            std::cout << "ERROR: Cannot delete from empty list at index n = " << std::to_string(n) << ".\n";
            return;
        }
        
        /// Delete last index.
        if (n == 0)
        {
            /// Point head to following node (break link).
            head = temp1->link;
            delete temp1;
            --listSize;
            return;
        }
        
        /// temp1 == node pushed after target node, [n-1]
        for (size_t i = 0; i < n - 1; ++i)
            temp1 = temp1->link;
        
        /// temp2 == target node for deletion, [n]
        Node* temp2 = temp1->link;
        temp1->link = temp2->link; // n+1th node
        
        delete temp2;
        --listSize;
    }
    
    size_t size() { return listSize; }
    
    /// Iterative reversal of the list.
    void reverse()
    {
        Node* temp = head;
        if (temp == NULL)
        {
            std::cout << "ERROR: Avoid reversing empty list.\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL; // tail
        while (current != NULL)
        {
            Node* next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    void print (bool isReversed)
    {
        Node* temp = head; // head address
        
        /// If head pointer is NULL, list is empty.
        if (temp == NULL)
        {
            std::cout << "ERROR: Cannot print empty list.\n";
            return;
        }
        
        std::cout << "List:";
        
        if (isReversed) {
            
            reverse_print(getHead());
            
        } else {
            
            while (temp != NULL)
            {
                std::cout << " " << temp->data;
                temp = temp->link;
            }
            
        }
        
        std::cout << "\n";
    }
    
    /// Reverse print using recursion. Does not affect intrinsic list order.
    void reverse_print (Node* head)
    {
        if (head == NULL) return; // base
        
        reverse_print (head->link);
        std::cout << " " << head->data;
    }
    
    Node* getHead() { return head; }
      
    Node* head = NULL;
};

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
    
    /// Reverse print using recursion. Does not affect intrinsic list order.
    void reverse_print (Node* head)
    {
        if (head == NULL) return; // base
        
        reverse_print (head->link);
        std::cout << " " << head->data;
    }
    
    void recursive_reverse (Node* p)
    {
        if (p->link == NULL)
        {
            m_Head = p;
            return;
        }
        
        /// Traverse head to tail.
        recursive_reverse (p->link);
        p->link->link = p;
        
        // ^^^
        // Node* q = p->link;
        // q->link = p;
        // ...where q = node where head now points
        //          p = the new next of q
        
        p->link = NULL;
    }
    
    /// Free memory from remaining list nodes.
    void free_list()
    {
        while (m_ListSize > 0)
        {
            Node* temp1 = m_Head;

            m_Head = temp1->link;
            delete temp1;
            --m_ListSize;
        }
    }
    
    size_t m_ListSize = 0;
    Node* m_Head = NULL;

public:
    
    LinkedList() = default;
    ~LinkedList() { free_list(); };
    
    /// Insert value at end of list.
    void insert (T x)
    {
        Node* temp = new Node;
        temp->data = x;
        temp->link = m_Head;
        m_Head = temp;
        
        ++m_ListSize;
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
            temp1->link = m_Head;
            m_Head = temp1;
            return;
        }
        
        Node* temp2 = m_Head;
        for (size_t i = 0; i < n - 1; ++i)
            temp2 = temp2->link;
        
        /// Update previous index with new link pointer.
        temp1->link = temp2->link;
        temp2->link = temp1;
        
        ++m_ListSize;
    }
    
    /// Break linking node and free memory at specified index [0, m_ListSize-1]
    void delete_at (size_t n)
    {
        Node* temp1 = m_Head;

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
            m_Head = temp1->link;
            delete temp1;
            --m_ListSize;
            return;
        }
        
        /// temp1 == node pushed after target node, [n-1]
        for (size_t i = 0; i < n - 1; ++i)
            temp1 = temp1->link;
        
        /// temp2 == target node for deletion, [n]
        Node* temp2 = temp1->link;
        temp1->link = temp2->link; // n+1th node
        
        delete temp2;
        --m_ListSize;
    }
    
    size_t size() { return m_ListSize; }
    
    /// Swap head and tail, reverse list elements.
    void reverse (bool isRecursive)
    {
        Node* temp = m_Head;

        if (!isRecursive) { // iterative
            
            if (temp == NULL)
            {
                std::cout << "ERROR: Avoid reversing empty list.\n";
                return;
            }
            
            Node* current = m_Head;
            Node* prev = NULL; // tail
            while (current != NULL)
            {
                Node* next = current->link;
                current->link = prev;
                prev = current;
                current = next;
            }
            m_Head = prev;
            
        } else { // recursive
         
            recursive_reverse (temp);
            
        }
    }
    
    void print (bool isReversed)
    {
        Node* temp = m_Head; // head address
        
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
    
    Node* getHead() { return m_Head; }
};

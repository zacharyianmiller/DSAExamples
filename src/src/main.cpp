//
//  linkedList2.cp
//  src
//
//  Created by Zachary Miller on 4/4/25.
//

#include "inc.h"

int main(int argc, const char * argv[]) {

    // Structure type for testing...
    DataStructureType dataStructureType = DataStructureType::LinkedList;
    
    LinkedList<int> filo;
    // ...
    
    // ----------------------------------------------------------------------
    
    switch (dataStructureType)
    {
        case DataStructureType::LinkedList:
            
            // Insert values
            filo.insert(0);
            filo.insert(1);
            filo.insert(2);
            filo.insert(3);
            filo.print();

            // Delete head node
            filo.delete_at(0);
            filo.print();
            
            break;
            
        default: // None
            assert("Data structure type not specified.");
    }
        
    return 0;
}

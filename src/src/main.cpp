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
    
    LinkedList<int> list;
    // ...
    
    // ----------------------------------------------------------------------
    
    switch (dataStructureType)
    {
        case DataStructureType::LinkedList:
            
            // Insert values
            list.insert(0);
            list.insert(1);
            list.insert(2);
            list.insert(3);
            
            list.reverse (true);
            list.print(false);
            
            break;
            
        default: // None
            assert("Data structure type not specified.");
    }
        
    return 0;
}

//
//  linkedList2.cp
//  src
//
//  Created by Zachary Miller on 4/4/25.
//

#include "inc.h"

int main(int argc, const char * argv[]) {

    /// Define type.
    DataStructureType dataStructureType = DataStructureType::LinkedList;
    
    LinkedList<int> linkedList;
    // ----------------------------------------------------------------------
    
    switch (dataStructureType)
    {
        case DataStructureType::LinkedList:
            
            linkedList.insert(0);
            linkedList.insert(1);
            linkedList.insert(2);
            linkedList.insert(3);
            linkedList.print();

            break;
            
        default: // None
            assert("Data structure type not specified.");
    }
        
    return 0;
}

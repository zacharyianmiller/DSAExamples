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
            
            linkedList.insertAt(0, 0);
            linkedList.insertAt(1, 1);
            
            linkedList.print();

            break;
            
        default: // None
            assert("Data structure type not specified.");
    }
        
    return 0;
}

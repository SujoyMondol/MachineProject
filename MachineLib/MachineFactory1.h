/**
 * @file MachineFactory1.h
 * @author sujoy
 *
 *
 */
 
#ifndef MACHINEFACTORY1_H
#define MACHINEFACTORY1_H
#include "Machine.h"

/**
 * Factory class for creating Machine 1
 */
class MachineFactory1 {
private:

public:
 std::shared_ptr<Machine> Create(std::wstring imagesDir);

};



#endif //MACHINEFACTORY1_H

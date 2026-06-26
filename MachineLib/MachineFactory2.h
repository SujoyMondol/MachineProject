/**
 * @file MachineFactory2.h
 * @author sujoy
 *
 *
 */
 
#ifndef MACHINEFACTORY2_H
#define MACHINEFACTORY2_H

class Machine;

/**
 * Class for creating Machine 2
 */
class MachineFactory2 {
private:

public:
 std::shared_ptr<Machine> Create(std::wstring imageDir);

};



#endif //MACHINEFACTORY2_H

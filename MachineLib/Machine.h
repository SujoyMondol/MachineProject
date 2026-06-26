/**
 * @file Machine.h
 * @author sujoy
 *
 *
 */
 
#ifndef MACHINE_H
#define MACHINE_H

#include <vector>

class Component;
class Box;
class MachineSystem;

/**
* Class for machine
*/
class Machine {
private:
 int mStartFrame; /// start frame of the machine

 double mElapsed; /// time elapsed

 int mMachineNumber; /// machine number for the machine

 std::vector<std::shared_ptr<Component>> mComponents; ///components of the machine

 std::shared_ptr<Box> mBox; /// box of the machine

 MachineSystem* mSystem = nullptr; ///system owning the machine

public:

 void Update(double elapsed);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics);

 void Reset();

 void AddComponent(std::shared_ptr<Component> component);

 void AddBox(std::shared_ptr<Box> box);

 /**
  * Set the machine number of the machine
  * @param machineNumber machine number to be set
  */
 void SetMachineNumber(int machineNumber) { mMachineNumber = machineNumber; }

 /**
  * Get the machine number for this machine
  * @return machine number of the machine
  */
 int GetMachineNumber() { return mMachineNumber; }

 /**
  * Set the system
  * @param system System to be set
  */
 void SetSystem(MachineSystem* system) { mSystem = system; }


 /**
  * Set the time for the machine
  * @param time time to be set
  */
 void SetTime(double time) { mElapsed = time;}

 void SetPosition(wxPoint position);



};



#endif //MACHINE_H

/**
 * @file MachineSystem.h
 * @author sujoy
 *
 *
 */
 
#ifndef MACHINESYSTEM_H
#define MACHINESYSTEM_H

#include "IMachineSystem.h"
#include "Machine.h"


class Machine;

/**
* Class for the machine system
*/
class MachineSystem :public IMachineSystem
{
private:
 ///Location of the machine system
 wxPoint mLocation;

 ///The frame of the machine
 int mFrame = 500;

 ///The frame rate of the machine
 double mFrameRate;

 /// THe machine number of the machine owned by the system 
 int mMachineNumber = 1;

 ///The flag of the machine system
 int mFlag;

 ///The current time of the machine
 double mMachineTime = 0.0;


 ///The machine owned by the machine system
 std::shared_ptr<Machine> mMachine = nullptr;

 ///Resources Directory
 std::wstring mResourcesDir;


public:
 MachineSystem() = delete;

 MachineSystem(std::wstring resourcesDir);

 void SetLocation(wxPoint location) override;


 wxPoint GetLocation() override { return mLocation;};

 void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;


 void SetMachineFrame(int frame) override;

 /**
  * Set the frame rate of the machine System
  * @param rate frame rate to be set
  */
 void SetFrameRate(double rate) override { mFrameRate = rate;};

 void ChooseMachine(int machine) override;

 /**
  * Get the machine number of the machine owned by the machine system
  * @return machine number of the machine owned by machine system
  */
 int GetMachineNumber() override { return mMachineNumber;}

 /**
  * Get the current time of the animation
  * @return the current time of the animation
  */
 double GetMachineTime() override {return mMachineTime;}

 void SetFlag(int flag) override {mFlag = flag;};


 void SetMachine(std::shared_ptr<Machine> machine);

 /**
  * Get the machine owned by the machine system
  * @return machine owned by the machine system
  */
 std::shared_ptr<Machine> GetMachine() { return mMachine;}

 void Reset();




};



#endif //MACHINESYSTEM_H

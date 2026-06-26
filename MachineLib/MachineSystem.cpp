/**
 * @file MachineSystem.cpp
 * @author sujoy
 */

#include "pch.h"
#include "MachineSystem.h"
#include "MachineFactory1.h"
#include "MachineFactory2.h"

/**
 * Create a machine system object
 * @param resourcesDir resources directory
 */
MachineSystem::MachineSystem(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
 ChooseMachine(1);


}

/**
 * Draw the machine owned by the machine system
 * @param graphics graphics context object used for drawing
 */
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{


 graphics->PushState();
 graphics->Translate(mLocation.x, mLocation.y);


 mMachine->Draw(graphics);
 graphics->PopState();
}

/**
 * Set the machine of the machine system
 * @param machine machine to be set
 */
void MachineSystem::SetMachine(std::shared_ptr<Machine> machine)
{
 mMachine = machine;
 machine->SetSystem(this);
}

/**
 * Choose whether machine 1 or machine 2 for the machine system
 * @param machine machine to be chosen
 */
void MachineSystem::ChooseMachine(int machine)
{

  switch(machine)
  {
  case 1:
   mMachineNumber = 1;

   MachineFactory1 machine1Factory;

   mMachine = machine1Factory.Create(mResourcesDir);

   mMachine->SetSystem(this);

   break;

  case 2:
   mMachineNumber = 2;

   MachineFactory2 machine2Factory;
   mMachine = machine2Factory.Create(mResourcesDir);

   mMachine->SetSystem(this);

   break;

  }
}


/**
 * Set the current frame of the machine system
 * @param frame the current frame
 */
void MachineSystem::SetMachineFrame(int frame)
{
 if (frame < mFrame)
 {
  mFrame = 0;
  Reset();
 }

 while (mFrame < frame) {

  mFrame++;
  double time = mFrame / mFrameRate;
  mMachineTime = time;
  mMachine->Update(1.0 / mFrameRate);
  mMachine->SetTime(time);
 }
}

/**
 * Reset the machine System
 */
void MachineSystem::Reset()
{
  if(mMachine != nullptr)
  {
   mMachine->Reset();
  }

  mMachineTime = 0.0;

}


void MachineSystem::SetLocation(wxPoint location)
{

 mLocation = location;

}

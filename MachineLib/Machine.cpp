/**
 * @file Machine.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Machine.h"

#include "Box.h"
#include "Component.h"
#include "MachineSystem.h"

/**
 * Add a component to the machine
 * @param component component to be added
 */
void Machine::AddComponent(std::shared_ptr<Component> component)
{
 mComponents.push_back(component);
 component->SetMachine(this);
}

/**
 * Add box to the machine
 * @param box box to be added to machine
 */
void Machine::AddBox(std::shared_ptr<Box> box)
{
 mBox = box;
 mComponents.push_back(box);
 box->SetMachine(this);
}

/**
 * Draw the machine
 * @param graphics graphics context object used for drawing
 */
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

 size_t index = 0;
 while (index < mComponents.size())
 {
  mComponents[index]->Draw(graphics, mSystem->GetLocation().x, mSystem->GetLocation().y, 0);
  ++index;
 }
 mBox->DrawForeground(graphics, mSystem->GetLocation().x, mSystem->GetLocation().y);
}


/**
 * Update the machine
 * @param time time elapsed
 */
void Machine::Update(double time)
{
 size_t index = 0;
 while (index < mComponents.size())
 {
  mComponents[index]->Advance(time);
  ++index;
 }
}

/**
 * Reset the machine
 */
void Machine::Reset()
{
 size_t index = 0;
 while (index < mComponents.size())
 {
  mComponents[index]->Reset();
  ++index;
 }

 while (index < mComponents.size())
 {
  mComponents[index]->Advance(0);
  ++index;
 }
}


/**
 * Set the position of the machine
 * @param position position to translate the components
 */
void Machine::SetPosition(wxPoint position)
{
 for(auto component: mComponents)
 {
  auto x = component->GetPosition().x + position.x;
  auto y = component->GetPosition().y + position.y;
  component->SetPosition(wxPoint(x, y));
 }
}



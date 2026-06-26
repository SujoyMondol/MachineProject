/**
 * @file Component.h
 * @author sujoy
 *
 *
 */
 
#ifndef COMPONENT_H
#define COMPONENT_H

#include "Machine.h"

class Machine;

/**
 * Base class for the compoenents in the machine
 */
class Component {
private:
 ///position of the component
 wxPoint mPosition = wxPoint(0, 0);

 ///Machine owning the compoenent
 Machine *mMachine = nullptr;

 ///Images directory used for drawing component
 std::wstring mImagesDir;

public:
 Component() = delete;

 Component(std::wstring resourcesDir);

 /**
  *
  * @param graphics Abstract function to draw the component
  * @param x x position
  * @param y y position
  * @param rotation rotation of this object
  */
 virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) = 0;

 /**
 * Set Initial Position for Component
*/
 virtual void SetInitialPosition(wxPoint point) {};

 /**
  * Set the position of the component
  * @param position position to be set
  */
 void SetPosition(wxPoint position) { mPosition = position; }

 /**
  * Get the position of the component
  * @return the position of the component
  */
 wxPoint GetPosition() { return mPosition; }

 ///Abstract function for resetting a component
 virtual void Reset() = 0;

 /**
  * Set the frame of the component
  * @param frame frame to be set
  */
 virtual void SetFrame(double frame) {};

 /**
  * Set the time of the component
  * @param time time to be set
  */
 virtual void SetTime(double time) {};

 /**
  * Set the machine of the compoent
  * @param machine machine to set to
  */
 void SetMachine(Machine *machine) { mMachine = machine; }

 /**
  * Virtual function to update the component
  * @param time time elapsed
  */
 virtual void Advance(double time) {}

 /**
  * Get the images directory for the component
  * @return the images directory for the component
  */
 std::wstring GetImagesDir() { return mImagesDir; }



};



#endif //COMPONENT_H

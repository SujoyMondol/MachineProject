/**
 * @file Crank.h
 * @author sujoy
 *
 *
 */
 
#ifndef CRANK_H
#define CRANK_H

#include "Component.h"
#include "Cylinder.h"
#include "Polygon.h"
#include "RotationSource.h"

/**
 * Class for Crank object
 */
class Crank : public Component
{
private:
 double mRotationAngle = 0.0; /// rotation angle of the crank
 double mRotationSpeed = 0.5; /// rotation speed of the crank
 bool mIsRotating = false; /// rotating status of the crank

 cse335::Cylinder mHandle;

 /// Rotation source for this component
 RotationSource mSource;



public:
 Crank() = delete;

 Crank(std::wstring resourcesDir);

 /**
  * Set up the handle of the crank
  */
 void SetupHandle();


 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;

 /**
  * Draw the crank
  * @param graphics graphics context object for drawing
  */
 void DrawCrank(std::shared_ptr<wxGraphicsContext> graphics);

 /**
  * Draw the handle of the crank
  * @param graphics graphics context object for drawing
  */
 void DrawHandle(std::shared_ptr<wxGraphicsContext> graphics);

 /**
  * Set the rotation speed of the crank
  * @param speed speed to set the rotation speed
  */
 void SetRotationSpeed(double speed) { mRotationSpeed = speed; }
 /**
  * Rotate the crank
  * @param time time elapsed
  */
 void Rotate(double time);
 /**
  * Toggle the rotating status of the crank
  */
 void ToggleRotation() { mIsRotating = !mIsRotating; }

 /**
  * Calculate the position of the crank
  * @return position of the crank
  */
 wxPoint CalculateCrankPosition() { return wxPoint(0, 0); }

 /**
 * Update the handle position
*/
 void UpdateHandlePosition();

 /**
 * Update the rotation of the crank
*/
 void UpdateRotation(double angle);

 void Reset() override;

 void Advance(double time) override;


 /**
  * Get a rotation source of the crank
  * @return rotation source of the crank
  */
 RotationSource *GetSource() { return &mSource; }



};



#endif //CRANK_H

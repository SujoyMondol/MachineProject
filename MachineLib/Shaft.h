/**
 * @file Shaft.h
 * @author sujoy
 *
 *
 */
 
#ifndef SHAFT_H
#define SHAFT_H

#include "Component.h"

#include "Cylinder.h"
#include "IRotationSink.h"
#include "RotationSource.h"

/**
 * Class for the Shaft component
 */
class Shaft : public Component, public IRotationSink {
private:


 /// rotation angle for the shaft
 double mRotationAngle;

 ///rotation speed of the shaft
 double mRotationSpeed;

 ///rotating status of the shaft
 bool isRotating = true;

 ///Cylinder representing the shaft
 cse335::Cylinder mCylinder;

 /// length of the shaft
 int mLength;

 ///Rotation source owned by the shaft
 RotationSource mSource;


public:
 Shaft() = delete;

 Shaft(std::wstring resourcesDir, int length);



 void DrawShaft(std::shared_ptr<wxGraphicsContext> graphics);

 /**
  * Set the Rotation Speed of the shaft
  * @param speed speed to be set
  */
 void SetRotationSpeed(double speed) { mRotationSpeed = speed; }

 /**
  * Rotate the shaft
  * @param deltaTime time elapsed
  */
 void Rotate(double deltaTime);

 /**
 * Toggle rotating state for the shaft
*/
 void ToggleRotation() { mRotationAngle = !mRotationAngle; }



 void Reset() override;

 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;


 void UpdateRotation(double angle) override;


 void Advance(double time);

 /**
  * Get the rotation source for the shaft
  * @return Rotation Source for the shaft
  */
 RotationSource* GetRotationSource() { return &mSource; }


};



#endif //SHAFT_H

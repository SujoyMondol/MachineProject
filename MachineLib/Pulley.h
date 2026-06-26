/**
 * @file Pulley.h
 * @author sujoy
 *
 *
 */
 
#ifndef PULLEY_H
#define PULLEY_H

#include "Component.h"
#include "IRotationSink.h"
#include "Cylinder.h"
#include "RotationSource.h"
#include "Shaft.h"

/**
 * Class for the pulley component
 */
class Pulley : public Component, public IRotationSink {
private:

 /// Cylinder for the pulley
 cse335::Cylinder mCylinder;

 /// Rotation Source of the Pulley
 RotationSource mSource;

 /// Rotation Angle for the pulley
 double mRotationAngle;

 /// The pulley that is driven by this pulley
 std::shared_ptr<Pulley> mDriven = nullptr;

 /// The diameter of the pulley
 int mDiameter;

 ///Determines whether to draw stripes on the belt
 bool mStripe = false;

 ///Offset for the first stripe
 double mStripeOffset1 = 0;

 ///Offset for the second stripe
 double mStripeOffset2 = 0;

 ///Offset factor for the stripes
 double mOffsetFactor = 0;



public:

 Pulley(std::wstring resourcesDir, int diameter);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;

 void Reset() override;

 void UpdateRotation(double angle) override;

 /**
  * Set the driven pulley
  * @param pulley pulley being driven by this pulley
  */
 void SetDriven(std::shared_ptr<Pulley> pulley) { mDriven = pulley; }


 /**
  * Set the diameter of this pulley
  * @return diameter of this pulley
  */
 int GetDiameter() { return mDiameter; }

 /**
  * Get the rotation source of this pulley
  * @return rotation source of this pulley
  */
 RotationSource* GetSource() { return &mSource; }

 /**
  * Set stripes on the belt
  */
 void SetStripe() { mStripe = true;}

 void Advance(double time) override;

 /**
  * Set the offset factor for the stripes
  * @param factor factor to be set
  */
 void SetOffsetFactor(double factor) { mOffsetFactor = factor; }


};



#endif //PULLEY_H

/**
 * @file Cam.h
 * @author sujoy
 *
 *
 */
 
#ifndef CAM_H
#define CAM_H

#include "Component.h"
#include "IRotationSink.h"
#include "Polygon.h"
#include "Cylinder.h"


class IKeyDropListener;


/**
 * Class for the Cam
 */
class Cam : public Component, public IRotationSink {
private:

 ///The key of the cam
 cse335::Polygon mKey;

 ///The cylinder of the cam
 cse335::Cylinder mCylinder;

 ///The hole of the cam
 cse335::Polygon mKeyHole;

 ///The amount to which the key would be dropped
 int mKeyDrop = 0;

 ///The amount to which to raise the key hole
 int mKeyHoleOffset = 0;


 ///The angle for rotation
 double mRotationAngle = 0.0;


 ///The rotation speed
 double mRotationSpeed;


 ///Determines whether key has been dropped or not
 bool mKeyIsDropped = false;

 ///Determines whther key hole needs to be drawn or not
 bool mKeyHoleStop = false;


 ///listeners which act depending on key drop
 std::vector<std::shared_ptr<IKeyDropListener>> mListeners;




public:
 Cam() = delete;

 Cam(std::wstring resourcesDir);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;

 void Reset() override;

 void UpdateRotation(double angle) override;
 /**
  * Setup the Key
  * @param imagesPath imagesPath for key
  */
 void SetupKey(std::wstring imagesPath);
 
 /**
 * Function to draw the cam
 
*/
 void DrawCam(std::shared_ptr<wxGraphicsContext> graphics);

 /**
  * 
  * @param graphics 
  */
 void DrawKey(std::shared_ptr<wxGraphicsContext> graphics);

 /**
  * Set the rotation speed
  * @param speed rotation speed to be set
  */
 void SetRotationSpeed(double speed) { mRotationSpeed = speed; }

 /**
  * Rotate the cam
  * @param deltaTime time elapsed
  */
 void Rotate(double deltaTime);



 void TriggerKeyDrop();

 void Advance(double time) override;

 void AddListener(std::shared_ptr<IKeyDropListener> keydropListener);

};



#endif //CAM_H

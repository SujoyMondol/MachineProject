/**
 * @file Cam.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Cam.h"
#include "IKeyDropListener.h"

/// Width of the cam on the screen in pixels
const double CamWidth = 17;

/// Cam diameter
const double CamDiameter = 60;

/// How big is the hole in the cam?
const double HoleSize = 8;

/// The key image
const std::wstring KeyImage = L"/key.png";

/// The key image size
const int KeyImageSize = 20;

/// The amount the key drops into the hole
const int KeyDrop = 10;


/**
 * Functions for creating a cam object
 * @param resourcesDir resources Directory
 */
Cam::Cam(std::wstring resourcesDir) : Component(resourcesDir)
{
 std::wstring imagesDir = resourcesDir + L"/images";

 std::wstring keyImage = imagesDir + KeyImage;

 mKey.SetImage(keyImage);
 mKey.Rectangle(-mKey.GetImageWidth()/2 *0.1, 0, mKey.GetImageWidth() * 0.1, mKey.GetImageHeight()*0.1);

 mKeyHole.Circle(HoleSize/2);
 mKeyHole.SetColor(*wxBLACK);

 mCylinder.SetSize(CamDiameter, CamWidth);
 mCylinder.SetColour(*wxWHITE);


}

/**
 * Draw the cam object
 * @param graphics graphics context object used for drawing
 * @param x x position
 * @param y y position
 * @param rotation rotation for the cam object
 */
void Cam::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{
 mKey.DrawPolygon(graphics, GetPosition().x + CamWidth/2,
 GetPosition().y-CamDiameter/2 + mKeyDrop);
 mCylinder.Draw(graphics, GetPosition().x, GetPosition().y, mRotationAngle);


 if(!mKeyHoleStop)
 {
  graphics->PushState();
  graphics->Clip(GetPosition().x, GetPosition().y-CamDiameter/2, CamWidth, CamDiameter);
  mKeyHole.DrawPolygon(graphics, GetPosition().x + CamWidth/2,
   GetPosition().y+CamDiameter/2 - mKeyHoleOffset);
  graphics->PopState();
 }
}

/**
 * Update the rotation of the cam
 * @param angle angle to be updated to
 */
void Cam::UpdateRotation(double angle)
{
 mRotationAngle = angle;
}

/**
 * Update the cam object
 * @param time time elapsed
 */
void Cam::Advance(double time)
{
 if(mRotationAngle > 0)
  {
 double angle = mRotationAngle *  M_PI / 2;

 if(!mKeyHoleStop)
 {
  mKeyHoleOffset = sin(angle) * (CamDiameter+5);
  if(mKeyHoleOffset >= CamDiameter + 3)
  {
   mKeyHoleStop = true;
   TriggerKeyDrop();
  }
 }
 }

}

/**
 * Trigger the key drop for the listeners
 */
void Cam::TriggerKeyDrop()
{
 mKeyDrop = KeyDrop;
 for(auto listener : mListeners)
 {
   listener->KeyDropTriggered();
 }
}

/**
 * Add a listener to the cam
 * @param keydropListener listener to be added
 */
void Cam::AddListener(std::shared_ptr<IKeyDropListener> keydropListener)
{
 mListeners.push_back(keydropListener);
}

/**
 * Reset the cam
 */
void Cam::Reset()
{
 mKeyDrop = 0;
 mKeyIsDropped = false;
 mKeyHoleStop = false;
 mKeyHoleOffset = 0.0;

}

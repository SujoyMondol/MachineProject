/**
 * @file Pulley.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Pulley.h"

/// How wide the hub is on each side of the pulley
const double PulleyHubWidth = 3;

/// How deep the belt is into the pulley
const double PulleyBeltDepth = 3;

/// The color to use for pulleys
const wxColour PulleyColor = wxColour(205, 250, 5);

/// The line color to use for the hub
/// First parameter to Cylinder::SetLines
const wxColour PulleyHubLineColor = wxColour(139, 168, 7);

/// The width to draw the lines on the hub
/// Second parameter to Cylinder::SetLines
const int PulleyHubLineWidth = 4;

/// The number of lines to draw on a pulley is the int(diameter / 6.0)
/// Third parameter to Cylinder::SetLines
const double PulleyHubLineCountDiviser = 6.0;

/**
 *
 * @param resourcesDir resources Directory
 * @param diameter diameter for this pulley
 */
Pulley::Pulley(std::wstring resourcesDir, int diameter) : Component(resourcesDir)
{
 mDiameter = diameter;
 mCylinder.SetSize(mDiameter, 3);
 mCylinder.SetColour(PulleyColor);
 mCylinder.SetLines(PulleyHubLineColor, PulleyHubLineWidth, PulleyHubLineCountDiviser);

}

/**
 * Reset the pulley
 */
void Pulley::Reset()
{
 mRotationAngle = 0.0;
}

/**
 * Update the angle of pulley and the stripe offsets
 * @param angle angle to be set
 */
void Pulley::UpdateRotation(double angle)
{
 mRotationAngle = angle;
 mStripeOffset1 += mOffsetFactor;
 mStripeOffset2 += mOffsetFactor;

 if(mDriven)
 {
  double y1 = mDriven->GetPosition().y- mStripeOffset1;
  double y2 = GetPosition().y - mStripeOffset2;


  if(y1 < mDriven->GetPosition().y-mDriven->GetDiameter()/2 - 30)
  {
   mStripeOffset1 = mDriven->GetDiameter() + 30;


   mStripeOffset1 *= -1;

  }

  if(y2 < mDriven->GetPosition().y-mDriven->GetDiameter()/2 - 30)
  {
   mStripeOffset2 = mDiameter/2;
   mStripeOffset2 *= -1;
  }
 }


}


/**
 * Draw the pulley
 * @param graphics graphics context object used for drawing
 * @param x x position
 * @param y y position
 * @param rotation rotation for this pulley
 */
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{
 mCylinder.Draw(graphics, GetPosition().x, GetPosition().y, mRotationAngle);
 mCylinder.Draw(graphics, GetPosition().x-10, GetPosition().y, mRotationAngle);

 if(mDriven)
 {

  auto drivenY = mDriven->GetPosition().y;
  auto length = drivenY - GetPosition().y;


  if(length > 0)
  {
   graphics->SetBrush(*wxBLACK_BRUSH);
   graphics->SetPen(*wxBLACK_PEN);
   graphics->DrawRoundedRectangle(GetPosition().x-7,GetPosition().y-mDiameter/2+3,
    7,length+50,rotation);
   graphics->SetBrush(*wxTRANSPARENT_BRUSH);
   graphics->SetPen(*wxTRANSPARENT_PEN);
  }else
  {
   length = mDriven->GetDiameter()-3 + (GetPosition().y+mDiameter/2)-(mDriven->GetPosition().y+mDriven->GetDiameter()/2)-3;
   graphics->SetBrush(*wxBLACK_BRUSH);
   graphics->SetPen(*wxBLACK_PEN);
   graphics->DrawRoundedRectangle(mDriven->GetPosition().x-7,
    mDriven->GetPosition().y-mDriven->GetDiameter()/2+3,7, length, rotation);
   graphics->SetBrush(*wxTRANSPARENT_BRUSH);
   graphics->SetPen(*wxTRANSPARENT_PEN);



    if(mStripe)
    {
     graphics->PushState();
     graphics->Clip(mDriven->GetPosition().x-7, mDriven->GetPosition().y
      - mDriven->GetDiameter()/2 + 3, 7, length);
     graphics->SetBrush(*wxWHITE_BRUSH);


     double y1 = mDriven->GetPosition().y - mStripeOffset1;
     double y2 = GetPosition().y - mStripeOffset2;

     graphics->DrawRoundedRectangle(mDriven->GetPosition().x-7,
     y1, 7, 5, rotation);
     graphics->DrawRoundedRectangle(GetPosition().x-7,
       y2, 7, 5, rotation);

     graphics->SetBrush(*wxWHITE_BRUSH);

     graphics->PopState();
    }

  }
 }
}


/**
 * Update the pulley
 * @param time time elapsed
 */
void Pulley::Advance(double time)
{
 if(mDriven)
 {

  mSource.SetRotation(mRotationAngle * (double)mDiameter/mDriven->GetDiameter());
 }else
 {
  mSource.SetRotation(mRotationAngle);
 }

}






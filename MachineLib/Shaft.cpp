/**
 * @file Shaft.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Shaft.h"

/// The color to draw the shaft
const wxColour ShaftColor = wxColour(220, 220, 220);

/// The color to draw the lines on the shaft
/// First parameter to Cylinder::SetLines
const wxColour ShaftLineColor = wxColour(100, 100, 100);

/// The width to draw the lines on the shaft
/// Second parameter to Cylinder::SetLines
const int ShaftLinesWidth = 1;

/// The number of lines to draw on the shaft
/// Third parameter to Cylinder::SetLines
const int ShaftNumLines = 4;

/**
 * Create a shaft object
 * @param resourcesDir resources directory
 * @param length length of the shaft
 */
Shaft::Shaft(std::wstring resourcesDir, int length) : Component(resourcesDir)
{
 mLength = length;
 mCylinder.SetSize(10, mLength);
 mCylinder.SetColour(ShaftColor);
 mCylinder.SetLines(ShaftLineColor, ShaftLinesWidth, ShaftNumLines);

}


/**
 * Reset the shaft
 */
void Shaft::Reset()
{

 mRotationAngle = 0.0;

}

/**
 * Draw the shaft
 * @param graphics graphics context object used for drawing
 * @param x x position
 * @param y y position
 * @param rotation rotation for the object
 */
void Shaft::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{

  DrawShaft(graphics);

}

/**
 * Update the rotation of the shaft
 * @param angle angle to be set to
 */
void Shaft::UpdateRotation(double angle)
{
  mRotationAngle = angle;
}


/**
 * Update the shaft
 * @param time time elapsed
 */
void Shaft::Advance(double time)
{

 mSource.SetRotation(mRotationAngle);

}

/**
 * Draw the shaft
 * @param graphics graphics context to render to
 */
void Shaft::DrawShaft(std::shared_ptr<wxGraphicsContext> graphics)
{
 mCylinder.Draw(graphics, GetPosition().x, GetPosition().y, mRotationAngle);
}





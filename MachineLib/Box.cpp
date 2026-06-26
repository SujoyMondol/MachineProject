/**
 * @file Box.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Box.h"
#include "Component.h"


/// The background image to use
const std::wstring BoxBackgroundImage = L"/box-background.png";

/// The foreground image to use
const std::wstring BoxForegroundImage = L"/box-foreground.png";

/// The lid image to use
const std::wstring BoxLidImage = L"/box-lid.png";

/// The horizontal scale for the lid when the angle is zero
const double LidZeroAngleScale = 0.02;

/// How long it takes to up the lid in seconds
const double LidOpeningTime = 0.25;

/**
 * Creates a box
 * @param resourcesDir resources directory
 */
Box::Box(std::wstring resourcesDir) : Component(resourcesDir)
{


    mBox.SetImage(GetImagesDir() + BoxBackgroundImage);
    mBox.Rectangle(-mBox.GetImageWidth() * 0.5/2, 0, mBox.GetImageWidth() * 0.5, mBox.GetImageHeight() * 0.5);
    mForeground.SetImage(GetImagesDir() + BoxForegroundImage);
    mForeground.Rectangle(-mForeground.GetImageWidth()*0.5/2, 0, mForeground.GetImageWidth()*0.5, mBox.GetImageHeight() * 0.5);

    mLid.SetImage(GetImagesDir() + BoxLidImage);
    mLid.Rectangle(0, 0, mLid.GetImageWidth()*0.5, mLid.GetImageHeight()*0.5);

    mLidScale = LidZeroAngleScale;


}

/**
 * Resets the box
 */
void Box::Reset()
{
  mLidScale = LidZeroAngleScale;
    mOpen = false;
    mAngle = 0.0;
}

/**
 * Draw the box
 * @param graphics graphis context object used for drawing
 * @param x x position
 * @param y y position
 * @param rotation rotation of the object
 */
void Box::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{


    mBox.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    graphics->PushState();
    graphics->Translate(GetPosition().x-125, GetPosition().y-250);
    graphics->Scale(1, mLidScale);

    mLid.DrawPolygon(graphics, 0, 0);

    graphics->PopState();


}

/**
 * Draw the foreground of the box
 * @param graphics graphics context object used for drawing
 * @param x x position
 * @param y y position
 */
void Box::DrawForeground(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    mForeground.DrawPolygon(graphics, GetPosition().x, GetPosition().y);

}


/**
 * Update the box
 * @param time time elapsed
 */
void Box::Advance(double time)
{

    double openAngle = M_PI / 2;

    if(mOpen && mAngle < openAngle)
    {
        mAngle += openAngle * time / LidOpeningTime;

        if(mAngle > openAngle)
        {
            mAngle = openAngle;
        }



        if(sin(mAngle) >= 0.0 && sin(mAngle) <= 0.98)
        {
            mLidScale = LidZeroAngleScale + sin(mAngle);
        }

    }
}


void Box::KeyDropTriggered()
{
    mOpen = true;
}




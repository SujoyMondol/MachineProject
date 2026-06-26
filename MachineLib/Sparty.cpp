/**
 * @file Sparty.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Sparty.h"

/// The spring pen size to use in pixels
const double SpringWireSize = 2;

/// Minimum spacing between spring wire
const double SpringWireMinSpacing = 1;

/// Color to draw the spring
const wxColour SpringColor = wxColour(220, 220, 220);

/// Sparty popup time in seconds
const double SpartyPopupTime = 0.25;

/**
 * Create the Sparty Object
 * @param resourcesDir resources directory
 * @param spartyNum determines which sparty image to pick
 * @param size size of the sparty image
 * @param decompressedLength decompressed Length of the spring
 * @param width width of the spring
 * @param numLinks number of links of the spring
 */
Sparty::Sparty(std::wstring resourcesDir, int spartyNum, int size, int decompressedLength,
               int width, int numLinks) : Component(resourcesDir)
{

 mSpartySize = size;
 mSpringDecompressedLength = decompressedLength;
 mSpringCompressedLength = decompressedLength / 6.5;
 mSpringLength = mSpringCompressedLength;
 mNumLinks = numLinks;
 mSpringWidth = width;

   switch(spartyNum)
   {
   case 1:
    mSparty.SetImage(GetImagesDir()+L"/sparty.png");
    break;
   case 2:
    mSparty.SetImage(GetImagesDir()+L"/sparty2.png");
    break;

   }

   mSparty.Rectangle(-mSpartySize/2, 0, mSpartySize, mSpartySize);

}

/**
 * Reset the Sparty Object
 */
void Sparty::Reset()
{
  mSpringLength = mSpringCompressedLength;
  mPopup = false;
  mBounceOffset = 0.0;
  mRotation = 0.0;
 mSwing = false;
 mDown = false;
 mAngle = 0.0;
}

/**
 * Draw the sparty and spring
 * @param graphics graphics context object used for drawing
 * @param x x position
 * @param y y position
 * @param rotation rotation for this object
 */
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{

 DrawSpring(graphics);

 mSparty.DrawPolygon(graphics, GetPosition().x, GetPosition().y-mSpringLength+20-mBounceOffset, mRotation);

}


/**
 * Draw a spring.
 * @param graphics Graphics context to render to

 */
void Sparty::DrawSpring(std::shared_ptr<wxGraphicsContext> graphics)
{
 auto path = graphics->CreatePath();

 // We keep track of three locations, the bottom of which
 // is y1. First half-loop will be y1 to y3, second half-loop
 // will be y3 to y2.
 double y1 = GetPosition().y;
 double linkLength = mSpringLength / mNumLinks;

 // Left and right X values
 double xR = GetPosition().x + mSpringWidth / 2;
 double xL = GetPosition().x - mSpringWidth / 2;

 path.MoveToPoint(GetPosition().x, y1);

 for(int i=0; i<mNumLinks; i++)
 {
  auto y2 = y1 - linkLength;
  auto y3 = y2 - linkLength / 2;

  path.AddCurveToPoint(xR, y1, xR, y3, GetPosition().x, y3);
  path.AddCurveToPoint(xL, y3, xL, y2, GetPosition().x, y2);

  y1 = y2;
 }

 graphics->StrokePath(path);
}

/**
 * Update sparty
 * @param time time elapsed
 */
void Sparty::Advance(double time)
{
 double openAngle = M_PI / 2;

 if(mPopup && mAngle < openAngle)
 {
  mAngle += openAngle * time / SpartyPopupTime;

  if(mAngle > openAngle)
  {
   mAngle = openAngle;
  }

  if(mSpringDecompressedLength*sin(mAngle) > mSpringCompressedLength)
  {
   mSpringLength = mSpringDecompressedLength*sin(mAngle);
  }



 }
 if(mAngle >= openAngle)
 {
 Bounce();
 }

}

/**
 * Start the popping up of sparty when the key is dropped
 */
void Sparty::KeyDropTriggered()
{
 mPopup = true;
}

/**
 * Cause the Sparty to bounce
 */
void Sparty::Bounce()
{
  // Wiggle it from left to right by rotating
  if(!mSwing && mRotation < 0.05)
  {
   mRotation += 0.001;
  }

  if(mRotation >= 0.05)
  {
   mSwing = true;

  }

  if(mSwing)
  {
    if(mRotation >= - 0.05)
    {
     mRotation -= 0.001;
    }else
    {
     mSwing = false;
    }
  }

 // Move Sparty up and down
  if(!mDown && mBounceOffset < 10 )
  {
   mBounceOffset += 1;
  }

  if(mBounceOffset >= 10)
  {
   mDown = true;
  }

  if(mDown)
  {
   if(mBounceOffset >=-10)
   {
    mBounceOffset -= 1;
   }else
   {
    mDown = false;
   }
  }

 //Update the spring length to add bouncy spring effects
 if(mSpringLength + mBounceOffset > mSpringDecompressedLength - mSpringCompressedLength)
 {
  mSpringLength += mBounceOffset;
 }else
 {
  mSpringLength -= mBounceOffset;
 }

}



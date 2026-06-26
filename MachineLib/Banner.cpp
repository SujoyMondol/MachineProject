/**
 * @file Banner.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Banner.h"


/// Scale to draw relative to the image sizes
const double BannerScale = 0.42;

/// Height of the banner in pixels
double const BannerHeight = 150 * BannerScale;

/// Width fo the banner in pixels
const double BannerWidth = 1024 * BannerScale;

/// Height of the banner roll image in pixels
const double BannerRollHeight = 300 * BannerScale;

/// Width of the banner roll image in pixels
double const BannerRollWidth = 16 * BannerScale;

/// How fast ot unfurl the banner in pixels per second
double const BannerSpeed = 41.65;

/// Minimum number of pixels to start with as unfurled
const double BannerMinimum = 15;


/**
 * Constructor for creating Banner
 * @param resourcesDir resources Directory
 */
Banner::Banner(std::wstring resourcesDir) : Component(resourcesDir)
{
  mRoll.SetImage(GetImagesDir()+L"/banner-roll.png");
    mRoll.Rectangle(-mRoll.GetImageWidth() * 0.5/2, 0, mRoll.GetImageWidth() * 0.5, mRoll.GetImageHeight()*0.5);
    mBanner.SetImage(GetImagesDir()+L"/banner.png");
    mBanner.Rectangle(-BannerWidth/2, 0, BannerWidth, BannerHeight);
}

/**
 * Reset the scale of the banner to be displayed
 */
void Banner::Reset()
{
 mScale = 0.0;
}

/**
 * Draw the Banner
 * @param graphics graphics context object used for drawing
 * @param x x position
 * @param y y position
 * @param rotation amount to rotate the banner
 */
void Banner::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{
  if(mScale < BannerWidth)
  {
    mRoll.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
  }
    graphics->PushState();
    graphics->Clip(GetPosition().x-430, GetPosition().y-100, BannerWidth, BannerHeight);

    mBanner.DrawPolygon(graphics, GetPosition().x +210- mScale , GetPosition().y-40);
    graphics->PopState();
}


/**
 * Updates the scale of the banner
 * @param time time elapsed
 */
void Banner::Advance(double time)
{
  if(mScale < BannerWidth)
  {
    mScale += 3;
  }
}



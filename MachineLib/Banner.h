/**
 * @file Banner.h
 * @author sujoy
 *
 *
 */

#ifndef BANNER_H
#define BANNER_H

#include "Component.h"
#include "Polygon.h"

/**
 * Banner for Machine 2
 */
class Banner : public Component
{
private:
 /// The scale determining how much of the banner needs to be drawn
 double mScale = 0.0;

 ///The roll holding the banner
 cse335::Polygon mRoll;

 ///The banner to be displayed
 cse335::Polygon mBanner;



public:
 Banner(std::wstring resourcesDir);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;

 void Reset() override;

 void Advance(double time) override;

};



#endif //BANNER_H

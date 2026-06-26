/**
 * @file Sparty.h
 * @author sujoy
 *
 *
 */
 
#ifndef SPARTY_H
#define SPARTY_H

#include "Component.h"
#include "Polygon.h"
#include "IKeyDropListener.h"


/**
 * Class for the sparty component
 */
class Sparty : public Component, public IKeyDropListener
{
private:

 /// Polygon holding the image of sparty
 cse335::Polygon mSparty;


 /// compressed legth of the spring
 double mSpringCompressedLength;

 /// decompressed length of the spring
 double mSpringDecompressedLength;

 /// current length of the spring
 double mSpringLength;

 ///width of the spring
 int mSpringWidth;

 ///number of links in the spring
 int mNumLinks;

 ///colour of the spring
 wxColour mSpringColour;

 /// size of the sparty
 int mSpartySize;


 /// Determines whether to pop sparty
 bool mPopup = false;

 /// The current angle
 double mAngle = 0.0;

 /// The offset for bounce
 double mBounceOffset = 0.0;

 /// The current rotation for sparty
 double mRotation = 0.0;

 /// Determines whether to swing sparty from right
 bool mSwing = false;

 /// Determines whether to drag Sparty Down
 bool mDown = false;


public:

 Sparty(std::wstring ImagePath,int spartyNum, int size, int decompressedLength, int width, int numLinks);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;

 void DrawSpring(std::shared_ptr<wxGraphicsContext> graphics);

 void Reset() override;

 void Advance(double time) override;

 void KeyDropTriggered() override;

 void Bounce();

};



#endif //SPARTY_H

/**
 * @file Box.h
 * @author sujoy
 *
 *
 */
 
#ifndef BOX_H
#define BOX_H


#include "Component.h"
#include "Polygon.h"
#include "IKeyDropListener.h"

/**
 * Class for the box
 */
class Box : public Component, public IKeyDropListener
{
private:

 /// the outline of the box
 cse335::Polygon mBox;

 ///The lid of the box
 cse335::Polygon mLid;


 ///The foreground of the box
 cse335::Polygon mForeground;

 ///Determines whether to open the lid or close the lid
 bool mOpen = false;

 ///The current scale determining how much of the lid to draw
 double mLidScale;


 /// The current angle of rotation of the box
 double mAngle = 0;


public:
 Box() = delete;

 Box(std::wstring resourcesDir);

 void Reset() override;

 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;


 void DrawForeground(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

 void Advance(double time) override;

 void KeyDropTriggered() override;

};

#endif //BOX_H

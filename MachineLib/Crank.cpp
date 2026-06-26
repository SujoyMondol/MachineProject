/**
 * @file Crank.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Crank.h"


/// The width of the crank on the screen in pixels
const int CrankWidth = 10;

/// The depth of the crank away from the screen in pixels
const int CrankDepth = 20;

/// The length of the crank in pixels
const int CrankLength = 50;

/// The diameter to draw the crank handle
const int HandleDiameter = 7;

/// How long the handle is in pixels
const int HandleLength = 40;

/// How much to the left of the crank X the handle starts in pixels
const int HandleStartX = -10;

/// Crank color
const wxColour CrankColor = wxColour(220, 220, 220);

/// Line color for the rod
const wxColour CrankHandleLineColor = wxColour(100, 100, 100);

/**
 * Create the crank object
 * @param resourcesDir resources directory
 */
Crank::Crank(std::wstring resourcesDir) : Component(resourcesDir)
{
 mHandle.SetSize(HandleDiameter, HandleLength);
 mHandle.SetColour(CrankColor);
 mHandle.SetLines(CrankHandleLineColor, 1, 4);


}

/**
 * Reset the crank
 */
void Crank::Reset()
{
 mRotationAngle = 0.0;
}

void Crank::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{
    double angle = mRotationAngle * (M_PI * 2);
    double handleY = GetPosition().y - 200 + cos(angle) * CrankLength;
    mHandle.Draw(graphics, GetPosition().x+140, handleY, mRotationAngle);

    wxPen blackPen(*wxBLACK);
    graphics->SetPen(blackPen);

    double crankLength = CrankDepth+CrankLength*cos(angle);
    if(crankLength <= CrankDepth)
    {
        graphics->DrawRoundedRectangle(GetPosition().x+150, handleY-10,CrankWidth, CrankDepth-CrankLength*cos(angle), rotation);
    }else
    {
        graphics->DrawRoundedRectangle(GetPosition().x+150, GetPosition().y-210, CrankWidth, CrankDepth+CrankLength*cos(angle) , rotation);
    }

    graphics->SetPen(wxPen(*wxTRANSPARENT_PEN));


}

/**
 * Update the crank
 * @param time time elapsed
 */
void Crank::Advance(double time)
{
    mRotationAngle += time*mRotationSpeed;
    mSource.SetRotation(mRotationAngle);

}

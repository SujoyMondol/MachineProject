/**
 * @file MusicBox.h
 * @author sujoy
 *
 *
 */
 
#ifndef MUSICBOX_H
#define MUSICBOX_H

#include "Component.h"
#include "IRotationSink.h"
#include "Polygon.h"
#include "Cylinder.h"
#include <wx/sound.h>
#include <map>

/**
* Class for the Music Box
*/
class MusicBox : public Component, public IRotationSink
{
private:
 /// The polygon for holding the mechanism image
 cse335::Polygon mPolygon;

 /// The spinning cylinder for the music box
 cse335::Cylinder mCylinder;

 /// The amount to rotate the cylinder
 double mRotation = 0.0;

 /// the directory containing audio
 std::wstring mAudioDir;

 ///The file used for loading songs
 std::wstring mSongFile;

 ///The song being played
 std::wstring mSongName;

 ///The current beat
 double mCurrentBeat = 0.0;

 ///A map connecting beats to notes
 std::map<double, std::wstring> mBeatsToNotes;

 /// A map connecting notes to songs
 std::map<std::wstring, std::wstring> mNotesToSongs;

 /// The beat being played
 double mBeat = 0.0;





public:

 MusicBox(std::wstring ResourcesDir, std::wstring songFile);
 void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation) override;
 void Reset() override;
 void UpdateRotation(double angle) override;

 void Advance(double time) override;

 void XmlLoad();


 void PlaySound();

};



#endif //MUSICBOX_H

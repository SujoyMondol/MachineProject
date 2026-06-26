/**
 * @file MusicBox.cpp
 * @author sujoy
 */

#include "pch.h"
#include "MusicBox.h"
#include <wx/sound.h>
#include <wx/xml/xml.h>

/// The music box mechanism image filename
const std::wstring MusicBoxImage = L"/images/mechanism.png";

/// Size to draw the music box mechanism image in pixels
const int MusicBoxImageSize = 120;

/// The color of the rotating music box drum
const wxColour MusicBoxDrumColor = wxColour(248, 242, 191);

/// The color of the lines on the music box rotating drum
const wxColour MusicBoxDrumLineColor = wxColour(20, 20, 20);

/// The music box drum width
const int MusicBoxDrumWidth = 40;

/// The music box drum diameter
const int MusicBoxDrumDiameter = 33;

/// Number of beats per turn of the music box drum
/// This also determines how many lines to draw on the cylinder
const int BeatsPerRotation = 12;

/// The audio directory in the resources
const std::wstring AudioDirectory = L"/audio/";


/**
 * Create the music box component
 * @param resourcesDir resources directory
 * @param songFile song file used to load songs
 */
MusicBox::MusicBox(std::wstring resourcesDir, std::wstring songFile) : Component(resourcesDir)
{

 mPolygon.SetImage(GetImagesDir() + L"/mechanism.png");
 mPolygon.Rectangle(-mPolygon.GetImageWidth()/2, 0,
  mPolygon.GetImageWidth() * 0.5, mPolygon.GetImageHeight() * 0.5);

    mCylinder.SetSize(MusicBoxDrumDiameter, MusicBoxDrumWidth);
    mCylinder.SetColour(MusicBoxDrumColor);
    mCylinder.SetLines(MusicBoxDrumLineColor, 1, BeatsPerRotation);

    mAudioDir = resourcesDir + L"/musicbox-resources/audio/";

    mSongFile = resourcesDir + L"/musicbox-resources/songs/" + songFile;

    mSongName = mAudioDir + L"691772__hollandm__a3-hard-kalimba.wav";

    XmlLoad();


}

/**
 * Reset the music box
 */
void MusicBox::Reset()
{
  mCurrentBeat = 0.0;
  mBeat = 0.0;
}


/**
 * Draw the music box
 * @param graphics graphics context object used for drawing the music box
 * @param x x position
 * @param y y position
 * @param rotation rotation of the object
 */
void MusicBox::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, int rotation)
{
  mPolygon.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    mCylinder.Draw(graphics, GetPosition().x-69, GetPosition().y-50, mRotation);
}

/**
 * Update the rotation of the music box
 * @param angle angle to be set to
 */
void MusicBox::UpdateRotation(double angle)
{

  mRotation = angle * 0.75;

}

/**
 * Update the music box
 * @param time time elapsed
 */
void MusicBox::Advance(double time)
{

 mCurrentBeat = mRotation * time * BeatsPerRotation * 6;


 // Find the last beat less than or equal to mCurrentBeat
 auto it = mBeatsToNotes.upper_bound(mCurrentBeat);

 if(it != mBeatsToNotes.end())
 {
  if(it->first > mBeat)
  {
  mBeat = it->first;

  auto note = mBeatsToNotes[mBeat];


     mSongName = mAudioDir + mNotesToSongs[note];
     PlaySound();

  }
 }


}


/**
 * Play the music
 */
void MusicBox::PlaySound()
{
 wxSound sound(mSongName);
 sound.Play(wxSOUND_ASYNC);
}


/**
 * Load the songs, beats and notes
 */
void MusicBox::XmlLoad()
{
   wxXmlDocument xmlDoc;

   if(!xmlDoc.Load(mSongFile))
   {
    wxMessageBox(L"Unable to load xml for sounds");
   }

   auto root = xmlDoc.GetRoot();

   auto beats = root->GetAttribute(L"beats");

   int beatsPerMeasure;

   beats.ToInt(&beatsPerMeasure);

   auto sounds = root->GetChildren();

   auto songNode = sounds->GetChildren();

   while(songNode)
   {

     auto songNote = songNode->GetAttribute(L"note");
     auto songFile = songNode->GetAttribute(L"file");

     auto noteSong = songNote.ToStdWstring();
     auto songName = songFile.ToStdWstring();

    mNotesToSongs.insert({noteSong, songName});


     songNode = songNode->GetNext();
   }

   auto notes = sounds->GetNext();

   auto noteNode = notes->GetChildren();
    int measure;
    double beat;
    wxString noteName;

    double absoluteBeat;
   while(noteNode)
   {
    noteNode->GetAttribute(L"measure").ToInt(&measure);
    noteNode->GetAttribute(L"beat").ToDouble(&beat);
    noteName = noteNode->GetAttribute(L"note");

    auto note = noteName.ToStdWstring();

    absoluteBeat = (measure - 1) * beatsPerMeasure + (beat - 1);

    mBeatsToNotes.insert({absoluteBeat, note});

    noteNode = noteNode->GetNext();
   }

}





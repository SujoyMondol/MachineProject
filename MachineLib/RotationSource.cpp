/**
 * @file RotationSource.cpp
 * @author sujoy
 */

#include "pch.h"
#include "RotationSource.h"
#include "IRotationSink.h"

/**
 * Add a rotation sink for the rotation source
 * @param sink sink to be added to sinks
 */
void RotationSource::AddSink(std::shared_ptr<IRotationSink> sink)
{
 mSinks.push_back(sink);
}

/**
 * Set the rotation of the sinks
 * @param angle angle to be set to
 */
void RotationSource::SetRotation(double angle)
{
  for(auto sink : mSinks)
  {
      sink->UpdateRotation(angle);
  }
}

/**
 * @file Component.cpp
 * @author sujoy
 */

#include "pch.h"
#include "Component.h"

/**
 * Base constructor for creating a component
 * @param resourcesDir resources directory
 */
Component::Component(std::wstring resourcesDir)
{
   mImagesDir = resourcesDir + L"/images";
}

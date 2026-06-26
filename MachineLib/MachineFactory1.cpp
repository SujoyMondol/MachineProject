/**
 * @file MachineFactory1.cpp
 * @author sujoy
 */

#include "pch.h"
#include "MachineFactory1.h"
#include "Box.h"
#include "Sparty.h"
#include "Crank.h"
#include "Shaft.h"
#include "Pulley.h"
#include "Cam.h"


/**
 * Create Machine 1
 * @param resourcesDir resources directory
 * @return Machine 1
 */
std::shared_ptr<Machine> MachineFactory1::Create(std::wstring resourcesDir)
{
 auto machine = std::make_shared<Machine>();

 machine->SetMachineNumber(1);

 auto box = std::make_shared<Box>(resourcesDir);

 //box->SetPosition(wxPoint(450, 525));

 auto sparty = std::make_shared<Sparty>(resourcesDir, 1,  212,
  260, 80, 15);

 //sparty->SetPosition(wxPoint(450, 525));

 auto crank = std::make_shared<Crank>(resourcesDir);

 crank->SetPosition(wxPoint(0, -20));

 auto shaft = std::make_shared<Shaft>(resourcesDir, 85);

 shaft->SetPosition(wxPoint(85, -220));

 auto pulley =  std::make_shared<Pulley>(resourcesDir, 40);



 pulley->SetPosition(wxPoint(100, -215));

 auto drivenPulley = std::make_shared<Pulley>(resourcesDir, 75);

 auto drivenShaft = std::make_shared<Shaft>(resourcesDir, 220);

 auto camShaft = std::make_shared<Shaft>(resourcesDir, 50);


 auto camPulley = std::make_shared<Pulley>(resourcesDir, 20);

 camPulley->SetPosition(wxPoint(-95, -70));

 auto camDrivenPulley = std::make_shared<Pulley>(resourcesDir, 75);

 auto cam = std::make_shared<Cam>(resourcesDir);

 camDrivenPulley->SetPosition(wxPoint(-95, -185));
 camShaft->SetPosition(wxPoint(-110, -185));
 cam->SetPosition(wxPoint(-85, -185));

 drivenPulley->SetPosition(wxPoint(100, -70));
 drivenShaft->SetPosition(wxPoint(-110, -70));

 pulley->SetDriven(drivenPulley);
 camPulley->SetDriven(camDrivenPulley);

 crank->GetSource()->AddSink(shaft);

 shaft->GetRotationSource()->AddSink(pulley);
 pulley->GetSource()->AddSink(drivenPulley);
 drivenPulley->GetSource()->AddSink(drivenShaft);
 drivenShaft->GetRotationSource()->AddSink(camPulley);
 camPulley->GetSource()->AddSink(camDrivenPulley);
 camDrivenPulley->GetSource()->AddSink(camShaft);
 camShaft->GetRotationSource()->AddSink(cam);

 cam->AddListener(box);
 cam->AddListener(sparty);

 machine->AddBox(box);
 machine->AddComponent(sparty);
 machine->AddComponent(shaft);
 machine->AddComponent(crank);
 machine->AddComponent(drivenShaft);
 machine->AddComponent(camShaft);
 machine->AddComponent(pulley);

 machine->AddComponent(drivenPulley);
 machine->AddComponent(camPulley);
 machine->AddComponent(camDrivenPulley);
 machine->AddComponent(cam);


 return machine;
}

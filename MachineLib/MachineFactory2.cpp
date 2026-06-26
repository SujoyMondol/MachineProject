/**
 * @file MachineFactory2.cpp
 * @author sujoy
 */

#include "pch.h"
#include "MachineFactory2.h"

#include "Machine.h"
#include "Box.h"
#include "Sparty.h"
#include "Crank.h"
#include "Shaft.h"
#include "Pulley.h"
#include "Cam.h"
#include "MusicBox.h"
#include "Banner.h"

/**
 * Creates Machine 2
 * @param resourcesDir resources Directory
 * @return Machine 2
 */
std::shared_ptr<Machine> MachineFactory2::Create(std::wstring resourcesDir)
{
 auto machine = std::make_shared<Machine>();

 machine->SetMachineNumber(2);

 auto box = std::make_shared<Box>(resourcesDir);



 auto sparty = std::make_shared<Sparty>(resourcesDir, 2,  212,
 280, 80, 15);
 auto crank = std::make_shared<Crank>(resourcesDir);

 crank->SetPosition(wxPoint(0, 150));




 auto shaft = std::make_shared<Shaft>(resourcesDir, 85);

 shaft->SetPosition(wxPoint(80, -50));

 auto pulley =  std::make_shared<Pulley>(resourcesDir, 40);

 pulley->SetPosition(wxPoint(100, -50));

 auto drivenPulley = std::make_shared<Pulley>(resourcesDir, 75);

 drivenPulley->SetPosition(wxPoint(100, -120));

 auto drivenShaft = std::make_shared<Shaft>(resourcesDir, 220);

 drivenShaft->SetPosition(wxPoint(-110, -120));

 pulley->SetDriven(drivenPulley);

 pulley->SetStripe();
 pulley->SetOffsetFactor(0.5);

 auto camPulley = std::make_shared<Pulley>(resourcesDir, 20);

 camPulley->SetPosition(wxPoint(-90, -120));

 auto camDrivenPulley = std::make_shared<Pulley>(resourcesDir, 50);

 camDrivenPulley->SetPosition(wxPoint(-90, -190));
 camPulley->SetStripe();
 camPulley->SetOffsetFactor(0.35);

 auto cam = std::make_shared<Cam>(resourcesDir);

 auto camShaft = std::make_shared<Shaft>(resourcesDir, 50);

 auto musicBox = std::make_shared<MusicBox>(resourcesDir, L"/pop.xml");

 musicBox->SetPosition(wxPoint(50, -70));

 auto banner = std::make_shared<Banner>(resourcesDir);

 banner->SetPosition(wxPoint(120, -235));



 cam->SetPosition(wxPoint(-80, -190));
 camShaft->SetPosition(wxPoint(-110, -190));

 cam->AddListener(box);
 cam->AddListener(sparty);


 camPulley->SetDriven(camDrivenPulley);

 crank->GetSource()->AddSink(shaft);
 shaft->GetRotationSource()->AddSink(pulley);
 pulley->GetSource()->AddSink(drivenPulley);
 drivenPulley->GetSource()->AddSink(drivenShaft);
 drivenShaft->GetRotationSource()->AddSink(camPulley);
 drivenShaft->GetRotationSource()->AddSink(musicBox);
 camPulley->GetSource()->AddSink(camDrivenPulley);
 camDrivenPulley->GetSource()->AddSink(cam);
 camDrivenPulley->GetSource()->AddSink(camShaft);


 machine->AddComponent(banner);
 machine->AddBox(box);
 machine->AddComponent(sparty);

 machine->AddComponent(drivenShaft);
 machine->AddComponent(camShaft);


 machine->AddComponent(shaft);
 machine->AddComponent(crank);
 machine->AddComponent(pulley);
 machine->AddComponent(drivenPulley);
 machine->AddComponent(camPulley);
 machine->AddComponent(camDrivenPulley);
 machine->AddComponent(cam);
 machine->AddComponent(musicBox);


 return machine;
}

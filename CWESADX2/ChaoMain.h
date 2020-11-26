#pragma once
#include "SADXModLoader.h"
void AL_CustomizationInit();

//DataPointer(char, ControlEnabled, 0x0174AFFE);
extern NJS_TEXLIST AL_OSAMENU;
void AL_NameDisplay_Create();
ObjectMaster* AL_LargeTitleBar_Create();
DataPointer(int, ChaoSaveTimer, 0x019F6474);
VoidFunc(sub_583C60, 0x583C60);
FunctionPointer(void, ProjectToScreen, (float screenX, float screenY, float worldSpaceZ), 0x005848F0);
extern bool DayNightCheat;
extern int SeasonIndicator;
extern int TimeOfDay;
extern int Weather;


extern NJS_TEXLIST AL_SANDHOLE_TEXLIST;
extern NJS_TEXLIST CWE_OBJECT_TEXLIST;
extern NJS_TEXLIST timeofdayTexlistReplacer;
extern int HyperSwimFruitID;
extern int HyperFlyFruitID;
extern int HyperRunFruitID;
extern int HyperPowerFruitID;
extern int ShinyFruitID;
//void ApplyWSwitch(int a1);
//bool GetWSwitch(int a1);
//void ShinyJewelSpace_Init();
//void ResetChaoObjectData(ChaoObjectData* result);
VoidFunc(AL_PlayerControlManager_Load, 0x0052BA00);
void ChaoMain_Init();
#pragma once
#include "SADXModLoader.h"
#include <vector>
#include "AL_ModAPI.h"

extern std::vector<std::pair<NJS_TEXLIST*, NJS_OBJECT*>> FruitObjects;
extern std::vector<GROW_PARAM> FruitStats;
DataArray(NJS_OBJECT*, FruitModels, 0x033C05A0, 35);
DataArray(GROW_PARAM, ChaoFruitStatArray, 0x008896F8, 24);

void ALO_FruitExecutor_DisplayHack(ObjectMaster* eax0);
void ALO_FruitExecutor_MainHook();
void ALO_Fruit_Init();
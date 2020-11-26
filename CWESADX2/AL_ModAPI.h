#pragma once
#include "SADXModLoader.h"
#include "al_kinder_bm.h"
#include <vector>
#include <map>
#include <string>
#include "motiontable.h"
#include "alo_accessory.h"
struct GROW_PARAM
{
	__int16 mood;
	__int16 belly;
	__int16 addexp[8];
};

struct HatEntry
{
	NJS_OBJECT* obj;
	NJS_TEXLIST* texlist;

};

void LoadMsgAlItem(char* filename);
void* GenerateMsgBuffer();

using RegisterDataFuncPtr = void(__cdecl*)();
using LastBiteFruitFuncPtr = void(__cdecl*)(ChaoData* chaoData, ObjectMaster* fruit);

extern std::vector<MOTION_TABLE> chaoAnimations;
extern std::map<std::string, int> registeredAnimations;
extern std::vector<LastBiteFruitFuncPtr> lastBiteFruit;
extern std::vector<bool> HideHatVec;
extern std::vector<std::pair<const char*, NJS_TEXLIST*>> TexlistLoads;
extern std::vector<std::pair<NJS_OBJECT*, NJS_TEXLIST*>> Accessories;
extern "C" {
	__declspec(dllexport) void RegisterBlackMarketGeneralFruit(ItemChance* chance);
	__declspec(dllexport) void RegisterBlackMarketRareFruit(ItemChance* chance);
	__declspec(dllexport) int RegisterChaoFruit(NJS_OBJECT* model, NJS_TEXLIST* texlist, GROW_PARAM* stats, BlackMarketItemAttributes* attrib, LastBiteFruitFuncPtr funcPtr = 0, const char* name = 0, const char* description = 0);
	__declspec(dllexport) int RegisterChaoHat(NJS_OBJECT* model, NJS_TEXLIST* texlist, BlackMarketItemAttributes* attrib, const char* name = 0, const char* description = 0, bool hideHead = true);
	__declspec(dllexport) int RegisterChaoAccessory(EAccessoryType type, NJS_OBJECT* model, NJS_TEXLIST* texlist, BlackMarketItemAttributes* attrib, const char* name, const char* description);
	__declspec(dllexport) void Chao_RegAnimation(ObjectMaster* a1, std::string name);
	__declspec(dllexport) void RegisterDataFunc(RegisterDataFuncPtr ptr);
	__declspec(dllexport) MOTION_TABLE* GetChaoAnimations();
	__declspec(dllexport) void RegisterChaoAnimation(std::string name, MOTION_TABLE* action);
	__declspec(dllexport) int GetChaoAnimationIndex(std::string name);
	__declspec(dllexport) void RegisterChaoTexlistLoad(const char* name, NJS_TEXLIST* load);
}
void CallRegisteredHooks();
void AL_ModAPI_UpdatePtr();
void Animation_Init();
int AddCharacterChaoEvo(NJS_OBJECT* model, const char* textureName, int textureCount);
void AL_ModAPI_Init();

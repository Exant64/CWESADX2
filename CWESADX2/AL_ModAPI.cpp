//#include "stdafx.h"
#include "AL_ModAPI.h"
//#include "ALifeSDK_Functions.h"
//#include "alo_fruit.h"
//#include "ChaoMain.h"
//#include "data/cwe/object_common_cnk/CakeTest.h"
//#include "alo_obakehead.h"
//#include "ninja_functions.h"
#include "Chao.h"
//#include "al_sandhole.h"

#include <list>
#include "alo_accessory.h"
#include "alo_fruit.h"

void ApplyAL_BODY();

std::vector<MOTION_TABLE> chaoAnimations;
std::map<std::string, int> registeredAnimations;
std::vector<std::pair<const char*, NJS_TEXLIST*>> TexlistLoads;
std::vector<LastBiteFruitFuncPtr> lastBiteFruit;
std::vector<RegisterDataFuncPtr> RegisterDataHooks;
std::vector<const char*> MsgAlItem;
std::vector<bool> HideHatVec;


extern "C" {
	int RegisterAlItemString(const char* str)
	{
		MsgAlItem.push_back(str);
		return MsgAlItem.size() - 1; //last item inserted
	}
	
	__declspec(dllexport) int RegisterChaoFruit(NJS_OBJECT* model, NJS_TEXLIST* texlist, GROW_PARAM* stats, BlackMarketItemAttributes* attrib, LastBiteFruitFuncPtr funcPtr, const char* name, const char* description)
	{
		int ret = FruitObjects.size();
		FruitObjects.push_back(std::make_pair(texlist, model));
		FruitStats.push_back(*stats);
		if (attrib)
		{
			if (attrib->Name == -1)
				attrib->Name = RegisterAlItemString(name);
			if (attrib->Description == -1)
				attrib->Description = RegisterAlItemString(description);
			FruitBMAttributesMod.push_back(*attrib);
			BlackMarketCategories[ChaoItemCategory_Fruit].Count++;
		}
		else
		{
			FruitBMAttributesMod.push_back({ 0,0,999,0,0,0 });
			BlackMarketCategories[ChaoItemCategory_Fruit].Count++;
		}

		if (funcPtr)
			lastBiteFruit.push_back(funcPtr);
		else
			lastBiteFruit.push_back(nullptr);

		return ret;
	}
	__declspec(dllexport) void RegisterDataFunc(RegisterDataFuncPtr ptr)
	{
		RegisterDataHooks.push_back(ptr);
	}
	__declspec(dllexport) int RegisterChaoHat(NJS_OBJECT* model, NJS_TEXLIST* texlist, BlackMarketItemAttributes* attrib, const char* name, const char* description, bool hideHead)
	{
		if (hideHead == 0)
		{

			return RegisterChaoAccessory(EAccessoryType::Head, model, texlist, attrib, name, description);
		}
		//int ret = MaskObjObjectList.size();
		//MaskObjObjectList.push_back(std::make_pair(model, texlist));
		HideHatVec.push_back(hideHead);
		if (attrib)
		{
			if (attrib->Name == -1)
				attrib->Name = RegisterAlItemString(name);
			if (attrib->Description == -1)
				attrib->Description = RegisterAlItemString(description);
			HatBMAttributesMod.push_back(*attrib);
			BlackMarketCategories[ChaoItemCategory_Hat].Count++;
		}
		else
		{
			HatBMAttributesMod.push_back({ 0,0,999,0,0,0 });
			BlackMarketCategories[ChaoItemCategory_Hat].Count++;
		}
		return 0; //return re;t
	}
	__declspec(dllexport) int RegisterChaoAccessory(EAccessoryType type, NJS_OBJECT* model, NJS_TEXLIST* texlist, BlackMarketItemAttributes* attrib, const char* name, const char* description)
	{
		int ret = Accessories.size();
		AccessoryTypeMap.insert(std::make_pair(ret, type));
		Accessories.push_back(std::make_pair(model, texlist));
		if (attrib)
		{
			if (attrib->Name == -1)
				attrib->Name = RegisterAlItemString(name);
			if (attrib->Description == -1)
				attrib->Description = RegisterAlItemString(description);
			AccessoryBMAttributes.push_back(*attrib);
			BlackMarketCategories[ChaoItemCategory_Accessory].Count++;
		}
		else
		{
			AccessoryBMAttributes.push_back({ 0,0,999,0,0,0 });
			BlackMarketCategories[ChaoItemCategory_Accessory].Count++;
		}
		return ret;
	}
	__declspec(dllexport) void RegisterBlackMarketGeneralFruit(ItemChance* chance)
	{
		if (chance)
			GeneralFruitMarket.push_back(*chance);
	}

	__declspec(dllexport) void RegisterBlackMarketRareFruit(ItemChance* chance)
	{
		if (chance)
			RareFruitMarket.push_back(*chance);
	}

	__declspec(dllexport) void RegisterChaoAnimation(std::string name, MOTION_TABLE* action)
	{
		int index = chaoAnimations.size();
		registeredAnimations.insert(std::make_pair(name, index));
		chaoAnimations.push_back(*action);
	}

	__declspec(dllexport) void Chao_RegAnimation(ObjectMaster* a1, std::string name)
	{
		//PrintDebug("playing registered animation %s, index %d \n", name, registeredAnimations[name]);
		//Chao_Animation(&a1->Data1.Chao->MotionTable, registeredAnimations[name]);
		AL_SetMotionLink(a1, registeredAnimations[name]);
	}
	__declspec(dllexport) MOTION_TABLE* GetChaoAnimations()
	{
		return &chaoAnimations[0];
	}
	__declspec(dllexport) int GetChaoAnimationIndex(std::string name)
	{
		return registeredAnimations[name];
	}
	__declspec(dllexport) void RegisterChaoTexlistLoad(const char* name, NJS_TEXLIST* load)
	{
		TexlistLoads.push_back(std::make_pair(name, load));
	}
}

FunctionPointer(void, MotionInit, (MOTION_CTRL* a1, MOTION_TABLE* a2), 0x00734EC0);
void __cdecl LoadChaoMotionTableMod(ObjectMaster* a1)
{
	chaowk* wk = (chaowk*)a1->Data1;
	MotionInit(&wk->MotionCtrl, &chaoAnimations[0]);
}
/*
const int BlackMarketPreviewTrampoline = 0x5897A1;
const int BlackMarketPreviewTrampoline2 = 0x58A701;
const int BlackMarketPreviewTrampoline3 = 0x0058A538;

__declspec(naked) void BlackMarketPreview()
{
	int id;
	__asm {mov id, eax}
	njSetTexture(FruitObjects[id].first);
	DrawCnkModel2(FruitObjects[id].second->chunkmodel);
	__asm {
		add esp, 0Ch
		jmp BlackMarketPreviewTrampoline}
}


void BlackMarketPreviewHat(int id, BlackMarketData* data)
{
	if (id >= 16 && id <= 84)
	{
		ProjectToScreen(390.0f, 212.0f, -26.0f / data->field_90);
		if (data->field_88)
		{
			njRotateX(0, data->field_88);
		}
		if (data->field_8C)
		{
			njRotateY(0, data->field_8C);
		}
		njTranslate(0, 0.0f, -1.4f, 0.0f);
		njSetTexture(&ChaoTexLists[0]);
		ColorEggModel(((NJS_OBJECT * *)GetDllData("MaskObjObjectList"))[16]->chunkmodel, id - 16);
	}
	else
	{
		if (id == 15)
			ProjectToScreen(390.0f, 212.0f, -13.0f / data->field_90);
		else
			ProjectToScreen(390.0f, 212.0f, -26.0f / data->field_90);

		if (data->field_88)
		{
			njRotateX(0, data->field_88);
		}
		if (data->field_8C)
		{
			njRotateY(0, data->field_8C);
		}
		switch (id)
		{
		case 4:
		case 6:
		case 7:
		case 8:
		case 9:
			njRotateX(0, 0x8000);
			break;
		default:
			break;
		}

		if (id == 15)
			njTranslate(0, 0.0, -0.15, 0.0);
		else
			njTranslate(0, 0.0, -1.4, 0.0);

		njSetTexture(&ChaoTexLists[0]);

		if (id >= 85)
		{
			njSetTexture(MaskObjObjectList[id - 85].second);
			njCnkDrawObject(MaskObjObjectList[id - 85].first);
		}
		else
			njCnkDrawObject(((NJS_OBJECT * *)GetDllData("MaskObjObjectList"))[id]);
	}
}
__declspec(naked) void BlackMarketHatHook()
{
	__asm
	{
		push edi
		push eax
		call BlackMarketPreviewHat
		add esp, 8
		jmp BlackMarketPreviewTrampoline
	}
}
void BlackMarketPreviewHat2(Sint8* a1, BlackMarketData* data, int val, int selected)
{
	int id = *a1;
	if (id >= 16 && id <= 84)
		//break;
		id;
	if (id == 15)
		ProjectToScreen(56.0f, val - 15, *(float*)0xC712FC);
	else ProjectToScreen(56.0f, val - 15, -52);
	if (selected == data->field_9C && data->field_A4)
	{
		njRotateY(0, data->field_A4);
	}
	switch (id)
	{
	case 4:
	case 6:
	case 7:
	case 8:
	case 9:
		njRotateX(0, 0x8000);
		break;
	default:
		break;
	}

	if (id == 15)
		njTranslate(0, 0.0f, -0.13f, 0.0f);
	else
		njTranslate(0, 0.0f, -1.4f, 0.0f);

	njSetTexture(&ChaoTexLists[0]);

	if (id >= 85)
	{
		njSetTexture(MaskObjObjectList[id - 85].second);
		njCnkDrawObject(MaskObjObjectList[id - 85].first);
	}
	else
	{
		NJS_OBJECT** list = (NJS_OBJECT * *)GetDllData("MaskObjObjectList");
		if (id == SA2BHat_Bucket ||
			id == SA2BHat_EmptyCan ||
			id == SA2BHat_FlowerPot ||
			id == SA2BHat_Pan)
			sub_42E730(list[id]);
		else njCnkDrawObject(list[id]);
	}

}
__declspec(naked) void BlackMarketHatHook2()
{
	__asm
	{
		mov eax, esp
		push[eax + 0Ch]
		push[eax + 10h]
		push[ebp + 8]
		push esi
		//push [esp+14h]
		call BlackMarketPreviewHat2
		add esp, 16
		jmp BlackMarketPreviewTrampoline3
	}
}

__declspec(naked) void BlackMarketPreview2()
{
	int id;
	NJS_OBJECT* e;
	__asm
	{
		movsx eax, [esi]
		mov id, eax
	}
	njSetTexture(FruitObjects[id].first);
	e = FruitObjects[id].second;
	__asm
	{
		mov ecx, e
		jmp BlackMarketPreviewTrampoline2
	}
}
*/
void AL_ModAPI_UpdatePtr()
{

	//ApplyAL_BODY();


	//WriteData((GROW_PARAM * *)0x535F28, (GROW_PARAM*)FruitStats.data());

	//WARNING: 255 LIMIT!!!
	//WriteData((unsigned char*)0x00589E27, (unsigned char)HatBMAttributesMod.size());

	//BlackMarketCategories[ChaoItemCategory_Fruit].attrib = FruitBMAttributesMod.data();
	//BlackMarketCategories[ChaoItemCategory_Hat].attrib = HatBMAttributesMod.data();
	BlackMarketCategories[ChaoItemCategory_Accessory].attrib = AccessoryBMAttributes.data();

}

void CallRegisteredHooks()
{
	for (int i = 0; i < RegisterDataHooks.size(); i++)
		RegisterDataHooks[i]();
}

void Animation_Init()
{
	//Animation
	MOTION_TABLE* actions = (MOTION_TABLE*)0x036A94E8;
	chaoAnimations.insert(chaoAnimations.end(), actions, &actions[622]);
	if (chaoAnimations.size() < 622)
		PrintDebug("Animation_Init: Couldnt copy animations!!!\n");
	WriteJump((void*)0x00734EC0, LoadChaoMotionTableMod);
}

std::vector<NJS_OBJECT*> AL_RootObject;

const int GetAL_RootObjectHook = 0x56CA23;
__declspec(naked) NJS_OBJECT** GetAL_RootObjectPtr()
{
	NJS_OBJECT** pointer;
	pointer = &AL_RootObject[0];
	__asm
	{
		mov eax, pointer
		jmp GetAL_RootObjectHook
	}
}

void FillAL_RootObject()
{
	NJS_OBJECT** chaoModels = (NJS_OBJECT * *)0x034BD4A8;
	for (int i = 0; i < 138 + 6; i++) //todo:check this count thing
	{
		AL_RootObject.push_back(chaoModels[i]);
	}
}

std::vector <NJS_TEXNAME> AL_BODY_TEXNAMES;
std::vector <std::pair<NJS_TEXLIST, std::string>>  loadTexlists;
//Returns chaotype

void EditChunkModelTexture(NJS_CNK_MODEL* model, int baseTexture)
{
	Sint16* pbuf = model->plist;
	Sint16* foundChunk = FindChunk(pbuf, NJD_CT_TID);
	while (foundChunk != nullptr)
	{
		foundChunk[1] = (unsigned short)((foundChunk[1] & ~0x1FFF) | min(baseTexture + (foundChunk[1] & 0x1FFF), (unsigned short)0x1FFF));
		foundChunk = FindChunk(foundChunk, NJD_CT_TID);
	}
}


void EditChunkObjectTexture(NJS_OBJECT* obj, int baseTexture)
{
	do
	{
		if (obj->chunkmodel)
			EditChunkModelTexture(obj->chunkmodel, baseTexture);
		if (obj->child)
			EditChunkObjectTexture(obj->child, baseTexture);
		obj = obj->sibling;
	} while (obj != nullptr);
}

int AddCharacterChaoEvo(NJS_OBJECT* model, const char* textureName, int textureCount)
{
	int startIndex = AL_BODY_TEXNAMES.size();
	NJS_TEXNAME texName = {};
	for (int i = 0; i < textureCount; i++)
		AL_BODY_TEXNAMES.push_back(texName);
	NJS_TEXLIST newTexlist;
	newTexlist.nbTexture = textureCount;
	newTexlist.textures = &AL_BODY_TEXNAMES[startIndex];
	loadTexlists.push_back(std::make_pair(newTexlist, textureName));
	EditChunkObjectTexture(model, startIndex);
	int newChaoType = (AL_RootObject.size() / 6) + 2;
	for (int i = 0; i < 6; i++)
		AL_RootObject.push_back(model);

	return newChaoType;
}


void ApplyAL_BODY()
{
	//ChaoTexLists[0].nbTexture = ChaoTexLists[0]_TEXNAMES.size();
	ChaoTexLists[0].textures = &AL_BODY_TEXNAMES[0];
}

void LoadTexlistsHook()
{
	LoadChaoPVPs();
	for (int i = 0; i < loadTexlists.size(); i++) {
		char* asd = (char*)loadTexlists[i].second.c_str();
		LoadChaoTexlist(asd, &loadTexlists[i].first, 1);
	}
}

//FunctionPointer(void*, LoadChaoMessageFile, (const char* filename, int language), 0x072C060);
void LoadMsgAlItem(char* filename)
{
	int* loadedFile = (int*)LoadChaoMessageFile(filename, TextLanguage);
	if (loadedFile)
	{
		int v12 = 0;
		do
		{
			unsigned int* v13 = (unsigned int*)& loadedFile[v12];
			MsgAlItem.push_back((const char*)(*v13 + (char*)loadedFile));
			++v12;
		} while (loadedFile[v12] != -1);
	}
}

std::vector<unsigned char> MsgBuffer;
void* GenerateMsgBuffer()
{
	MsgBuffer.clear();
	int pointer = 4 * (MsgAlItem.size() + 1);
	for (int i = 0; i < MsgAlItem.size(); i++)
	{
		unsigned char* ptrBuffer = (unsigned char*)& pointer;
		MsgBuffer.push_back(ptrBuffer[3]);
		MsgBuffer.push_back(ptrBuffer[2]);
		MsgBuffer.push_back(ptrBuffer[1]);
		MsgBuffer.push_back(ptrBuffer[0]);
		pointer += strlen(MsgAlItem[i]) + 1;
	}
	MsgBuffer.push_back(0xFF); MsgBuffer.push_back(0xFF); MsgBuffer.push_back(0xFF); MsgBuffer.push_back(0xFF);
	for (int i = 0; i < MsgAlItem.size(); i++)
	{
		for (int j = 0; j < strlen(MsgAlItem[i]); j++)
			MsgBuffer.push_back(MsgAlItem[i][j]);
		MsgBuffer.push_back(0);
	}
	return MsgBuffer.data();
}

void AL_ModAPI_Init()
{
	//dynamic msg 
	LoadMsgAlItem((char*)"ChaoDXMessageItem");

	//Fruit
	for (int i = SA2BFruit_ChaoGardenFruit; i < 24; i++) {
		//FruitObjects.push_back(std::make_pair(&AL_OBJECT_TEXLIST, FruitModels[i]));
		//FruitStats.push_back(ChaoFruitStatArray[i]);
		//FruitBMAttributesMod.push_back(FruitBMAttributes[i]);
		//lastBiteFruit.push_back(nullptr);
	}

	//Hat
	for (int i = 0; i < BlackMarketCategories[ChaoItemCategory_Hat].Count; i++) {
	//	HatBMAttributesMod.push_back(HatBMAttributes[i]);
	}

	//Black Market
	for (int i = 0; i < 4; i++)
	{
		//GeneralFruitMarket.push_back(GeneralFruitChances[i]);
	}

	//load msgalitem custom
	WriteCall((void*)0x0058B71C, GenerateMsgBuffer);

	//WriteJump((void*)0x00589552, BlackMarketPreview);
	//WriteJump((void*)0x0058A827, BlackMarketPreview2);
	//WriteJump((void*)0x00589574, BlackMarketHatHook);
	//WriteJump((void*)0x0058A843, BlackMarketHatHook2);

#ifdef CWEV9
	//custom chao
	ChaoTexLists[0]_TEXNAMES = std::vector<NJS_TEXNAME>(143);
	WriteCall((void*)0x052ACA0, LoadTexlistsHook);
	FillAL_RootObject();
	WriteJump((void*)0x0056CA13, GetAL_RootObjectPtr);
	ApplyChaoTexLists[0]();
#endif
	AL_ModAPI_UpdatePtr();

	//TEST
	//RegisterChaoAnimation("PianoAnimationTest", &actions[340]);
	//ChaoItemStats stats = {0,0,0,0,0,0,40,0,0,0};
	//int ID = RegisterChaoFruit(&object_cake, &PROJECT_SANDHOLE_OBJECT_TEXLIST, &stats);
	//ItemChance chance = {ID, 100};
	//RegisterBlackMarketGeneralFruit(&chance, &BlackMarketCategories[ChaoItemCategory_Fruit].attrib[SA2BFruit_SquareFruit]);
}

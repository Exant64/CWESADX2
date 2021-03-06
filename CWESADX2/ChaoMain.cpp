#include "SADXModLoader.h"
#include "ChaoMain.h"
//#include "CWE.h"
//#include "al_minimal.h"
//#include "ninja_functions.h"
#include "patchedcolors.h"
#include "AL_ModAPI.h"
#include "chao.h"
NJS_TEXNAME AL_SANDHOLE_TEXNAME[2];
NJS_TEXLIST AL_SANDHOLE_TEXLIST = { arrayptrandlength(AL_SANDHOLE_TEXNAME) };

NJS_TEXNAME CWE_OBJECT_TEXNAME[45];
NJS_TEXLIST CWE_OBJECT_TEXLIST = { arrayptrandlength(CWE_OBJECT_TEXNAME) };

NJS_TEXNAME timeofdayTexnames[100]; //reserved 100 to be sure
NJS_TEXLIST timeofdayTexlistReplacer = { timeofdayTexnames, 100 };

NJS_TEXNAME osamenu_tex[9];
NJS_TEXLIST AL_OSAMENU = { osamenu_tex, 9 };

bool UseBrightChao = false;
bool UseMixedColors = false;
bool DayNightCheat = true;

int SeasonIndicator = 1;
int TimeOfDay;
int Weather = 0;

int HyperSwimFruitID;
int HyperFlyFruitID;
int HyperRunFruitID;
int HyperPowerFruitID;
int ShinyFruitID;


void ChaoMain_Constructor_Hook()
{
	PrintDebug("ChaoMain Constructor\n");
	//PrintDebug("ChaoSaveTimer = %d \n", ChaoSaveTimer);
	//LoadChaoTexlist("al_minda", &AL_SANDHOLE_TEXLIST, 1);
	LoadChaoTexlist("CWE_OBJECT", &CWE_OBJECT_TEXLIST, 1);
	//LoadChaoTexlist("AL_OSAMENU_TEX_E", &AL_OSAMENU, 1);
	for (int i = 0; i < TexlistLoads.size(); i++)
	{
		LoadChaoTexlist(TexlistLoads[i].first, TexlistLoads[i].second, 1);
	}

}
/*
VoidFunc(sub_52E400, 0x52E400);
void ChaoMain_subprgmanager_Hook()  //use this to do something on ChaoWorld loading -- NOT WORKING, SINCE SAVE FILE ISNT LOADED YET
{
	sub_52E400();
	//ReadCWESaveFile();
}

void ResetChaoObjectData(ChaoObjectData* result)
{
	result->Type = -1;
	result->position.x = 0.0;
	result->Garden = -1;
	result->position.y = 0.0;
	result->position.z = 0.0;
	result->Age = 0;
	result->Size = 0;
}
DataPointer(ChaoObjectData*, dword_19F6454, 0x19F6454);
void __cdecl sub_52E920(int a1)
{
	int v1; // esi
	double v2; // st7
	ALFSave* result; // eax
	int v4; // ebx
	ChaoObjectData* v5; // edi
	ChaoObjectData* v6; // ebp
	NJS_VECTOR* v8; // esi
	int v10; // [esp+18h] [ebp-10h]
	NJS_VECTOR a4; // [esp+1Ch] [ebp-Ch]

	v1 = CurrentChaoArea;
	v10 = CurrentChaoArea;
	v2 = (double)rand() * 0.000030517578125 * 360.0 * 182.0444488525391;
	result = (ALFSave*)(signed int)v2;
	v4 = (signed int)v2;
	if ((unsigned int)(v1 - 1) <= 2)
	{
		result = (ALFSave*)(a1 - 2);
		switch (a1)
		{
		case 2:
			result = (ALFSave*)GetChaoSavePointer();
			v5 = result->ChaoAnimalSlots;
			v6 = (ChaoObjectData*)& result->RaceData;
			break;
		case 3:
			result = (ALFSave*)GetChaoSavePointer();
			v5 = result->ChaoFruitSlots;
			v6 = result->ChaoSeedSlots;
			break;
		case 7:
			result = (ALFSave*)GetChaoSavePointer();
			v5 = result->ChaoSeedSlots;
			v6 = result->ChaoHatSlots;
			break;
		case 9:
			result = (ALFSave*)GetChaoSavePointer();
			v5 = result->ChaoHatSlots;
			v6 = result->ChaoAnimalSlots;
			break;
		default:
			return;
			//v5 = v10;
			//v6 = v10;
			break;
		}
		if (v5 < v6)
		{
			v8 = &v5->position;
			do
			{
				result = (ALFSave*)(unsigned __int16)v5->Type;
				if ((signed __int16)v5->Type < 0)
				{
					goto LABEL_30;
				}
				if (v5->Garden == CurrentChaoArea)
				{
					if (v5 != (ChaoObjectData*)dword_19F6454)
					{
						a4.x = 0.0f;
						a4.y = 0.0f;
						a4.z = 0.0f;
						switch (a1)
						{
						case 2:
							if (v5->Type >= 21 && v5->Type < 25)
							{
								ALO_ChaosDriveExecutor_Load(
									LOBYTE(v5->Type) - 21,
									v8,
									&a4,
									(ChaoData*)v5);
							}
							else
							{
								AL_MinimalExecutor_Load(v5->Type, v8, v4, &a4, (int)v5);
							}
							break;
						case 3:
							if (v5->Size)
							{
								ALO_FruitExecutor_Load(
									v5->Type,
									v8,
									v4,
									&a4,
									(ChaoData*)v5);
							}
							else
							{
								ResetChaoObjectData(v5);
							}
							break;
						case 7:
							ALO_SeedExecutor_Load(v5->Type, v8, &a4, (int)v5);
							break;
						case 9:
							ALO_ObakeHeadExecutor_Load(
								v5->Type,
								v8,
								v4,
								&a4,
								(int)v5);
							break;
						default:
							goto LABEL_27;
						}
					}
					goto LABEL_27;
				}
				if (v5->Garden <= 0 || v5->Garden > 3)
				{
				LABEL_30:
					v8->x = 0.0f;
					v8->y = 0.0f;
					v8->z = 0.0f;
					v5->Type = -1;
					result = 0;
					v5->Size = 0;
					v5->Age = 0;
					v5->Garden = -1;
				}
			LABEL_27:
				++v5;
				v8 = (NJS_VECTOR*)((char*)v8 + 20);
			} while (v5 < v6);
		}
	}
}
const int sub_46E5B0Ptr = 0x46E5B0;
void sub_46E5B0(ObjectMaster* a1, int a2)
{
	__asm
	{
		push a1
		mov ecx, a2
		call sub_46E5B0Ptr
		add esp, 4
	}
}

DataPointer(int, HeldItemType, 0x19F6450);

void ApplyWSwitch(int a1)
{
	int index = ChaoSaveIndexThing;
	if (index != 1)
		index = 0;
	ChaoSave[index].ChaoGardensUnlocked |= a1;
}

bool GetWSwitch(int a1)
{
	int index = ChaoSaveIndexThing;
	if (index != 1)
		index = 0;
	return ChaoSave[index].ChaoGardensUnlocked & a1;
}

const int sub_46E5E0Ptr = 0x46E5E0;
void sub_46E5E0(int a1, int a2)
{
	__asm
	{
		mov eax, a1
		mov edx, a2
		call sub_46E5E0Ptr
	}
}

*/
FunctionPointer(void, StopHoldingTaskP, (unsigned __int8 a1), 0x004420C0);
FunctionPointer(int, AL_GetHoldingItemCategory, (), 0x007174D0);
FunctionPointer(int, sub_7174E0, (), 0x007174E0);
FunctionPointer(ObjectMaster*, Animal_Load, (char a1, NJS_VECTOR* a2, int a3, NJS_VECTOR* a4, int a5), 0x00722200);
FunctionPointer(ObjectMaster*, GardenFruit_Create, (int a1, NJS_VECTOR* position, Angle angle, NJS_VECTOR* a4, ITEM_SAVE_INFO* a5), 0x00722DE0);
FunctionPointer(ObjectMaster*, ALO_ObakeHeadCreate, (char a1, NJS_VECTOR* a2, int a3, NJS_VECTOR* a4, int a5), 0x007236F0);
void __cdecl LoadHeldItem_()
{
	int v0; // edi
	int v1; // eax
	ITEM_SAVE_INFO* v2; // ebx
	Angle v3; // esi
	ObjectMaster* v4; // esi
	int v5; // eax
	ObjectMaster* v6; // [esp+8h] [ebp-1Ch]
	NJS_VECTOR position; // [esp+Ch] [ebp-18h]
	NJS_VECTOR a4; // [esp+18h] [ebp-Ch]

	v0 = AL_GetHoldingItemCategory();
	v1 = sub_7174E0();
	v2 = (ITEM_SAVE_INFO*)v1;
	position.x = 0.0;
	position.y = 0.0;
	position.z = 0.0;
	a4.x = 0.0;
	a4.y = 0.0;
	a4.z = 0.0;
	if (v1 && sub_7174E0() >= 0)
	{
		v3 = EntityData1Ptrs[0]->Rotation.y;
		position.x = EntityData1Ptrs[0]->Position.x;
		position.y = EntityData1Ptrs[0]->Position.y;
		position.z = EntityData1Ptrs[0]->Position.z;
		position.x = njSin(v3) * 3.0 + position.x;
		position.z = njCos(v3) * 3.0 + position.z;
		StopHoldingTaskP(0);
		GetCharObj2(0)->ObjectHeld = 0;
		switch (v0)
		{
		case 2:
			if (v2->Type >= 0 && v2->Type < 15)
			{
				v4 = Animal_Load(v2->Type, &position, EntityData1Ptrs[0]->Rotation.y, &a4, (int)v2);
				goto LABEL_15;
			}
			break;
		case 3:
			v4 = GardenFruit_Create(v2->Type, &position, EntityData1Ptrs[0]->Rotation.y, &a4, v2);
			goto LABEL_15;
		case 8:
			v4 = Accessory_Load(v2->Type, &position, EntityData1Ptrs[0]->Rotation.y, &a4, (short*)v2);
			goto LABEL_15;
		case 9:
			v4 = Accessory_Load(v2->Type, &position, EntityData1Ptrs[0]->Rotation.y, &a4, (short*)v2);
		LABEL_15:
			v5 = CurrentChaoStage;
			if (v5 >= 4 && v5 <= 6)
			{
				v2->Garden = CurrentChaoStage;
			}
			SetHeldObject(0, v4);
			return;
		}
		v4 = nullptr;
		goto LABEL_15;
	}
}
void ChaoMain_Init()
{
	//WriteCall((void*)0x0052B2DA, ChaoMain_subprgmanager_Hook);
	WriteCall((void*)0x00715445, ChaoMain_Constructor_Hook);
	//WriteJump((void*)0x52E920, sub_52E920);
	WriteJump(LoadHeldItem, LoadHeldItem_);
	//WriteJump((void*)0x52F2A0, sub_52F2A0);
}
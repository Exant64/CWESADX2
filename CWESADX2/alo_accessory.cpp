//#include "stdafx.h"
#include "SADXModLoader.h"
#include <map>
#include <vector>
#include "alo_accessory.h"
//#include "ninja_functions.h"
//#include "AL_ModAPI.h"
//#include "Chao.h"
#include "data/cwe/object_common_cnk/alo_mannequin.nja"
#include "ChaoMain.h"
std::vector<std::pair<NJS_OBJECT*, NJS_TEXLIST*>> Accessories;
std::map<int, EAccessoryType> AccessoryTypeMap;
VoidFunc(sub_42D340, 0x42D340);
extern NJS_OBJECT object_alo_mannequin;

void Accessory_Display(ObjectMaster* a1)
{
	njPushMatrixEx();

	njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
	njRotateY(0, a1->Data1->Rotation.y);

	njSetTexture(&CWE_OBJECT_TEXLIST);
	njCnkDrawObject(&object_alo_mannequin);

	njSetTexture(Accessories[a1->Data1->Rotation.x].second);
	njCnkDrawObject(Accessories[a1->Data1->Rotation.x].first);

	njPopMatrixEx();
}

FunctionPointer(ObjectMaster*, ALO_ObakeHeadCreate, (int a1, NJS_VECTOR* a2, int a3, NJS_VECTOR* a4, int a5), 0x007236F0);
ObjectMaster* Accessory_Load(int ID, NJS_VECTOR* position, int rotY, NJS_VECTOR* velocity, short* savedata)
{
	ObjectMaster* obj = ALO_ObakeHeadCreate(ID, position, rotY, velocity, (int)savedata);
	if (ID >= 256) {
		//is accessory
		obj->Data1->CollisionInfo->CollisionArray[2].kind = 0x94;//InitCollision(obj, ALO_Accessory_collision, 3, 5);
		obj->Data1->Rotation.x = ID - 256;
		obj->DisplaySub = Accessory_Display;
		((al_entry_work*)obj->UnknownA_ptr)->category = ChaoItemCategory_Accessory;
	}
	return obj;
}

FunctionPointer(ChaoData*, AL_GetNewChaoSaveInfo, (), 0x00531AA0);
DataArray(BlackMarketItem, PurchasedItems, 0x01DBEDA0, 6);
DataPointer(int, PurchasedItemCount, 0x01DBEDAC);
const int sub_5319F0Ptr = 0x5319F0;
int sub_5319F0(int a1)
{
	int retVal;
	__asm
	{
		mov esi, a1
		call sub_5319F0Ptr
		mov retVal, eax
	}
	return retVal;
}
/*
void __cdecl sub_548F40(ObjectMaster* a2)
{
	EntityData1* v1; // esi
	__int16 v2; // ax
	EntityData1* v3; // edi
	float* v4; // ebx
	double v5; // st7
	float* v6; // ebx
	int v7; // eax
	int v8; // ebp
	int v9; // eax
	int v10; // esi
	ChaoData* v11; // edi
	ObjectMaster* v12; // eax
	Float* v13; // eax
	Float v14; // edx
	Float v15; // ecx
	ChaoData* v16; // eax
	unsigned int v17; // eax
	DWORD* v18; // edx
	signed int v19; // eax
	short* v20; // ecx
	int v21; // eax
	unsigned int v22; // eax
	DWORD* v23; // edx
	signed int v24; // eax
	short* v25; // ecx
	int v26; // eax
	int v27; // eax
	int v28; // ecx
	int v29; // eax
	BlackMarketItem* v30; // esi
	BlackMarketItem* v31; // edi
	int v32; // [esp+8h] [ebp-D0h]
	NJS_VECTOR position; // [esp+Ch] [ebp-CCh]
	NJS_VECTOR output; // [esp+18h] [ebp-C0h]
	NJS_VECTOR result; // [esp+24h] [ebp-B4h]
	AL_GENE a1; // [esp+30h] [ebp-A8h]

	v1 = (EntityData1*)a2->Data1.Entity;
	v1->Index++;
	if (v1->Index > 0xFu)
	{
		v1->Index = 0;

		position.x = MainCharObj1[0]->Position.x;
		position.y = MainCharObj1[0]->Position.y + 4.5;
		position.z = MainCharObj1[0]->Position.z;

		result.x = 0.0;
		result.y = (0.5 - (double)rand() * 0.000030517578125) * 0.2000000029802322 * 1.600000023841858 + 0.960000052452088;
		result.z = (0.5 - (double)rand() * 0.000030517578125) * 0.25 * 1.600000023841858 + 0.559999998807907;

		njPushMatrixEx();
		memcpy(MatrixBase, (void*)0x025F02A0, 0x30);
		v5 = (0.5 - (double)rand() * 0.000030517578125) * 60.0 * -182.0444488525391;
		if (0x4000 - (signed int)v5 != MainCharObj1[0]->Rotation.y)
		{
			njRotateY(MatrixBase, 0x4000 - (signed int)v5 - MainCharObj1[0]->Rotation.y);
		}
		njCalcVector(&result, &output, MatrixBase);
		njPopMatrixEx();

		v7 = PurchasedItemCount;
		if (PurchasedItemCount <= 0)
		{
			a2->MainSub = DeleteObject_;
		}
		else
		{
			v8 = v7 - 1;
			v1->Rotation.x = v7 - 1;
			v9 = PurchasedItems[v7 - 1].Category;
			v10 = PurchasedItems[v8].Type;
			--PurchasedItemCount;
			v32 = v10;
			switch (v9)
			{
			case 1:
				if (sub_5319F0(CurrentChaoArea) < 8)
				{
					v11 = AL_GetNewChaoSaveInfo();
					InitChaoDNA(&a1);
					a1.EggColor = v32;
					if (v11)
					{
						v12 = CreateChaoEgg(&a1, v11, 0, &position, 3);
					}
					else
					{
						v12 = CreateChaoEgg(&a1, 0, 0, &position, 3);
					}
					if (v12)
					{
						*(NJS_VECTOR*)v12->EntityData2 = output;
						//MOV_SetVelo(v12, &output);
					}
					break;
				}
				++PurchasedItemCount;
				return;
			case 3:
				ALO_FruitExecutor_Load(v10, &position, MainCharObj1[0]->Rotation.y, &output, (ChaoData*)AL_GetNewItemSaveInfo(3));
				break;
			case 7:
				ALO_SeedExecutor_Load(v10, &position, &output, (int)AL_GetNewItemSaveInfo(3));
				break;
			case ChaoItemCategory_Accessory:
				Accessory_Load(v10 + 256, &position, MainCharObj1[0]->Rotation.y, &output, (short*)AL_GetNewItemSaveInfo(9));
				break;
			case 9:
				ALO_ObakeHeadExecutor_Load(v10, &position, MainCharObj1[0]->Rotation.y, &output, (int)AL_GetNewItemSaveInfo(9));
				break;
			default:
				goto LABEL_34;
			}

		LABEL_33:
			PurchasedItems[v8].Category = (ChaoItemCategory)-1;
		LABEL_34:
			if (v8 != PurchasedItemCount)
			{
				v27 = v8;
				if (v8 < PurchasedItemCount)
				{
					v28 = PurchasedItemCount - v8;
					v29 = PurchasedItemCount - v8;
					v30 = &PurchasedItems[v8 + 1];
					v31 = &PurchasedItems[v8];
					while (v28)
					{
						*v31 = *v30;
						++v30;
						++v31;
						--v28;
					}
					v27 = v8 + v29;
				}
				PurchasedItems[v27].Category = (ChaoItemCategory)-1;
			}
		}
	}
}
*/
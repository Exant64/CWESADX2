#include "SADXModLoader.h"
#include "al_kinder_bm.h"
#include <random>
#include "AL_ModAPI.h"
#include "ChaoMain.h"
#include "chao.h"
#include "alo_fruit.h"
BlackMarketItem PurchasedItems[4];
int PurchasedItemCount;
extern NJS_OBJECT object_alo_mannequin;
std::vector<ItemChance> GeneralFruitMarket;
std::vector<ItemChance> RareFruitMarket;
std::vector<BlackMarketItemAttributes> FruitBMAttributesMod;
std::vector<BlackMarketItemAttributes> HatBMAttributesMod;
std::vector<BlackMarketItemAttributes> AccessoryBMAttributes;
FunctionPointer(int, GetTotalNumberEmblem, (), 0x0725380);
const int BlackMarketInventorySize = 32;
void GeneralFruit()
{
	for (size_t i = 0; i < GeneralFruitMarket.size(); i++)
	{
		if (BlackMarketItemCount >= BlackMarketInventorySize)
			break;
		int v11 = (signed int)(rand() * 0.000030517578125 * 100.0);
		if (v11 < GeneralFruitMarket[i].chance) {
			BlackMarketInventory[BlackMarketItemCount].Category = ChaoItemCategory_Fruit;
			BlackMarketInventory[BlackMarketItemCount].Type = GeneralFruitMarket[i].item;
			BlackMarketItemCount++;
		}
	}
}
void RareFruit()
{
	for (size_t i = 0; i < RareFruitMarket.size(); i++)
	{
		if (BlackMarketItemCount >= BlackMarketInventorySize)
			break;
		int v11 = (signed int)(rand() * 0.000030517578125f * 100.0f);
		int item = RareFruitMarket[i].item;
		if (item == SA2BFruit_Mushroom)
		{
			float random = (double)rand() * 0.000030517578125f;
			if (random < 0.3f)
				item = SA2BFruit_MushroomAlt;
		}
		if (GetTotalNumberEmblem() >= BlackMarketCategories[ChaoItemCategory_Fruit].attrib[item].RequiredEmblems)
		{
			if (v11 < RareFruitMarket[i].chance) {
				BlackMarketInventory[BlackMarketItemCount].Category = ChaoItemCategory_Fruit;
				BlackMarketInventory[BlackMarketItemCount].Type = item;
				BlackMarketItemCount++;
			}
		}
	}

}
//get max object count sub_717650
//also this sub_7253C0

//7174B0 sets the held item type

//7174D0 checks purchaseditemcount || already holding chao
int __cdecl sub_717650(int a1)
{
	int result; // eax

	if (a1 == 3)
	{
		result = 40;
	}
	else if (a1 == ChaoItemCategory_Accessory)
	{
		return 24;
	}
	else
	{
		result = a1 != 9 ? 0 : 0x18;
	}


	return result;
}
int CanIPurchase()
{
	if (PurchasedItemCount >= 4)
		return 0;
	else return -1;
}



ITEM_SAVE_INFO dummyItemHack;

ITEM_SAVE_INFO* ReturnDummyItem() { return &dummyItemHack; }

void PurchaseItem(int object, ITEM_SAVE_INFO* a2)
{
	PurchasedItems[PurchasedItemCount].Category = (ChaoItemCategory)object;
	PurchasedItems[PurchasedItemCount++].Type = a2->Type;
}
FunctionPointer(void, njQuadTextureStart, (bool enable), 0x0077DD90);
FunctionPointer(void, njQuadTextureEnd, (), 0x0077DDE0);
FunctionPointer(void, njDrawQuadTexture, (NJS_QUAD_TEXTURE* points, float scale), 0x0077E970);
float flt_1A13BE0 = 40.0f;
float flt_1A13BE4 = 16.0f;
float flt_1A13BE8 = 64.0;
float flt_1A13BEC = 16.0;
float flt_1A13BF0 = 0.0;
float flt_1A13BF4 = 424.0f;
float flt_1A13BD8 = -1.5f;
void DrawPurchasedItems()
{
	NJS_QUAD_TEXTURE v9;
	int v2 = 0;
	njQuadTextureStart(false);
	if (PurchasedItemCount > 0)
	{
		v9.u1 = 0.0;
		v9.u2 = 1.0;
		njSetTexture(&ChaoTexLists[1]);
		v9.v2 = 1.0;
		v9.v1 = 0.0;
		for (int i = 0; i < PurchasedItemCount; i++)
		{
			switch (PurchasedItems[i].Category)
			{
			case 1:
				v2 = 4;
				break;
			case 3:
				v2 = 5;
				break;
			case 7:
				v2 = 3;
				break;
			case 8:
			default:
				v2 = 6;
				break;
			}
			*(int*)0x03D0FCE4 = 0xFFFFFFFF;
			njSetTextureNum(v2);
			float v3 = (double)i;
			float v4 = v3 * flt_1A13BE0 + flt_1A13BE8;
			v9.x1 = v4 - flt_1A13BE4;
			v9.x2 = v4 + flt_1A13BE4;
			float v5 = v3 * flt_1A13BF0 + flt_1A13BF4;
			v9.y1 = 480.0f - (flt_1A13BEC + v5);
			v9.y2 = 480.0f - (v5 - flt_1A13BEC);
			float v6 = -1.0 / flt_1A13BD8;
			njDrawQuadTexture(&v9, v6);
		}
	}
	njQuadTextureEnd();
}
VoidFunc(sub_732C40, 0x732C40);
void DrawPurchasedItems_Hook()
{
	DrawPurchasedItems();
	sub_732C40();
}

void AlItemIconTaskExec(ObjectMaster* a1) { a1->DisplaySub(a1); }
ObjectMaster* AlItemIconTaskExec_ptr = 0;
VoidFunc(sub_716460, 0x716460);
void AlItemIconTaskExecKill()
{
	AlItemIconTaskExec_ptr = 0;
}
void AlItemIconTaskExecHook()
{
	LoadAnimalPVMs();
	if (!AlItemIconTaskExec_ptr)
	{
		AlItemIconTaskExec_ptr = AllocateObjectMaster(1, AlItemIconTaskExec);
		if (AlItemIconTaskExec_ptr)
		{
			AlItemIconTaskExec_ptr->DeleteSub = (ObjectFuncPtr)AlItemIconTaskExecKill;
			AlItemIconTaskExec_ptr->DisplaySub = (ObjectFuncPtr)DrawPurchasedItems;
		}
	}
}

FunctionPointer(int, AL_GetCurrGardenChaoCount, (), 0x00715DF0);
FunctionPointer(ChaoDataBase*, AL_GetNewChaoSaveInfo, (), 0x00715E60);

FunctionPointer(ObjectMaster*, GardenHat_Create, (int a1, NJS_VECTOR* a2, int a3, NJS_VECTOR* a4, ITEM_SAVE_INFO* a5), 0x007236F0);
FunctionPointer(void, GardenFruit_Create, (int a1, NJS_VECTOR* position, Angle angle, NJS_VECTOR* a4, ITEM_SAVE_INFO* a5), 0x722DE0);

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
	ChaoDataBase* v11; // edi
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
	ChaoDNA a1; // [esp+30h] [ebp-A8h]

	v1 = (EntityData1*)a2->Data1;
	v1->Index++;
	if (v1->Index > 0xFu)
	{
		v1->Index = 0;

		position.x = PlayerPtrs[0]->Data1->Position.x;
		position.y = PlayerPtrs[0]->Data1->Position.y + 4.5;
		position.z = PlayerPtrs[0]->Data1->Position.z;

		result.x = 0.0;
		result.y = (0.5 - (double)rand() * 0.000030517578125) * 0.2000000029802322 * 1.600000023841858 + 0.960000052452088;
		result.z = (0.5 - (double)rand() * 0.000030517578125) * 0.25 * 1.600000023841858 + 0.559999998807907;

		njPushMatrixEx();
		njUnitMatrix(0);
		v5 = (0.5 - (double)rand() * 0.000030517578125) * 60.0 * -182.0444488525391;
		if (0x4000 - (signed int)v5 != PlayerPtrs[0]->Data1->Rotation.y)
		{
			njRotateY(0, 0x4000 - (signed int)v5 - PlayerPtrs[0]->Data1->Rotation.y);
		}
		njCalcVector(0, &result, &output);
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
				if (AL_GetCurrGardenChaoCount() < 8)
				{
					v11 = (ChaoDataBase*)AL_GetNewChaoSaveInfo();
					InitChaoDNA(&a1);
					a1.field_1[0] = v32;
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
						MOV_SetVelo(v12, &output);
					}
					break;
				}
				++PurchasedItemCount;
				return;
			case 3:
				GardenFruit_Create(v10, &position, PlayerPtrs[0]->Data1->Rotation.y, &output, AL_GetNewItemSaveInfo(3));
				break;
			case ChaoItemCategory_Accessory:
				Accessory_Load(v10 + 256, &position, PlayerPtrs[0]->Data1->Rotation.y, &output, (short*)AL_GetNewItemSaveInfo(9));
				break;
			case 9:
				GardenHat_Create(v10, &position, PlayerPtrs[0]->Data1->Rotation.y, &output, AL_GetNewItemSaveInfo(9));
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

DataArray(ItemChance, GeneralFruitChances, 0x0885584, 4);
DataArray(BlackMarketItemAttributes, BMFruit, 0x884658, 23);
struct SSellEgg
{
	__int16 emblem0;
	__int16 emblem1;
	char id[3];
};

DataArray(SSellEgg, kSellEggList, 0x00885508, 10);

std::vector<bool> set(255);
FunctionPointer(void, BlackMarketAddInventory, (ChaoItemCategory category, char type), 0x00726B20);
void FBuyListAddSet100(std::vector<bool>& set, ChaoItemCategory category)
{
	for (int i = 0; i < set.size(); i++)
	{
		if (set[i])
		{
			BlackMarketAddInventory(category, i);
			set[i] = false;
		}
	}
}
DataArray(unsigned char, byte_8A2C7C, 0x885580, 4);
char byte_8A2EFC[] =
{ '\x01', '\x02', '\x03', '\0' };
char byte_8A2FA4[4] =
{ '\x04', '\x05', '\x06', '\0' };
DataArray(NJS_CNK_OBJECT*, ChaoItemModels_, 0x36008E8, 10);
DataArray(NJS_CNK_OBJECT*, ChaoFruitModels_, 0x33C05A0, 20);
FunctionPointer(void, chRareEggDrawModel, (NJS_CNK_MODEL* a1, int a2), 0x0078AF10);
void FBuyListUpdate()
{
	int v3; // edi
	int v5; // ebx
	signed int v16; // edi
	int v19; // ecx
	int v22; // ebp
	char* v23; // esi
	signed int v26; // edi
	BlackMarketItemAttributes* v29; // ecx
	signed int v30; // esi
	signed int v31; // eax
	signed int v35; // ebx
	signed int v38; // eax
	double v49; // st7
	int v51; // [esp+10h] [ebp-4Ch]
	char v54[255]; // [esp+38h] [ebp-24h]


	BlackMarketItemCount = 0;
	v3 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (GetTotalNumberEmblem() >= kSellEggList[i].emblem0)
		{
			int selectedEggID = kSellEggList[i].id[((*(int*)0x19F6464 + *(int*)0x19F6468) & 0x7FFFFFFF) % 3];
			if (GetTotalNumberEmblem() >= kSellEggList[i].emblem1) //shiny emblem
			{
				if ((double)rand() * 0.000030517578125 < 0.300000011920929)
				{
					selectedEggID += 27;
				}
			}
			v54[v3++] = selectedEggID;
		}
	}
	v5 = 1 + (signed int)((double)rand() * 0.000030517578125 * 5.0);
	if (v3 > v5)
	{
		v22 = 0;

		if (BlackMarketItemCount < BlackMarketInventorySize)
		{
			do
			{
				if (v22 >= v5)
				{
					break;
				}
				v23 = &v54[(signed int)((double)rand() * 0.000030517578125 * (double)v3)];
				--v3;
				++v22;
				set[*v23] = true;
				*v23 = (char)v54[v3];
			} while (v22 + BlackMarketItemCount < BlackMarketInventorySize);
		}
		FBuyListAddSet100(set, ChaoItemCategory_Egg);
	}
	else
	{
		if (v3 > 0)
		{
			for (int i = 0; i < v3; i++)
			{
				if (BlackMarketItemCount >= BlackMarketInventorySize)
				{
					break;
				}
				BlackMarketAddInventory(ChaoItemCategory_Egg, v54[i]);
			}
		}
	}

	GeneralFruit();
	v16 = 0;
	if (BlackMarketItemCount < BlackMarketInventorySize)
	{
		do
		{
			if (v16 >= 2)
			{
				break;
			}
			int id = byte_8A2C7C[(signed int)((double)rand() * 0.000030517578125 * 3.0)];
			if (!set[id])
			{
				set[id] = true;
				++v16;
			}
		} while (v16 + BlackMarketItemCount < BlackMarketInventorySize);
	}
	FBuyListAddSet100(set, ChaoItemCategory_Fruit);

	v19 = BlackMarketItemCount;
	if (BlackMarketItemCount < BlackMarketInventorySize)
	{
		//BlackMarketAddInventory(ChaoItemCategory_Seed, 0);
		if (BlackMarketItemCount < BlackMarketInventorySize)
		{
			if ((double)rand() * 0.000030517578125 < 0.7f)
			{
				//BlackMarketAddInventory(ChaoItemCategory_Seed, byte_8A2EFC[-(signed int)((double)rand() * 0.000030517578125 * -3.0)]);
			}
		}
	}
	v26 = 0;
	if (BlackMarketItemCount < BlackMarketInventorySize)
	{
		do
		{
			if (v26 >= 2)
			{
				break;
			}
			int id = byte_8A2FA4[(signed int)((double)rand() * 0.000030517578125 * 3.0)];
			if (!set[id])
			{
				set[id] = true;
				++v26;
			}
		} while (v26 + BlackMarketItemCount < BlackMarketInventorySize);
	}
	//FBuyListAddSet100(set, ChaoItemCategory_Seed);

	v29 = BlackMarketCategories[ChaoItemCategory_Hat].attrib;
	v30 = 0;
	v31 = 0;
	do
	{
		if (v31 != SA2BHat_BlueWoolBeanie
			&& v31 != SA2BHat_BlackWoolBeanie
			&& v29->PurchasePrice > 0
			&& GetTotalNumberEmblem() >= v29->RequiredEmblems)
			//&& (rand() * 0.000030517578125) > 0.5
			//&& v31 < 32)
		{
			v54[v30++] = v31;
		}
		++v31;
		++v29;
	} while (v31 < HatBMAttributesMod.size());
	if (v30 > 5)
	{
		v35 = 0;

		if (BlackMarketItemCount < BlackMarketInventorySize)
		{
			do
			{
				if (v35 >= 5)
				{
					break;
				}
				int id = v54[(signed int)((double)rand() * 0.000030517578125 * (double)v30)];
				if (id == SA2BHat_RedWoolBeanie)
				{
					v38 = (signed int)((double)rand() * 0.000030517578125 * 31.0);
					if (v38 >= 5)
					{
						if (v38 < 15
							&& GetTotalNumberEmblem() >= BlackMarketCategories[ChaoItemCategory_Hat].attrib[SADXHat_BlueWoolBeanie].RequiredEmblems)
						{
							id = SA2BHat_BlueWoolBeanie;
						}
					}
					else if (GetTotalNumberEmblem() >= BlackMarketCategories[ChaoItemCategory_Hat].attrib[SADXHat_BlackWoolBeanie].RequiredEmblems)
					{
						id = SA2BHat_BlackWoolBeanie;
					}
				}
				if (GetTotalNumberEmblem() >= BlackMarketCategories[ChaoItemCategory_Hat].attrib[id].RequiredEmblems)
				{
					if (!set[id])
					{
						set[id] = true;
						++v35;
					}
				}
			} while (v35 + BlackMarketItemCount < BlackMarketInventorySize);
		}
		FBuyListAddSet100(set, ChaoItemCategory_Hat);
	}
	else
	{
		if (v30 > 0)
		{
			for (int i = 0; i < v30; i++)
				if (BlackMarketItemCount < BlackMarketInventorySize)
				{
					BlackMarketAddInventory(ChaoItemCategory_Hat, v54[i]);
				}
		}
	}

	//accessory, hardcoded type
	for (int i = 0; i < AccessoryBMAttributes.size(); i++)
	{
		if (GetTotalNumberEmblem() >= AccessoryBMAttributes[i].RequiredEmblems &&
			rand() * 0.000030517578125 >= 0.75)
		{
			BlackMarketAddInventory(ChaoItemCategory_Accessory, i);
		}
	}

	RareFruit();

}
int __cdecl sub_721AD0(BlackMarketItem* a1)
{
	signed int v1; // edx
	int v2; // ecx
	int result; // eax
	BlackMarketCategoryAttribute* v4; // edx

	v1 = a1->Category;
	v2 = a1->Type;
	result = 0;
	PrintDebug("%d %d \n", a1->Category, a1->Type);
	if (v1 >= 0 && v1 < 11)
	{
		v4 = &BlackMarketCategories[v1];
		if (v4)
		{
			if (v2 >= 0 && v2 < v4->Count)
			{
				result = (int)& v4->attrib[v2];
			}
		}
	}
	return result;
}
inline NJS_POINT2 get_offset(Uint8 align, const NJS_POINT2& center)
{
	NJS_POINT2 offset = { 0,0 };

	// if we're scaling a background with fill mode, manually set
	// coordinate offset so the entire image lands in the center.

	float scale_h = HorizontalStretch;
	float scale_v = VerticalStretch;

	float scale_min = min(scale_h, scale_v);
	float scale_max = max(scale_h, scale_v);


	const auto h = static_cast<float>(HorizontalResolution);
	const auto v = static_cast<float>(VerticalResolution);

	if (h / scale_v > 640.0f)
	{
		offset.x = (h - 640.0f * scale_min) / 2.0f;
	}
	if (v / scale_h > 480.0f)
	{
		offset.y = (v - 480.0f * scale_min) / 2.0f;
	}


	return offset;
}

float HorizStretch(float X)
{
	float scale_h = HorizontalStretch;
	float scale_v = VerticalStretch;

	float scale_min = min(scale_h, scale_v);
	float scale_max = max(scale_h, scale_v);
	NJS_POINT2 point = { X, 0 };
	
	//return  X * scale_min + get_offset(0, point).x;
	if(X >= 320)
		return HorizontalStretch * 320 + (X - 320);
	else
		return HorizontalStretch * 320 - (320 - X);
}
float VertiStretch(float X)
{
	float scale_h = HorizontalStretch;
	float scale_v = VerticalStretch;

	float scale_min = min(scale_h, scale_v);
	float scale_max = max(scale_h, scale_v);
	NJS_POINT2 point = { 0, X };
	//return X * scale_min + get_offset(0, point).x;
//	if (X >= 240)
//		return VerticalStretch * 240.0f - (320 - X);
	return 
		(X - 240.0f) + (VerticalStretch * 240.0f);
}
float VertiStretch2(float X)
{
	return VerticalStretch * 240.0 - (240 - X);
}
void __cdecl Preview1(BlackMarketData* a1)
{
	//njPushMatrixEx();
	int field_AC = *(int*)((int)& a1->field_A0 + 0xC);
	float v45 = 164;
	BlackMarketItem* item = &BlackMarketInventory[field_AC];
	int index = field_AC;
	for (float v45 = 161; v45 < 321; v45 += 40)
	{
		njPushMatrixEx();
		//njUnitMatrix(0);

		switch (item->Category)
		{
		case ChaoItemCategory_Egg:
			ProjectToScreen(HorizStretch(56.0), VertiStretch(v45 + 17), -68.0);
			if (index == a1->field_9C && a1->field_A4)
			{
				njRotateY(0, a1->field_A4);
			}
			njSetTexture((NJS_TEXLIST*)& ChaoTexLists[0]);

			njScale(0, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch);
			chRareEggDrawModel((NJS_CNK_MODEL*)0x3601B7C, item->Type);
			break;
		case ChaoItemCategory_Accessory:
			ProjectToScreen(HorizStretch(56.0f), VertiStretch(v45), -52);

			if (index == a1->field_9C && a1->field_A4)
			{
				njRotateY(0, a1->field_A4);
			}
			njTranslate(0, 0.0f, -1.4f, 0.0f);

			njSetTexture(&CWE_OBJECT_TEXLIST);
			njCnkDrawObject(&object_alo_mannequin);

			njSetTexture(Accessories[item->Type].second);
			njCnkDrawObject(Accessories[item->Type].first);
			break;
		case ChaoItemCategory_Fruit:
			ProjectToScreen(HorizStretch(56.0), VertiStretch(v45), -44.0);
			if (item->Type == 20 || item->Type == 21)
			{
				njScale(0, 1, 1, 1);
			}
			else
			{
				njScale(0, 1, 1, 0.001f);
			}
			if (index == a1->field_9C && a1->field_A4)
			{
				njRotateY(0, a1->field_A4);
			}
			njSetTexture((NJS_TEXLIST*)0x033A11F0);
			//sub_42D340();

			DrawCnkModel(ChaoFruitModels_[item->Type]->chunkmodel);
			break;
		case ChaoItemCategory_Seed:
			ProjectToScreen(56.0, (v45), -22.0);

			njScale(0, 1, 1, 0.001f);

			if (index == a1->field_9C && a1->field_A4)
			{
				njRotateY(0, a1->field_A4);
			}
			njSetTexture(&AL_OBJECT_TEXLIST);
			//sub_42D340();
			//sub_42D500(((NJS_OBJECT * *)0x012E537C)[item->Type]->chunkmodel);
			break;
		case ChaoItemCategory_Hat:
			if (item->Type >= SA2BHat_NormalEggShell && item->Type < 85)
				break;

			if (item->Type == 15)
				ProjectToScreen(HorizStretch(56.0f), VertiStretch(v45), -52);//*(float*)0xC712FC);
			else
				ProjectToScreen(HorizStretch(56.0f), VertiStretch(v45), -52);
			if (index == a1->field_9C && a1->field_A4)
			{
				njRotateY(0, a1->field_A4);
			}
			switch (item->Type)
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

			if (item->Type == 15)
				njTranslate(0, 0.0f, -0.13f, 0.0f);
			else
				njTranslate(0, 0.0f, -1.4f, 0.0f);

			njSetTexture(&ChaoTexLists[0]);

			if (item->Type >= 85)
			{
				PrintDebug("UNIMPLEMENTED");
				//njSetTexture(MaskObjObjectList[item->Type - 85].second);
				//njCnkDrawObject(MaskObjObjectList[item->Type - 85].first);
			}
			else
			{
				njSetZCompare(3u);
				njCnkDrawObject(ChaoItemModels_[item->Type]);
				npSetZCompare();
				//njPopMatrixEx();
			}
			break;

		default:
			break;
		}
		item = &BlackMarketInventory[++index];
		njPopMatrixEx();
	}


}
void __cdecl Preview2(BlackMarketData* a1)
{
	njPushMatrixEx();

	//njUnitMatrix(0);
	int type = *(char*)((int)a1 + 0x5D);
	float field_90 = *(float*)((int)a1 + 0x9C);
	switch (*(char*)((int)a1 + 0x5C))
	{
	case ChaoItemCategory_Accessory:
		ProjectToScreen(HorizStretch(390.0f), VertiStretch2(212.0f), -26.0f / field_90);
		if (a1->field_88)
		{
			njRotateX(0, a1->field_88);
		}
		if (a1->field_8C)
		{
			njRotateY(0, a1->field_8C);
		}
		njTranslate(0, 0.0, -1.4, 0.0);

		njSetTexture(&CWE_OBJECT_TEXLIST);
		njCnkDrawObject(&object_alo_mannequin);

		njSetTexture(Accessories[type].second);
		njCnkDrawObject(Accessories[type].first);

		break;
	case ChaoItemCategory_Egg:
		ProjectToScreen(HorizStretch(390.0), VertiStretch2(212.0), -34.0 / field_90);
		njScale(0, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch);
		if (a1->field_88)
		{
			njRotateX(0, a1->field_88);
		}
		if (a1->field_8C)
		{
			njRotateY(0, a1->field_8C);
		}
		njTranslate(0, 0.0, -2.8, 0.0);
		njSetTexture(ChaoTexLists);
		chRareEggDrawModel((NJS_CNK_MODEL*)0x3601B7C, type);
		break;
	case 2:
		ProjectToScreen(HorizStretch(390.0), VertiStretch2(212.0), -26.0 / field_90);
		njScale(0, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch);
		if (a1->field_88)
		{
			njRotateX(0, a1->field_88);
		}
		if (a1->field_8C)
		{
			njRotateY(0, a1->field_8C);
		}

		{
			njScale(0, 1.2, 1.2, 1.2);
			njSetTexture((NJS_TEXLIST*)0x171A294);
			njCnkDrawObject(((NJS_OBJECT * *)0x0171A294)[type]);
			DataArray(NJS_OBJECT*, AnimalModels, 0x03608A90, 20);
			DataArray(NJS_MOTION*, off_3619AD4, 0x3619AD4, 20);
			njSetTexture(AnimalTexLists[type]);
			njAction_QueueObject(AnimalModels[type], off_3619AD4[type], *(float*)((int)a1 + 160));
		}


		break;
	case ChaoItemCategory_Fruit:
		ProjectToScreen(HorizStretch(390.0), VertiStretch2(212.0), -22.0 / field_90);
		njScale(0, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch);
		if (a1->field_88)
		{
			njRotateX(0, a1->field_88);
		}
		if (a1->field_8C)
		{
			njRotateY(0, a1->field_8C);
		}
		njTranslate(0, 0.0, -0.4f, 0.0);
		//njSetTexture(FruitObjects[type].first);
		//DrawCnkModel(FruitObjects[type].second->chunkmodel);
		njSetTexture(&AL_OBJECT_TEXLIST);
		njCnkDrawObject(ChaoFruitModels_[type]);
		break;
	case ChaoItemCategory_Seed:
		ProjectToScreen(HorizStretch(390.0), VertiStretch(212.0), -11.0 / field_90);
		njScale(0, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch, 1.0 / HorizontalStretch);
		if (a1->field_88)
		{
			njRotateX(0, a1->field_88);
		}
		if (a1->field_8C)
		{
			njRotateY(0, a1->field_8C);
		}
		njTranslate(0, 0.0, -0.8f, 0.0);
		njSetTexture(&AL_OBJECT_TEXLIST);
		//DrawCnkModel(((NJS_OBJECT * *)0x012E537C)[type]->chunkmodel);
		break;
	case ChaoItemCategory_Hat:
		if (type >= 16 && type <= 84)
		{
			ProjectToScreen(390.0f, 212.0f, -26.0f / field_90);
			if (a1->field_88)
			{
				njRotateX(0, a1->field_88);
			}
			if (a1->field_8C)
			{
				njRotateY(0, a1->field_8C);
			}
			njTranslate(0, 0.0f, -1.4f, 0.0f);
			njSetTexture(&ChaoTexLists[0]);
			chRareEggDrawModel((NJS_CNK_MODEL*)0x35E29FC, type - 16);
		}
		else
		{
			if (type == 15)
				ProjectToScreen(390.0f, 212.0f, -13.0f / field_90);
			else
				ProjectToScreen(390.0f, 212.0f, -26.0f / field_90);

			if (a1->field_88)
			{
				njRotateX(0, a1->field_88);
			}
			if (a1->field_8C)
			{
				njRotateY(0, a1->field_8C);
			}
			switch (type)
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

			if (type == 15)
				njTranslate(0, 0.0, -0.15, 0.0);
			else
				njTranslate(0, 0.0, -1.4, 0.0);


			if (type >= 85)
			{
				if (!HideHatVec[type - 85])
				{
					njSetTexture(&CWE_OBJECT_TEXLIST);
					njCnkDrawObject(&object_alo_mannequin);
				}
			}

			njSetTexture(&ChaoTexLists[0]);

			if (type >= 85)
			{
				//njSetTexture(MaskObjObjectList[type - 85].second);
				//njCnkDrawObject(MaskObjObjectList[type - 85].first);
			}
			else
				njCnkDrawObject(ChaoItemModels_[type]);
		}
		break;

	default:
		break;
	}

	//njPopMatrixEx();

	//DoLighting(LightIndexBackupMaybe);
}
const int JumpBackHere = 0x007277ED;
int backupesi;
int backupedi;
void __declspec(naked) Preview1Hook()
{

	_asm
	{
		mov backupesi, esi
		push esi
		call Preview1
		add esp, 4
		mov esi, backupesi
		jmp JumpBackHere
	}
}
const int JumpBackHere_ = 0x007264DF;
void __declspec(naked) Preview2Hook()
{
	_asm
	{
		mov backupedi, edi
		push edi
		call Preview2
		add esp, 4
		mov edi, backupedi
		jmp JumpBackHere_
	}
}

void al_kinder_bm_Init()
{
	for (int i = 0; i < 4; i++)
	{
		GeneralFruitMarket.push_back(GeneralFruitChances[i]);
	}
	//WriteJump((void*)0x00728A54, (void*)0x728CFD);
	//gba fruit
	for (int i = 13; i < 20; i++)
	{
		ItemChance chance = { i, 40 };
		GeneralFruitMarket.push_back(chance);

		BMFruit[i].Name = 106 + (i - 13);
		BMFruit[i].Description = 106 + (i - 13);
		BMFruit[i].PurchasePrice = 350;
		BMFruit[i].SalePrice = 75;
		BMFruit[i].RequiredEmblems = 0;
	}

	//TEMP PATCH
	//WriteData<2>((char*)0x007284BF, (char)0x90);

	WriteJump((void*)0x0726B80, FBuyListUpdate);
	//WriteJump((void*)0x721AD0, sub_721AD0); //debug
	//general fruit
	//WriteData((int*)0x00726D1E, (int)(&GeneralFruitMarket.data()->chance));
	//WriteData((int*)0x00726D29, (int)GeneralFruitMarket.data());
	//WriteData((char*)0x726D3D, (char)(GeneralFruitMarket.size() * 2));

	WriteJump((void*)0x0072731B, Preview1Hook);
	WriteJump((void*)0x00725D18, Preview2Hook);

	//accessory
	WriteJump((void*)0x717650, sub_717650);

	//purchase item hack
	WriteCall((void*)0x00727D57, ReturnDummyItem); //makes sure the game doesnt allocate any space for the object
	WriteCall((void*)0x00727D8C, PurchaseItem);
	WriteData((char*)0x00727D3B, (char)0xEB); //hacks jump
	WriteCall((void*)0x00727D1F, CanIPurchase);

	//purchased items display
	WriteCall((void*)0x0072717B, DrawPurchasedItems_Hook);

	//purchased item display in garden too
	WriteCall((void*)0x007193F2, AlItemIconTaskExecHook);

	//spit out items hack
	WriteData((int*)0x007224C2, (int)sub_548F40);
}
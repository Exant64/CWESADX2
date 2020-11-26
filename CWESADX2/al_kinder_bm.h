#pragma once
#include <vector>
#pragma pack(push, 8)
struct __declspec(align(4)) MessageFontThing
{
	signed __int16 signed0;
	__int16 gap2;
	__int16 field_4;
	__int16 field_6;
	signed __int16* psigned8;
};
#pragma pack(pop)


#pragma pack(push, 8)
struct __declspec(align(4)) MessageField0
{
	MessageFontThing* dword0;
	float float4;
	float float8;
	float xSize;
	float ySize;
	int field_14;
	float field_18;
};
#pragma pack(pop)


#pragma pack(push, 8)
struct MessageField0Array
{
	MessageField0 array[9];
};
#pragma pack(pop)

#pragma pack(push, 8)
struct __declspec(align(4)) Message380
{
	int Mode;
	Buttons ButtonPress;
	int ButtonOn;
	float floatC;
	float float10;
	float float14;
	int dword18;
};
#pragma pack(pop)


struct Message380Array
{
	Message380 array[32];
};


#pragma pack(push, 8)
struct __declspec(align(4)) KinderCoMessageThing
{
	MessageField0Array* gap0;
	Message380Array* pointerToSomething0x380;
	__int16 someKindaCount;
	__int16 wordsLeftMaybe;
	float floatC;
	float posX;
	float posY;
	float rectSizeX;
	float rectSizeY;
	float field_20;
	float field_24;
	__int16 field_28;
	char enabled;
	char field_2B;
	int ContinueDotColor;
};
#pragma pack(pop)


#pragma pack(push, 8)
struct  BlackMarketData
{
	ObjectMaster* pobjectmaster0;
	__int32 dword4;
	int char8;
	__int16 wordC;
	char gapE[2];
	__int32 MsgAlKinderBl;
	__int32 dword14;
	__int32 dword18;
	__int32 dword1C;
	__int32 dword20;
	__int32 dword24;
	__int32 dword28;
	__int32 dword2C;
	char byte30;
	char byte31;
	char byte32;
	char byte33;
	char byte34;
	char gap35[3];
	float float38;
	KinderCoMessageThing* pkindercomessagething3C;
	char byte40;
	char gap41[3];
	__int32 dword44;
	__int32* MsgAlItem;
	char byte4C;
	char byte4D;
	char byte4E;
	char byte4F;
	char gap50;
	char field_51;
	char field_52;
	char field_53;
	BlackMarketItemAttributes* SelectedItemAttr;
	KinderCoMessageThing field_58;
	int field_88;
	int field_8C;
	float field_90;
	float motionFrame;
	char field_98;
	char field_99;
	char byte9A;
	char gap9B;
	int field_9C;
	int field_A0;
	int field_A4;
	char gapA8[40];
	char byteD0;
	char byteD1;
};
#pragma pack(pop)

struct ItemChance
{
	Sint8 item;
	Sint8 chance;
};

struct BlackMarketCategoryAttribute
{
	BlackMarketItemAttributes* attrib;
	int Count;
};
DataArray(BlackMarketCategoryAttribute, BlackMarketCategories, 0x00884D38, 17);
void al_kinder_bm_Init();
extern std::vector<ItemChance> GeneralFruitMarket;
extern std::vector<ItemChance> RareFruitMarket;
extern std::vector<BlackMarketItemAttributes> FruitBMAttributesMod;
extern std::vector<BlackMarketItemAttributes> HatBMAttributesMod;
extern std::vector<BlackMarketItemAttributes> AccessoryBMAttributes;
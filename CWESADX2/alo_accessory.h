#pragma once
enum EAccessoryType : unsigned char
{
	Head = 0,
	Face,
	Chest,
	Feet,
	AccessoryTypeCount
};
extern std::vector<std::pair<NJS_OBJECT*, NJS_TEXLIST*>> Accessories;
extern std::map<int, EAccessoryType> AccessoryTypeMap;
void __cdecl sub_548F40(ObjectMaster* a2);
ObjectMaster* Accessory_Load(int ID, NJS_VECTOR* position, int rotY, NJS_VECTOR* velocity, short* savedata);
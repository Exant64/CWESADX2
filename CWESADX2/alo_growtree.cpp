#include "chao.h"
//#define TREE
#ifdef TREE
FunctionPointer(void, AL_PackageTreeSaveInfo, (ObjectMaster* a1), 0x07211E0);
al_material_object* __cdecl create_al_material(NJS_CNK_OBJECT* a1)
{
	NJS_CNK_OBJECT* v1; // esi
	int v3; // eax
	al_material_object* v4; // edi
	NJS_CNK_MODEL* v5; // ebp
	AllocatedMem* v6; // eax
	al_material_model* v7; // ebx
	char* v8; // esi
	int* chunkDetect; // eax
	signed int vertexCountMaybe; // edi
	AllocatedMem* v11; // eax
	int* v12; // ebx
	char* v13; // ebp
	int v14; // esi
	char* v15; // eax
	char v16; // cl
	int v17; // ecx
	int v18; // esi
	char* v19; // edi
	NJS_CNK_OBJECT* v20; // esi
	al_material_model* v21; // [esp+4h] [ebp-8h]
	al_material_object* v22; // [esp+8h] [ebp-4h]

	v1 = a1;
	if (!a1)
	{
		return 0;
	}
	v3 = MemoryManager->Allocate(0x3C, "..\\..\\src\\Chao\\al_material.c", 886);
	v4 = (al_material_object*)(v3 + 4);
	*(_DWORD*)v3 = 0x12345678;
	v22 = (al_material_object*)(v3 + 4);
	memset((void*)(v3 + 4), 0, 0x38u);
	if (!v4)
	{
		return 0;
	}
	memmove((char*)v4, (char*)a1, 0x38u);
	v5 = a1->chunkmodel;
	if (v5)
	{
		v6 = (AllocatedMem*)MemoryManager->Allocate(0x3C, "..\\..\\src\\Chao\\al_material.c", 898);
		v7 = (al_material_model*)& v6->Data;
		v6->Cookie = 305419896;
		v21 = (al_material_model*)& v6->Data;
		memset(&v6->Data, 0, 0x38u);
		memmove((char*)v7, (char*)a1->model, 0x18u);
		v7->model.Radius = 0.0;
		v4->object.model = &v7->model;
		v8 = (char*)v5->Vertex;
		if (v5->Vertex)
		{
			chunkDetect = v5->Vertex;
			vertexCountMaybe = 1;
			if (*(_DWORD*)v8 != 255)
			{
				do
				{
					++chunkDetect;
					++vertexCountMaybe;
				} while (*chunkDetect != 255);
			}
			
			v12 = (int*)AllocateArray(4, vertexCountMaybe);
			memmove((char*)v12, v8, 4 * vertexCountMaybe);
			v4 = v22;
			v21->model.Vertex = v12;
			v7 = v21;
		}
		v13 = (char*)v5->Poly;
		v14 = 0;
		if (v13)
		{
			v15 = v13;
			while (1)
			{
				do
				{
					while (1)
					{
						while (1)
						{
							while (1)
							{
							LABEL_12:
								while (1)
								{
									v16 = *v15;
									if ((unsigned __int8)* v15 >= 1u)
									{
										break;
									}
									++v14;
									v15 += 2;
								}
								if ((unsigned __int8)v16 >= 8u)
								{
									break;
								}
								++v14;
								v15 += 2;
							}
							if ((unsigned __int8)v16 >= 0x10u)
							{
								break;
							}
						LABEL_17:
							v14 += 2;
							v15 += 4;
						}
						if ((unsigned __int8)v16 >= 0x20u)
						{
							break;
						}
						v14 += 2;
						v15 += 4;
						switch (v16)
						{
						case 0x11:
						case 0x12:
						case 0x14:
							goto LABEL_17;
						case 0x13:
						case 0x15:
						case 0x16:
							v14 += 4;
							v15 += 8;
							break;
						case 0x17:
							v14 += 6;
							v15 += 12;
							break;
						default:
							goto LABEL_12;
						}
					}
				} while ((unsigned __int8)v16 < 0x38u || (unsigned __int8)v16 < 0x40u);
				if ((unsigned __int8)v16 >= 0xFFu)
				{
					break;
				}
				v17 = *((unsigned __int16*)v15 + 1);
				v15 += 2 * v17 + 4;
				v14 += v17 + 2;
			}
			v18 = v14 + 1;
			v19 = (char*)AllocateArray(2, v18);
			memmove(v19, v13, 2 * v18);
			v7->model.Poly = (__int16*)v19;
			v4 = v22;
		}
		else
		{
			v7->model.Poly = 0;
		}
		v1 = a1;
	}
	if (v1->child)
	{
		v4->object.child = (NJS_OBJECT*)create_al_material((NJS_CNK_OBJECT*)v1->child);
	}
	v20 = (NJS_CNK_OBJECT*)v1->sibling;
	if (v20)
	{
		v4->object.sibling = (NJS_OBJECT*)create_al_material(v20);
	}
	return v4;
}
void lerp_al_material(NJS_OBJECT* a1, NJS_OBJECT* a2, NJS_OBJECT* material, float lerpFactor)
{
	float lerp1 = lerpFactor;
	float lerp2 = 1.0 - lerpFactor;
	while (1) {
		if (material->model)
		{
			float* testfl = (float*)material->chunkmodel->vlist;
			NJS_VECTOR* matlist = (NJS_VECTOR*)(material->chunkmodel->vlist + 2);
			NJS_VECTOR* a1list = (NJS_VECTOR*)(a1->chunkmodel->vlist + 2);
			NJS_VECTOR* a2list = (NJS_VECTOR*)(a2->chunkmodel->vlist + 2);
			Sint32* test = (Sint32*)material->chunkmodel->vlist;
			testfl += 2;
			for (int i = 0; i < (material->chunkmodel->vlist[1] >> 16); i++)
			{
				testfl[0] = lerp2 * a1list->x + a2list->x * lerp1;
				testfl[1] = lerp2 * a1list->y + a2list->y * lerp1;
				testfl[2] = lerp2 * a1list->z + a2list->z * lerp1;
				a1list = (NJS_VECTOR*)((char*)a1list + 16);
				a2list = (NJS_VECTOR*)((char*)a2list + 16);
				testfl += 4;
			}
		}

		material->pos[0] = a2->pos[0] * lerp1 + lerp2 * a1->pos[0];
		material->pos[1] = a1->pos[1] * lerp2 + a2->pos[1] * lerp1;
		material->pos[2] = a1->pos[2] * lerp2 + a2->pos[2] * lerp1;
		//LerpChaoRotation((int)a1->ang, (int)a2->ang, (int)material->ang, lerpFactor);
		material->ang[0] = ((float)a2->ang[0] * lerp1) + ((float)a1->ang[0] * lerp2);
		material->ang[1] = ((float)a1->ang[1] * lerp2) + ((float)a2->ang[1] * lerp1);
		material->ang[2] = ((float)a1->ang[2] * lerp2) + ((float)a2->ang[2] * lerp1);

		if (material->child)
			lerp_al_material(a1->child, a2->child, material->child, lerpFactor);
		if (!material->sibling)
			break;
		material = material->sibling;
		a1 = a1->sibling;
		a2 = a2->sibling;
	}
}

enum 
{
	MD_PLANT = 0x0,
	MD_SEED = 0x1,
	MD_SEED_TO_SAPLING = 0x2,
	MD_SEED_TO_SAPLING2 = 0x3,
	MD_SAPLING = 0x4,
	MD_SAPLING_GROW = 0x5,
	MD_SAPLING_GROW2 = 0x6,
	MD_ADULT = 0x7,
	MD_DEAD = 0x8,
	MD_DEAD2 = 0x9,
	MD_FADEOUT = 0xA,
};

enum CI_KIND_AL
{
	CI_KIND_AL_CHAO = 0x81,
	CI_KIND_AL_CHAO_FIELD = 0x82,
	CI_KIND_AL_FRUIT = 0x83,
	CI_KIND_AL_FRUIT_FIELD = 0x84,
	CI_KIND_AL_SEED = 0x85,
	CI_KIND_AL_SEED_FIELD = 0x86,
	CI_KIND_AL_MINIMAL = 0x87,
	CI_KIND_AL_MINIMAL_FIELD = 0x88,
	CI_KIND_AL_TREE = 0x89,
	CI_KIND_AL_TREE_FIELD = 0x8A,
	CI_KIND_AL_TOY = 0x8B,
	CI_KIND_AL_TOY_FIELD = 0x8C,
	CI_KIND_AL_EGG = 0x8D,
	CI_KIND_AL_EGG_FIELD = 0x8E,
	CI_KIND_AL_TRASH = 0x8F,
	CI_KIND_AL_TRASH_FIELD = 0x90,
	CI_KIND_AL_DAKKO_FIELD = 0x91,
	CI_KIND_AL_NADE_FIELD = 0x92,
	CI_KIND_AL_OBAKE_HEAD = 0x93,
	CI_KIND_AL_CDR = 0x94,
	CI_KIND_AL_PUNCH = 0x95,
	CI_KIND_AL_SHADOW = 0x96,
	CI_KIND_AL_ONARA = 0x97,
	CI_KIND_AL_SOUND = 0x98,
	CI_KIND_AL_HELLO = 0x99,
	CI_KIND_AL_TOBIKOMI = 0x9A,
	CI_KIND_AL_REQUEST_WATER = 0x9B,
	CI_KIND_AL_NOISE = 0x9C,
	CI_KIND_AL_CONTACT = 0x9D,
	CI_KIND_AL_ACTION = 0x9E,
	CI_KIND_AL_SONG = 0x9F,
	CI_KIND_AL_BALL = 0xA0,
	CI_KIND_AL_FIRE = 0xA1,
	CI_KIND_AL_BIKKURI = 0xA2,
	CI_KIND_AL_BOX = 0xA3,
	CI_KIND_AL_WALL = 0xA4,
	CI_KIND_AL_RANDOM_MUSIC = 0xA5,
	CI_KIND_AL_DANCE = 0xA6,
	CI_KIND_AL_SING = 0xA7,
	CI_KIND_AL_SING_ONCHI = 0xA8,
	CI_KIND_AL_RAKUGAKI = 0xA9,
	CI_KIND_AL_FINISH = 0xAA,
	CI_KIND_AL_NEST = 0xAB,
	CI_KIND_AL_PLANT_POS = 0xAC,
	CI_KIND_AL_WATER = 0xAD,
	CI_KIND_AL_THIRSTY = 0xAE,
	CI_KIND_AL_TOUCH = 0xAF,
	CI_KIND_AL_SWITCH = 0xB0,
	CI_KIND_AL_CHANGE = 0xB1,
	CI_KIND_AL_SET_RACE_TREE = 0xB2,
	CI_KIND_AL_SET_RACE_GLIDE = 0xB3,
	CI_KIND_AL_SET_RACE_JUMP = 0xB4,
	CI_KIND_AL_SET_RACE_LAKE = 0xB5,
	CI_KIND_AL_SET_RACE_KARIMONO = 0xB6,
	CI_KIND_AL_SET_RACE_KOWAI = 0xB7,
	CI_KIND_AL_SET_RACE_GOAL = 0xB8,
	CI_KIND_AL_SET_RACE_ENABLE_TURN = 0xB9,
	CI_KIND_AL_SET_RACE_ALONG_LANE = 0xBA,
	CI_KIND_AL_SET_RACE_REMEMBER_POS = 0xBB,
	CI_KIND_AL_SET_RACE_THINK_POS = 0xBC,
	CI_KIND_AL_SET_RACE_PARALLEL = 0xBD,
	CI_KIND_AL_SET_RACE_GOAL_BANZAI = 0xBE,
	CI_KIND_AL_SET_RACE_PATHCOLLI = 0xBF,
	CI_KIND_AL_SET_RACE_POLYCOLLI = 0xC0,
	CI_KIND_AL_SET_RACE_EACHCOLLI = 0xC1,
	CI_KIND_AL_LOG = 0xC2,
	CI_KIND_AL_ROCK = 0xC3,
	CI_KIND_AL_HOLL = 0xC4,
	CI_KIND_AL_KANI = 0xC5,
	CI_KIND_AL_ANSWER_POS = 0xC6,
	CI_KIND_AL_ANSWER_OBJ = 0xC7,
	CI_KIND_AL_GOOD = 0xC8,
	CI_KIND_AL_TV = 0xC9,
	CI_KIND_AL_RADICASE = 0xCA,
	CI_KIND_AL_CLIMB = 0xCB,
	CI_KIND_AL_FURIMUKI = 0xCC,
	CI_KIND_AL_STAGE_CHANGER = 0xCD,
	CI_KIND_END = 0xFF,
};

enum
{
	CI_TREE_FOR = 0x0,
	CI_TREE_LMO = 0x1,
	CI_TREE_SHADOW = 0x2,
	CI_TREE_PLANT = 0x3,
	CI_TREE_SENSOR = 0x4,
	CI_TREE_THIRSTY = 0x5,
	CI_TREE_SAPLING = 0x6,
	CI_TREE_SPHERE = 0x7,
	CI_TREE_SAPLING_SPHERE = 0x8,
};


struct FRUIT_INFO
{
	float growth;
	float AimGrowth;
	int SwingCounter;
	NJS_POINT3 pos;
	int angx;
	int angy;
};

#pragma pack(push, 8)
struct __declspec(align(4)) ALO_GrowTreeExecutor_Data
{
	EntityData1 entityData;
	char kind;
	char state;
	__int16 field_32;
	float growth;
	int life;
	int water;
	int pos_num;
	FRUIT_INFO fruit[3];
	float scale;
	float ScaleSpd;
	int ThirstyFlag;
	int WaterFlag;
	int LeafRotAng;
	float LeafWidth;
	int LeafDispNum;
	int FruitRotAng;
	float FruitWidth;
	int FruitDispNum;
	int SwingFlag;
	int SwingCountFlag;
	float SwingDist;
	int RollAngle;
	int TouchAngle;
	int ChaoSwingPhase;
	int RollPhase;
	int garden;
	void* pMySaveInfo;
	NJS_TEXLIST* texlist;
	NJS_OBJECT* pLocalObject;
	NJS_OBJECT* pShadowObject;
	NJS_OBJECT* pCopyObject;
};
#pragma pack(pop)
int sub_546340(ObjectMaster* a1)
{
	ALO_GrowTreeExecutor_Data* v1; // esi
	int v2; // ecx

	int result; // eax
	int v12; // edx

	v1 = (ALO_GrowTreeExecutor_Data*)a1->Data1;
	v1->growth = 1.0;
	v1->state = 3;
	v1->fruit[0].growth = (double)rand() * 0.000030517578125 * -0.300000011920929;
	v1->fruit[1].growth = (double)rand() * 0.000030517578125 * -0.300000011920929;
	v1->fruit[2].growth = (double)rand() * 0.000030517578125 * -0.300000011920929;
	v1->fruit[0].SwingCounter = (unsigned __int16)(11
		- (signed int)((double)rand() * 0.000030517578125 * -13.99999904632568));
	v1->fruit[1].SwingCounter = (unsigned __int16)(11
		- (signed int)((double)rand() * 0.000030517578125 * -13.99999904632568));
	v2 = (unsigned __int16)(11 - (signed int)((double)rand() * 0.000030517578125 * -13.99999904632568));
	v1->fruit[2].SwingCounter = (unsigned __int16)v2;
	for (int i = 0; i < 9; i++)
	{
		CCL_Disable(a1->Data1, i);
	}
	CCL_Enable(a1->Data1, 0);
	CCL_Enable(a1->Data1, CI_TREE_LMO);
	CCL_Enable(a1->Data1, CI_TREE_SHADOW);
	CCL_Enable(a1->Data1, CI_TREE_SPHERE);
	if (a1->Data2)
	{
		//sub_47D9E0(a1->Data1.Undefined, 13);
	}
	result = 0;
	v1->entityData.Action = MD_ADULT;
	v1->entityData.NextAction = 0;
	v1->entityData.InvulnerableTime = 0;
	v1->entityData.Index = 0;
	v12 = (unsigned __int8)(v1->kind - 1) != 0 ? 6000 : 15000;
	v1->ThirstyFlag = 0;
	v1->life = v12;
	return result;
}
void sub_546300(ALO_GrowTreeExecutor_Data* a1)
{
	a1->pCopyObject = (NJS_OBJECT*)create_al_material(off_132913C[3 * (unsigned __int8)a1->kind]);
}
void __cdecl ALO_GrowTreeExecutor_Main(ObjectMaster* a1)
{
	ObjectMaster* v1; // edi
	ALO_GrowTreeExecutor_Data* v2; // ebx
	al_entry_work* v3; // ecx
	__int16 v4; // ax
	unsigned __int16 v5; // ax
	__int16 v6; // ax
	float v7; // ST30_4
	__int16 v8; // ax
	unsigned __int16 v9; // ax
	int v10; // eax
	double v11; // st7
	__int16 v12; // ax
	int v13; // edx
	NJS_OBJECT* v14; // edx
	int v15; // eax
	float v16; // ST30_4
	__int16 v17; // ax
	unsigned __int16 v18; // ax
	int v19; // eax
	int v20; // eax
	//UnknownData2* v21; // edi
	float v22; // ST30_4
	double v23; // st7
	double v24; // st6
	double v25; // st5
	FRUIT_INFO* v26; // esi
	double v27; // rt1
	double v28; // st5
	double v29; // st7
	float v30; // ST24_4
	float v31; // ST24_4
	float v32; // ST24_4
	signed int v33; // edi
	float v34; // ST34_4
	double v35; // ST34_8
	double v36; // ST34_8
	DWORD* v37; // eax
	ChaoData* lerpFactor; // ST10_4
	Angle v39; // ST08_4
	ChaoData* v40; // ST10_4
	Angle v41; // ST08_4
	ChaoData* v42; // ST10_4
	Angle v43; // ST08_4
	ChaoData* v44; // ST10_4
	Angle v45; // ST08_4
	_BOOL1 v46; // sf
	unsigned __int8 v47; // of
	float v48; // ST34_4
	double v49; // st6
	float v50; // ST34_4
	double v51; // st7
	float v52; // ST34_4
	__int16 v53; // ax
	float v54; // ST34_4
	signed int v55; // ecx
	
	CollisionInfo* v57; // eax
	float v58; // [esp+18h] [ebp-2Ch]
	ALO_GrowTreeExecutor_Data* a3; // [esp+1Ch] [ebp-28h]
	int a3a; // [esp+1Ch] [ebp-28h]
	FRUIT_INFO* v61; // [esp+20h] [ebp-24h]
	NJS_VECTOR a4; // [esp+2Ch] [ebp-18h]
	NJS_VECTOR position; // [esp+38h] [ebp-Ch]

	v1 = a1;
	v2 = (ALO_GrowTreeExecutor_Data*)a1->Data1;
	a3 = (ALO_GrowTreeExecutor_Data*)a1->Data1;
	switch (v2->entityData.Action)
	{
	case 0:
		if (ALW_RecieveCommand(a1) == 5)
		{
			v3 = (al_entry_work*)a1->UnknownA_ptr;
			v4 = -1;
			if (v3)
			{
				v4 = v3->command_value;
				v3->command_value = -1;
			}
			v2->kind = v4 + 1;
			CCL_Disable(a1->Data1, CI_TREE_PLANT);
			CCL_Enable(a1->Data1, CI_TREE_SENSOR);
			CCL_Enable(a1->Data1, CI_TREE_THIRSTY);
			v2->ThirstyFlag = 0;
			v2->water = 0;
			v2->entityData.Action = MD_SEED;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
			v2->state = 1;
		}
		goto LABEL_121;
	case 1:
		if (ALOField_Find(a1, CI_TREE_SENSOR, CI_KIND_AL_WATER))
		{
			v2->water = 10000;
		}
		v5 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v5 + 1;
		if (v5 >= ChaoGlobal.SeedClock)
		{
			v2->entityData.InvulnerableTime = 0;
			v2->water += 100;
		}
		if (v2->water >= 10000)
		{
			v2->water = 6000;
			CCL_Disable(a1->Data1, CI_TREE_SENSOR);
			v2->entityData.Action = MD_SEED_TO_SAPLING;
			v2->entityData.NextAction = 0;
			v2->state = 2;
		}
		goto LABEL_121;
	case 2:
		v6 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v6 + 1;
		if ((unsigned __int16)v6 > 180u)
		{
			sub_546300(v2);
			CCL_Enable(a1->Data1, CI_TREE_SAPLING);
			v2->scale = 0.0099999998;
			v2->ScaleSpd = 0.0;
			v2->entityData.Action = MD_SEED_TO_SAPLING2;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
		}
		goto LABEL_121;
	case 3:
		v7 = (1.0 - v2->scale) * 0.1500000059604645 + v2->ScaleSpd;
		v2->ScaleSpd = v7;
		v2->scale = v7 + v2->scale;
		v2->ScaleSpd = v2->ScaleSpd * 0.8500000238418579;
		v8 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v8 + 1;
		if ((unsigned __int16)v8 > 200u)
		{
			v2->scale = 1.0;
			v2->water = 10000;
			v2->ThirstyFlag = 0;
			v2->entityData.Action = MD_SAPLING;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
		}
		goto LABEL_121;
	case 4:
		if (ALOField_Find(a1, 4, CI_KIND_AL_WATER))
		{
			v2->water = 10000;
			CCL_Disable(a1->Data1, CI_TREE_SENSOR);
			CCL_Disable(a1->Data1, CI_TREE_THIRSTY);
			v2->entityData.Action = MD_SAPLING_GROW;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
		}
		v9 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v9 + 1;
		if (v9 > ChaoGlobal.SaplingClock)
		{
			v2->water -= ChaoGlobal.WaterSub;
			v2->entityData.InvulnerableTime = 0;
		}
		v10 = v2->water;
		v11 = v2->growth;
		if (v10 <= 5000)
		{
			v2->growth = v11 + 0.0000199999994947575;
			if (v10 < 0)
			{
				v2->water = 0;
			}
		}
		else
		{
			v2->growth = v11 + 0.00004999999873689376;
		}
		if (v2->water < 6000 && !v2->ThirstyFlag)
		{
			v2->ThirstyFlag = 1;
			CCL_Enable(a1->Data1, CI_TREE_SENSOR);
			CCL_Enable(a1->Data1, CI_TREE_THIRSTY);
		}
		lerp_al_material(
			off_132913C[3 * (unsigned __int8)v2->kind],
			off_132913C[3 * (unsigned __int8)v2->kind + 1],
			(al_material_object*)v2->pCopyObject,
			v2->growth);
		if (v2->growth >= 1.0)
		{
			sub_546340(a1);
		}
		goto LABEL_121;
	case 5:
		v12 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v12 + 1;
		if ((unsigned __int16)v12 > 180u)
		{
			v2->ScaleSpd = 0.0;
			v2->entityData.Action = MD_SAPLING_GROW2;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
			//if (CurrentChaoArea == NextChaoArea)
			{
				//SE_CallV2(4116, &a1->Data1.Undefined->Position, 0, 0, 0);
				v1 = a1;
			}
		}
		goto LABEL_121;
	case 6:
		v14 = v2->pCopyObject;
		v15 = 3 * (unsigned __int8)v2->kind;
		v16 = (1.0 - v2->growth) * 0.1500000059604645 + v2->ScaleSpd;
		v2->ScaleSpd = v16;
		v2->growth = v16 + v2->growth;
		v2->ScaleSpd = v2->ScaleSpd * 0.8500000238418579;
		lerp_al_material(off_132913C[v15], off_132913C[v15 + 1], (al_material_object*)v14, v2->growth);
		v17 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v17 + 1;
		if ((unsigned __int16)v17 > 200u)
		{
			sub_546340(a1);
		}
		goto LABEL_121;
	case 7:
		v2->WaterFlag = 0;
		if (ALOField_Find(a1, CI_TREE_SENSOR, CI_KIND_AL_WATER))
		{
			v2->water = 10000;
			CCL_Disable(a1->Data1, CI_TREE_SENSOR);
			CCL_Disable(a1->Data1, CI_TREE_THIRSTY);
			v2->ThirstyFlag = 0;
			v2->WaterFlag = 1;
		}
		v18 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v18 + 1;
		if (v18 > ChaoGlobal.TreeClock)
		{
			v19 = v2->water;
			if (v19 <= 5000)
			{
				if (v19 <= 2000)
				{
					v2->life -= 3;
				}
				else
				{
					v2->life -= 2;
				}
			}
			else
			{
				--v2->life;
			}
			v20 = v19 - (unsigned __int16)ChaoGlobal.WaterSub;
			v2->water = v20;
			if (v20 < 0)
			{
				v2->water = 0;
			}
			if (v2->state == 3 && v2->life <= 0)
			{
				v2->state = 0;
				v2->entityData.Action = MD_DEAD;
				v2->entityData.NextAction = 0;
				v2->entityData.InvulnerableTime = 0;
				v2->entityData.Index = 0;
				v2->life = 0;
			}
			if (v2->water < 6000 && !v2->ThirstyFlag)
			{
				v2->ThirstyFlag = 1;
				CCL_Enable(a1->Data1, CI_TREE_SENSOR);
				CCL_Enable(a1->Data1, CI_TREE_THIRSTY);
			}
			v2->entityData.InvulnerableTime = 0;
		}
		v58 = njScalor(&a1->EntityData2->speed);
		v2->SwingDist = v58;
		if (v58 < 0.0099999998)
		{
			v2->ChaoSwingPhase = sub_446960(0, 1024, v2->ChaoSwingPhase);
		}
		v21 = a1->EntityData2;
		v2->RollAngle = (signed int)(v58 * 6.0 * 182.0444488525391);
		v22 = atan2f(v21->speed.x, v21->speed.z);
		v2->TouchAngle = 0x4000 - (signed int)(v22 * 10430.38043493439);
		v23 = 0.0;
		v21->speed.x = 0.0;
		v21->speed.y = 0.0;
		v21->speed.z = 0.0;
		v2->SwingCountFlag = 0;
		if (v58 < 0.1000000014901161 && v2->SwingFlag)
		{
			//if (CurrentChaoArea == NextChaoArea)
			{
			//	SE_CallV2_TIMER((EntityData1*)a1, 4104, &v2->entityData.Position, 1, -15, 60);
				v2 = a3;
			}
			v2->SwingFlag = 0;
			v2->SwingCountFlag = 1;
			v23 = 0.0;
		}
		if (v58 > 0.949999988079071 && !v2->SwingFlag)
		{
			v2->SwingFlag = 1;
			v2->SwingCountFlag = 1;
		}
		v24 = 1.0;
		v25 = 2.0;
		a3a = 0;
		v61 = v2->fruit;
		v26 = v2->fruit;
		break;
	case 8:
		v52 = v2->growth + 0.009999999776482582;
		v2->growth = v52;
		if (v52 > 1.0)
		{
			v2->growth = 1.0;
			v2->entityData.Action = 9;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
		}
		lerp_al_material(
			off_132913C[3 * (unsigned __int8)v2->kind + 1],
			off_132913C[3 * (unsigned __int8)v2->kind + 2],
			(al_material_object*)v2->pCopyObject,
			v2->growth);
		goto LABEL_121;
	case 9:
		v53 = v2->entityData.InvulnerableTime;
		v2->entityData.InvulnerableTime = v53 + 1;
		if ((unsigned __int16)v53 > 18000u)
		{
			v2->entityData.Action = 10;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
			v2->scale = 1.0;
		}
		goto LABEL_121;
	case 10:
		v54 = v2->scale - 0.009999999776482582;
		v2->scale = v54;
		if (v54 < 0.0)
		{
			v2->scale = 0.0;
			for (int i = 0; i < 9; i++)
				CCL_Disable(a1->Data1, i);
			CCL_Enable(a1->Data1, CI_TREE_PLANT);
			v2->entityData.Action = 0;
			v2->entityData.NextAction = 0;
			v2->entityData.InvulnerableTime = 0;
			v2->entityData.Index = 0;
			tree_delete_al_material(v2);
		}
		goto LABEL_121;
	default:
		goto LABEL_121;
	}
	while (1)
	{
		v27 = v25;
		v28 = v23;
		v29 = v27;
		if (v28 > v26->growth)
		{
			if (dword_1DC0F8C < (unsigned __int16)word_1312D68 && sub_52F4F0(3) < 40)
			{
				v26->growth = ChaoGlobal.TreeFruitAddGrowth + v26->growth;
			}
		}
		else
		{
			v30 = ChaoGlobal.TreeFruitAddGrowth + v26->growth;
			v26->growth = v30;
			if (v30 > v29)
			{
				v26->growth = v29;
			}
			if (v26->growth > (double)v26->AimGrowth)
			{
				v26->AimGrowth = v26->growth;
			}
			if (v2->WaterFlag)
			{
				if (v24 > v26->AimGrowth)
				{
					v31 = v26->AimGrowth + 0.6000000238418579;
					v26->AimGrowth = v31;
					if (v31 > v24)
					{
						v26->AimGrowth = v24;
					}
				}
			}
			if (v26->AimGrowth > (double)v26->growth)
			{
				v32 = v26->growth + 0.07999999821186066;
				v26->growth = v32;
				if (v32 > v29)
				{
					v26->growth = v29;
				}
			}
			if (dword_1A26C10)
			{
				++dword_1AED214;
			}
			else
			{
				++dword_1AED218;
			}
		}
		if (v26->growth > 0.8999999761581421)
		{
			v33 = 0;
			if (v2->SwingCountFlag)
			{
				if (--v26->SwingCounter <= 0)
				{
					v33 = 1;
				}
			}
			if (v26->growth > 1.899999976158142 && (unsigned __int16)v2->entityData.InvulnerableTime % 10 == 1)
			{
				if ((double)rand() * 0.000030517578125 < 0.002000000094994903)
				{
				LABEL_90:
					v26->SwingCounter = (unsigned __int16)(11
						- (signed int)((double)rand()
							* 0.000030517578125
							* -13.99999904632568));
					v34 = (double)rand() * 0.000030517578125 * -0.300000011920929;
					v26->growth = v34;
					v26->AimGrowth = v34;
					v35 = (0.5 - (double)rand() * 0.000030517578125) * 0.009999999776482582;
					a4.x = njSin(v2->TouchAngle) * 0.02999999932944775 + v35;
					a4.y = 0.0;
					v36 = (0.5 - (double)rand() * 0.000030517578125) * 0.009999999776482582;
					a4.z = njCos(v2->TouchAngle) * 0.02999999932944775 + v36;
					if ((double)rand() * 0.000030517578125 < 0.5)
					{
						a4.x = a4.x * -1.0;
						a4.z = -1.0 * a4.z;
					}
					sub_546670(&position, v2, a3a);
					v37 = sub_52F9E0(3);
					if (v2->state == 5)
					{
						switch (v2->garden)
						{
						case 1:
							v42 = (ChaoData*)v37;
							v43 = (signed int)((double)rand() * 0.000030517578125 * 360.0 * 0.0054931640625);
							ALO_FruitExecutor_Load(0, &position, v43, &a4, v42);
							break;
						case 2:
							v40 = (ChaoData*)v37;
							v41 = (signed int)((double)rand() * 0.000030517578125 * 360.0 * 0.0054931640625);
							ALO_FruitExecutor_Load(1, &position, v41, &a4, v40);
							break;
						case 3:
							lerpFactor = (ChaoData*)v37;
							v39 = (signed int)((double)rand() * 0.000030517578125 * 360.0 * 0.0054931640625);
							ALO_FruitExecutor_Load(2, &position, v39, &a4, lerpFactor);
							break;
						}
					}
					else
					{
						v44 = (ChaoData*)v37;
						v45 = (signed int)((double)rand() * 0.000030517578125 * 360.0 * 0.0054931640625);
						ALO_FruitExecutor_Load((unsigned __int8)v2->kind + 2, &position, v45, &a4, v44);
					}
					//if (CurrentChaoArea == NextChaoArea)
					{
						//SE_CallV2(4105, &a1->Data1.Undefined->Position, 0, 0, 0);
						v26 = v61;
					}
					v29 = 2.0;
					goto LABEL_103;
				}
				v29 = 2.0;
			}
			if (!v33)
			{
				goto LABEL_103;
			}
			goto LABEL_90;
		}
	LABEL_103:
		++v26;
		v47 = __OFSUB__(a3a + 1, 3);
		v46 = a3a++ - 2 < 0;
		v61 = v26;
		if (!((unsigned __int8)v46 ^ v47))
		{
			break;
		}
		v24 = 1.0;
		v25 = v29;
		v23 = 0.0;
	}
	v48 = 0.8999999761581421 * v58 + v2->FruitWidth;
	v2->FruitWidth = v48;
	if (v48 > 14.0)
	{
		v2->FruitWidth = 14.0f;
	}
	v49 = v2->FruitWidth;
	v2->FruitRotAng += 1824;
	v2->FruitWidth = v49 * 0.9800000190734863;
	v50 = v58 * 0.300000011920929 + v2->LeafWidth;
	v2->LeafWidth = v50;
	if (v50 > 6.0)
	{
		v2->LeafWidth = 6.0;
	}
	v51 = v2->LeafWidth;
	v2->LeafRotAng += 1536;
	v1 = a1;
	v2->LeafWidth = v51 * 0.9860000014305115;
LABEL_121:
	AL_PackageTreeSaveInfo(a1); 
	Chao_AddToCollisionList(v1);
}
#endif
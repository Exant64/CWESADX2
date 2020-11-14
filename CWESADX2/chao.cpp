
#include "chao.h"
#include <cstdlib>
#include "data/toy/alo_eda.nja"
//#include "albhv/albhv_hanabi.h"
//#include "albhv/albhv_piano.h"
//#include "albhv/albhv_console.h"
//#include "albhv/albhv_float.h"
//#include "albhv/albhv_fishing.h"
//#include "albhv/albhv_ball.h"
#include "al_knowledge.h"

FunctionPointer(void, SetChunkColor, (int a1), 0x0078A320);
FunctionPointer(void, ApplyWSwitch, (int a1), 0x00717470);

const int AL_DecideAimSwimPositionptr = 0x0073B840;
void AL_DecideAimSwimPosition(ObjectMaster* a1)
{
	__asm
	{
		mov eax, a1
		call AL_DecideAimSwimPositionptr
	}
}

static const void* const SwimControlPtr = (void*)0x73BB40;
void SwimControl(ObjectMaster* a1)
{
	__asm {
		mov esi, [a1]
		call SwimControlPtr
	}
}
void CryingParticle_Load(NJS_VECTOR* vel, NJS_VECTOR* pos, float scale);
signed int __cdecl Tantrum(ObjectMaster* a1)
{
	ObjectMaster* v1; // edi
	chaowk* v2; // esi
	int v3; // eax
	float v6; // ST2C_4
	//Data1Ptr v8; // esi
	v1 = a1;
	v2 = (chaowk*)a1->Data1;
	v3 = v2->Behavior.Mode;
	if (v3)
	{
		if (v3 == 1)
		{
			v2->Behavior.Timer--;
			if (v2->Behavior.Timer <= 0)
			{
				v6 = (10000 - AL_EmotionGetValue(a1, (EMOTION_ENUM)0xAu)) * 0.000099999997;

				AL_SetIntervalTimer(v1, 0xEu, ((rand() * 0.000030517578f + v6) * 10800 * 0.5f + 1200));
				return 1;
			}
		}
	}
	else
	{
		AL_FaceSetEye(a1, 1, -1);
		AL_FaceSetMouth(a1, 6, -1);
		AL_SetMotionLinkStep(a1, 479, 0x14u);
		++v2->Behavior.Mode;
		v2->Behavior.Timer = (240 - (rand() * 0.000030517578f * -201.0f));
	}
	bool test = ((v2->Behavior.Timer % 8) < 4);
	if (test)
	{
		AL_SHAPE* v8 = &v2->Shape;
		float v9 = v8->LeftEyePos.y;
		NJS_VECTOR a3, v17;
		float v10 = v8->LeftEyePos.x;
		a3.y = v9;
		float v11 = v8->LeftEyePos.z;
		a3.x = v10;
		a3.y = v9 - 0.2f;
		float v12 = v8->LeftEyeVec.x;
		a3.z = v11;
		v17.x = v12 * 0.1f;
		v17.y = v8->LeftEyeVec.y * 0.1f + 0.1f;
		v17.z = 0.1f * v8->LeftEyeVec.z;

		CryingParticle_Load(&v17, &a3, 0.1);
		float v13 = v8->RightEyePos.x;
		a3.y = v8->RightEyePos.y;
		float v14 = v8->RightEyePos.z;
		a3.x = v13;
		a3.y = a3.y - 0.2f;
		float v15 = v8->RightEyeVec.x;
		a3.z = v14;
		v17.x = v15 * 0.1f;
		v17.y = v8->RightEyeVec.y * 0.1f + 0.1f;
		v17.z = 0.1f * v8->RightEyeVec.z;
		CryingParticle_Load(&v17, &a3, 0.1);
	}
	
	if (!(v2->Behavior.Timer % 60) && rand() * 0.000030517578125 < 0.5)
	{
		QueueSound_XYZ(1002, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z, 200);
	}
	return 0;
}
signed int __cdecl ALBHV_Cry_(ObjectMaster* a1)
{
	ObjectMaster* v1; // esi
	chaowk* v2; // edi
	int v3; // eax
	AL_BEHAVIOR* v4; // edi
	int v5; // eax
	double v6; // st7
	int v7; // eax
	ObjectMaster* a1a; // [esp+Ch] [ebp+4h]

	v1 = a1;
	v2 = (chaowk*)a1->Data1;
	v3 = v2->Behavior.Mode;
	v4 = &v2->Behavior;
	if (v3)
	{
		if (v3 != 1)
		{
			goto LABEL_26;
		}
	}
	else
	{
		v5 = v2->MotionCtrl.pose;
		if (v5 <= 0 || v5 > 3)
		{
			if ((double)rand() * 0.000030517578 >= 0.5)
			{
				AL_SetMotionLinkStep(a1, 528, 0x23u);
			}
			else
			{
				AL_SetMotionLinkStep(a1, 526, 0x23u);
			}
		}
		else
		{
			v6 = (double)rand() * 0.000030517578;
			if (v6 >= 0.40000001)
			{
				if (v6 >= 0.80000001)
				{
					AL_SetMotionLinkStep(a1, 536, 0x23u);
				}
				else
				{
					AL_SetMotionLinkStep(a1, 534, 0x23u);
				}
			}
			else
			{
				AL_SetMotionLinkStep(a1, 531, 0x23u);
			}
		}
		if ((double)rand() * 0.000030517578 >= 0.5)
		{
			AL_FaceSetEye(a1, 1, -1);
		}
		else
		{
			AL_FaceSetEye(a1, 3, -1);
		}
		if ((double)rand() * 0.000030517578 >= 0.40000001)
		{
			AL_FaceSetMouth(a1, ChaoMouth_OpenFrown, -1);
		}
		else
		{
			AL_FaceSetMouth(a1, ChaoMouth_ClosedFrown, -1);
		}
		++v4->Mode;
		v4->Timer = (100 - ((double)rand() * 0.000030517578 * -101.0));
	}
	if (AL_IsMotionStop(v1) || (v7 = v4->Timer, v4->Timer = v7 - 1, v7 <= 0))
	{
		AL_EmotionAdd(v1, EM_MD_SORROW, -10);
		if (AL_EmotionGetValue(v1, EM_MD_SORROW) < 10)
		{
			return 1;
		}
		v4->Mode = 0;
	}
LABEL_26:
	if (v2->Behavior.Timer % 8 < 4)
	{
		AL_SHAPE* v13 = &v2->Shape;
		NJS_VECTOR a3, v22;
		float v14 = v13->LeftEyePos.y;
		
		float v15 = v13->LeftEyePos.x;
		a3.y = v14;
		float v16 = v13->LeftEyePos.z;
		a3.x = v15;
		a3.y = v14 - 0.2f;
		float v17 = v13->LeftEyeVec.x;
		a3.z = v16;
		v22.x = v17 * 0.1f;
		v22.y = v13->LeftEyeVec.y * 0.1f + 0.1f;
		v22.z = 0.1f * v13->LeftEyeVec.z;
		CryingParticle_Load(&v22, &a3, 0.1);
		float v18 = v13->RightEyePos.x;
		a3.y = v13->RightEyePos.y;
		float v19 = v13->RightEyePos.z;
		a3.x = v18;
		a3.y = a3.y - 0.2f;
		float v20 = v13->RightEyeVec.x;
		a3.z = v19;
		v22.x = v20 * 0.1f;
		v22.y = v13->RightEyeVec.y * 0.1f + 0.1f;
		v22.z = 0.1f * v13->RightEyeVec.z;
		CryingParticle_Load(&v22, &a3, 0.1);
	}
	//if (!(v1->Data1->Timer % 180u))
	{
		//sound code
		//rand();
	}

	return 0;
}
signed int __cdecl FartReaction(ObjectMaster* a1)
{
	chaowk* v2;

	v2 = (chaowk*)a1->Data1;
	if (!v2->Behavior.Mode)
	{
		AL_SetMotionLink(a1, 568);
		AL_IconSet(a1, 5, 60);
		AL_FaceSetEye(a1, 1, -1);
		AL_FaceSetMouth(a1, 4, -1);
		++v2->Behavior.Mode;
	}
	v2->Behavior.Timer++;
	if (v2->Behavior.Timer >= 60 * 2)
		return 1;
	return 0;
}

DataArray(BHV_FUNC, ALBHV_IllnessFunc, 0x036B3AF4, 6);
void AL_CalcIntention_Illness(ObjectMaster* a1, float* a2)
{
	chaowk* data1 = (chaowk*)a1->Data1;
	for (int i = 0; i < 6; i++)
	{
		if (data1->pParamGC->Emotion.IllState[i] < 0)
		{
			if (((AL_EmotionGetValue(a1, EM_ST_CONDITION)) + 20000) < (rand() * 0.000030517578125f * 30000.0f))
			{
				AL_SetBehavior(a1, ALBHV_IllnessFunc[i]);
				*a2 = 0.99f;
			}
		}
	}
}
void __cdecl AL_CalcIntentionScore_Chat(ObjectMaster* a1, float* a2);
void AL_CalcIntentionScore_Tree(ObjectMaster* a1, float* a2);
signed int sub_563B70(ObjectMaster* a1);
void ThinkControllerHook(ObjectMaster* a1, float* a2)
{
	chaowk* data1 = (chaowk*)a1->Data1;
	ChaoData2* data2 = (ChaoData2*)a1->Data2;

	//fart reaction restoration
	if (ALOField_Find(a1, 1, 151))
	{
		AL_SetBehavior(a1, FartReaction);
		*a2 = 1;
	}
	if(sub_563B70(a1)) *a2 = 1;
	AL_CalcIntention_Illness(a1, a2);
	AL_CalcIntentionScore_Fear(a1, a2);
	AL_CalcIntentionScore_Tree(a1, a2);

}

void HeroDarkRattle(ObjectMaster* a1, int a2, NJS_CNK_OBJECT* model, NJS_TEXLIST* texlist)
{
	DataPointer(NJS_CNK_OBJECT, NormalRattle, 0x36B6E6C);
	DataPointer(NJS_CNK_OBJECT, HeroRattle, 0x36B66B4);
	DataPointer(NJS_CNK_OBJECT, DarkRattle, 0x36B58EC);
	if (AL_IsHero2(a1))
	{
		AL_SetItem(a1, a2, &HeroRattle, &AL_TOY_TEXLIST);
	}
	else if (AL_IsDark2(a1))
	{
		AL_SetItem(a1, a2, &DarkRattle, &AL_TOY_TEXLIST);
	}
	else
	{
		AL_SetItem(a1, a2, &NormalRattle, &AL_TOY_TEXLIST);
	}
}

char __cdecl Chao_Evolve2(ObjectMaster* a1)
{
	DataPointer(float, HPosVPosMinimum, 0x034BBA0C);
	DataPointer(float, AlignmentMinimum, 0x034BBA10);
	ChaoDataBase* v1; // esi
	char type; // bl
	v1 = ((chaowk*)a1->Data1)->pParamGC;
	if (-HPosVPosMinimum >= v1->PowerRun || v1->PowerRun >= HPosVPosMinimum || -HPosVPosMinimum >= v1->FlySwim || v1->FlySwim >= HPosVPosMinimum)
	{
		if (v1->PowerRun >= v1->FlySwim)
		{
			type = ChaoType_Neutral_Power;
			if (-v1->PowerRun >= v1->FlySwim)
			{
				type = ChaoType_Neutral_Swim;
			}
		}
		else if (-v1->PowerRun >= v1->FlySwim)
		{
			type = ChaoType_Neutral_Run;
		}
		else
		{
			type = ChaoType_Neutral_Fly;
		}

		int i = 0;
		while (v1->SADXAnimalBehaviors & (1 << i))
		{
			if (++i >= 15)
			{
				if (v1->Happiness > 80 && v1->Reincarnations >= 2u)
				{
					if (type == ChaoType_Neutral_Fly)
						type = ChaoType_Tails;
					if (type == ChaoType_Neutral_Power)
						type = ChaoType_Knuckles;
					if (type == ChaoType_Neutral_Run)
						type = ChaoType_Amy;
				}
				break;
			}
		}
	}
	else
	{
		type = ChaoType_Neutral_Normal;
		int i = 0;
		while (v1->SADXAnimalBehaviors & (1 << i))
		{
			if (++i >= 15)
			{
				if (v1->Happiness > 80 && v1->Reincarnations >= 2u)
				{
					type = ChaoType_Neutral_Chaos;
				}
				break;
			}
		}
	}
	if ((-AlignmentMinimum >= v1->Alignment || v1->Alignment >= AlignmentMinimum)) //hero or dark
	{
		if ((type >= ChaoType_Tails && type <= ChaoType_Amy))
			type = ChaoType_Neutral_Normal;
		if (v1->Alignment <= 0.0) //if dark then
		{
			type += 2; //turn neutral into dark
			ApplyWSwitch(0x40);
			PlayJingle(118);
		}
		else //else if hero then
		{
			++type; //turn neutral into hero
			ApplyWSwitch(0x10);
			PlayJingle(117);
		}
	}
	else
	{
		if (type >= ChaoType_Tails && type <= ChaoType_Amy)
		{

			//PlayJingle("chao_new_garden.adx");
		}
	}
	v1->Type = (ChaoType)type;
	v1->EvolutionProgress = 0.0;
	v1->PowerRun = 0.0;
	v1->FlySwim = 0.0;
	Chao_IncrementTypeStat(&v1->DNA, v1);
	return type;
}

enum ChunkMaterialFlagsEnum
{
	DontUseTexture = 0x1,
	HasSecondTexture = 0x2,
	SecondTextureEnvironmentMap = 0x4,
	UseChunkObjectColor = 0x8,
};

void __cdecl ChaoColoring(int texture, int color, int shiny, int highlights, NJS_CNK_MODEL* model)
{
	int flag; // esi
	unsigned __int16 v6; // ax
	_BOOL1 noTexture; // zf
	unsigned __int16 v8; // ax


	flag = 0;
	if (model)
	{
		if (shiny)
		{
			flag = SecondTextureEnvironmentMap | HasSecondTexture;
			SetChunkTextureIndexB(34u);
			v6 = GetChunkTextureIndex(model);
			SetChunkTextureIndexA(v6);
		}
		else
		{
			noTexture = texture == 0;
			if (texture <= 0)
			{
			LABEL_7:
				if (noTexture)
				{
					if (color > 0)
					{
						flag |= UseChunkObjectColor;
						SetChunkColor(((int*)0x0389D828)[color]);
					}
					if (highlights)
					{
						flag |= DontUseTexture;
					}
					else
					{
						v8 = GetChunkTextureIndex(model);
						SetChunkTextureIndexA(v8);
					}
				}
				if (flag)
				{
					EnableChunkMaterialFlags();
					SetChunkMaterialFlags((ChunkMaterialFlagsEnum)flag);
				}
				else
				{
					DisableChunkMaterialFlags();
					SetChunkMaterialFlags(0);
				}
				return;
			}
			flag = UseChunkObjectColor | SecondTextureEnvironmentMap;
			SetChunkColor(-1);
			SetChunkTextureIndexA(texture + 17);
		}
		noTexture = texture == 0;
		goto LABEL_7;
	}
}

void __cdecl chSetRareMaterial(int texture, int color, int shiny, int highlights, NJS_CNK_MODEL* model, int mixColor1, int mixColor2)
{
	int flag; // esi
	unsigned __int16 v6; // ax
	_BOOL1 noTexture; // zf
	unsigned __int16 v8; // ax

	flag = 0;
	if (model)
	{
		if (shiny)
		{
			flag = 6;
			SetChunkTextureIndexB(34u);
			v6 = GetChunkTextureIndex(model);
			SetChunkTextureIndexA(v6);
		}
		else
		{
			noTexture = texture == 0;
			if (texture <= 0)
			{
			LABEL_7:
				if (noTexture)
				{
					if (color > 0)
					{
						flag |= UseChunkObjectColor;
						SetChunkColor(((int*)0x0389D828)[color - 1]);
					}
					if (highlights)
					{
						flag |= DontUseTexture;
					}
					else
					{
						v8 = GetChunkTextureIndex(model);
						SetChunkTextureIndexA(v8);
					}
				}
				if (flag)
				{
					EnableChunkMaterialFlags();
					SetChunkMaterialFlags((ChunkMaterialFlagsEnum)flag);
				}
				else
				{
					DisableChunkMaterialFlags();
					SetChunkMaterialFlags(0);
				}
				return;
			}
			flag = UseChunkObjectColor | SecondTextureEnvironmentMap;
			SetChunkColor(-1);
			SetChunkTextureIndexA(texture + 17);
		}
		noTexture = texture == 0;
		goto LABEL_7;
	}
	if (mixColor1 != 0 && mixColor2 != 0)
	{
		NJS_COLOR* colorsNJ = (NJS_COLOR*)0x0389D828;
		NJS_COLOR resultMixed;
		resultMixed.argb.b = (Uint8)(colorsNJ[mixColor1].argb.b * 0.5f + colorsNJ[mixColor2].argb.b * (1 - 0.5f));
		resultMixed.argb.r = (Uint8)(colorsNJ[mixColor1].argb.r * 0.5f + colorsNJ[mixColor2].argb.r * (1 - 0.5f));
		resultMixed.argb.g = (Uint8)(colorsNJ[mixColor1].argb.g * 0.5f + colorsNJ[mixColor2].argb.g * (1 - 0.5f));
		resultMixed.argb.a = (Uint8)(colorsNJ[mixColor1].argb.a * 0.5f + colorsNJ[mixColor2].argb.a * (1 - 0.5f));
		SetChunkColor(resultMixed.color);
	}
}

void AL_CalcParameter_Condition(ObjectMaster* a1, EMOTION_ENUM a2, int a3)
{
	//todo check if this works?
	AL_EmotionAdd(a1, a2, a3);

	if (AL_EmotionGetValue(a1, EM_ST_NOURISHMENT) > ChaoGlobal.ParamConditionTriggerAddN)
		AL_EmotionAdd(a1, EM_ST_CONDITION, ChaoGlobal.ParamAddConditionN);
	if (AL_EmotionGetValue(a1, EM_ST_NOURISHMENT) < ChaoGlobal.ParamConditionTriggerSubN)
		AL_EmotionAdd(a1, EM_ST_CONDITION, -ChaoGlobal.ParamSubConditionN);
	if (AL_EmotionGetValue(a1, EM_ST_STRESS) > ChaoGlobal.ParamConditionTriggerS)
		AL_EmotionAdd(a1, EM_ST_CONDITION, -ChaoGlobal.ParamSubConditionS);
	if (AL_EmotionGetValue(a1, EM_MD_PAIN) > ChaoGlobal.ParamConditionTriggerP)
		AL_EmotionAdd(a1, EM_ST_CONDITION, -ChaoGlobal.ParamSubConditionP);
}

int __cdecl AdjustAngle(__int16 bams_a, unsigned __int16 bams_b, int dang)
{
	int result; // eax
	__int16 v4; // cx

	result = bams_b;
	v4 = bams_b - bams_a;
	if ((bams_b - bams_a) > dang || v4 < -dang)
	{
		if (v4 >= 0)
		{
			result = (dang + bams_a);
		}
		else
		{
			result = (bams_a - dang);
		}
	}
	return result;
}
int __cdecl DiffAngle(int a1, int a2)
{
	int result; // eax

	result = a2 - a1;
	if ((a2 - a1) < 0)
	{
		result = a1 - a2;
	}
	return result;
}

#pragma pack(push, 8)
struct __declspec(align(4)) what_drawsprite
{
	what_drawsprite* next;
	void(__cdecl* function_ptr)(what_drawsprite*, void*);
	int texid;
	int angle;
	float some_other_scale;
	float scale;
	NJS_VECTOR position;
	NJS_VECTOR scale_v;
	NJS_ARGB color;
	float depth;
	void* user_data;
	float field_48;
	int field_4C;
};
#pragma pack(pop)
struct particle_info
{
	float scl;
	float sclspd;
	float animspd;
	float friction;
	float yacc;
	NJS_POINT3 pos;
	NJS_POINT3 velo;
	NJS_ARGB argb;
};
particle_info stru_97E3D0 =
{
   1.0,
   0.038f,
   0.19,
   0.06f,
   0.025,
  {  0.0,  0.0,  0.0 },
  {  0.0,  0.0,  0.0 },
  {  1.0,  1.0,  1.0,  1.0 }
};

FunctionPointer(what_drawsprite*, AllocateParticle, (int a1, int a2), 0x0456BF0);
void __cdecl CreateDust(NJS_VECTOR* a1, NJS_VECTOR* a2, float a3)
{
	what_drawsprite* v4; // esi

	v4 = AllocateParticle(0x0097E388, 0x4B9770);
	if (v4)
	{
		v4->position = *a1;
		v4->scale_v = *a2;
		v4->scale = a3 * 0.15000001;
		v4->some_other_scale = rand() * 0.000030517578 * 6.0;
		v4->angle = (rand() * 0.000030517578 * 360.0 * 65536.0 * 0.002777777777777778);
		v4->color.a = 1.0;
		v4->color.r = 1.0;
		v4->color.g = 1.0;
		v4->color.b = 1.0;
		v4->user_data = &stru_97E3D0;
	}
}
signed int __cdecl ALBHV_HoukiRe(ObjectMaster* a1)
{
	chaowk* v1; // esi
	int v2; // eax
	AL_BEHAVIOR* v3; // esi
	int v5; // eax
	int a1a; // [esp+Ch] [ebp+4h]

	v1 = (chaowk*)a1->Data1;
	v2 = v1->Behavior.Mode;
	v3 = &v1->Behavior;
	switch (v2) {
	case 0:
		AL_SetMotionLink(a1, 337);
		AL_FaceSetEye(a1, 0, -1);
		AL_SetItem(a1, 11, (NJS_CNK_OBJECT*)0x036B8BBC, &AL_TOY_TEXLIST);
		a1a = rand();
		++v3->Mode;
		v3->Timer = (600 - (a1a * 0.000030517578 * -201.0));
		break;
	case 1:
		if (v3->SubTimer++ % 35 == 0)
		{
			NJS_VECTOR pos;
			pos.x = v1->entity.Position.x + njSin(v1->entity.Rotation.y) * 3.0;
			pos.y = v1->entity.Position.y + 0.2;
			pos.z = v1->entity.Position.z + njCos(v1->entity.Rotation.y) * 3.0;
			NJS_VECTOR a2;
			a2.x = -0.1;
			a2.y = 0;
			a2.z = 0;
			CreateDust(&pos, &a2, 0);
		}
		v5 = v3->Timer;
		v3->Timer = v5 - 1;
		if (v5 > 0)
		{
			return 0;
		}
		return 1;
		break;
	}
	return 0;

}
#pragma pack(push, 8)
struct __declspec(align(4)) FRUIT_INFO
{
	float growth;
	float AimGrowth;
	int SwingCounter;
	NJS_POINT3 pos;
	int angx;
	int angy;
};
#pragma pack(pop)

#pragma pack(push, 8)
struct __declspec(align(4)) ALO_GrowTreeExecutor_Data
{
	EntityData1 entityData;
	char kind;
	char state;
	float growth;
	int life;
	int water;
	char pos_num;
	FRUIT_INFO fruitLifeData[3];
	int scale;
	int ScaleSpd;
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
	float RollPhase;
	int field_AC;
	int field_B0;
	NJS_TEXLIST* texlist_;
	float field_B8;
	int field_BC;
	int someSine;
};
#pragma pack(pop)

FunctionPointer(al_perception_link*, AL_GetFoundTree, (ObjectMaster* a1), 0x073E660);
int ALBHV_TreeShake(ObjectMaster* a1)
{
	chaowk* wk = (chaowk*)a1->Data1;
	ALO_GrowTreeExecutor_Data* treedata = nullptr;

	switch (wk->Behavior.Mode)
	{
	case 0:
		AL_SetMotionLink(a1, 211 + 3);
		wk->Behavior.Mode++;
		wk->Behavior.Timer = 60;
		break;
	case 1:
		wk->Behavior.Timer--;
		if (wk->Behavior.Timer <= 0)
		{
			AL_SetMotionLink(a1, 213 + 3);
			wk->Behavior.Timer = 300 + (rand() * 0.000030517578f * 100);
			wk->Behavior.Mode++;
		}
		break;
	case 2:
		wk->Behavior.Timer--;
		if (wk->Behavior.Timer <= 0)
		{
			wk->Behavior.Mode++;
			wk->Behavior.Timer = 30;
			AL_SetMotionLink(a1, 214 + 3);
		}
		else
		{
			treedata = (ALO_GrowTreeExecutor_Data*)ALW_GetLockOnTask(a1)->Data1;
			treedata->LeafWidth = 14.0f;
			treedata->FruitWidth = 14.0f;
			wk->Behavior.SubTimer++;
			if (wk->Behavior.SubTimer % 30 == 0)
				treedata->SwingFlag = 1;
		}
		break;
	case 3:
		wk->Behavior.Timer--;
		if (wk->Behavior.Timer <= 0)
		{
			return 1;
		}
		break;
	}
	return 0;
}
void AL_CalcIntentionScore_Tree(ObjectMaster* a1, float* a2)
{
	if (rand() * 0.000030517578 >= 0.60000002)
	{
		int Hunger = AL_EmotionGetValue(a1, EM_ST_HUNGER);
		float score = ChaoGlobal.IntentionHungerFruitSearchMaxScore
			* AL_CalcScoreTypeA(Hunger, ChaoGlobal.IntentionHungerFruitSearchTrigger);
		AL_ScoreRandomize(&score);
		if (score > * a2)
		{
			al_perception_link* v1 = AL_GetFoundTree(a1);
			if (v1 && !ALW_IsSheAttentionOtherOne(a1, v1->pEntry->tp)) //check if tree found and tree isnt being used by another action
			{
				ALW_LockOn(a1, v1->pEntry->tp);
				AL_SetBehavior(a1, ALBHV_Notice);
				AL_SetNextBehavior(a1, ALBHV_GoToLockOn);
				AL_SetNextBehavior(a1, ALBHV_TurnToLockOn);
				AL_SetNextBehavior(a1, ALBHV_TreeShake);
				*a2 = score;
			}
		}
	}
}
bool __cdecl ALBHV_Eda(ObjectMaster* a1)
{
	ObjectMaster* v1; // edi
	chaowk* v2; // esi
	int v3; // eax
	AL_BEHAVIOR* v4; // esi
	int v5; // edx
	ObjectMaster* a1a; // [esp+Ch] [ebp+4h]

	v1 = a1;
	v2 = (chaowk*)a1->Data1;
	v3 = v2->Behavior.Mode;
	v4 = &v2->Behavior;
	if (v3)
	{
		if (v3 != 1)
		{
			return 0;
		}
	}
	else
	{
		AL_SetMotionLink(a1, 355);
		//AL_FaceSetEye(a1, AL_EYE_NUM_NIKO, -1);
		// AL_FaceSetMouth(a1, AL_MOUTH_NUM_NIKO, -1);		
		AL_SetItem(a1, 11, &object_eda_obj2_obj2, &CHAO_TEXLIST);
		++v4->Mode;
		v4->Timer = (300 - (rand() * 0.000030517578 * -301.0));
	}
	return 0;
}
signed int sub_564760(ObjectMaster* a1);
void Chao_Init()
{
	//attempt at patching something
	WriteCall((void*)0x0071EEF0, nullsub);

	WriteJump(ALBHV_Houki, ALBHV_HoukiRe);

	//character chao
	WriteJump((void*)0x0073C3A0, Chao_Evolve2);

	//sound restoration, todo restore particles
	WriteJump(ALBHV_HungryDada, Tantrum);
	WriteJump(ALBHV_Cry, ALBHV_Cry_);
	//console restoration 
	//WriteJump(ALBHV_GoToTV, ALBHV_GoToBoat);

	//temp debug hanabi
	//WriteJump(ALBHV_Think, ALBHV_Eda);
	//WriteJump(ALBHV_Think, ALBHV_GoToBoat);

	//float toy
	//WriteCall((void*)0x0073C13F, ALBHV_FloatCheck);
	WriteCall((void*)0x0071EE6D, sub_563B70); //ball
	WriteCall((void*)0x0071EEA3, sub_564760); //box
	//piano
	//WriteData((int*)0x0075F2E1, (int)ALBHV_GoToPiano);
	//WriteData((int*)0x0075F2E8, (int)& Chao_BallJoinDecision);
	//WriteData((int*)0x0075F2EE, (int)& behaviour::ALBHV_GoToConsole);

	//distance timers restored
	WriteCall((void*)0x00731B35, AL_KW_Control);
	WriteCall((void*)0x00731B1F, AL_KW_Control);

	//brings back condition values increasing
	WriteCall((void*)0x00731A8F, AL_CalcParameter_Condition);

	//think controller custom
	//WriteCall((void*)0x0073D4B1, ThinkControllerHook);

	//unused rattles
	WriteCall((void*)0x00763345, HeroDarkRattle);
}
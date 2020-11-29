
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
#include "alo_accessory.h"

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
signed int __cdecl ALBHV_HungryDada_(ObjectMaster* a1)
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
	//PrintDebug("%f %f %f \n", Current_CharObj1->Position.x, Current_CharObj1->Position.y, Current_CharObj1->Position.z);
	//fart reaction restoration
	if (ALOField_Find(a1, 1, 151))
	{
		AL_SetBehavior(a1, FartReaction);
		*a2 = 1;
	}
	AL_EmotionAdd(a1, EMOTION_ENUM::EM_ST_BREED, 10000);
	if (GetChaoObject(0, 0) == a1)
	{
		data1->pParamGC->DNA.Color1 = SADXRetailColour_Red;
		data1->pParamGC->DNA.Color2 = SADXRetailColour_Red;
	}
	if (GetChaoObject(0, 1) == a1)
	{
		data1->pParamGC->DNA.Color1 = SADXRetailColour_Grey;
		data1->pParamGC->DNA.Color2 = SADXRetailColour_Grey;
	}
	//if(sub_563B70(a1)) *a2 = 1;
	//AL_CalcIntention_Illness(a1, a2);
	AL_CalcIntentionScore_Fear(a1, a2);
	//AL_CalcIntentionScore_Tree(a1, a2);

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

void __cdecl ChaoColoring_(int texture, int color, int shiny, int highlights, NJS_CNK_MODEL* model)
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

void __cdecl chSetRareMaterial_(int texture, int color, int shiny, int highlights, NJS_CNK_MODEL* model, int mixColor1, int mixColor2)
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
void AL_SetAccessory(ObjectMaster* a1, int type)
{
	chaowk* wk = (chaowk*)a1->Data1;
	wk->pParamGC->Accessories[AccessoryTypeMap[type]] = type + 1;
}
int AL_GetAccessory(ObjectMaster* a1, int type)
{
	chaowk* wk = (chaowk*)a1->Data1;
	return wk->pParamGC->Accessories[type];
}

FunctionPointer(void, AL_GrabObjectBothHands, (ObjectMaster* a1, ObjectMaster* a2), 0x00744810);
FunctionPointer(signed int, AL_CheckObakeHead, (ObjectMaster* a1), 0x0073AE70);
FunctionPointer(void*, AL_GetItemSaveInfo, (ObjectMaster* a1), 0x07176A0);
FunctionPointer(void, AL_ClearItemSaveInfo, (void* a1), 0x00717670);
FunctionPointer(void, AL_ClearItemSaveInfoPtr, (ObjectMaster* a1), 0x07176C0);
//putting accessory on
signed int __cdecl ALBHV_WearAccessory(ObjectMaster* a1)
{
	chaowk* v1; // esi
	int v2; // eax
	AL_BEHAVIOR* v3; // esi
	int v4; // eax
	al_entry_work* v6; // eax
	al_entry_work* v7; // esi
	ObjectMaster* v8; // eax
	void* v9; // eax

	v1 = (chaowk*)a1->Data1;
	v2 = v1->Behavior.Mode;
	v3 = &v1->Behavior;
	if (!v2)
	{
		AL_SetMotionLinkStep(a1, 202, 0x23u);
		++v3->Mode;
		v3->Timer = 0;
		return AL_MoveHoldingObject(a1) == 0;
	}
	v4 = v2 - 1;
	if (v4)
	{
		if (v4 == 1 && AL_IsMotionStop(a1))
		{
			return 1;
		}
		return AL_MoveHoldingObject(a1) == 0;
	}
	v3->Timer++;
	if (v3->Timer < 35 || !AL_IsMotionStop(a1))
	{
		return AL_MoveHoldingObject(a1) == 0;
	}
	v6 = ALW_IsCommunicating(a1);
	v7 = v6;
	if (v6)
	{
		v8 = v6->tp;
		if (v8)
		{
			AL_SetAccessory(a1, v8->Data1->Rotation.x);
			if (AL_GetItemSaveInfo(v7->tp))
			{
				v9 = AL_GetItemSaveInfo(v7->tp);
				AL_ClearItemSaveInfo(v9);
				AL_ClearItemSaveInfoPtr(v7->tp);
			}
			v7->tp->MainSub = DeleteObject_;
		}
	}
	AL_SetMotionLinkStep(a1, 203, 0x23u);
	return AL_MoveHoldingObject(a1) == 0;
}
signed int __cdecl ALBHV_PutOnAccessoryTemp(ObjectMaster* a1)
{
	chaowk* v1; // esi
	int v2; // eax
	AL_BEHAVIOR* v3; // esi
	int v4; // eax
	al_entry_work* v6; // eax
	al_entry_work* v7; // esi
	ObjectMaster* v8; // eax
	void* v9; // eax

	v1 = (chaowk*)a1->Data1;
	v2 = v1->Behavior.Mode;
	v3 = &v1->Behavior;
	v6 = ALW_IsCommunicating(a1);
	v7 = v6;
	if (v6)
	{
		v8 = v6->tp;
		if (v8)
		{
			AL_SetAccessory(a1, v8->Data1->Rotation.x);
			if (AL_GetItemSaveInfo(v7->tp))
			{
				v9 = AL_GetItemSaveInfo(v7->tp);
				AL_ClearItemSaveInfo(v9);
				AL_ClearItemSaveInfoPtr(v7->tp);
			}
			v7->tp->MainSub = DeleteObject_;
		}
	}
	return 1;
}
FunctionPointer(void, StopHoldingTaskP, (unsigned __int8 a1), 0x04420C0);
signed int __cdecl ALBHV_TurnToAccessory(ObjectMaster* a1)
{
	chaowk* v1; // edi
	char* v2; // eax
	ObjectMaster* v3; // ebx
	int v4; // eax
	ChaoDataBase* v5; // ecx
	signed int result; // eax
	int v7; // eax

	v1 = (chaowk*)a1->Data1;
	if (!v1->Behavior.Mode)
	{
		AL_SetMotionLinkStep(a1, 202, 0xFu);
		++v1->Behavior.Mode;
		v1->Behavior.Timer = 60;
	}
	if (MOV_TurnToAim2(a1, 0x600) >= 0xB6)
	{
		return 0;
	}
	v3 = ALOField_Find2(a1->Data1, 0x94);
	if (v3 != 0)
	{
		if (ALW_IsHeld(v3))
		{
			return 0;
		}
		StopHoldingTaskP(0);
		AL_GrabObjectBothHands(a1, v3);
		AL_SetBehaviorWithTimer(a1, ALBHV_HoldThink, -1);
		v5 = v1->pParamGC;
		if ((v1->pParamGC->SADXAnimalBehaviors & (1 << 13)) || (v1->pParamGC->SA2AnimalBehavior & (1 << 16)) && !AL_GetAccessory(a1, AccessoryTypeMap[v3->Data1->Rotation.x]))
			AL_SetNextBehavior(a1, ALBHV_PutOnAccessoryTemp);
		else
			AL_SetNextBehavior(a1, ALBHV_Throw);

		return 0;
	}
	else
	{
		v7 = v1->Behavior.Timer;
		v1->Behavior.Timer = v7 - 1;
		if (v7 > 0)
		{
			return 0;
		}
		result = 1;
	}
	return result;
}
signed int __cdecl AL_CheckAccessory(ObjectMaster* a1)
{
	signed int(__cdecl * v1)(ObjectMaster*); // eax
	//ObjectMaster* v2; // eax
	ObjectMaster* v3; // esi

	v1 = AL_GetBehavior(a1);
	if ((int)v1 == 0x5607C0)
	{
		return 0;
	}
	if ((int)v1 == 0x54EF10)
	{
		return 0;
	}
	if (v1 == ALBHV_TurnToAccessory)
	{
		return 0;
	}

	v3 = ALOField_Find2(a1->Data1, 0x94);
	if (!v3)
	{
		return 0;
	}
	al_entry_work* v4 = (al_entry_work*)v3->UnknownA_ptr;
	if (v4)
	{
		if (v4->flag & 2)
		{
			return 0;
		}
	}
	MOV_SetAimPos(a1, &v3->Data1->Position);
	//a1->EntityData2->Waypoint = v3->Data1->Position;
	AL_SetBehaviorWithTimer(a1, ALBHV_TurnToAccessory, -1);
	return 1;
}
signed int __cdecl AL_CheckObakeHeadAndAccessory(ObjectMaster* a1)
{
	return AL_CheckAccessory(a1) || AL_CheckObakeHead(a1);
}
VoidFunc(_before_cnk, 0x00720A10);
VoidFunc(_after_cnk, 0x00720A40);
FunctionPointer(void, sub_534E10, (ObjectMaster* a1, int a2), 0x007187D0);
DataPointer(short, Chao_NodeIndex, 0x03CE04E4);
FunctionPointer(void, njSetZCompare, (Uint8 index), 0x0077ED00);
FunctionPointer(void, chRareEggDrawModel, (NJS_CNK_MODEL* a1, int a2), 0x0078AF10);
FunctionPointer(void, AL_CalcMotionMartix, (ChunkObjectPointer* a1), 0x00765010);
FunctionPointer(void, ChaoColoring, (int texture, int color, int shiny, int highlights, NJS_CNK_MODEL* model), 0x0078AE30);
VoidFunc(npSetZCompare, 0x00401420);
unsigned char DCWings = 0x90;
unsigned char CharacterIndex = 0x14;
void DrawChaoNew(ObjectMaster* a1, ChunkObjectPointer* chunkObjectPointer)
{
	NJS_OBJECT* v14; // eax
	NJS_OBJECT* v18; // eax
	NJS_OBJECT* v19; // eax
	NJS_OBJECT* v20; // eax
	signed int v36; // esi
	char v37; // zf
	int v44; // [esp+28h] [ebp-38h]

	while (1)
	{
		chaowk* wk = (chaowk*)a1->Data1;
		njPushMatrixEx();
		AL_CalcMotionMartix(chunkObjectPointer);
		//chibi chao lol
		//if (Chao_NodeIndex == 0)
			//njScale(0.5, 0.5, 0.5);
		//if (Chao_NodeIndex == 17 ||
			//Chao_NodeIndex == 20)
			//njScale(1.5, 1.5, 1.5);
		if (chunkObjectPointer->toy.model)
		{
			njSetTexture(chunkObjectPointer->toy.texlist);
			SetChunkMaterialFlags(SecondTextureEnvironmentMap);
			njPushMatrixEx();
			if (chunkObjectPointer->useTransform)
			{
				njTranslate(
					0,
					chunkObjectPointer->position.x,
					chunkObjectPointer->position.y,
					chunkObjectPointer->position.z);
				if (chunkObjectPointer->rotation.z)
				{
					njRotateZ(0, chunkObjectPointer->rotation.z);
				}
				if (chunkObjectPointer->rotation.y)
				{
					njRotateY(0, chunkObjectPointer->rotation.y);
				}
				if (chunkObjectPointer->rotation.x)
				{
					njRotateX(0, chunkObjectPointer->rotation.x);
				}
			}
			njScale(0, chunkObjectPointer->toy.scale, chunkObjectPointer->toy.scale, chunkObjectPointer->toy.scale);
			//SetFlag(1);
			njCnkDrawObject(chunkObjectPointer->toy.model);
			//SetFlag(0);
			njPopMatrixEx();
			SetChunkMaterialFlags(0);
		}


		if (Chao_NodeIndex == 1)
		{

		}

		if (Chao_NodeIndex == 16)
		{

			if (wk->pParamGC->Accessories[0])
			{
				njSetTexture(Accessories[wk->pParamGC->Accessories[0] - 1].second);
				njCnkDrawObject(Accessories[wk->pParamGC->Accessories[0] - 1].first);
			}
			if (wk->pParamGC->Accessories[1])
			{
				njSetTexture(Accessories[wk->pParamGC->Accessories[1] - 1].second);
				njCnkDrawObject(Accessories[wk->pParamGC->Accessories[1] - 1].first);
			}
			if (wk->pParamGC->Accessories[2])
			{
				njSetTexture(Accessories[wk->pParamGC->Accessories[2] - 1].second);
				njCnkDrawObject(Accessories[wk->pParamGC->Accessories[2] - 1].first);
			}

			if (wk->pParamGC->Headgear)
			{
				njSetTexture(&ChaoTexLists[0]);
				njSetTexture(ChaoTexLists);
				switch (wk->pParamGC->Headgear)
				{
				case SADXHat_Pumpkin:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_Pumpkin);
					npSetZCompare();
					break;
				case SADXHat_Skull:
					njCnkDrawObject(&ChaoHat_Skull);
					break;
				case SADXHat_Apple:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_Apple);
					npSetZCompare();
					break;
				case SADXHat_Bucket:
					njCnkDrawObject(&ChaoHat_Bucket);
					break;
				case SADXHat_EmptyCan:
					njCnkDrawObject(&ChaoHat_EmptyCan);
					break;
				case SADXHat_CardboardBox:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_CardboardBox);
					npSetZCompare();
					break;
				case SADXHat_FlowerPot:
					njSetZCompare(3u);
					_before_cnk();
					njCnkDrawObject(&ChaoHat_FlowerPot);
					_after_cnk();
					npSetZCompare();
					break;
				case SADXHat_PaperBag:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_PaperBag);
					npSetZCompare();
					break;
				case SADXHat_Pan:
					_before_cnk();
					njCnkDrawObject(&ChaoHat_Pan_A);
					_after_cnk();
					njSetZCompare(3u);
					_before_cnk();
					njCnkDrawObject(&ChaoHat_Pan_B);
					_after_cnk();
					npSetZCompare();
					_before_cnk();
					njCnkDrawObject(&ChaoHat_Pan_C);
					_after_cnk();
					break;
				case SADXHat_Stump:
					njCnkDrawObject(&ChaoHat_Stump);
					break;
				case SADXHat_Watermelon:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_Watermelon);
					npSetZCompare();
					break;
				case SADXHat_RedWoolBeanie:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_RedWoolBeanie);
					npSetZCompare();
					break;
				case SADXHat_BlueWoolBeanie:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_BlueWoolBeanie);
					npSetZCompare();
					break;
				case SADXHat_BlackWoolBeanie:
					njSetZCompare(3u);
					njCnkDrawObject(&ChaoHat_BlackWoolBeanie);
					npSetZCompare();
					break;
				case SADXHat_Pacifier:
					njCnkDrawObject(&ChaoHat_Pacifier);
					break;
				default:
					njPushMatrixEx();
					DataPointer(NJS_OBJECT, EggShell, 0x035E2A14);
					njTranslate(0, 0.0, EggShell.pos[1], 0.0);
					chRareEggDrawModel(EggShell.chunkmodel, (unsigned __int8)wk->pParamGC->Headgear - 16);
					njPopMatrixEx();
					njSetZCompare(3u);
					njCnkDrawObject((NJS_OBJECT*)0x35E2BBC);
					npSetZCompare();
					njCnkDrawObject((NJS_OBJECT*)0x35E2DCC);
					break;

					goto LABEL_97;
				}
			}
		}
		else if (Chao_NodeIndex == 1)
		{
			if (wk->pParamGC->HideFeet && wk->pParamGC->Type < (unsigned __int8)ChaoType_Neutral_Chaos)
			{
				njSetTexture(ChaoTexLists);
				sub_534E10(a1, (unsigned __int8)wk->entity.Index);
				DataArray(NJS_CNK_OBJECT*, ChaoFeetHiddenModels, 0x03600930, 25);
				*((_DWORD*)ChaoFeetHiddenModels[wk->pParamGC->Type]->chunkmodel->plist + 1) = *((_DWORD*)chunkObjectPointer->base.chunkmodel->plist
					+ 1);
				ChaoColoring(
					wk->pParamGC->Texture,
					wk->pParamGC->Color,
					wk->pParamGC->Shiny,
					wk->pParamGC->MonotoneHighlights,
					chunkObjectPointer->base.chunkmodel);
				njCnkDrawObject(ChaoFeetHiddenModels[wk->pParamGC->Type]);
				SetChunkMaterialFlags(0);
				DisableChunkMaterialFlags();
				goto LABEL_95;
			}
		}
		else if (Chao_NodeIndex == 35 && wk->pParamGC->Medal)
		{
			njSetTexture(&ChaoTexLists[4]);
			_before_cnk();
			njCnkDrawObject(ChaoJewelModels[wk->pParamGC->Medal]);
			_after_cnk();
			goto LABEL_98;
		}
		if (((!wk->pParamGC->Headgear)
			|| Chao_NodeIndex != 18
			&& Chao_NodeIndex != 21
			&& Chao_NodeIndex != 19
			&& Chao_NodeIndex != 22
			&& Chao_NodeIndex != 23
			&& Chao_NodeIndex != 25
			&& Chao_NodeIndex != 24
			&& Chao_NodeIndex != 26
			&& Chao_NodeIndex != 30
			&& Chao_NodeIndex != 31
			&& Chao_NodeIndex != 27
			&& Chao_NodeIndex != 29)
			&& (!wk->pParamGC->HideFeet
				|| wk->pParamGC->Type >= (unsigned __int8)CharacterIndex
				|| ((DCWings == 0x90) || (Chao_NodeIndex != 37 && Chao_NodeIndex != 39)) && Chao_NodeIndex != 6 && Chao_NodeIndex != 13 && Chao_NodeIndex != 8))
		{
			if (chunkObjectPointer->animalPart && wk->pParamGC->Type < CharacterIndex)
			{
				njSetTexture((NJS_TEXLIST*)0x033A1340);
				_before_cnk();
				DrawCnkModel((NJS_CNK_MODEL*)chunkObjectPointer->animalPart->model);
				_after_cnk();
			}
			else if (chunkObjectPointer->base.chunkmodel)
			{
				v36 = wk->Face.EyeLidExpressionCurrSlopeAng;
				v44 = wk->Face.EyeLidExpressionCurrCloseAng + wk->Face.EyeLidBlinkAng - 0x4000;
				switch (Chao_NodeIndex)
				{
				case 19:
					njSetTexture(&ChaoTexLists[0]);
					ChaoColoring(
						wk->pParamGC->Texture,
						wk->pParamGC->Color,
						wk->pParamGC->Shiny,
						wk->pParamGC->MonotoneHighlights,
						chunkObjectPointer->base.chunkmodel);
					sub_534E10(a1, a1->Data1->Index);
					v37 = v36 == 0;
					goto LABEL_86;
				case 22:
					njSetTexture(&ChaoTexLists[0]);
					ChaoColoring(
						wk->pParamGC->Texture,
						wk->pParamGC->Color,
						wk->pParamGC->Shiny,
						wk->pParamGC->MonotoneHighlights,
						chunkObjectPointer->base.chunkmodel);
					sub_534E10(a1, a1->Data1->Index);
					v36 = -v36;
					v37 = v36 == 0;
				LABEL_86:
					if (v36)
					{
						njRotateZ(0, v36);
					}
					if (v44)
					{
						njRotateX(0, v44);
					}
				LABEL_91:
					if (Chao_NodeIndex != 19 && Chao_NodeIndex != 22
						|| wk->Face.EyeLidExpressionCurrCloseAng + wk->Face.EyeLidBlinkAng)
					{
						break;
					}
				LABEL_96:
					SetChunkMaterialFlags(0);
					DisableChunkMaterialFlags();
				LABEL_97:
					goto LABEL_98;
				case 27:
					njSetTexture(&ChaoTexLists[5]);
					break;
				case 18:
				case 21:
					njSetTexture(&ChaoTexLists[2]);
					if (Chao_NodeIndex != 18)
					{
						njTranslate(0, -wk->Face.EyePosX, wk->Face.EyePosY, 0);
						goto LABEL_91;
					}
					njTranslate(0, wk->Face.EyePosX, wk->Face.EyePosY, 0);
					break;
				default:
					njSetTexture(&ChaoTexLists[0]);
					if ((DCWings == 0x90) || (Chao_NodeIndex != 37 && Chao_NodeIndex != 39))
					{
						ChaoColoring(
							wk->pParamGC->Texture,
							wk->pParamGC->Color,
							wk->pParamGC->Shiny,
							wk->pParamGC->MonotoneHighlights,
							chunkObjectPointer->base.chunkmodel);

					}
					sub_534E10(a1, a1->Data1->Index);
					goto LABEL_91;
				}
				if (Chao_NodeIndex == 27)
				{
					njSetZCompare(3u);
					DrawCnkModel(chunkObjectPointer->base.chunkmodel);
					njSetZCompare(1u);
				}
				else
				{
					DrawCnkModel(chunkObjectPointer->base.chunkmodel);
				}
			LABEL_95:
				goto LABEL_96;
			}
		}
		LABEL_98:
			SetMaterialAndSpriteColor((NJS_ARGB*)0x3B18230);
			SetChunkMaterialFlags(0);
			DisableChunkMaterialFlags();
		Chao_NodeIndex++;
		if (chunkObjectPointer->base.child)
		{
			DrawChao(a1, (ChunkObjectPointer*)chunkObjectPointer->base.child);
		}
		njPopMatrixEx();
		if (!chunkObjectPointer->base.sibling)
		{
			break;
		}
		chunkObjectPointer = (ChunkObjectPointer*)chunkObjectPointer->base.sibling;
	}
}


void Chao_Init()
{
	//attempt at patching something
	WriteCall((void*)0x0071EEF0, nullsub);

	WriteJump(ALBHV_Houki, ALBHV_HoukiRe);

	WriteJump((void*)0x0073E730, DrawChaoNew);

	//character chao
	WriteJump((void*)0x0073C3A0, Chao_Evolve2);

	//sound restoration, todo restore particles
	WriteJump(ALBHV_HungryDada, ALBHV_HungryDada_);
	WriteJump(ALBHV_Cry, ALBHV_Cry_);

	//console restoration 
	//WriteJump(ALBHV_GoToTV, ALBHV_GoToBoat);

	//temp debug hanabi
	//WriteJump(ALBHV_Think, ALBHV_Eda);
	//WriteJump(ALBHV_Think, ALBHV_GoToBoat);

	WriteCall((void*)0x071EE7F, AL_CheckObakeHeadAndAccessory);

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
	WriteCall((void*)0x0073D4B1, ThinkControllerHook);

	//unused rattles
	WriteCall((void*)0x00763345, HeroDarkRattle);
}
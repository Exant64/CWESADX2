
#include "../chao.h"
#include <cstdlib>
#include "../al_toy/alo_ball.h"
double CheckDistance(NJS_VECTOR* a1, NJS_VECTOR* a2)
{
	double x_dist; // st6
	double y_dist; // st4
	double x_len; // st5
	double z_dist; // st6
	float len; // [esp+4h] [ebp-4h]

	x_dist = a2->x - a1->x;
	y_dist = a2->y - a1->y;
	x_len = x_dist * x_dist;
	z_dist = a2->z - a1->z;
	len = y_dist * y_dist + x_len + z_dist * z_dist;
	if (len < 0.02500000037252903)
	{
		return 0.0;
	}
	return (float)sqrt(len);
}
signed int __cdecl sub_563830(ObjectMaster* a1)
{
	ObjectMaster* v1; // esi
	chaowk* v3; // edi
	int v4; // edx
	ObjectMaster* v5; // ecx
	EntityData1* v6; // eax
	Float v7; // ST1C_4
	Float v8; // ST20_4
	double v9; // st7
	NJS_VECTOR* Waypoint; // eax
	Float v11; // ST24_4
	unsigned __int16 v14; // ax
	ChaoDataBase* v15; // ecx
	int v16; // eax
	int v17; // ecx
	int v18; // eax
	int v19; // edx
	ChaoDataBase* v20; // ecx
	int v21; // eax
	int v22; // ecx
	int v23; // eax
	ChaoDataBase* v24; // eax
	float a2; // [esp+24h] [ebp+4h]
	float a2a; // [esp+24h] [ebp+4h]

	v1 = a1;
	MOVE_WORK* v2 = (MOVE_WORK*)a1->Data2;
	v3 = (chaowk*)a1->Data1;
	if (v3->Behavior.Mode)
	{
		if (v3->Behavior.Mode != 1)
		{
			goto LABEL_14;
		}
	}
	else
	{
		a2 = (double)rand() * 0.000030517578125;
		if (a2 >= (double)0.15f)
		{
			v4 = 119;
			if (a2 >= 0.60000002)
			{
				v4 = 106;
			}
		}
		else
		{
			v4 = 118;
		}
		//Chao_PlayAnimationSpeed(&v1->Data1.Chao->MotionTable, v4, 0xAu);
		AL_SetMotionLinkStep(a1, v4, 0xA);
		rand();
		AL_FaceSetEye(v1, 4, -1);
		if ((double)rand() * 0.000030517578125 >= 0.4000000059604645)
		{
			AL_FaceSetMouth(v1, 3, -1);
		}
		else
		{
			AL_FaceSetMouth(v1, 1, -1);
		}
		AL_IconSet(a1, 1, 120);
		++v3->Behavior.Mode;
		v3->Behavior.Timer = 0;
	}
	v5 = ALO_BallPtr;
	if (ALO_BallPtr)
	{
		v6 = ALO_BallPtr->Data1;
		v7 = v6->Position.x * 1.019999980926514;
		v8 = v6->Position.y;
		v9 = 1.019999980926514 * v6->Position.z;
		Waypoint = &v2->AimPos;
		Waypoint->x = v7;
		v11 = v9;
		Waypoint->y = v8;
		Waypoint->z = v11;
		if ((ALO_BallPtr->Data1->Status & 0x1000))
		{
			goto LABEL_19;
		}
	}
LABEL_14:
	if (!(++v3->Behavior.Timer % 100) && (double)rand() * 0.000030517578125 < 0.1500000059604645)
	{
		AL_SetBehavior(a1, ALBHV_Koke);
	}
	if (dword_1DBE56C)
	{
		AL_IconSet(a1, 5, 240);
		goto LABEL_19;
	}
	MOV_TurnToAim2(v1, 384);
	if (v2->Flag & 0x400)
	{
		v14 = AL_ParameterGetSkill(a1, 2);
		a2a = 0.000007f * (double)v14 + 0.028f;
		v2->Acc.x = njSin(a1->Data1->Rotation.y) * a2a;
		v2->Acc.z = njCos(a1->Data1->Rotation.y) * a2a;
	}
	if (!v3->pParamGC->Emotion.Timer)
	{
		v3->pParamGC->Emotion.Timer = 1;
		AL_EmotionAdd(a1, EM_ST_TIRE, 300);
		AL_EmotionAdd(a1, EM_ST_TEDIOUS, 100);
	}
	if (v3->Behavior.Timer > 3000 || AL_EmotionGetValue(a1, EM_ST_TEDIOUS) < 1000u || AL_EmotionGetValue(a1, EM_ST_TIRE) > 7000u)
	{
	LABEL_19:
		ALW_CommunicationOff(a1);
		return 1;
	}
	return 0;
}
FunctionPointer(signed int, AL_CheckWhistle,(ObjectMaster* a1),0x0073B770);
signed int sub_563B70(ObjectMaster* a1)
{
	chaowk* v1; // eax
	ChaoDataBase* v2; // esi
	int v3; // eax
	int retval = 0;
	if (AL_CheckWhistle(a1))
		retval = 1;
	if (!BallUsable)
	{
		return retval;
	}
	v1 = (chaowk*)a1->Data1;
	v2 = v1->pParamGC;
	if (AL_EmotionGetValue(a1, EM_ST_TEDIOUS) <= 4000u
		|| CheckDistance(&v1->entity.Position, &ALO_BallPtr->Data1->Position) >= 50.0)
	{
		return retval;
	}
	AL_EmotionAdd(a1, EM_ST_TEDIOUS, -2000);
	AL_SetBehavior(a1, sub_563830);
	return 1;
}
#include "..//chao.h"
#include "..//data/toy/alm_box.njm"
#include "..//data/toy/object_al_toy_box.nja"
void __cdecl ALO_BoxExecutor_Main(ObjectMaster* a1)
{
	double v1; // st7
	ObjectMaster* v2; // esi
	EntityData1* v3; // ebp
	ObjectMaster* v4; // eax
	int v5; // eax
	double v6; // st6
	__int16 v7; // ax
	char v8; // al
	double v9; // st7
	double v10; // st7
	float a1a; // [esp+24h] [ebp+4h]
	Float a1b; // [esp+24h] [ebp+4h]
	float a1c; // [esp+24h] [ebp+4h]
	Float a1d; // [esp+24h] [ebp+4h]
	
	v1 = 0.0;
	v2 = a1;
	v3 = a1->Data1;
	switch (v3->Action)
	{
	case 0:
		v4 = ALOField_Find2(a1->Data1, 0xAF);
		if (v4)
		{
			if (v4->Parent)
			{
				if ((double)rand() * 0.000030517578125 < 0.5)
				{
					v3->Scale.y = 0.0099999998;
					v3->Scale.z = 0.0;
					v3->Scale.x = 0.0;
				}
				CCL_Disable(a1->Data1, 1);
				v3->Action = 1;
				v3->NextAction = 0;
				v3->InvulnerableTime = 0;
				v3->Index = 0;
				v3->InvulnerableTime = 30 - (signed int)((double)rand() * 0.000030517578125 * -121.0);
				v1 = 0.0;
			}
		}
		break;
	case 1:
		if (!--v3->InvulnerableTime)
		{
			//if (CurrentChaoArea == NextChaoArea)
			{
				//SE_CallV2(4138, &v3->Position, 0, 0, 0);
				v1 = 0.0;
				v2 = a1;
			}
			v3->Action = 2;
			v3->NextAction = 0;
			v3->InvulnerableTime = 0;
			v3->Index = 0;
		}
		break;
	case 2:
		a1a = v3->Scale.x + 0.300000011920929;
		v3->Scale.x = a1a;
		if (!v3->NextAction && a1a > 1.0)
		{
			if (v3->Scale.y > 0.0)
			{
				j_ALOField_Load2(162, &v3->Position, 5.0, 2);
				v1 = 0.0;
			}
			v3->NextAction = 1;
		}
		v6 = (double)stru_121C9AC.nbFrame - 1.0;
		if (v3->Scale.x > v6)
		{
			v3->Scale.x = v6;
			v3->Action = 3;
			v3->NextAction = 0;
			v3->InvulnerableTime = 0;
			v3->Index = 0;
		}
		break;
	case 3:
		v7 = v3->InvulnerableTime;
		v3->InvulnerableTime = v7 + 1;
		if ((unsigned __int16)v7 > 60u)
		{
			v3->Action = 4;
			v3->NextAction = 0;
			v3->InvulnerableTime = 0;
			v3->Index = 0;
		}
		break;
	case 4:
		a1b = v3->Scale.x - 0.1000000014901161;
		v3->Scale.x = a1b;
		if (a1b < 0.0)
		{
			v3->Scale.x = 0.0;
			v3->Scale.y = 0.0;
			v3->Scale.z = 0.0;
			v3->Rotation.x = 0;
			v3->Rotation.z = 0;
			v3->Action = 0;
			v3->NextAction = 0;
			v3->InvulnerableTime = 0;
			v3->Index = 0;
		}
		break;
	default:
		break;
	}
	v8 = v3->Action;
	if (v3->Action < 2)
	{
		goto LABEL_32;
	}
	if (v8 <= 3)
	{
		if (v1 < v3->Scale.y)
		{
			v10 = v3->Scale.y;
			v3->Rotation.x += 4096;
			v3->Rotation.z += 4864;
			a1c = (5.0 - v10) * 0.1500000059604645 + v3->Scale.z;
			a1d = a1c * 0.9599999785423279;
			v3->Scale.z = a1d;
			v3->Scale.y = a1d + v3->Scale.y;
			Chao_AddToCollisionList(v2);
			a1->DisplaySub(a1);
			return;
		}
		goto LABEL_32;
	}
	if (v8 != 4)
	{
	LABEL_32:
		Chao_AddToCollisionList(v2);
		a1->DisplaySub(a1);
		return;
	}
	if (v1 >= v3->Scale.y || v3->Scale.x >= 10.0)
	{
		v3->Rotation.x += 4096;
		v3->Rotation.z += 4864;
		Chao_AddToCollisionList(v2);

	}
	else
	{
		v3->Rotation.x += 4096;
		v3->Scale.z = v1;
		v9 = v3->Scale.y;
		v3->Rotation.z += 4864;
		v3->Scale.y = v9 * 0.800000011920929;
		Chao_AddToCollisionList(v2);
	}
	a1->DisplaySub(a1);
}
VoidFunc(_before_cnk, 0x00720A10);
VoidFunc(sub_7801E0, 0x007801E0);
VoidFunc(sub_7801F0, 0x007801F0);
VoidFunc(_after_cnk, 0x00720A40);
FunctionPointer(void, sub_789690, (NJS_CNK_OBJECT* a1, NJS_MOTION* a2, float a3), 0x789690);
void __cdecl sub_720A70(NJS_CNK_OBJECT* a1, NJS_MOTION* a2, float a3)
{
	_before_cnk();
	sub_7801F0();
	sub_789690(a1, a2, a3);
	sub_7801F0();
	_after_cnk();
}
void ALO_BoxExecutor_Display(ObjectMaster* a1)
{
	if (ScaleObjectMaster_XYZ(a1, 2.5, 2.5, 1.0))
	{
		njSetTexture(&AL_TOY_TEXLIST);
		njPushMatrixEx();
		{
			njTranslateV(0, &a1->Data1->Position);
			njRotateY(0, a1->Data1->Rotation.y);
			njPushMatrixEx();
			{
				njTranslate(0, 0, 0, 3);
				njRotateY(0, 0x8000);
				if (a1->Data1->Scale.x >= 0.01)
				{
					sub_720A70(&object_00E1B204, &stru_121C9AC, a1->Data1->Scale.x);
					//if frame is not 0 animate
				}
				else
				{
					njCnkDrawObject(&object_00E1B204);
					//if frame very small render default pose
				}
			}
			njPopMatrixEx();
			if (a1->Data1->Scale.x >= 0.01)
			{
				float v8 = njSin(a1->Data1->Rotation.x) * 30.0 * 182.0444488525391;
				float v14 = njSin(a1->Data1->Rotation.z) * 30.0 * 182.0444488525391;
				float v10 = 0;
				if (a1->Data1->Scale.y >= 2.0)
				{
					v10 = 1.5;
				}
				else
				{
					v10 = a1->Data1->Scale.y * 0.5 + 0.5;
				}
				njPushMatrixEx();
				njTranslate(0, 0, a1->Data1->Scale.y, 0);
				njRotateX(0, v8);
				njRotateZ(0, v14);
				njRotateY(0, 0x8000);
				njScale(0, v10, v10, v10);
				DrawCnkModel(&stru_121D264);
				njPopMatrixEx();
			}
		}
		njPopMatrixEx();
	}
}
void __cdecl Box_Delete(ObjectMaster* a1)
{
	ChaoData1* v1; // eax

	ALW_CancelEntry(a1);

	if (a1->Data2)
	{
		HeapFreeSADX(a1->Data2);
		a1->Data2 = 0;
	}
	if (a1->UnknownB_ptr)
	{
		HeapFreeSADX(a1->UnknownB_ptr);
		a1->UnknownB_ptr = 0;
	}
}
CollisionData boxCollision = { '\0', '\0', 'w', '\f', 32768u, { 0.0, 1.6, 0.0 }, 1.6, 0.0, 0.0, 0.0, 0, 0, 0 };
void ALO_BoxExecutor_Load_(ObjectMaster* a1)
{
	a1->MainSub = ALO_BoxExecutor_Main;
	a1->DeleteSub = ALW_CancelEntry;
	AddToGlobalChaoThingMaybe(6, a1, 8, 0);
}
void ALO_BoxExecutor_Load(NJS_VECTOR* pos)
{
	ObjectMaster* box = LoadObject(LoadObj_Data1, 4, ALO_BoxExecutor_Load_);
	box->DisplaySub = ALO_BoxExecutor_Display;
	Collision_Init(box, &boxCollision, 1, 4);

	box->Data1->Position = *pos;
	box->Data1->Scale.x = 0;
	box->Data1->Scale.y = 0;
	box->Data1->Scale.z = 0;
	box->Data1->Rotation.y = 0x4000;
	box->Data1->Rotation.x = 0;
	box->Data1->Rotation.z = 0;
}
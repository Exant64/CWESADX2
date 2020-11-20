
#include "alo_ball.h"
#include "..//motiontable.h"
#include "..//chao.h"
struct BALL_WORK
{
	float inv_radius;
	int HeldAng;
	int RotSpd;
	NJS_POINT3 axis;
	NJS_MATRIX mat;
};
ObjectMaster* ALO_BallPtr;

double sub_77FC90(NJS_VECTOR* a1, NJS_VECTOR* a2 , NJS_VECTOR* a3)
{
	float v3; // ST04_4
	double v4; // st7
	float v5; // ST04_4
	Float v6; // ST08_4
	float v7; // ST04_4
	double v8; // st7
	float v9; // ST04_4
	Float v10; // ST0C_4
	float v11; // ST04_4
	double v12; // st7
	float v13; // ST04_4
	Float v14; // ST04_4
	float v15; // ST08_4
	float v16; // ST0C_4
	float v17; // ST04_4
	long double v18; // st7
	float v20; // [esp+Ch] [ebp-4h]

	v3 = a3->y * a1->z;
	v4 = v3;
	v5 = a3->z * a1->y;
	v6 = v4 - v5;
	v7 = a1->x * a3->z;
	v8 = v7;
	v9 = a3->x * a1->z;
	v10 = v8 - v9;
	v11 = a3->x * a1->y;
	v12 = v11;
	v13 = a1->x * a3->y;
	v14 = v12 - v13;
	a2->x = v6;
	a2->y = v10;
	a2->z = v14;
	v15 = v6 * v6;
	v16 = v10 * v10;
	v17 = v14 * v14;
	v18 = v16 + v15 + v17;
	if (v18 <= 0.0)
	{
		v20 = sqrt(0.0);
	}
	else
	{
		v20 = sqrt(v18);
	}
	return v20;
}
int dword_1DBE56C;
int BallUsable;

void sub_55CC40(ObjectMaster* a1)
{
	EntityData1* data1 = a1->Data1;
	MOVE_WORK* move = (MOVE_WORK*)a1->Data2;
	BALL_WORK* ball = (BALL_WORK*)a1->UnknownB_ptr;
	if (!data1->NextAction)
	{
		CCL_Enable(data1, 0);
		CCL_Enable(data1, 1);
		CCL_Disable(data1, 2);
		data1->NextAction++;
	}
	if (data1->Status >= 0)
	{
		if (data1->CollisionInfo)
		{
			if (data1->CollisionInfo->flag & 4)
			{
				data1->Action = 1;
				data1->NextAction = 0;
			}
		}
	}
	else
	{
		data1->Action = 2;
		data1->NextAction = 0;
	}
}
void sub_55CCC0(ObjectMaster *a1)
{
	EntityData1* data1 = a1->Data1;
	MOVE_WORK* move = (MOVE_WORK*)a1->Data2;
	BALL_WORK* ball = (BALL_WORK*)a1->UnknownB_ptr;
	if (!data1->NextAction)
	{
		CCL_Enable(data1, 0);
		CCL_Enable(data1, 1);
		CCL_Disable(data1, 2);
		data1->NextAction++;
	}
	NJS_VECTOR v54, a1_thing;
	if (data1)
	{
		if (data1->CollisionInfo)
		{
			if (data1->CollisionInfo->flag & 4)
			{
				v54.x = data1->Position.x - move->PrePos.x;
				v54.y = data1->Position.y - move->PrePos.y;
				v54.z = data1->Position.z - move->PrePos.z;
				a1_thing = v54;
				if (njScalor(&a1_thing) >= 0.0099999998)
				{
					njUnitVector(&a1_thing);
				}
				float v12, v13, v14, v15, v16, v17, v18, v19, v20, v53, v21, v22, v23, v24, v25, v49;
				v12 = a1_thing.x;
				v13 = move->Velo.x * a1_thing.x;
				v14 = v13;
				v15 = a1_thing.y;
				v16 = a1_thing.y * move->Velo.y;
				v17 = v14 + v16;
				v18 = move->Velo.z * a1_thing.z;
				v19 = v17 + v18;
				v20 = a1_thing.z;
				v53 = v19;
				v21 = a1_thing.y * v54.y;
				v22 = v21;
				v23 = a1_thing.x * v54.x;
				v24 = v22 + v23;
				v25 = a1_thing.z * v54.z;
				v49 = v24 + v25;
				if (v53 < (double)v49)
				{
					float v50 = (v49 - v53) * 1.1f;
					if (ALOField_Find(a1, 1, 0x81))
					{
						v50 = v50 * 2.9f;
						move->Velo.y = move->Velo.y + 0.28f;
					}
					float v26;
					if (v50 <= 1.0)
					{
						v26 = v50;
					}
					else
					{
						v26 = 1.0f;
					}
					move->Velo.x = v12 * v26 + move->Velo.x;
					move->Velo.y = v15 * v26 + move->Velo.y;
					move->Velo.z = v20 * v26 + move->Velo.z;
				}
				
			}
		}
	}
	if (data1->Position.y < move->WaterY + 1.5)
	{
		if (move->WaterY - 1.5 >= data1->Position.y)
		{
			move->Acc.y = move->Acc.y - (move->Gravity + move->Gravity);
		}
		else
		{
			move->Acc.y = (move->WaterY - data1->Position.y + 1.5) * -move->Gravity * 0.6666666865348816 + move->Acc.y;
		}
		move->Velo.x = move->Velo.x * 0.9750000238418579;
		move->Velo.y = move->Velo.y * 0.9300000071525574;
		move->Velo.z = 0.9750000238418579 * move->Velo.z;
		ball->RotSpd = (signed int)((double)ball->RotSpd * 0.0054931640625 * 0.9599999785423279 * 182.0444488525391);
		dword_1DBE56C = 1;
	}
	MOV_Control(a1);
	move->PrePos = data1->Position;
	MOV_DetectCollision(a1);
	if (data1->Status & 1)
	{
		move->Velo.x = move->Velo.x * 0.9900000095367432;
		move->Velo.z = 0.9900000095367432 * move->Velo.z;
		float v33 = njScalor(&move->Velo);
		if (v33 <= 0.00009999999747378752)
		{
			ball->RotSpd = 0;
		}
		else
		{
			
			a1_thing.x = 0.0;
			a1_thing.y = 1.0;
			a1_thing.z = 0.0;
			sub_77FC90(&move->Velo, &ball->axis, &a1_thing);
			if (njScalor(&ball->axis) <= 0.0)
			{
				ball->axis.x = 0.0;
				ball->axis.y = 1.0;
				ball->axis.z = 0.0;
			}
			else
			{
				njUnitVector(&ball->axis);
			}
			float v38 = move->Velo.x * 0.0;
			float v39 = v38 + move->Velo.y;
			float v40 = move->Velo.z * 0.0;
			float v41 = v39 + v40;
			float v42 = v41;
			float v43 = 0.0 * v41;
			a1_thing.x = v43;
			a1_thing.z = v43;
			a1_thing.y = v42;
			v54.x = move->Velo.x - v43;
			v54.y = move->Velo.y - a1_thing.y;
			v54.z = move->Velo.z - v43;
			ball->RotSpd = (signed int)(njScalor(&v54) * ball->inv_radius * 10430.38043493439);
		}
	}
	if (ball->RotSpd)
	{
		NJS_MATRIX mat;
		njUnitMatrix(mat);
		njRotate(mat, &ball->axis, ball->RotSpd);
		njMultiMatrix(mat, ball->mat);
		memcpy(ball->mat, mat, sizeof(NJS_MATRIX));
		
	}
	if (data1->Status & 0x1000)
	{
		ball->RotSpd = 0;
		data1->Action = 2;
		data1->NextAction = 0;
	}
}
void sub_55D150(ObjectMaster* a1)
{
	EntityData1* data1 = a1->Data1;
	MOVE_WORK* move = (MOVE_WORK*)a1->Data2;
	BALL_WORK* ball = (BALL_WORK*)a1->UnknownB_ptr;
	if (!data1->NextAction)
	{
		CCL_Disable(data1, 0);
		CCL_Disable(data1, 1);
		CCL_Enable(data1, 2);
		move->AimAng.y = data1->Rotation.y + Current_CharObj1->Rotation.y;
		ALW_CommunicationOff(a1);
		data1->NextAction++;
	}
	data1->Rotation.y = move->AimAng.y - Current_CharObj1->Rotation.y;
	if(!(data1->Status & 0x1000))
	{ 
		move->Velo.x = move->Velo.x * 0.4f;
		move->Velo.y = move->Velo.y * 0.7f;
		move->Velo.z = move->Velo.z * 0.4f;
		move->Acc.x = 0;
		move->Acc.y = 0;
		move->Acc.z = 0;
		move->PrePos = data1->Position;
		data1->Action = 1;
		data1->NextAction = 0;
	}
}
void sub_55D230(ObjectMaster* a1)
{
	EntityData1* data1 = a1->Data1;
	MOVE_WORK* move = (MOVE_WORK*)a1->Data2;
	BALL_WORK* ball = (BALL_WORK*)a1->UnknownB_ptr;
	int command = ALW_RecieveCommand(a1);
	if (!data1->NextAction)
	{
		CCL_Disable(data1, 0);
		CCL_Disable(data1, 1);
		CCL_Disable(data1, 2);
		data1->InvulnerableTime = 0;
		data1->NextAction++;
	}
	if(command == 2)
	{
		++data1->InvulnerableTime;
		if (data1->InvulnerableTime >= 180)
		{
			data1->InvulnerableTime = 0;
			//if index-- == 1, index is never set to anything though afaik so idk whats up here
			ALW_SendCommand(a1, 4);
			CheckThingButThenDeleteObject(a1);
		}
	}
	else if (command == 3)
	{
		data1->Action = 1;
		data1->NextAction = 0;
	}
	if (!AL_TraceHoldingPosition(a1))
	{
		data1->Action = 1;
		data1->NextAction = 0;
	}
}
void Ball_Main(ObjectMaster* a1)
{
	MotionTableEntry* v1; // esi
	EntityData1* v2; // edi
	int v4; // ecx

	
	EntityData1* data1 = a1->Data1;
	MOVE_WORK* move = (MOVE_WORK*)a1->Data2;
	BALL_WORK* ball = (BALL_WORK*)a1->UnknownB_ptr;

	v2 = (EntityData1*)a1->Data1;
	dword_1DBE56C = 0;
	move->Flag |= 4;
	switch (v2->Action)
	{
	case 0:
		sub_55CC40(a1);
		break;
	case 1:
		sub_55CCC0(a1);
		break;
	case 2:
		sub_55D150(a1);
		break;
	case 3:
		sub_55D230(a1);
		break;
	}
	float v5;
	if (v2->Action != 1 || (v5 = njScalor(&move->Velo), BallUsable = 1, v5 <= 0.4000000059604645))
	{
		BallUsable = 0;
	}
	Chao_AddToCollisionList(a1);
	a1->DisplaySub(a1);
}
void Ball_Display(ObjectMaster* a1)
{
	BALL_WORK* ball = (BALL_WORK*)a1->UnknownB_ptr;

	if (ScaleObjectMaster_XYZ(a1, 3.0f, 3.0f, 1.0f)) {
		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);
		njControl3D_Add(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);

		njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y + 1, a1->Data1->Position.z);
		njMultiMatrix(0, ball->mat);
		if(CurrentChaoStage == 4)
			njCnkDrawObject((NJS_CNK_OBJECT*)0x036ADE9C);
		else if (CurrentChaoStage == 6)
			njCnkDrawObject((NJS_CNK_OBJECT*)0x36AE5D4);
		else if (CurrentChaoStage == 5)
			njCnkDrawObject((NJS_CNK_OBJECT*)0x36AEC8C);
		//0x36AE5D4 - hero
		//0x36AEC8C - dark
		njControl3D_Remove(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njPopMatrixEx();
	}
}
void __cdecl Ball_Delete(ObjectMaster* a1)
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
void Ball_Load(ObjectMaster* a1)
{
	ObjectFunc(ALO_Delete, 0x71A6B0);
	AddToGlobalChaoThingMaybe(6, a1, 4, 0);
	a1->DeleteSub = Ball_Delete;
	a1->MainSub = Ball_Main;
	a1->DisplaySub = Ball_Display;
	a1->Data1->Action = 1;
	a1->Data1->NextAction = 0;
}
//CollisionData ballCollision = { 0, 0xC77, 0, 0,{ 0,1.2,0},{2,0,0},  0,0 };
CollisionData ALO_Ball_collision[3] =
{
 {'\0','\x01','p','\0',9216u,{0.0,1.5,0.0},5,3.0,0.0,0.0,0,0,0},
 {'\0','\0','\x06','\f',0u,{0.0,0.0,0.0},2.0,0,0,0.0,0,0,0},
 {'\xA0','\x01','p','\f',0u,{0.0,-2.0,0.0},4.2,6.0,1.0,0.0,0,0,0}
};
FunctionPointer(int, ObjectMovableInitialize, (EntityData1* data1, MOVE_WORK* data2, int n),0x0049CDA0);
void CreateBall(NJS_VECTOR* pos, NJS_VECTOR* vel)
{
	ObjectMaster* piano;
	EntityData1* pianoData;

	piano = LoadObject(LoadObj_Data1, 3, Ball_Load);
	Collision_Init(piano, ALO_Ball_collision, 3, 5);
	piano->UnknownB_ptr = (BALL_WORK*)HeapAllocateThing(sizeof(BALL_WORK));
	MOVE_WORK* move = (MOVE_WORK*)AllocateChaoData2(piano);
	EntityData1* data1 = piano->Data1;
	BALL_WORK* ball = (BALL_WORK*)piano->UnknownB_ptr;

	ball->inv_radius = 0.66666669f;
	ball->HeldAng = 0;
	ball->RotSpd = 0;
	ball->axis = { 0,0,0 };
	njUnitMatrix(ball->mat);

	ObjectMovableInitialize(data1, move, 4);
	data1->Position = *pos;
	move->Velo = *vel;
	move->Gravity = -0.05f;
	move->Top = 1.5f;
	move->Bottom = -2.5f;
	move->BoundFloor = 0.85f;
	move->Offset.y = 1.0f;
	move->BoundFriction = 0.99f;
	move->work.l = 0;
	move->PrePos = data1->Position;
	dword_1DBE56C = 0;
	
	ALO_BallPtr = piano;
	pianoData = piano->Data1;
	if (pianoData)
	{
		pianoData->Action = 0;
		
		pianoData->Rotation.y = 12800;
		pianoData->Scale.x = 1;
		pianoData->Scale.y = 1;
		pianoData->Scale.z = 1;
		
		//SetCollisionInfoRadius(radio->Data1->CollisionInfo, 20.0);


	}
}

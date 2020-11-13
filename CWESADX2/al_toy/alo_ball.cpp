
#include "alo_ball.h"
#include "..//motiontable.h"
#include "..//chao.h"
void Ball_Main(ObjectMaster* a1)
{
	MotionTableEntry* v1; // esi
	EntityData1* v2; // edi
	int v4; // ecx
	ObjectMaster* v5; // eax


	v2 = (EntityData1*)a1->Data1;
	if (ALOField_Find(a1, 0, 233))
		a1->Data1->Status += 1000;

	Chao_AddToCollisionList(a1);

	a1->DisplaySub(a1);
}
void Ball_Display(ObjectMaster* a1)
{

	if (ScaleObjectMaster_XYZ(a1, 3.0f, 3.0f, 1.0f)) {
		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);
		njControl3D_Add(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);

		njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y + 1, a1->Data1->Position.z);
		njRotateZ(0, a1->Data1->Status);
		njScale(0, 1, 1, 1);
		njCnkDrawObject((NJS_CNK_OBJECT*)0x36AE5D4);

		njControl3D_Remove(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njPopMatrixEx();
	}
}
void Ball_Load(ObjectMaster* a1)
{
	ObjectFunc(ALO_Delete, 0x71A6B0);
	AddToGlobalChaoThingMaybe(6, a1, 5, 0);
	a1->DeleteSub = ALO_Delete;
	a1->MainSub = Ball_Main;
	a1->DisplaySub = Ball_Display;
}
//CollisionData ballCollision = { 0, 0xC77, 0, 0,{ 0,1.2,0},{2,0,0},  0,0 };
CollisionData ALO_Ball_collision[3] =
{
 {'\0','\x01','p','\0',9216u,{0.0,1.5,0.0},15.0,3.0,0.0,0.0,0,0,0},
 {'\0','\0','\x06','\f',0u,{0.0,0.0,0.0},5.0,1.0,1.0,0.0,0,0,0},
 {'\xA0','\x01','p','\f',0u,{0.0,-2.0,0.0},5.1999998,6.0,1.0,0.0,0,0,0}
};

void CreateBall()
{
	ObjectMaster* piano;
	EntityData1* pianoData;

	piano = LoadObject(LoadObj_Data1, 3, Ball_Load);



	pianoData = piano->Data1;
	if (pianoData)
	{
		pianoData->Action = 0;
		if (!GetModuleHandle(L"DCMods_Main")) {
			pianoData->Position.x = -64;
			pianoData->Position.y = 2;
			pianoData->Position.z = 213;
		}
		else
		{
			pianoData->Position.x = -107;
			pianoData->Position.y = 2;
			pianoData->Position.z = 132.6;
		}
		pianoData->Rotation.y = 12800;
		pianoData->Scale.x = 1;
		pianoData->Scale.y = 1;
		pianoData->Scale.z = 1;
		Collision_Init(piano, ALO_Ball_collision, 3, 5);
		//SetCollisionInfoRadius(radio->Data1->CollisionInfo, 20.0);


	}
}

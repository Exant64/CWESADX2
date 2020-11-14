#pragma once
#include "../SADXModLoader.h"
#include "..//chao.h"
#include "../data/toy/alo_float.nja"
enum
{
	MD_FLOAT_IDLE,
	MD_FLOAT_PICKEDUP,
	MD_FLOAT_SWIM,
	MD_FLOAT_FLY_UP,
	MD_FLOAT_FLY_DOWN_START,
	MD_FLOAT_FLY_DOWN
};
//extern NJS_OBJECT object_00F005A0;
void ALO_Float_Displayer_(ObjectMaster* a1)
{
	if (a1->Data1->field_A) 
	{
		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);

		njControl3D_Backup();

		njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
		njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);

		//EnableChunkMaterialFlags();
		//DisableChunkMaterialFlags();
		//SetChunkMaterialFlags(8);
		//SetChunkTextureIndexA(117);
		//SetChunkTextureIndexB(117);
		//*(int*)0x03D0856C = 0xFFFFFFFF;
		//*(unsigned char*)0x03D0856F = (255 - (a1->Data1->Rotation.x / 335.0f) * 255.0f);
		//*(float*)0x3D0857C = -0.5f;
		njRotateY(0, a1->Data1->Rotation.y);
		njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z - 2.65);
		
		njCnkDrawObject((NJS_CNK_OBJECT*)0x0389A900);//0x03898530 - coffin
		//njCnkDrawObject(&object_0349A900);
		njPopMatrixEx();

		//DisableChunkMaterialFlags();
		njControl3D_Restore();
	}
}
FunctionPointer(float, CalcCamDist,(ObjectMaster* a1),0x00736460);
void ALO_Float_Displayer(ObjectMaster* a1)
{
	float a3 = -1.0 - CalcCamDist(a1) * 0.000099999997;
	DrawModelCallback_Queue((void(__cdecl*)(void*))ALO_Float_Displayer_, a1, a3, QueuedModelFlagsB_EnableZWrite);
}

void ALO_Float_Main(ObjectMaster* a1)
{
	//if (ALW_RecieveCommand(a1) == ALW_CMD_CHANGE)
		//a1->Data1->Action = MD_FLOAT_FLY_UP;
	switch (a1->Data1->Action)
	{
	case MD_FLOAT_IDLE:
		CCL_Enable(a1->Data1, 0);
		if (ALW_IsHeld(a1))
		{
			a1->Data1->Action = MD_FLOAT_PICKEDUP;

		}
		break;
	case MD_FLOAT_PICKEDUP:
		CCL_Disable(a1->Data1, 0);
		if (!AL_TraceHoldingPosition(a1))
		{
			a1->Data1->Action = MD_FLOAT_IDLE;
		}
		break;
	case MD_FLOAT_FLY_UP:
		a1->Data1->field_A = 1;
		a1->Data1->Position.y += 0.15f;
		a1->Data1->Rotation.y += 4096;
		a1->Data1->Rotation.x += 5;

		if (a1->Data1->Rotation.x > 335)
			a1->Data1->Rotation.x = 335;

		if (a1->Data1->Position.y > 10)
		{
			a1->Data1->Position.y = 10;
			a1->Data1->Action = MD_FLOAT_FLY_DOWN_START;
		}
		break;
	case MD_FLOAT_FLY_DOWN_START:
		a1->Data1->Position = a1->Data1->Scale;
		a1->Data1->Position.y = 10;
		a1->Data1->Action = MD_FLOAT_FLY_DOWN;
		break;
	case MD_FLOAT_FLY_DOWN:
		a1->Data1->Position.y -= 0.15f;
		a1->Data1->Rotation.y -= 4096;
		a1->Data1->Rotation.x -= 5;
		if (a1->Data1->Rotation.x < 0)
			a1->Data1->Rotation.x = 0;
		if (a1->Data1->Position.y <= a1->Data1->Scale.y)
		{
			a1->Data1->Position.y = a1->Data1->Scale.y;
			a1->Data1->Action = MD_FLOAT_IDLE;
		}
		break;
	}
	ALO_Float_Displayer(a1);
	AddToCollisionList(a1->Data1);
}
CollisionData floatColl  = { '\0', '\0', 'w', '\f', 32768u, { 0.0, 0.0, 0.0 }, 2.0, 0.0, 0.0, 0.0, 0, 0, 0 };
void ALO_Float_Load(ObjectMaster* a1)
{
	a1->MainSub = ALO_Float_Main;
	Collision_Init(a1, &floatColl, 1, 4);
	AddToGlobalChaoThingMaybe(6, a1, 2, 0);
}

void ALO_Float_Create(NJS_VECTOR* a1, int rotY)
{
	ObjectMaster* p = LoadObject(LoadObj_Data1, 4, ALO_Float_Load);


	p->DisplaySub = ALO_Float_Displayer;
	p->Data1->field_A = 1; //enable display
	p->Data1->Position = *a1;
	p->Data1->Rotation.y = rotY;
	p->Data1->Scale = p->Data1->Position; //scale = default pos
	//p->Data1->Position = { 10,0,0 };

}
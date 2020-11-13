#pragma once
#include "../SADXModLoader.h"
#include "..//chao.h"
enum 
{
	MD_BOAT_IDLE,
	MD_BOAT_PICKEDUP,
	MD_BOAT_SWIM,
	MD_BOAT_FLY_UP,
	MD_BOAT_FLY_DOWN_START,
	MD_BOAT_FLY_DOWN
};

void ALO_Boat_Displayer(ObjectMaster *a1)
{
	njPushMatrixEx();
	njSetTexture(&AL_TOY_TEXLIST);

	njControl3D_Backup();

	njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);

	EnableChunkMaterialFlags();
	SetChunkMaterialFlags(8);

	*(int*)0x03D0856C = 0xFFFFFFFF;
	*(unsigned char*)0x03D0856F = ( 255 - (a1->Data1->Rotation.x / 335.0f) * 255.0f);

	njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
	njRotateY(0, a1->Data1->Rotation.y);
	njCnkDrawObject((NJS_CNK_OBJECT*)0x03897AC0);
	njPopMatrixEx();

	DisableChunkMaterialFlags();
	njControl3D_Restore();
}
FunctionPointer(void, CCL_Enable, (EntityData1* a1, int a2), 0x41C1F0);
FunctionPointer(void, CCL_Disable, (EntityData1* a1, int a2), 0x041C220);
void ALO_Boat_Main(ObjectMaster *a1)
{
	if (ALW_RecieveCommand(a1) == ALW_CMD_CHANGE) 
	{
		ALW_CommunicationOff(a1);
		a1->Data1->Action = MD_BOAT_FLY_UP;
	}
//	PrintDebug("DUCK COMMU %d\n", (int)((al_entry_work*)a1->UnknownA_ptr)->pCommu);
	//PrintDebug("DUCK LOCKON %d\n", (int)ALW_GetLockOnTask(a1));
	switch (a1->Data1->Action)
	{
	case MD_BOAT_IDLE:
		CCL_Enable(a1->Data1,0);
		if (ALW_IsHeld(a1))
		{
			a1->Data1->Action = MD_BOAT_PICKEDUP;

		}
		break;
	case MD_BOAT_PICKEDUP:
		CCL_Disable(a1->Data1, 0);
		if (!AL_TraceHoldingPosition(a1))
		{
			a1->Data1->Action = MD_BOAT_IDLE;
		}
		break;
	case MD_BOAT_FLY_UP:
		a1->Data1->Position.y += 0.15f;
		a1->Data1->Rotation.y += 4096;
		a1->Data1->Rotation.x += 5;

		if(a1->Data1->Rotation.x > 335)
			a1->Data1->Rotation.x = 335;

		if (a1->Data1->Position.y > 10)
		{
			a1->Data1->Position.y = 10;
			a1->Data1->Action = MD_BOAT_FLY_DOWN_START;
		}
		break;
	case MD_BOAT_FLY_DOWN_START:
		a1->Data1->Position = a1->Data1->Scale;
		a1->Data1->Position.y = 10;
		a1->Data1->Action = MD_BOAT_FLY_DOWN;
		break;
	case MD_BOAT_FLY_DOWN:
		a1->Data1->Position.y -= 0.15f;
		a1->Data1->Rotation.y -= 4096;
		a1->Data1->Rotation.x -= 5;
		if (a1->Data1->Rotation.x < 0)
			a1->Data1->Rotation.x = 0;
		if (a1->Data1->Position.y <= a1->Data1->Scale.y) 
		{
			a1->Data1->Position.y = a1->Data1->Scale.y;
			a1->Data1->Action = MD_BOAT_IDLE;
		}
		break;
	}
	ALO_Boat_Displayer(a1);
	AddToCollisionList(a1->Data1);
}
CollisionData boatColl = { '\0', '\0', 'w', '\f', 32768u, { 0.0, 0.0, 0.0 }, 2.0, 0.0, 0.0, 0.0, 0, 0, 0 };
void ALO_Boat_Load(ObjectMaster *a1)
{
	a1->MainSub = ALO_Boat_Main;
	Collision_Init(a1, &boatColl, 1, 4);
	AddToGlobalChaoThingMaybe(6, a1, 2, 0);
}

void ALO_Boat_Create(NJS_VECTOR *a1, int rotY)
{
	ObjectMaster* p = LoadObject(LoadObj_Data1, 4, ALO_Boat_Load);
	
	p->DisplaySub = ALO_Boat_Displayer;
	p->Data1->Position = *a1;
	p->Data1->Rotation.y = rotY;
	p->Data1->Scale = p->Data1->Position; //scale = default pos
	//p->Data1->Position = { 10,0,0 };
	
}
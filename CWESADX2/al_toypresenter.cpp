#include "al_toypresenter.h"
#include "chao.h"
extern NJS_OBJECT object_00E1B204;

extern NJS_OBJECT object_00E1AA0C;
NJS_OBJECT* objectsL[] = { &TVTest , (NJS_OBJECT*)0x389B3E4, &object_00E1B204, (NJS_CNK_OBJECT*)0x036ADE9C, (NJS_CNK_OBJECT*)0x36AE5D4, (NJS_CNK_OBJECT*)0x36AEC8C, &object_00E1AA0C, (NJS_CNK_OBJECT*)0x36AEC8C ,(NJS_CNK_OBJECT*)0x36AEC8C ,(NJS_CNK_OBJECT*)0x36AEC8C };
NJS_OBJECT* objectsS[] = { (NJS_OBJECT*)0x36B6E6C , (NJS_OBJECT*)0x036BA8EC,  (NJS_OBJECT*)0x036B42BC, 0,  (NJS_OBJECT*)0x036B50BC,(NJS_OBJECT*)0x036B8BBC,
0, (NJS_OBJECT*)0x036B838C ,(NJS_OBJECT*)0x36B9F64, (NJS_OBJECT*)0x036BB22C, (NJS_OBJECT*)0x036BAD78, (NJS_OBJECT*)0x036B995C };
void ToyPresenter_Display(ObjectMaster* a1)
{
	if (a1->Data1->Action)
	{
		njPushMatrixEx();
		njTranslate(0, -84, 29.5 + 1, 366.0 - 5);
		njRotateY(0, a1->Data1->Rotation.y);
		njScale(0, a1->Data1->Scale.x * 1.25f, a1->Data1->Scale.x * 1.25f, a1->Data1->Scale.x * 1.25f);
		njSetTexture(&AL_TOY_TEXLIST);
		if (a1->Data1->Status != -1)
			njCnkDrawObject(objectsL[a1->Data1->Status]);
		njPopMatrixEx();

		njPushMatrixEx();
		njTranslate(0, -84, 29.5 + 1, 366.0 + 5);
		njRotateY(0, a1->Data1->Rotation.y);
		njScale(0, a1->Data1->Scale.x * 1.25f, a1->Data1->Scale.x * 1.25f, a1->Data1->Scale.x * 1.25f);
		njCnkDrawObject(objectsS[a1->Data1->Index]);
		njPopMatrixEx();
	}
}

void ToyPresenter_Main(ObjectMaster* a1)
{
	EntityData1* v1; // esi
	char v2; // cl
	__int16 v3; // ax
	Float v5; // [esp+8h] [ebp+4h]

	v1 = a1->Data1;
	v2 = v1->Action;
	switch (v1->Action)
	{
	case 0:
		if (++v1->InvulnerableTime <= 20)
		{
			goto LABEL_12;
		}
		v1->Rotation.y += 512;
		v1->Action = v2 + 1;
		v1->NextAction = 0;
		break;
	case 1:
		v1->Scale.x += 0.08f;
		if (v1->Scale.x <= 1.0)
		{
			goto LABEL_12;
		}
		v1->Scale.x = 1.0;
		v1->Rotation.y += 512;
		v1->Action = v2 + 1;
		v1->NextAction = 0;
		v1->InvulnerableTime = 0;
		break;
	case 2:
		if (v1->InvulnerableTime == 30)
		{

		}
		v3 = v1->InvulnerableTime;
		v1->InvulnerableTime = v3 + 1;
		if ((unsigned __int16)v3 <= 0x14Au)
		{
			goto LABEL_12;
		}
		++v1->Action;
		v1->Rotation.y += 512;
		v1->NextAction = 0;
		v1->InvulnerableTime = 0;
		break;
	case 3:
		v5 = v1->Scale.x - 0.07999999821186066f;
		v1->Scale.x = v5;
		if (v5 >= 0.0f)
		{
			goto LABEL_12;
		}
		v1->Scale.x = 0.0f;
		v1->Rotation.y += 512;
		v1->Action = v2 + 1;
		v1->NextAction = 0;
		break;
	default:
	LABEL_12:
		v1->Rotation.y += 512;
		break;
	}
	a1->DisplaySub(a1);
}

void ToyPresenter_Load(int ID, int ID2)
{
	ObjectMaster* toyPresenter = LoadObject(LoadObj_Data1, 5, ToyPresenter_Main);
	toyPresenter->DisplaySub = ToyPresenter_Display;
	
	if (ID == 0)
	{
		switch (ID2)
		{
		case 0:
			toyPresenter->Data1->Status = AL_LTOY_TV;
			toyPresenter->Data1->Index = AL_STOY_SCOP;
			break;
		case 1:
			toyPresenter->Data1->Status = AL_LTOY_RADICASE;
			toyPresenter->Data1->Index = AL_STOY_JYOURO;
			break;
		case 2:
			toyPresenter->Data1->Status = AL_LTOY_BOX;
			toyPresenter->Data1->Index = AL_STOY_GARAGARA;
			break;
		case 3:
			toyPresenter->Data1->Status = AL_LTOY_HORSE;
			toyPresenter->Data1->Index = AL_STOY_CAR;
			break;
		case 4:
			toyPresenter->Data1->Status = AL_LTOY_BALL_N;
			toyPresenter->Data1->Index = AL_STOY_BOOK;
			break;
		}
	}
	else if (ID == 1)
	{
		switch (ID2)
		{
		case 0:
			toyPresenter->Data1->Status = AL_LTOY_BALL_H;
			toyPresenter->Data1->Index = AL_STOY_DOLL;
			break;
		case 1:
			toyPresenter->Data1->Status = AL_LTOY_BALL_D;
			toyPresenter->Data1->Index = AL_STOY_HOUKI;
			break;
		case 2:
			toyPresenter->Data1->Status = -1;
			toyPresenter->Data1->Index = AL_STOY_HOPPING;
			break;
		case 3:
			toyPresenter->Data1->Status = -1;
			toyPresenter->Data1->Index = AL_STOY_CRAYON;
			break;
		case 4:
			toyPresenter->Data1->Status = -1;
			toyPresenter->Data1->Index = AL_STOY_SYABON;
			break;
		}
	}
}
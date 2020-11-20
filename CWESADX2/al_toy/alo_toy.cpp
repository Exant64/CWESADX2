
#include "alo_toy.h"
#include "alo_horse.h"
#include "alo_radio.h"
#include "alo_tv.h" 
#include "alo_piano.h"
#include "alo_ball.h"
#include "..//chao.h"
//#include "../SeedGameObject.h"

extern ObjectMaster* PlaceConsole(NJS_VECTOR* pos);
extern void ALO_BoxExecutor_Load(NJS_VECTOR* a1);

void LoadSSGardenNew()
{
	//ToyPresenter_Load();
//	LoadClassRoom();
	NJS_VECTOR pos = { -52.5f ,0,-120.5f };
	LoadSSGarden();
	//	PlaceConsole(&pos);
		//ALO_Boat_Create(&pos, 0);
	NJS_VECTOR a3 = { 0,0,0 };
	NJS_VECTOR ballPos = { 24,0,10 };
	NJS_VECTOR boxPos = { 177,1.75f,13 };
	NJS_VECTOR boxDCPos = { 189, 3, -15.5f };
	

	//ToysUnlocked = -1; //debug
	if (ToysUnlocked & 1)
		PlaceTV();
	if (ToysUnlocked & (1 << AL_LTOY_BALL_N))
		CreateBall(&ballPos, &a3);
	if (ToysUnlocked & (1 << AL_LTOY_BOX))
	{
		if (!GetModuleHandle(L"DCMods_Main"))
			ALO_BoxExecutor_Load(&boxPos);
		else
			ALO_BoxExecutor_Load(&boxDCPos);
	}
}
void LoadMRGardenNew()
{
	NJS_VECTOR position;
	NJS_VECTOR velocity;

	LoadMRGarden();
	NJS_VECTOR ballPos = { 120,1.87,106 };
	NJS_VECTOR boxPos = { 177,1.75f,13 };
	NJS_VECTOR a3 = { 0,0,0 };
	//ToysUnlocked = -1; //debug
	if (ToysUnlocked & (1 << AL_LTOY_BALL_H))
		CreateBall(&ballPos, &a3);
	if (ToysUnlocked & (1 << AL_LTOY_HORSE))
		PlaceHorse();
	//CreatePiano();
	position.x = -64;
	position.y = 1.74;
	position.z = 213;
	velocity.y = 1;
	//Seed_Create(0, &position, 0, &velocity, 0);
}
void LoadECGardenNew()
{
	LoadECGarden();
	//ToysUnlocked = -1; //debug
	if (ToysUnlocked & (1 << AL_LTOY_RADICASE))
		PlaceRadio();
	NJS_VECTOR a3 = { 0,0,0 };
	NJS_VECTOR ballPos = { 79,4.41f,-165};
	if (ToysUnlocked & (1 << AL_LTOY_BALL_D))
		CreateBall(&ballPos, &a3);
}
FunctionPointer(void, Chao_SetMedal, (ChaoSetmedalThing* a1), 0x00730360);
FunctionPointer(signed int, sub_7512D0, (int a1, signed int a2), 0x7512D0);
DataPointer(char, CurrentChaoRaceType, 0x03CD3709); //ruby, etc
DataPointer(char, CurrentChaoRace, 0x03CD370A); //beginner, etc

FunctionPointer(int, sub_74F740, (int a1), 0x74F740);
void RaceUnlocks(ChaoSetmedalThing* a1)
{
	Chao_SetMedal(a1);
	//if (CurrentChaoRaceType == 0) //beginner
	{
		//if (CurrentChaoRace < 2)

		int v1 = sub_7512D0((int)& a1->gap0[5312], 0);
		ChaoSetmedalThing2* v3 = (ChaoSetmedalThing2*)sub_74F740((int)& a1->gap0[244 * v1 + 3264]);
		chaowk* data1 = (chaowk*)v3->dword8D0->Data1;
		//ToyPresenter_Load(CurrentChaoRace);
		if (CurrentChaoRaceType == 0)
		{
			switch (CurrentChaoRace)
			{
			case 0:
				ToysUnlocked |= 1 << AL_LTOY_TV;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_SCOP;
				break;
			case 1:
				ToysUnlocked |= 1 << AL_LTOY_RADICASE;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_JYOURO;
				break;
			case 2:
				ToysUnlocked |= 1 << AL_LTOY_BOX;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_GARAGARA;
				break;
			case 3:
				ToysUnlocked |= 1 << AL_LTOY_HORSE;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_CAR;
				break;
			case 4:
				ToysUnlocked |= 1 << AL_LTOY_BALL_N;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_BOOK;
				break;
			}
		}
		else if (CurrentChaoRaceType == 1)
		{
			switch (CurrentChaoRace)
			{
			case 0:
				ToysUnlocked |= 1 << AL_LTOY_BALL_H;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_DOLL;
				break;
			case 1:
				ToysUnlocked |= 1 << AL_LTOY_BALL_D;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_HOUKI;
				break;
			case 2:
			//	ToysUnlocked |= 1 << AL_LTOY_BOX;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_HOPPING;
				break;
			case 3:
				//ToysUnlocked |= 1 << AL_LTOY_HORSE;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_CRAYON;
				break;
			case 4:
				//ToysUnlocked |= 1 << AL_LTOY_BALL_N;
				data1->pParamGC->KnowledgeBTL.SToyFlag |= 1 << AL_STOY_SYABON;
				break;
			}
		}

	}
}

void Toys_Init()
{
	WriteCall((void*)0x0072E729, RaceUnlocks);

	WriteCall((void*)0x007155D6, LoadSSGardenNew);
	WriteCall((void*)0x007155F6, LoadMRGardenNew);
	WriteCall((void*)0x007155E6, LoadECGardenNew);
}

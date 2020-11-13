#include "chao.h"
#include "al_knowledge.h"

int AL_KW_GetRelationIndex(ObjectMaster* a1, ObjectMaster* a2)
{
	chaowk* wk1 = (chaowk*)a1->Data1;
	chaowk* wk2 = (chaowk*)a2->Data1;

	//if already registered, find it
	for (int i = 0; i < 20; i++)
	{
		if (wk2->pParamGC->ChaoID.id[0] != 0 &&
			wk2->pParamGC->ChaoID.id[0] == wk1->pParamGC->KnowledgeBTL.chao[i].id.id[0] &&
			wk2->pParamGC->ChaoID.id[1] == wk1->pParamGC->KnowledgeBTL.chao[i].id.id[1])
			return i;
	}

	//if not registered, find new slot for it
	for (int i = 0; i < 20; i++)
	{
		if (wk1->pParamGC->KnowledgeBTL.chao[i].id.id[0] == 0)
		{
			wk1->pParamGC->KnowledgeBTL.chao[i].id = wk2->pParamGC->ChaoID;
			return i;
		}

	}

	//if nothing is available, invalid 
	return -1;
}

void __cdecl AL_KW_MeetChao(ObjectMaster* a1, int index)
{
	chaowk* wk1 = (chaowk*)a1->Data1;

	//increment meet
	if (wk1->pParamGC->KnowledgeBTL.chao[index].meet < 0xFFFFu)
	{
		wk1->pParamGC->KnowledgeBTL.chao[index].meet++;
	}

	//likeness goes up by random
	float val = (float)rand() * 0.000030517578f;
	if (val >= 0.5f)
		wk1->pParamGC->KnowledgeBTL.chao[index].like++;
	else if (val < 0.15f)
		wk1->pParamGC->KnowledgeBTL.chao[index].like--;

	//limit likeness
	if (wk1->pParamGC->KnowledgeBTL.chao[index].like > 50) wk1->pParamGC->KnowledgeBTL.chao[index].like = 50;
	if (wk1->pParamGC->KnowledgeBTL.chao[index].like < -50) wk1->pParamGC->KnowledgeBTL.chao[index].like = -50;

	wk1->pParamGC->KnowledgeBTL.chao[index].distance = 2 * (wk1->pParamGC->KnowledgeBTL.chao[index].distance / 3);
}

int AL_KW_GetMeetChao(ObjectMaster* a1, int index)
{
	chaowk* wk1 = (chaowk*)a1->Data1;
	return wk1->pParamGC->KnowledgeBTL.chao[index].meet;
}

void AL_KW_MeetEachother(ObjectMaster* a1, ObjectMaster* a2)
{
	int relationIndex1 = AL_KW_GetRelationIndex(a1, a2);
	int relationIndex2 = AL_KW_GetRelationIndex(a2, a1);
	if (relationIndex1 > -1)
		AL_KW_MeetChao(a1, relationIndex1);
	if (relationIndex2 > -1)
		AL_KW_MeetChao(a2, relationIndex2);
}

void AL_KW_Control(ObjectMaster* a1)
{
	chaowk* data1 = (chaowk*)a1->Data1;
	if (data1->pParamGC->KnowledgeBTL.KwTimer++ >= 10)
	{
		data1->pParamGC->KnowledgeBTL.KwTimer = 0;
		for (int i = 0; i < 6; i++)
		{
			data1->pParamGC->KnowledgeBTL.player[i].distance += 6;
			if (data1->pParamGC->KnowledgeBTL.player[i].distance > 50000) data1->pParamGC->KnowledgeBTL.player[i].distance = 50000;
			data1->pParamGC->KnowledgeDX.player[i].distance += 6;
			if (data1->pParamGC->KnowledgeDX.player[i].distance > 50000) data1->pParamGC->KnowledgeDX.player[i].distance = 50000;
		}
		for (int i = 0; i < 20; i++)
		{
			data1->pParamGC->KnowledgeBTL.chao[i].distance += 6;
			if (data1->pParamGC->KnowledgeBTL.chao[i].distance > 50000) data1->pParamGC->KnowledgeBTL.chao[i].distance = 50000;
		}
	}
}
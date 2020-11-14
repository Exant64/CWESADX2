#include "../chao.h"

int __cdecl sub_5647B0(ObjectMaster* a1)
{
	chaowk* v1; // esi
	int v2; // edi
	MOVE_WORK* v3; // ebx
	int result; // eax

	v1 = (chaowk*)a1->Data1;
	if (v1->Behavior.Mode)
	{
		goto LABEL_8;
	}
	AL_SetMotionLink(a1, 568 + 3);
	AL_FaceSetEye(a1, 1, -1);
	AL_FaceSetMouth(a1, 8, -1);
	AL_IconSet(a1, 5, 300);
	++v1->Behavior.Mode;
	v1->Behavior.Timer = 0;
	if ((double)rand() * 0.000030517578125 >= 0.5)
	{
		//if (CurrentChaoArea != NextChaoArea)
		{
			goto LABEL_8;
		}
		//v1 = a1->Data1.Chao;
		v2 = 24685;
	}
	else
	{
		//if (CurrentChaoArea != NextChaoArea)
		{
			goto LABEL_8;
		}
		v2 = 24617;
	}
	//SE_CallV2(v2, &v1->entity.Position, 0, 0, 110);
LABEL_8:
	v3 = (MOVE_WORK*)a1->Data2;
	result = 0;
	if (v3->Flag & 0x400)
	{
		v3->Velo.x = v3->Velo.x * 0.8999999761581421;
		v3->Velo.y = v3->Velo.y * 0.8999999761581421;
		v3->Velo.z = 0.8999999761581421 * v3->Velo.z;
	}
	return result;
}
FunctionPointer(signed int, AL_CheckMinimal, (ObjectMaster* a1), 0x00739D10);
signed int sub_564760(ObjectMaster* a1)
{
	if (AL_GetBehavior(a1) == sub_5647B0)
	{
		return AL_CheckMinimal(a1);
	}
	ObjectMaster* v1 = ALOField_Find2(a1->Data1, 162);
	if (!v1)
	{
		return 0;
	}
	AL_SetBehaviorWithTimer(a1, sub_5647B0, 500);
	return 1;
}
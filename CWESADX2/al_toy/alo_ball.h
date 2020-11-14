#pragma once
#include "../SADXModLoader.h"
DataPointer(NJS_CNK_OBJECT, TestModelBall, 0x0389A014);
extern ObjectMaster* ALO_BallPtr;
extern int dword_1DBE56C;
extern int BallUsable;
void Ball_Main(ObjectMaster* a1);
void Ball_Display(ObjectMaster* a1);
void Ball_Load(ObjectMaster* a1);
void CreateBall(NJS_VECTOR* pos, NJS_VECTOR* vel);

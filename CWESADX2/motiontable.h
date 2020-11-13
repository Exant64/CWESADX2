#pragma once

struct NJS_MKEY_SA 
{
	Sint16 keyframe;
	Sint16 ang[3];
};

struct MotionTableAction
{
	NJS_MOTION* NJS_MOTION;
	__int16 FlagThing1;
	__int16 field_6;
	int TransitionToID;
	int field_C;
	float StartFrame;
	float EndFrame;
	float PlaySpeed;
};

#pragma pack(push, 8)
struct __declspec(align(4)) MotionTableEntry
{
	short flag;
	__int16 gap2;
	int AnimID2;
	int AnimID;
	float frameIncreaseSpeed_;
	float float10;
	float dword14;
	__int16 gap18;
	__int16 field_1A;
	float frame;
	float field_20;
	float FrameCount2;
	float PlaySpeed2;
	NJS_MOTION* NJS_MOTION;
	short word30;
	__int16 field_32;
	float dword34;
	int dword38;
	int FrameCount;
	int PlaySpeed;
	int NJS_MOTIONAlt;
	MotionTableAction* PointerToAnimations;
};
#pragma pack(pop)

struct MOTION_TABLE
{
	NJS_MOTION* pMotion;
	__int16 mode;
	__int16 posture;
	int next;
	int link_step;
	float start;
	float end;
	float spd;
};
struct MOTION_INFO
{
	int mode;
	float frame;
	float start;
	float end;
	float spd;
	NJS_MOTION* pMotion;
};
struct MOTION_CTRL
{
	short flag;
	__int16 pose;
	int AnimID;
	int TransitionToID;
	float frameIncreaseSpeed_;
	float someSpeedThing;
	float linkFrame;
	__int16 SomeFlagThingInEntry2;
	__int16 field_1A;
	float frame;
	float StartFrame2;
	float EndFrame2;
	float PlaySpeed2;
	NJS_MOTION* LastNJS_Motion;
	short SomeFlagThingInEntry;
	__int16 field_32;
	float StartFrame;
	float StartFrame_;
	float EndFrame;
	float PlaySpeed;
	NJS_MOTION* NJS_MOTION;
	MOTION_TABLE* PointerToAnimations;
};

#pragma once
#include "SADXModLoader.h"
#include "motiontable.h"
#include <random>
enum eAL_LTOY
{
	AL_LTOY_TV = 0x0,
	AL_LTOY_RADICASE = 0x1,
	AL_LTOY_BOX = 0x2,
	AL_LTOY_BALL_N = 0x3,
	AL_LTOY_BALL_H = 0x4,
	AL_LTOY_BALL_D = 0x5,
	AL_LTOY_HORSE = 0x6,
	AL_LTOY_UKIWA = 0x7,
	AL_LTOY_DUCK = 0x8,
	AL_LTOY_KANOKE = 0x9,
	AL_LTOY_PIANO = 0xA,
	AL_LTOY_ORGAN = 0xB,
	NB_AL_LTOY = 0xC,
};
enum eAL_STOY
{
	AL_STOY_GARAGARA = 0x0,
	AL_STOY_CAR = 0x1,
	AL_STOY_BOOK = 0x2,
	AL_STOY_CRACKER = 0x3,
	AL_STOY_DOLL = 0x4,
	AL_STOY_HOUKI = 0x5,
	AL_STOY_FIREWORK = 0x6,
	AL_STOY_HOPPING = 0x7,
	AL_STOY_CRAYON = 0x8,
	AL_STOY_SYABON = 0x9,
	AL_STOY_SCOP = 0xA,
	AL_STOY_JYOURO = 0xB,
	NB_AL_STOY = 0xC,
};

struct ChaoSetmedalThing
{
	char gap0[5500];
	short word157C;
};
enum EMOTION_ENUM
{
	EM_MD_PLEASURE = 0x0,
	EM_MD_ANGER = 0x1,
	EM_MD_SORROW = 0x2,
	EM_MD_FEAR = 0x3,
	EM_MD_SURPRISE = 0x4,
	EM_MD_PAIN = 0x5,
	EM_MD_RELAX = 0x6,
	EM_MD_TOTAL = 0x7,
	EM_ST_SLEEPY = 0x8,
	EM_ST_SLEEP_DEPTH = 0x9,
	EM_ST_HUNGER = 0xA,
	EM_ST_BREED = 0xB,
	EM_ST_TEDIOUS = 0xC,
	EM_ST_LONELY = 0xD,
	EM_ST_TIRE = 0xE,
	EM_ST_STRESS = 0xF,
	EM_ST_NOURISHMENT = 0x10,
	EM_ST_CONDITION = 0x11,
	EM_ST_THIRSTY = 0x12,
	EM_PER_CURIOSITY = 0x13,
	EM_PER_KINDNESS = 0x14,
	EM_PER_AGRESSIVE = 0x15,
	EM_PER_SLEEPY_HEAD = 0x16,
	EM_PER_SOLITUDE = 0x17,
	EM_PER_VITALITY = 0x18,
	EM_PER_GLUTTON = 0x19,
	EM_PER_REGAIN = 0x1A,
	EM_PER_SKILLFUL = 0x1B,
	EM_PER_CHARM = 0x1C,
	EM_PER_CHATTY = 0x1D,
	EM_PER_CALM = 0x1E,
	EM_PER_FICKLE = 0x1F,
	NB_EMOTION = 0x20,
};
#pragma pack(push, 8)
struct __declspec(align(4)) CHAO_GLOBAL
{
	int CalcBuyo;
	int DispWorldEntry;
	int DispOnScreen;
	int DispScreenFrame;
	int DispField;
	unsigned __int16 InitMulPotentialSkill;
	unsigned __int16 InitBaseLife;
	unsigned __int16 InitMulLife;
	unsigned __int16 InitMulForm;
	unsigned __int16 InitMulAttr;
	__int16 field_1E;
	float WalkAcc;
	float WalkSlowAcc;
	float RunAcc;
	float BoundFriction;
	float BoundFloor;
	unsigned __int16 SkillLimit;
	unsigned __int16 LifeMaxLimit;
	char EmotionMoodLimit;
	char field_39;
	unsigned __int16 EmotionStateLimit;
	char EmotionPersonalityLimit;
	char field_3D;
	char field_3E;
	char field_3F;
	float DeformLimit;
	float GrowthLimit;
	float GrowthMayuPoint;
	float NormalBoundary;
	float NeutralBoundary;
	float AddGrowthTime;
	float TimeAddGrowthChild;
	float TimeAddGrowthAdult;
	float TimeAddAttrChild;
	float TimeAddAttrAdult;
	float PartsSetProb;
	float PartsRemoveProb;
	float CamDistShadowCutLev1;
	float CamDistShadowCutLev2;
	float CamDistShadowCutLev3;
	float CamDistShadowCutLev4;
	float CamDistShadowCutLev5;
	unsigned int MayuWaitTime;
	unsigned int MayuFadeInTime;
	unsigned int MayuTypeChageTime;
	unsigned int MayuFadeOutTime;
	unsigned int MayuRelaxTime;
	float MayuExpandRatio;
	float MayuShrinkRatio;
	float MayuInitAlpha;
	__int16 SucceedBoundaryUserLike;
	unsigned __int16 SucceedBoundaryStress;
	unsigned __int16 SucceedBoundaryCondition;
	unsigned __int16 SucceedBoundaryMood;
	float FruitAddGrowthChild;
	float FruitAddGrowthAdult;
	unsigned __int16 FruitAddStaminaChild;
	unsigned __int16 FruitAddStaminaAdult;
	int FruitAddRecoverLife;
	int FruitAddLifeMax;
	int FruitAddUserLike;
	float FruitAddAttrChild;
	float FruitAddAttrAdult;
	float FruitDislikeSubAttr;
	float FruitPakuriSubAttr;
	float MinimalAddFormChild;
	float MinimalAddFormAdult;
	float MinimalAddAttrChild;
	float MinimalAddAttrAdult;
	float MinimalAddGrowthChild;
	float MinimalAddGrowthAdult;
	int MinimalAddUserLike;
	float DakkoAddAttr;
	float DamageSubAttr;
	float NadeAddAttr;
	float ThrownSubAttr;
	int DamageAddLife;
	int DamageAddLifeMax;
	unsigned __int16 NestFlowerInterval;
	unsigned __int16 nbNestFlower;
	float NestRange;
	unsigned __int16 NestWaitTime;
	unsigned __int16 SeedClock;
	unsigned __int16 SaplingClock;
	unsigned __int16 TreeClock;
	unsigned __int16 WaterSub;
	__int16 field_11A;
	float TreeFruitAddGrowth;
	unsigned __int16 FruitMaxNum;
	unsigned __int16 KwSubFear;
	unsigned __int16 KwAddDistance;
	unsigned __int16 SkillWalk;
	unsigned __int16 SkillRun;
	unsigned __int16 SkillRun2;
	float SkillRunAccBase;
	float SkillRunAccRatio;
	unsigned __int16 SkillSwimInukaki;
	unsigned __int16 SkillSwimBataashi;
	unsigned __int16 SkillSwimCrawl;
	__int16 field_13A;
	float SkillSwimAccBase;
	float SkillSwimAccRatio;
	unsigned __int16 ParamSubPleasure;
	unsigned __int16 ParamSubAnger;
	unsigned __int16 ParamSubSorrow;
	unsigned __int16 ParamSubFear;
	unsigned __int16 ParamSubSurprise;
	unsigned __int16 ParamSubPain;
	unsigned __int16 ParamSubRelax;
	unsigned __int16 ParamAddSleepy;
	unsigned __int16 ParamSubSleepy;
	unsigned __int16 ParamAddSleepDepth;
	unsigned __int16 ParamSubSleepDepth;
	unsigned __int16 ParamWakeUpSleepDepth;
	unsigned __int16 ParamAddHunger;
	unsigned __int16 ParamSubHunger;
	unsigned __int16 ParamAddBreed;
	unsigned __int16 ParamAddTediousCuriosity;
	unsigned __int16 ParamAddTediousAggressive;
	unsigned __int16 ParamAddTediousCalm;
	unsigned __int16 ParamSubTediousWalk;
	unsigned __int16 ParamSubTediousSwim;
	unsigned __int16 ParamAddLonely;
	unsigned __int16 ParamAddLonelyGreet;
	unsigned __int16 ParamAddLonelySuri;
	unsigned __int16 ParamAddLonelyAttack;
	unsigned __int16 ParamAddTireNormal;
	unsigned __int16 ParamSubTireSleep;
	unsigned __int16 ParamSubTireRest;
	unsigned __int16 ParamAddTireWalk;
	unsigned __int16 ParamAddTireRun;
	unsigned __int16 ParamAddTireSwim;
	unsigned __int16 ParamSubTireSwimStop;
	unsigned __int16 ParamSubNourishment;
	unsigned __int16 ParamAddConditionN;
	unsigned __int16 ParamConditionTriggerAddN;
	unsigned __int16 ParamSubConditionN;
	unsigned __int16 ParamConditionTriggerSubN;
	unsigned __int16 ParamSubConditionS;
	unsigned __int16 ParamConditionTriggerS;
	unsigned __int16 ParamSubConditionP;
	unsigned __int16 ParamConditionTriggerP;
	unsigned __int16 ParamAddConditionRest;
	unsigned __int16 ParamAddThirsty;
	unsigned __int16 ParamSubThirstySwim;
	unsigned __int16 ChaoTimerBaseInterval;
	unsigned __int16 ChaoTimerLifeInterval;
	unsigned __int16 ChaoTimerEmotionInterval;
	unsigned __int16 ChaoTimerMoodInterval;
	unsigned __int16 ChaoTimerKnowledgeInterval;
	unsigned __int16 ChaoTimerIllInterval;
	__int16 field_1A6;
	float IntentionScoreRandomRatio;
	float IntentionMinScore;
	unsigned int IntentionAngerTrigger;
	unsigned int IntentionAngerPlayerTrigger;
	float IntentionAngerMinScore;
	float IntentionAngerMaxScore;
	unsigned int IntentionFearTrigger;
	unsigned int IntentionFearPlayerTrigger;
	float IntentionFearMinScore;
	float IntentionFearMaxScore;
	unsigned int IntentionSorrowTrigger;
	float IntentionSorrowMinScore;
	float IntentionSorrowMaxScore;
	unsigned int IntentionPainTrigger;
	float IntentionPainMinScore;
	float IntentionPainMaxScore;
	unsigned int IntentionPleasureTrigger;
	float IntentionPleasureMinScore;
	float IntentionPleasureMaxScore;
	unsigned int IntentionHungerGooMinInterval;
	unsigned int IntentionHungerGooIntervalRange;
	unsigned int IntentionHungerGooTrigger;
	float IntentionHungerGooMaxScore;
	unsigned int IntentionHungerFruitGoToEatTrigger;
	float IntentionHungerFruitGoToEatMaxScore;
	unsigned int IntentionHungerFruitSearchTrigger;
	float IntentionHungerFruitSearchMaxScore;
	unsigned int IntentionAkubiMinInterval;
	unsigned int IntentionAkubiIntervalRange;
	unsigned int IntentionAkubiTrigger1;
	unsigned int IntentionAkubiTrigger2;
	unsigned int IntentionAkubiTrigger3;
	float IntentionAkubiMaxScore;
	unsigned int IntentionPlayerGreetLonelyTrigger;
	float IntentionPlayerGreetMaxScore;
	unsigned int IntentionPlayerSuriSuriLonelyTrigger;
	float IntentionPlayerSuriSuriMaxScore;
	unsigned int IntentionSleepTrigger;
	float IntentionSleepMaxScore;
	unsigned int IntentionHimaTrigger;
	float IntentionHimaMaxScore;
	unsigned int IntentionThirstyTrigger;
	float IntentionThirstyMaxScore;
	unsigned int IntentionApproachNestTrigger;
	float IntentionApproachNestMaxScore;
	unsigned int IntentionJyouroThirstyTrigger;
	float IntentionJyouroMaxScore;
	unsigned int IntentionRestTrigger1;
	unsigned int IntentionRestTrigger2;
	float IntentionRestMaxScore;
	unsigned int IntentionRestEndTrigger;
	unsigned int RaceIntervalSubStamina;
	unsigned int RaceSubStaminaSwim;
	unsigned int RaceSubStaminaFly;
	unsigned int RaceSubStaminaRun;
	unsigned int RaceSubStaminaClimb;
	unsigned int RaceSubStaminaTree;
	unsigned int RaceSubStaminaOther;
	unsigned int RaceAddStaminaSit;
	unsigned int RaceCheerInterval;
	unsigned int RaceCheerDecAimStamina;
	unsigned int RaceCheerDecStamina;
	float RaceTurboRatioSwim;
	float RaceTurboRatioFly;
	float RaceTurboRatioRun;
	float RaceTurboRatioClimb;
	float RaceTurboRatioTree;
	float RaceTurboRatioOther;
};
#pragma pack(pop)
FunctionPointer(void, CCL_Enable, (EntityData1* a1, int a2), 0x0041C1F0);
FunctionPointer(void, MOV_Control, (ObjectMaster* a1), 0x0073FEF0);
FunctionPointer(void, MOV_DetectCollision, (ObjectMaster* a1), 0x0741290);
FunctionPointer(void, CCL_Disable, (EntityData1* a1, int a2), 0x41C220);
FunctionPointer(ObjectMaster*, ALOField_Load, (ObjectMaster* a1, char a2, NJS_VECTOR* a3, float a4, int random), 0x00764A60);
FunctionPointer(ObjectMaster*, ALOField_Find, (ObjectMaster* a1, int a2, char a3), 0x0723FF0);
FunctionPointer(ObjectMaster*, ALOField_Find2, (EntityData1* a1, int a2), 0x0041C930);
FunctionPointer(ObjectMaster*, j_ALOField_Load2, (char a1, NJS_VECTOR* a2, float a3, int a4), 0x00764AF0);
FunctionPointer(void, HeapFreeSADX, (LPVOID lpMem), 0x00780FB0);
FunctionPointer(void, ALW_CancelEntry, (ObjectMaster *a1), 0x0071A6B0);
FunctionPointer(void*, HeapAllocSADX, (int count, int size), 0x00780F90);
struct ChaoSetmedalThing2
{
	char gap0[2256];
	ObjectMaster* dword8D0;
};
DataPointer(CHAO_GLOBAL, ChaoGlobal, 0x034BB9C0);
FunctionPointer(Sint32, PlaySoundXYZAlt, (int a1, EntityData1* a2, int a3, int a4, float x, float y, float z), 0x0424FC0);
typedef int(__cdecl* BHV_FUNC)(ObjectMaster*);
#define BHVFunc(NAME, ADDRESS) FunctionPointer(int,NAME,(ObjectMaster*),ADDRESS);

enum eKW_BHV_KIND : int32_t
{
	KW_BHV_ART = 0x0,
	KW_BHV_DANCE = 0x1,
	KW_BHV_SING = 0x2,
	KW_BHV_MUSIC = 0x3,
	KW_BHV_MINI1 = 0x4,
	KW_BHV_MINI2 = 0x5,
	KW_BHV_MINI3 = 0x6,
	KW_BHV_MINI4 = 0x7,
	KW_BHV_MINI5 = 0x8,
	KW_BHV_MINI6 = 0x9,
	KW_BHV_MINI7 = 0xA,
	KW_BHV_MINI8 = 0xB,
	KW_BHV_MINI9 = 0xC,
	KW_BHV_MINI10 = 0xD,
	KW_BHV_MINI11 = 0xE,
	KW_BHV_MINI12 = 0xF,
	KW_BHV_MINI13 = 0x10,
	KW_BHV_MINI14 = 0x11,
	KW_BHV_MINI15 = 0x12,
	KW_BHV_MINI16 = 0x13,
	KW_BHV_MINI17 = 0x14,
	KW_BHV_MINI18 = 0x15,
	KW_BHV_TOY1 = 0x16,
	KW_BHV_TOY2 = 0x17,
	KW_BHV_TOY3 = 0x18,
	KW_BHV_TOY4 = 0x19,
	KW_BHV_TOY5 = 0x1A,
	KW_BHV_TOY6 = 0x1B,
	KW_BHV_TOY7 = 0x1C,
	KW_BHV_TOY8 = 0x1D,
	KW_BHV_TOY9 = 0x1E,
	KW_BHV_TOY10 = 0x1F,
	KW_BHV_TOY11 = 0x20,
	KW_BHV_FLY = 0x21,
	KW_BHV_SWIM = 0x22,
	KW_BHV_CLIMB_TREE = 0x23,
	KW_BHV_CLIMB_WALL = 0x24,
	KW_BHV_WATER = 0x25,
	KW_BHV_SWING = 0x26,
	KW_BHV_SIT = 0x27,
	KW_BHV_DENGURI = 0x28,
	KW_BHV_TOILET = 0x29,
	KW_BHV_PYON = 0x2A,
	KW_BHV_BOWLING = 0x2B,
	KW_BHV_FUKKIN = 0x2C,
	KW_BHV_SHIRIFURI = 0x2D,
	KW_BHV_OJIGI = 0x2E,
	KW_BHV_CHIWA = 0x2F,
	KW_BHV_NADERU = 0x30,
	KW_BHV_AGERU = 0x31,
	KW_BHV_TALK = 0x32,
	KW_BHV_PUNCH = 0x33,
	KW_BHV_OKOSU = 0x34,
	KW_BHV_TEFURI = 0x35,
	KW_BHV_HAKUSYU = 0x36,
	KW_BHV_SURIYORU = 0x37,
	KW_BHV_AKANBE = 0x38,
	KW_BHV_WA = 0x39,
	KW_BHV_NAGERU = 0x3A,
	KW_BHV_FIGHT = 0x3B,
	KW_BHV_IGAMI = 0x3C,
	KW_BHV_LISTEN = 0x3D,
	KW_BHV_WATCH = 0x3E,
};

struct KW_BHV_ENTRY
{
	eKW_BHV_KIND bhv;
};
struct AL_BEHAVIOR
{
	unsigned __int16 Flag;
	unsigned __int16 Mode;
	unsigned __int16 SubMode;
	unsigned __int16 MoveMode;
	int InterruptFlag;
	int Timer;
	int SubTimer;
	int LimitTimer;
	int BehaviorTimer;
	unsigned __int16 Intention;
	unsigned __int16 IntentionMode;
	int IntentionSubMode;
	unsigned int IntentionTimer[18];
	unsigned int IntervalTimer[128];
	int FreeWork;
	float MoveRadius;
	NJS_POINT3 BasePos;
	int(__cdecl* PrevFunc)(task*);
	int nbBhvFuncEntry;
	int CurrBhvFuncNum;
	int(__cdecl* BhvFuncList[16])(task*);
	int ReserveTimerList[16];
	int CurrKwBhvNum;
	int KwBhvList[4];
	unsigned int dummy[16];
};
struct AL_GROUP_OBJECT_LIST
{
	NJS_CNK_OBJECT* Zero[40];
	NJS_CNK_OBJECT* Normal[40];
	NJS_CNK_OBJECT* Swim[40];
	NJS_CNK_OBJECT* Fly[40];
	NJS_CNK_OBJECT* Run[40];
	NJS_CNK_OBJECT* Power[40];
};

struct AL_ITEM_INFO
{
	NJS_CNK_OBJECT* pObject;
	NJS_TEXLIST* pTexlist;
	NJS_POINT3 OffsetPos;
	Rotation3 OffsetAng;
};

struct AL_SHAPE
{
	al_object* pObject;
	al_object* CurrObjectList[40];
	AL_GROUP_OBJECT_LIST* pObjectList;
	AL_GROUP_OBJECT_LIST* pObjectListH;
	AL_GROUP_OBJECT_LIST* pObjectListD;
	NJS_POINT3 BodyPos;
	NJS_POINT3 HeadPos;
	NJS_POINT3 LeftHandPos;
	NJS_POINT3 RightHandPos;
	NJS_POINT3 LeftFootPos;
	NJS_POINT3 RightFootPos;
	NJS_POINT3 MouthPos;
	NJS_POINT3 MouthVec;
	NJS_POINT3 LeftEyePos;
	NJS_POINT3 LeftEyeVec;
	NJS_POINT3 RightEyePos;
	NJS_POINT3 RightEyeVec;
	NJS_CNK_OBJECT* pLeftHandItemObject;
	NJS_TEXLIST* pLeftHandItemTexlist;
	float LeftHandItemScale;
	float LeftHandItemActiveFlag;
	NJS_CNK_OBJECT* pRightHandItemObject;
	NJS_TEXLIST* pRightHandItemTexlist;
	float RightHandItemScale;
	float RightHandItemActiveFlag;
	unsigned __int16* palette;
	unsigned __int16 Flag;
	__int16 ColorNum;
	int EnvNum;
	unsigned int IconColor;
	float SclH;
	float SclV;
	float CamDist;
};

struct AL_ICON_INFO
{
	unsigned __int16 Mode;
	unsigned __int16 TexNum;
	int Timer;
	NJS_POINT3 Offset;
	NJS_POINT3 Pos;
	NJS_POINT3 Velo;
	NJS_POINT3 Scl;
	NJS_POINT3 SclSpd;
};

struct AL_ICON
{
	__int16 CurrType;
	__int16 NextType;
	int Timer;
	int NextTimer;
	int PuniPhase;
	int PosPhase;
	unsigned int Color;
	unsigned __int16 TexAnimNum;
	unsigned __int16 TexAnimTimer;
	int ang;
	NJS_POINT3 Up;
	NJS_POINT3 Pos;
	AL_ICON_INFO Upper;
	AL_ICON_INFO Lower;
};
struct AL_ZONE
{
	unsigned __int16 Flag;
	unsigned __int16 CurrNum;
	float Ratio;
	NJS_LINE Plane;
};


#pragma pack(push, 8)
struct __declspec(align(8)) chaowk
{
	EntityData1 entity;
	int Timer;
	int pMayu;
	ObjectMaster* pBookTask;
	int NestFlag;
	ObjectMaster* pAnyTask;
	int pAimTask;
	int AimNum;
	int RememberNum;
	int pitch;
	int ClimbFirstPos;
	int IsParamCopy;
	ChaoDataBase* pParamGC;
	TMP_PARAM tmpParam;
	int Stamina;
	int AimStamina;
	int tp;
	int pre_ang[3];
	int ChaoFlag;
	int ColliFormat;
	float CurrZone;
	MOTION_CTRL MotionCtrl;
	MOTION_CTRL MiniMotionCtrl;
	MOTION_TABLE MiniMotionTable[4];
	AL_BEHAVIOR Behavior;
	AL_SHAPE Shape;
	AL_FACE_CTRL Face;
	AL_ICON Icon;
	AL_ZONE Zone;
	AL_PERCEPTION Perception;
	void* pWork;
};
#pragma pack(pop)
enum
{
	BHV_RET_CONTINUE = 0x0,
	BHV_RET_FINISH = 0x1,
	BHV_RET_THINK = 0x2,
	BHV_RET_BREAK = 0x3,
};

enum MayuKind
{
	MayuKind_Grow = 0x0,
	MayuKind_Succeed = 0x1,
	MayuKind_Death = 0x2,
};
enum
{
	INT_TIMER_PLAYER = 0x0,
	INT_TIMER_CHAO = 0x1,
	INT_TIMER_GREET = 0x2,
	INT_TIMER_SING = 0x3,
	INT_TIMER_MUSIC = 0x4,
	INT_TIMER_DANCE = 0x5,
	INT_TIMER_ART = 0x6,
	INT_TIMER_TOY = 0x7,
	INT_TIMER_LTOY = 0x8,
	INT_TIMER_MINIMAL = 0x9,
	INT_TIMER_TV = 0xA,
	INT_TIMER_RADICASE = 0xB,
	INT_TIMER_BOX = 0xC,
	INT_TIMER_BALL = 0xD,
	INT_TIMER_GOO = 0xE,
	INT_TIMER_AKUBI = 0xF,
	INT_TIMER_COCOONREACT = 0x10,
	NB_INT_TIMER = 0x11
};
enum
{
	ALW_CMD_ERROR = 0xFFFFFFFF,
	ALW_CMD_NONE = 0x0,
	ALW_CMD_GO = 0x1,
	ALW_CMD_EAT = 0x2,
	ALW_CMD_CHANGE = 0x3,
	ALW_CMD_FINISH = 0x4,
	ALW_CMD_PLANTED = 0x5,
	ALW_CMD_BYE = 0x6,
};
enum
{
	G_PER_CURIOSITY = 0x0,
	G_PER_KINDNESS = 0x1,
	G_PER_AGRESSIVE = 0x2,
	G_PER_SLEEPY_HEAD = 0x3,
	G_PER_SOLITUDE = 0x4,
	G_PER_VITALITY = 0x5,
	G_PER_GLUTTON = 0x6,
	G_PER_REGAIN = 0x7,
	G_PER_SKILLFUL = 0x8,
	G_PER_CHARM = 0x9,
	G_PER_CHATTY = 0xA,
	G_PER_CALM = 0xB,
	G_PER_FICKLE = 0xC,
	NB_G_PER = 0xD,
};
#pragma pack(push, 8)
struct __declspec(align(2)) ITEM_SAVE_INFO
{
	__int16 Type;
	__int16 Garden;
	__int16 Size;
	__int16 Age;
	NJS_VECTOR position;
};
#pragma pack(pop)
FunctionPointer(void, njSetZCompare, (Uint8 index), 0x0077ED00);
VoidFunc(npSetZCompare, 0x00401420);
FunctionPointer(ITEM_SAVE_INFO*, AL_GetNewItemSaveInfo, (int a1), 0x00717760);
void SwimControl(ObjectMaster* a1);
FunctionPointer(bool, ALW_IsHeld, (ObjectMaster* a1), 0x71A320);
FunctionPointer(signed int, AL_TraceHoldingPosition, (ObjectMaster* a1), 0x744790);
FunctionPointer(int, ALW_CountEntry, (unsigned __int16 index), 0x0071A2D0);
FunctionPointer(BHV_FUNC, AL_GetBehavior, (ObjectMaster* a1), 0x0071EC40);
FunctionPointer(int, AL_ParameterGetSkill, (ObjectMaster* a1, unsigned __int16 a2), 0x00730C30);
FunctionPointer(int, MOV_TurnToAim2, (ObjectMaster* a1, int a2), 0x00740160);
FunctionPointer(double, MOV_DistFromAim, (ObjectMaster* a1), 0x007400A0);
FunctionPointer(signed int, AL_MoveHoldingObject, (ObjectMaster* a1), 0x744600);
FunctionPointer(signed int, AL_EmotionAdd, (ObjectMaster* a1, EMOTION_ENUM a2, int a3), 0x00720030);
FunctionPointer(signed int, AL_EmotionGetValue, (ObjectMaster* a1, EMOTION_ENUM a2), 0x00720160);
FunctionPointer(void, AL_SetBehavior, (ObjectMaster* a1, signed int(__cdecl* a2)(ObjectMaster*)), 0x0071EF10);
FunctionPointer(void, AL_SetBehaviorWithTimer, (ObjectMaster* a1, signed int(__cdecl* a2)(ObjectMaster*), int a3), 0x071EC80);
FunctionPointer(void, AL_SetNextBehavior, (ObjectMaster* a1, signed int(__cdecl* a2)(ObjectMaster*)), 0x0071EF30);
FunctionPointer(void, AL_SetMotionLink, (ObjectMaster* a1, int a2), 0x00734F00);
FunctionPointer(void, AL_SetMotionSpd, (ObjectMaster* a1, float a2), 0x0734F80);
FunctionPointer(void, AL_IconSet, (ObjectMaster* a1, int a2, int a3), 0x00736E90);
FunctionPointer(void, AL_FaceSetMouth, (ObjectMaster* a1, int a2, int a3), 0x00737190);
FunctionPointer(void, AL_FaceSetEye, (ObjectMaster* a1, int a2, int n), 0x007370A0);
FunctionPointer(void, AL_SetMotionLinkStep, (ObjectMaster* a1, int a2, unsigned __int16 a3), 0x00734F20);
FunctionPointer(int, MOV_SetAimPos, (ObjectMaster* a1, NJS_VECTOR* a2), 0x00740080);
FunctionPointer(bool, AL_IsHero2, (ObjectMaster* a1), 0x007306B0);
FunctionPointer(bool, AL_IsDark2, (ObjectMaster* a1), 0x007306F0);
FunctionPointer(int, AL_SetItem, (ObjectMaster* a1, int a2, NJS_CNK_OBJECT* model, NJS_TEXLIST* texlist), 0x00734AF0);
FunctionPointer(int, AL_SetItemOffset, (ObjectMaster* a1, int a2, AL_ITEM_INFO* pInfo), 0x00734B60);
FunctionPointer(void, AL_SetItemParallelLeftHand, (ObjectMaster* a1, NJS_CNK_OBJECT* a2, NJS_TEXLIST* a3), 0x00734C20);
FunctionPointer(ObjectMaster*, AL_GetFoundToyTask, (ObjectMaster* a1), 0x0073E6C0);
FunctionPointer(signed int, ALW_LockOn, (ObjectMaster* a1, ObjectMaster* a2), 0x71A380);
FunctionPointer(int, ALW_TurnToLockOn, (ObjectMaster* a1, int a2), 0x0071A820);
FunctionPointer(float, ALW_CalcDistFromLockOn, (ObjectMaster* a1), 0x0071A3D0);
FunctionPointer(al_entry_work*, ALW_IsCommunicating, (ObjectMaster* retstr), 0x71A560);
FunctionPointer(int, ALW_SendCommand, (ObjectMaster* retstr, __int16 a2), 0x0071A5D0);
FunctionPointer(__int16, ALW_RecieveCommand, (ObjectMaster* retstr), 0x0071A5B0);
FunctionPointer(ObjectMaster*, ALW_GetLockOnTask, (ObjectMaster* a1), 0x071A3B0);
FunctionPointer(void, AL_FixPosition, (ObjectMaster* a1), 0x00731D20);
FunctionPointer(int, MOV_SetVelo, (ObjectMaster* a1, NJS_VECTOR* a2), 0x0073FFE0);
FunctionPointer(void, AL_SetMotionSkip, (ObjectMaster* a1, int a2), 0x734F60);
FunctionPointer(bool, ALW_IsSheAttentionOtherOne, (ObjectMaster* a1, ObjectMaster* a2), 0x71A490);
FunctionPointer(signed int, ALW_CommunicationOn, (ObjectMaster* a1, ObjectMaster* a2), 0x71A4C0);
FunctionPointer(signed int, ALW_CommunicationOff, (ObjectMaster* a1), 0x071A520);
FunctionPointer(int, AL_SetIntervalTimer, (ObjectMaster* a1, unsigned __int16 a2, int a3), 0x73CF10);
FunctionPointer(double, AL_CalcScoreTypeA, (signed int value, signed int minimum), 0x0073CE10);
FunctionPointer(void, AL_CalcIntentionScore_JoinMusic, (ObjectMaster* a1, float* a2), 0x00761DA0);
FunctionPointer(void, AL_ScoreRandomize, (float* a1), 0x0073CEA0);
FunctionPointer(void, AL_CalcIntentionScore_Fear, (ObjectMaster* a1, float* a2), 0x0075E460);
FunctionPointer(bool, AL_IsMotionStop, (ObjectMaster* a1), 0x735040);
FunctionPointer(bool, AL_IsMotionEnd, (ObjectMaster* a1), 0x00735020);
FunctionPointer(void, AL_ForwardAcc, (ObjectMaster* a1, float a2), 0x00723F60);
FunctionPointer(void, AL_ForwardSpd, (ObjectMaster* a1, float a2), 0x00723F90);
FunctionPointer(void, AL_Brake, (ObjectMaster* tp, float brake), 0x00723FC0);
void AL_DecideAimSwimPosition(ObjectMaster* a1);

BHVFunc(ALBHV_OsanpoThrown, 0x71EB50)
BHVFunc(ALBHV_OdekakeEject, 0x71F0C0)
BHVFunc(ALBHV_SitSleep, 0x71F260)
BHVFunc(ALBHV_Akubi, 0x71F3E0)
BHVFunc(ALBHV_Tron, 0x71F630)
BHVFunc(ALBHV_Sleep, 0x71F920)
BHVFunc(ALBHV_SleepSelect, 0x71FED0)
BHVFunc(ALBHV_BornDamage, 0x738450)
BHVFunc(ALBHV_Damage, 0x738540)
BHVFunc(ALBHV_Thrown, 0x7387D0)
BHVFunc(ALBHV_Nade, 0x738B90)
BHVFunc(ALBHV_DakkoNormal, 0x738E70)
BHVFunc(ALBHV_DakkoDislike, 0x738EC0)
BHVFunc(ALBHV_DakkoLike, 0x739380)
BHVFunc(ALBHV_DakkoTron, 0x739510)
BHVFunc(ALBHV_Dakko, 0x7395D0)
BHVFunc(ALBHV_Capture, 0x739860)
BHVFunc(ALBHV_TurnToMinimal, 0x739C80)
BHVFunc(ALBHV_Eat, 0x739D80)
BHVFunc(ALBHV_PickUpLockOn, 0x73A7B0)
BHVFunc(ALBHV_GoToEat, 0x73A8A0)
BHVFunc(ALBHV_TurnToFruit, 0x73A920)
BHVFunc(ALBHV_HoldThink, 0x73AB20)
BHVFunc(ALBHV_WearObakeHead, 0x73ABB0)
BHVFunc(ALBHV_Throw, 0x73ACB0)
BHVFunc(ALBHV_TurnToObakeHead, 0x73AD80)
BHVFunc(ALBHV_Move, 0x73AF00)
BHVFunc(ALBHV_Koke, 0x73AF20)
BHVFunc(ALBHV_Climb, 0x73B030)
BHVFunc(ALBHV_Glide, 0x73B220)
BHVFunc(ALBHV_ChasePlayer, 0x73B370)
BHVFunc(ALBHV_NoticePlayer, 0x73B560)
BHVFunc(ALBHV_SwimObore, 0x73BD40)
BHVFunc(ALBHV_SwimBataashi, 0x73BE50)
BHVFunc(ALBHV_SwimCrawl, 0x73BED0)
BHVFunc(ALBHV_SwimSeoyogi, 0x73BF50)
BHVFunc(ALBHV_SwimPuha, 0x73BFD0)
BHVFunc(ALBHV_Swim, 0x73C110)
BHVFunc(ALBHV_BornPon, 0x73C320)
BHVFunc(ALBHV_BornKyoro, 0x73C360)
BHVFunc(ALBHV_Mayu, 0x73C890)
BHVFunc(ALBHV_Dead, 0x73CA70)
BHVFunc(ALBHV_Think, 0x73CCC0)
BHVFunc(ALBHV_Notice, 0x73D680)
BHVFunc(ALBHV_TurnToAim, 0x73D700)
BHVFunc(ALBHV_GoToAim, 0x73D750)
BHVFunc(ALBHV_TurnToLockOn, 0x73D850)
BHVFunc(ALBHV_Turn, 0x73D8E0)
BHVFunc(ALBHV_TurnRandom, 0x73D9F0)
BHVFunc(ALBHV_GoToLockOn, 0x73DB00)
BHVFunc(ALBHV_Touch, 0x73DBE0)
BHVFunc(ALBHV_Oshaburiburi, 0x7468F0)
BHVFunc(ALBHV_Tameiki, 0x75B440)
BHVFunc(ALBHV_MesoMeso, 0x75B4F0)
BHVFunc(ALBHV_Cry, 0x75B6C0)
BHVFunc(ALBHV_Sorrow, 0x75B870)
BHVFunc(ALBHV_PostureChangeStand, 0x75B980)
BHVFunc(ALBHV_PostureChangeSit, 0x75BA10)
BHVFunc(ALBHV_HaiHai, 0x75BC70)
BHVFunc(ALBHV_WalkNormal, 0x75BD00)
BHVFunc(ALBHV_Run, 0x75BDC0)
BHVFunc(ALBHV_Run2, 0x75BEB0)
BHVFunc(ALBHV_JumpToPond, 0x75BFE0)
BHVFunc(ALBHV_GoToWater, 0x75C0A0)
BHVFunc(ALBHV_NyokiNyoki, 0x75C0D0)
BHVFunc(ALBHV_Jyouro, 0x75C1C0)
BHVFunc(ALBHV_ApproachToJyouro, 0x75C3D0)
BHVFunc(ALBHV_Rest, 0x75C4E0)
BHVFunc(ALBHV_Nest, 0x75C810)
BHVFunc(ALBHV_ApproachNest, 0x75CB60)
BHVFunc(ALBHV_Greet, 0x75CF80)
BHVFunc(ALBHV_CalcMeetPlayer, 0x75D010)
BHVFunc(ALBHV_SuriSuri, 0x75D030)
BHVFunc(ALBHV_SuriSuriPlayer, 0x75D0F0)
BHVFunc(ALBHV_Anger, 0x75D4C0)
BHVFunc(ALBHV_Genkotu, 0x75D590)
BHVFunc(ALBHV_Kick, 0x75D600)
BHVFunc(ALBHV_Punch, 0x75D670)
BHVFunc(ALBHV_PokaPoka, 0x75D6E0)
BHVFunc(ALBHV_Akanbe, 0x75D750)
BHVFunc(ALBHV_AttackPlayer, 0x75D7B0)
BHVFunc(ALBHV_Pleasure, 0x75DB80)
BHVFunc(ALBHV_Pain, 0x75DE10)
BHVFunc(ALBHV_Awawa, 0x75E0C0)
BHVFunc(ALBHV_RunawayFromPlayer, 0x75E2C0)
BHVFunc(ALBHV_WatchTV, 0x75E6C0)
BHVFunc(ALBHV_ListenRadicase, 0x75E890)
BHVFunc(ALBHV_JumpFromHorse, 0x75EA60)
BHVFunc(ALBHV_RideHorse, 0x75EAF0)
BHVFunc(ALBHV_GoToTV, 0x75EDA0)
BHVFunc(ALBHV_GoToRadicase, 0x75EE50)
BHVFunc(ALBHV_GoToOrgan, 0x75EF00)
BHVFunc(ALBHV_GoToHorse, 0x75EF20)
BHVFunc(ALBHV_GoToBox, 0x75EFA0)
BHVFunc(ALBHV_Sing1, 0x75F370)
BHVFunc(ALBHV_Sing2, 0x75F4E0)
BHVFunc(ALBHV_Sing3, 0x75F670)
BHVFunc(ALBHV_Sing4, 0x75F800)
BHVFunc(ALBHV_Sing5, 0x75F990)
BHVFunc(ALBHV_SingNormal, 0x75FD20)
BHVFunc(ALBHV_SingOnchi, 0x75FEB0)
BHVFunc(ALBHV_ListenSing, 0x75FFF0)
BHVFunc(ALBHV_Urusai, 0x760120)
BHVFunc(ALBHV_FuriFuriDance, 0x7606C0)
BHVFunc(ALBHV_KuruKuruDance, 0x760790)
BHVFunc(ALBHV_BoxDance, 0x760860)
BHVFunc(ALBHV_GoGoDance, 0x7608C0)
BHVFunc(ALBHV_RadioDance, 0x760960)
BHVFunc(ALBHV_WatchDance, 0x760AD0)
BHVFunc(ALBHV_WatchDanceStand, 0x760C00)
BHVFunc(ALBHV_Maracas, 0x761050)
BHVFunc(ALBHV_Bell, 0x761230)
BHVFunc(ALBHV_Drum, 0x761330)
BHVFunc(ALBHV_Fue, 0x761560)
BHVFunc(ALBHV_Castanets, 0x761670)
BHVFunc(ALBHV_Rappa, 0x761830)
BHVFunc(ALBHV_Cymbal, 0x761960)
BHVFunc(ALBHV_Tambourine, 0x761AF0)
BHVFunc(ALBHV_ListenMusic, 0x761C70)
BHVFunc(ALBHV_GoToPlayerPleasure, 0x761F60)
BHVFunc(ALBHV_NeedFruit, 0x762070)
BHVFunc(ALBHV_Goo, 0x762140)
BHVFunc(ALBHV_HungryDada, 0x7622B0)
BHVFunc(ALBHV_Seki, 0x762610)
BHVFunc(ALBHV_Kusyami, 0x762790)
BHVFunc(ALBHV_Kayui, 0x7628D0)
BHVFunc(ALBHV_Hanamizu, 0x7629E0)
BHVFunc(ALBHV_Syakkuri, 0x762B20)
BHVFunc(ALBHV_Haraita, 0x762C80)
BHVFunc(ALBHV_Syabon, 0x763050)
BHVFunc(ALBHV_Houki, 0x763260)
BHVFunc(ALBHV_Garagara, 0x763300)
BHVFunc(ALBHV_Hanabi, 0x7633A0)
BHVFunc(ALBHV_Book, 0x763610)
BHVFunc(ALBHV_Minicar, 0x763760)
BHVFunc(ALBHV_Doll, 0x763910)
BHVFunc(ALBHV_Hopping, 0x7639E0)
BHVFunc(ALBHV_Kaoarau, 0x763B20)
BHVFunc(ALBHV_Bakuten, 0x763BB0)
BHVFunc(ALBHV_Draming, 0x763C00)
BHVFunc(ALBHV_BreakDance, 0x763D70)
BHVFunc(ALBHV_GoGoDanceMini, 0x763DC0)
BHVFunc(ALBHV_Dosukoi, 0x763E10)
BHVFunc(ALBHV_InoDash, 0x763EA0)
BHVFunc(ALBHV_Otakai, 0x763FC0)
BHVFunc(ALBHV_ShiriDance, 0x764060)
BHVFunc(ALBHV_BoxDanceDX, 0x7640E0)
BHVFunc(ALBHV_Onara, 0x764160)
BHVFunc(ALBHV_Fire, 0x7642E0)
BHVFunc(ALBHV_PyonPyon, 0x7643B0)
BHVFunc(ALBHV_Fukkin2, 0x764440)
BHVFunc(ALBHV_Fukkin, 0x7644D0)
BHVFunc(ALBHV_Denguri, 0x764500)
BHVFunc(ALBHV_GoroGoro, 0x7645B0)
BHVFunc(ALBHV_HaraSuberi, 0x764660)
BHVFunc(ALBHV_Shippo, 0x764700)
BHVFunc(ALBHV_Art, 0x76E890)

void Chao_Init();

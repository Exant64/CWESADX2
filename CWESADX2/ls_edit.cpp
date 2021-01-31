#include "pch.h"
#include "SADXModLoader.h"
#include <math.h>

unsigned char byte_80DB95DC = 0;
unsigned char byte_80DB95DB = 0;
unsigned char byte_80DB95D9 = 0;
NJS_POINT3 stru_80DB95ED;
struct NJS_RGB
{
	float r;
	float g;
	float b;
};

struct LE_PALIGHT_ENV
{
	char stgNo;
	char actNo;
	char chrNo;
	char flgs;
	NJS_POINT3 vec;
	float dif;
	NJS_RGB amb;
	float cpow;
	NJS_RGB co;
	float spow;
	NJS_RGB spe;
	float cpow2;
	NJS_RGB co2;
	float spow2;
	NJS_RGB spe2;
};

LE_PALIGHT_ENV stru_80DB96A1;

struct PALIGHT_EDIT
{
	const char* text;
	float* value;
};

PALIGHT_EDIT off_807A9108[30] =
{
  { "%s", NULL },
  { "%s", NULL },
  { "X     =%+2.3f", &stru_80DB95ED.x },
  { "Y     =%+2.3f", &stru_80DB95ED.y },
  { "Z     =%+2.3f", &stru_80DB95ED.z },
  { "DIF   =%2.3f(0~4)", &stru_80DB96A1.dif },
  { "AMBrgb=%2.3f(0~4)", &stru_80DB96A1.amb.r },
  { "AMB R =%2.3f(0~4)", &stru_80DB96A1.amb.r },
  { "AMB G =%2.3f(0~4)", &stru_80DB96A1.amb.g },
  { "AMB B =%2.3f(0~4)", &stru_80DB96A1.amb.b },
  { "CO pow=%3.2f(0~99)", &stru_80DB96A1.cpow },
  { "CO rgb=%2.3f(0~4)", &stru_80DB96A1.co.r },
  { "CO  R =%2.3f(0~4)", &stru_80DB96A1.co.r  },
  { "CO  G =%2.3f(0~4)", &stru_80DB96A1.co.g  },
  { "CO  B =%2.3f(0~4)", &stru_80DB96A1.co.b  },
  { "SP pow=%3.2f(0~99)", & stru_80DB96A1.spow },
  { "SP rgb=%2.3f(0~4)", &stru_80DB96A1.spe.r},
  { "SP  R =%2.3f(0~4)", &stru_80DB96A1.spe.r },
  { "SP  G =%2.3f(0~4)", &stru_80DB96A1.spe.g },
  { "SP  B =%2.3f(0~4)", &stru_80DB96A1.spe.b },
  { "CO2pow=%3.2f(0~99)", &stru_80DB96A1.cpow2 },
  { "CO2rgb=%2.3f(0~4)", &stru_80DB96A1.co2.r },
  { "CO2 R =%2.3f(0~4)", &stru_80DB96A1.co2.r },
  { "CO2 G =%2.3f(0~4)", &stru_80DB96A1.co2.g },
  { "CO2 B =%2.3f(0~4)", &stru_80DB96A1.co2.b },
  { "SP2pow=%3.2f(0~99)", &stru_80DB96A1.spow2 },
  { "SP2rgb=%2.3f(0~4)", &stru_80DB96A1.spe2.r },
  { "SP2 R =%2.3f(0~4)", &stru_80DB96A1.spe2.r },
  { "SP2 G =%2.3f(0~4)", &stru_80DB96A1.spe2.g },
  { "SP2 B =%2.3f(0~4)", &stru_80DB96A1.spe2.b }
};

unsigned int dword_80FC1131[512 * 10];

unsigned int __fastcall GetLight(int a1, int a2, int a3)
{
	return dword_80FC1131[512 * a1 + 2 * a3 + a2];
}

// positive sp value has been detected, the output may be wrong!
void __fastcall CalculateLight(int a1, LE_PALIGHT_ENV* a2)
{
	double v3; // fp30
	double v4; // fp31
	NJS_BGRA* v6; // r31
	int i; // r30
	double v8; // fp28
	double v9; // fp27
	double v10; // fp1
	double v11; // fp0
	double v12; // fp2
	double v13; // fp1
	unsigned int v14; // fp0
	unsigned int v15; // r0
	unsigned int v16; // r4
	unsigned int v17; // r5
	double v18; // fp27
	double v19; // fp1
	double v20; // fp6
	double v21; // fp0
	double v22; // fp1
	unsigned int v23; // fp0
	unsigned int v24; // r0
	unsigned int v25; // r4
	unsigned int v26; // r5
	unsigned int v27; // r0


	v4 = 255.0f;
	v6 = (NJS_BGRA*)&dword_80FC1131[512 * a1];
	for (i = 0; i < 256; ++i)
	{
		v9 = powf(((255 - i) / 255.0f), a2->cpow);
		v10 = powf(i / 255.0f, a2->cpow2);
		v11 = (float)((float)(a2->co.r * (float)v9) + (float)(a2->co2.r * (float)v10));
		v12 = (a2->amb.g + ((a2->co.g * v9) + (a2->co2.g * v10)));
		v13 = (float)(a2->amb.b + (float)((float)(a2->co.b * (float)v9) + (float)(a2->co2.b * (float)v10)));
		v14 = (int)(float)((float)v4 * (float)(a2->amb.r + (float)v11));
		v15 = v14;
		if (v14 <= 255)
		{
			if (v14 < 0)
				v15 = 0;
		}
		else
		{
			v15 = 255;
		}
		v16 = (int)(float)((float)v4 * (float)v12);
		if (v16 <= 255)
		{
			if (v16 < 0)
				v16 = 0;
		}
		else
		{
			v16 = 255;
		}
		v17 = (int)(float)((float)v4 * (float)v13);
		if (v17 <= 255)
		{
			if (v17 < 0)
				v17 = 0;
		}
		else
		{
			v17 = 255;
		}
		//*v6 = v17 | (v15 << 16) | 0xFF000000 | (v16 << 8);
		v6->a = 0xFF;
		v6->r = v15;
		v6->g = v16;
		v6->b = v17;
		//PrintDebug("%d %d %d \n", v15, v16, v17);
		v18 = powf(((255 - i) / 255.0f), a2->spow);
		v19 = powf(i / 255.0f, a2->spow2);
		v20 = (float)v19;
		v21 = (float)((float)(a2->spe.r * (float)v18) + (float)(a2->spe2.r * (float)v19));
		v22 = (float)((float)(a2->spe.g * (float)v18) + (float)(a2->spe2.g * (float)v19));
		v23 = (int)(float)((float)v4 * (float)v21);
		v24 = v23;
		if (v23 <= 255)
		{
			if (v23 < 0)
				v24 = 0;
		}
		else
		{
			v24 = 255;
		}
		v25 = (int)(float)((float)v4 * (float)v22);
		if (v25 <= 255)
		{
			if (v25 < 0)
				v25 = 0;
		}
		else
		{
			v25 = 255;
		}
		v26 = (int)(float)((float)v4 * (float)((float)(a2->spe.b * (float)v18) + (float)(a2->spe2.b * (float)v20)));
		if (v26 <= 255)
		{
			if (v26 < 0)
				v26 = 0;
		}
		else
		{
			v26 = 255;
		}
//		v6[1] = v26 | (v24 << 16) | 0xFF000000 | (v25 << 8);
		v6[1].a = 0xFF;
		v6[1].r = v24;
		v6[1].g = v25;
		v6[1].b = v26;
		v6 += 2;
	}
}

void DisplayLSInfo(int a1, int a2)
{
	memcpy(&stru_80DB96A1, (void*)0x03ABDAF0, sizeof(LE_PALIGHT_ENV));
	CalculateLight(byte_80DB95D9, &stru_80DB96A1);
	SetDebugFontColor(0xFFEEEEAA);
	short levelandact = GetLevelAndAct();
	char a = HIBYTE(levelandact);
	DisplayDebugStringFormatted(((a1 + 7) << 16) | (a2 + 1), "ST %d ACT %d", a, (char)levelandact + 1);
	if (byte_80DB95DB >= byte_80DB95DC)
	{
		if (byte_80DB95DB - byte_80DB95DC > 19)
			byte_80DB95DC = byte_80DB95DB - 19;
	}
	else
	{
		byte_80DB95DC = byte_80DB95DB;
	}
	int v7 = a1 << 16;
	int v8 = (a1 + 1) << 16;
	for (int i = 0; i < 20; ++i)
	{
		int v10 = byte_80DB95DC + i;
		if (v10 == byte_80DB95DB)
		{
			SetDebugFontColor(0xFF66DD66);
			DisplayDebugStringFormatted(v7 | (a2 + i + 2), ">");
		}
		SetDebugFontColor(0xFFDDDDDD);
		PALIGHT_EDIT* v11 = &off_807A9108[v10];
		float* v12 = (float*)v11->value;
		const char* v13, *v14;
		int v15;
		if (v12)
		{
			DisplayDebugStringFormatted(v8 | (a2 + i + 2), v11->text, *v12);
			continue;
		}
		if (v10)
		{
			if (v10 != 1)
				continue;
			v13 = v11->text;
			v14 = "NO USE XYZ";
			v15 = v8 | (a2 + i + 2);
			if ((stru_80DB96A1.flgs & 2) != 0)
				v14 = "USE XYZ";
		}
		else
		{
			v13 = v11->text;
			v14 = "FILE";
			v15 = v8 | (a2 + i + 2);
			if ((stru_80DB96A1.flgs & 1) != 0)
				v14 = "THIS INFO";
		}
		DisplayDebugStringFormatted(v15, v13, v14);
	}

	//DrawRect_DrawNowMaybe(0, 400, 640, 480, -1, 0xFF000000);
	NJS_POINT2COL lightDisp1;
	NJS_POINT2 p[4];
	NJS_COLOR col[4];
	NJS_TEX uv[4];
	uv[0] = { 0 };
	uv[1] = { 0 };
	uv[2] = { 0 };
	uv[3] = { 0 };
	p[0] = { 0 };
	p[1] = { 0 };
	p[2] = { 0 };
	p[3] = { 0 };
	lightDisp1.p = (NJS_POINT2*)p;
	lightDisp1.col = col;
	lightDisp1.tex = uv;
	lightDisp1.num = 4;
	float v16 = 64;
	float v18 = 405;
	float v19 = 419;
	float v20 = 2;
	int v17 = 0;
	do
	{
		unsigned int v21 = GetLight(byte_80DB95D9, 0, v17);
		p[2].x = v16;
		p[2].y = v18;
		col[2].color = v21;
		p[3].x = v16;
		p[3].y = v19;
		col[3].color = v21;

		if (v17 > 0)
			njDrawTriangle2D_SomeOtherVersion(&lightDisp1, 4, -1, 0x20);
			
		++v17;
		v16 += v20;
		p[0] = p[2];
		col[0] = col[2];
		p[1] = p[3];
		col[1] = col[3];
	} while (v17 < 256);

	uv[0] = { 0 };
	uv[1] = { 0 };
	uv[2] = { 0 };
	uv[3] = { 0 };
	p[0] = { 0 };
	p[1] = { 0 };
	p[2] = { 0 };
	p[3] = { 0 };
	lightDisp1.p = (NJS_POINT2*)p;
	lightDisp1.col = col;
	lightDisp1.tex = uv;
	lightDisp1.num = 4;
	 v16 = 64;
	 v18 = 429;
	 v19 = 443;
	 v20 = 2;
	 v17 = 0;
	do
	{
		unsigned int v21 = GetLight(byte_80DB95D9, 1, v17);
		p[2].x = v16;
		p[2].y = v18;
		col[2].color = v21;
		p[3].x = v16;
		p[3].y = v19;
		col[3].color = v21;

		if (v17 > 0)
			njDrawTriangle2D_SomeOtherVersion(&lightDisp1, 4, -1, 0x20);

		++v17;
		v16 += v20;
		p[0] = p[2];
		col[0] = col[2];
		p[1] = p[3];
		col[1] = col[3];
	} while (v17 < 256);
}
void DisplayLSInfo_(ObjectMaster* a1)
{
	DisplayLSInfo(0, 10);
}
void LS_Init()
{
	byte_80DB95DB = 0;
	byte_80DB95DC = 0;
	byte_80DB95D9 = 2;
	//byte_80DB95DD = byte_80DB95D9;
//	LoadObject(LoadObj_Data1, 4, DisplayLSInfo_);
}
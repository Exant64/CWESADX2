#include "SADXModLoader.h"
#include "motiontable.h"
#include "data/motion/alm_crayonfix.nam"
#include "IniFile.hpp"
#include "al_kinder_bm.h"
#include "al_toy/alo_toy.h"
#include "chao.h"
#include "al_sound.h"
#include "patchedcolors.h"
#include "data/mixColorTable.h"
#include "ChaoMain.h"

#include "data/accessory/ala_glasses_round.nja"
#include "data/accessory/ala_glasses_square.nja"
#include "data/accessory/ala_bowtie_red.nja"
#include "data/accessory/ala_baseballcap.nja"
#include "data/accessory/ala_glasses_aviators.nja"
#include "data/accessory/ala_headphones.nja"
#include "data/cwe/object_common_cnk/alo_missing.nja"
#include "AL_ModAPI.h"

extern "C"
{
	bool shinyjewelegg;

	__declspec(naked) void DarkEyeHack()
	{
		__asm
		{
			xor eax, eax
			retn
		}
	}
	FunctionPointer(void, ColorChunkModel, (int a1), 0x78A320);
	void __cdecl EggColoring(NJS_CNK_MODEL* a1, int a2)
	{
		DataArray(int, off_389D7B8, 0x389D7B8, 4);
		DataArray(int, dword_389D7B8, 0x389D7B8, 6);
		DataPointer(D3DMATRIX, stru_389D7E8, 0x0389D7E8);
		DataArray(NJS_TEXLIST, ChaoTexLists, 0x033A1038, 7);
		DataArray(int, dword_389D828, 0x389D828, 13);
		DataArray(int, dword_088A3D8, 0x088A3D8, 13);
		switch (a2)
		{
		case SADXEggColour_Black_TwoTone:
		case SADXEggColour_Normal:
			DisableChunkMaterialFlags();
			break;
		case SADXEggColour_Yellow_MonoTone:
		case SADXEggColour_White_MonoTone:
		case SADXEggColour_Brown_MonoTone:
		case SADXEggColour_Aqua_MonoTone:
		case SADXEggColour_Pink_MonoTone:
		case SADXEggColour_Blue_MonoTone:
		case SADXEggColour_Grey_MonoTone:
		case SADXEggColour_Green_MonoTone:
		case SADXEggColour_Red_MonoTone:
		case SADXEggColour_LightGreen_MonoTone:
		case SADXEggColour_Purple_MonoTone:
		case SADXEggColour_Orange_MonoTone:
		case SADXEggColour_Black_MonoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(9u);
			ColorChunkModel(dword_389D828[a2 - SADXEggColour_Yellow_MonoTone]);
			break;
		case SADXEggColour_Yellow_TwoTone:
		case SADXEggColour_White_TwoTone:
		case SADXEggColour_Brown_TwoTone:
		case SADXEggColour_Aqua_TwoTone:
		case SADXEggColour_Pink_TwoTone:
		case SADXEggColour_Blue_TwoTone:
		case SADXEggColour_Green_TwoTone:
		case SADXEggColour_Red_TwoTone:
		case SADXEggColour_LightGreen_TwoTone:
		case SADXEggColour_Purple_TwoTone:
		case SADXEggColour_Orange_TwoTone:
		case SADXEggColour_Grey_TwoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(8u);
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
			ColorChunkModel(dword_389D828[a2 - SADXEggColour_Yellow_TwoTone]);
			break;
		case SADXEggColour_NormalShiny:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(6u);
			Direct3D_SetTexList(ChaoTexLists);
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
			//SetChunkTextureIndexB(0x22u);
			//Direct3D_Device->
			break;
		case SADXEggColour_YellowShiny_MonoTone:
		case SADXEggColour_WhiteShiny_MonoTone:
		case SADXEggColour_BrownShiny_MonoTone:
		case SADXEggColour_AquaShiny_MonoTone:
		case SADXEggColour_PinkShiny_MonoTone:
		case SADXEggColour_BlueShiny_MonoTone:
		case SADXEggColour_GreyShiny_MonoTone:
		case SADXEggColour_GreenShiny_MonoTone:
		case SADXEggColour_RedShiny_MonoTone:
		case SADXEggColour_LightGreenShiny_MonoTone:
		case SADXEggColour_PurpleShiny_MonoTone:
		case SADXEggColour_OrangeShiny_MonoTone:
		case SADXEggColour_BlackShiny_MonoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(15u);
			Direct3D_SetTexList(ChaoTexLists);
			ColorChunkModel(dword_389D828[a2 - SADXEggColour_YellowShiny_MonoTone]);
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
			SetChunkTextureIndexB(0x22u);
			break;
		case SADXEggColour_YellowShiny_TwoTone:
		case SADXEggColour_WhiteShiny_TwoTone:
		case SADXEggColour_BrownShiny_TwoTone:
		case SADXEggColour_AquaShiny_TwoTone:
		case SADXEggColour_PinkShiny_TwoTone:
		case SADXEggColour_BlueShiny_TwoTone:
		case SADXEggColour_GreyShiny_TwoTone:
		case SADXEggColour_GreenShiny_TwoTone:
		case SADXEggColour_RedShiny_TwoTone:
		case SADXEggColour_LightGreenShiny_TwoTone:
		case SADXEggColour_PurpleShiny_TwoTone:
		case SADXEggColour_OrangeShiny_TwoTone:
		case SADXEggColour_BlackShiny_TwoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(0xEu);
			Direct3D_SetTexList(ChaoTexLists);
		LABEL_8:
			ColorChunkModel(dword_389D828[a2 - SADXEggColour_YellowShiny_TwoTone]);
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
			SetChunkTextureIndexB(0x22u);
			break;
		case SADXEggColour_YellowJewel:
		case SADXEggColour_WhiteJewel:
		case SADXEggColour_PinkJewel:
		case SADXEggColour_BlueJewel:
		case SADXEggColour_GreenJewel:
		case SADXEggColour_PurpleJewel:
		case SADXEggColour_AquaJewel:
		case SADXEggColour_RedJewel:
		case SADXEggColour_BlackJewel:
		case SADXEggColour_LightGreenJewel:
		case SADXEggColour_OrangeJewel:
		case SADXEggColour_Pearl:
		case SADXEggColour_Metal1:
		case SADXEggColour_Metal2:
		case SADXEggColour_Glass:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(4u);
			Direct3D_SetTexList(ChaoTexLists);
			ColorChunkModel(-1);
			SetChunkTextureIndexA(a2 - 36);
			break;
			//Edited part, added shiny jewel eggs.
		case 69:
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
		case 80:
		case 81:
		case 82:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(0xEu);
			Direct3D_SetTexList(ChaoTexLists);
			ColorChunkModel((int)dword_088A3D8[a2 - SADXEggColour_Glass]);
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
			SetChunkTextureIndexB(0x22u);
		default:
			return;
		}
	}

	DataArray(NJS_BGRA, ShinyJewelColors, 0x0088A3D8, 28);

	//Shiny Jewel Patch SADX
	void PatchShinyJewelPC()
	{
		for (int i = 0; i < 28; i++)
			ShinyJewelColors[i].a = 0xA0;
	}

	void PatchShinyJewelGC()
	{
		// 76, 200, 0, 255 - original
		// 0, 255, 76, 200 - gc
		for (int i = 0; i < 28; i++)
		{
			std::swap(ShinyJewelColors[i].b, ShinyJewelColors[i].r);
			std::swap(ShinyJewelColors[i].g, ShinyJewelColors[i].a);
		}
	}
	FunctionPointer(void, AL_BlendGene, (ChaoDNA* parent1, ChaoDNA* parent2, ChaoDNA* a3), 0x071DFC0);
	void AL_CreateChildGene(ObjectMaster* pMotherTask, ObjectMaster* pFatherTask, ChaoDNA* pChildGene)
	{
		ChaoDNA FatherGene;
		ChaoDNA MotherGene;
		chaowk* wk1, *wk2;
		wk1 = (chaowk*)pMotherTask->Data1;
		wk2 = (chaowk*)pFatherTask->Data1;
		memcpy(&MotherGene, &wk1->pParamGC->DNA, sizeof(ChaoDNA));
		memcpy(&FatherGene, &wk2->pParamGC->DNA, sizeof(ChaoDNA));

		AL_BlendGene(&MotherGene, &FatherGene, pChildGene);
		for (int i = 0; i < 210; i++)
		{
			if (pChildGene->Color1 == mixColorTable[i].color1 && pChildGene->Color2 == mixColorTable[i].color2)
			{
				pChildGene->Color1 = mixColorTable[i].result;
				pChildGene->Color2 = mixColorTable[i].result;
				break;
			}
		}
	}

	void RegisterCWEData()
	{
		AL_ModAPI_Init();

#define ACCESSORYRINGS 2500
		BlackMarketItemAttributes baseballAttrib = { ACCESSORYRINGS,500,0,-1,-1,0 };
		BlackMarketItemAttributes bowtieRed = { ACCESSORYRINGS,500,0,-1,-1,0 };
		BlackMarketItemAttributes roundGlasses = { ACCESSORYRINGS,500,0,-1,-1,0 };
		BlackMarketItemAttributes aviators = { ACCESSORYRINGS,500,0,-1,-1,0 };
		BlackMarketItemAttributes headphones = { ACCESSORYRINGS,500,0,-1,-1,0 };

		RegisterChaoAccessory(EAccessoryType::Head, &object_ala_baseball, &CWE_OBJECT_TEXLIST, &baseballAttrib, "Baseball Cap", "");
		RegisterChaoAccessory(EAccessoryType::Head, &object_ala_bowtie_red, &CWE_OBJECT_TEXLIST, &bowtieRed, "Bowtie", "");
		RegisterChaoAccessory(EAccessoryType::Face, &object_ala_glasses_round, &CWE_OBJECT_TEXLIST, &roundGlasses, "Round Glasses", "");
		RegisterChaoAccessory(EAccessoryType::Face, &object_ala_glasses_aviators, &CWE_OBJECT_TEXLIST, &aviators, "Aviators", "Glasses for high flyers.");
		RegisterChaoAccessory(EAccessoryType::Head, &headphone_cups, &CWE_OBJECT_TEXLIST, &headphones, "Headphones", "Music makes you lose control.");
		PrintDebug("%d count \n", BlackMarketCategories[ChaoItemCategory_Accessory].Count++);

		CallRegisteredHooks();

		for (int i = 0; i < 50; i++)
		{
			BlackMarketItemAttributes missingattrib = { ACCESSORYRINGS,500,0,-1,-1,0 };
			RegisterChaoAccessory(EAccessoryType::Head, &object_alo_missing, &CWE_OBJECT_TEXLIST, 0, "Missing Item", "Missing Item");
			//RegisterChaoHat(&object_alo_missing, &CWE_OBJECT_TEXLIST, 0, "Missing Item", "Missing Item", true);
		}
		AL_ModAPI_UpdatePtr();
	}

	int CWE_Loaded = 0;
	void HookRegisterCWEData()
	{
		PrintDebug("ChaoMain Prolog\n");
		if (!CWE_Loaded)
		{

			RegisterCWEData();
			CWE_Loaded = 1;
		}
	}
	struct WIDELINE_TEXDATA
	{
		int index;
		NJS_COLOR pColor[2];
		float uv1;
		float uv2;
		float uv3;
		float uv4;
		float uv5;
		float uv6;
		float uv7;
		float uv8;
	};
	struct LinePosition
	{
		NJS_POINT3 Pos[2];
		float fWidth[2];
	};

	const int sub_7A6790Ptr = 0x7A6790;
	void sub_7A6790(float* a1, WIDELINE_TEXDATA* a2, NJS_POINT3* a3)
	{
		__asm
		{
			mov esi, a3
			mov edi, a2
			mov ebx, a1
			call sub_7A6790Ptr
		}
	}
	/*
	int FUN_8c044d00(int param_1, int param_2, int* param_3)

	{
		int uVar1;
		int* puVar2;
		int iVar3;
		int in_fr0;

		if ((DAT_8c88f610 <= *(float*)(param_2 + 8)) || (DAT_8c88f610 <= *(float*)(param_2 + 0x14))) {
			puVar2 = param_3 + 1;
			iVar3 = param_2 + 0xc;
			if (DAT_8c88f610 <= *(float*)(param_2 + 8)) {
				if (DAT_8c88f610 <= *(float*)(param_2 + 0x14)) {
					*(int*)(param_1 + 0x18) = *param_3;
					*(int*)(param_1 + 0x1c) = *puVar2;
				}
				else {
					*(int*)(param_1 + 0x18) = *param_3;
					FUN_8c044cac(iVar3, param_2, *puVar2, *param_3);
					*(int*)(param_1 + 0x1c) = in_fr0;
				}
			}
			else {
				FUN_8c044cac(param_2, iVar3, *param_3, *puVar2);
				*(int*)(param_1 + 0x18) = in_fr0;
				*(int*)(param_1 + 0x1c) = *puVar2;
			}
			FUN_8c085f14(param_2, param_1);
			FUN_8c085f14(iVar3, param_1 + 0xc);
			uVar1 = 1;
		}
		else {
			uVar1 = 0;
		}
		return uVar1;
	}
	*/

	const int sub_7A6520Ptr = 0x7A6520;
	void sub_7A6520(LinePosition* a1, float* a2, NJS_VECTOR* a3)
	{
		//int retval;
		__asm
		{
			mov ebx, a1
			mov edi, a2
			mov esi, a3
			call sub_7A6520Ptr
			//mov retval, eax
		}
	}

	void FUN_8c044cac(float* param_1, float* param_2)

	{
		float fVar1;

		if (param_1[2] == param_2[2]) {
			return;
		}
		fVar1 = (MinDrawDistance - param_1[2]) / (param_2[2] - param_1[2]);
		param_1[2] = MinDrawDistance;
		*param_1 = fVar1 * (*param_2 - *param_1) + *param_1;
		param_1[1] = fVar1 * (param_2[1] - param_1[1]) + param_1[1];
		return;
	}

	void FUN_8c085f14(float* param_1, float* param_2)

	{
		float fVar1;
		float fVar2;

		fVar2 = _nj_screen_.dist;
		fVar1 = param_1[2];
		//*(float*)(param_2 + 8) = fVar1;
		fVar2 = fVar2 / fVar1;
		fVar1 = *param_1;
		*(float*)(param_2 + 4) = 1 * fVar2 * param_1[1];
		*(float*)(param_2 + 0) = 1 * fVar2 * fVar1;
		
		return;
	}

	void FUN_8c0450a0(float* param_1, int param_2, float* param_3)

	{
		int iVar1;
		int iVar2;
		float* pfVar3;
		int iVar4;
		int iVar5;
		float in_fr0;
		float fVar6;
		float fVar7;
		float fVar8;
		NJS_VECTOR NStack164;
		float afStack152[2];
		float fStack144;
		float afStack140[24];
		float local_2c[4];

		if (!MissedFrames) {
			in_fr0 = atan2f(param_1[4] - param_1[1], param_1[3] - *param_1);
			afStack152[0] = in_fr0 * 10430.38;
			pfVar3 = param_1 + 6;
			fVar6 = 1.0;
			iVar4 = 0;
			iVar5 = 0;
			fVar8 = 320.0;
			fVar7 = 240.0;
			if (param_1 < pfVar3) {
				do {
					fStack144 = param_1[2];
					FUN_8c085f14(afStack152, &NStack164.x);
					NStack164.x = NStack164.x * *(float*)(param_2 + iVar5);
					NStack164.y = NStack164.y * *(float*)(param_2 + iVar5);
					afStack140[iVar4 * 6] = (*param_1 - NStack164.x) + fVar8;
					iVar2 = iVar4 + 1;
					afStack140[iVar4 * 6 + 1] = param_1[1] + NStack164.y + fVar7;
					afStack140[iVar4 * 6 + 2] = fVar6 / param_1[2];
					afStack140[iVar4 * 6 + 5] = *(float*)((int)param_3 + iVar5 + 4);
					afStack140[iVar2 * 6] = *param_1 + NStack164.x + fVar8;
					afStack140[iVar2 * 6 + 1] = (param_1[1] - NStack164.y) + fVar7;
					iVar1 = iVar4 * 6;
					param_1 = param_1 + 3;
					iVar4 = iVar4 + 2;
					afStack140[iVar2 * 6 + 2] = afStack140[iVar1 + 2];
					afStack140[iVar2 * 6 + 5] = *(float*)((int)param_3 + iVar5 + 4);
					iVar5 = iVar5 + 4;
				} while (param_1 < pfVar3);
			}
			iVar4 = 0;
			pfVar3 = afStack140;
			while (pfVar3 < local_2c) {
				pfVar3[3] = *(float*)((int)param_3 + iVar4 + 0xc);
				pfVar3[4] = *(float*)((int)param_3 + iVar4 + 0x10);
				pfVar3[9] = *(float*)((int)param_3 + iVar4 + 0x14);
				pfVar3[10] = *(float*)((int)param_3 + iVar4 + 0x18);
				pfVar3 = pfVar3 + 0xc;
				iVar4 = iVar4 + 0x10;
			}
			njDrawTextureMemList((NJS_TEXTURE_VTX*)afStack140, 4, *param_3, 1);
		}
		return;
	}




	int FUN_8c044dca(LinePosition* param_1, NJS_VECTOR* param_2, Rotation3* param_3, float* param_4, float param_5)

	{
		NJS_VECTOR fStack64;
		NJS_VECTOR uStack52;
		NJS_VECTOR auStack40[2];
		//NJS_VECTOR auStack28;

		njPushMatrix(_nj_unit_matrix_);
		uStack52.y = 0.0;
		uStack52.x = 0.0;
		uStack52.z = -param_5;
		if (param_3->y != 0) {
			njRotateY(0, param_3->y);
		}
		if (param_3->x != 0) {
			njRotateX(0, param_3->x);
		}
		njCalcPoint(0, &uStack52, &fStack64);
		njPopMatrix(1);
		fStack64.x = param_2->x + fStack64.x;
		fStack64.y = param_2->y + fStack64.y;
		fStack64.z = param_2->z + fStack64.z;
		njCalcPoint(0, param_2, &auStack40[0]);
		njCalcPoint(0, &fStack64, &auStack40[1]);
		sub_7A6520(param_1, param_4, auStack40);
		//param_1->Pos[0].x = auStack40[0].x;
		//param_1->Pos[0].y = auStack40[0].y;
		//param_1->Pos[1].x = auStack40[1].x;
		//param_1->Pos[1].y = auStack40[1].y;
		FUN_8c085f14(&auStack40[0].x, &param_1->Pos[0].x);
		FUN_8c085f14(&auStack40[1].x, &param_1->Pos[1].x);
		return 1;
	
	}

	FunctionPointer(void, DrawWideLine3D, (NJS_POINT3* pPos, Rotation3* pAng, float* pWidthTable, int* pColor, float fLength),0x007A65E0);
	void __cdecl DrawWideLineDC(NJS_VECTOR* param_1, Rotation3* param_2, float* param_3, WIDELINE_TEXDATA* param_4, float param_5)
	{
		int iVar1;
		LinePosition auStack36;

		iVar1 = FUN_8c044dca(&auStack36, param_1, param_2, param_3, param_5);
		if (iVar1 == 1) {
			//FUN_8c0450a0((float*)&auStack36, (int)auStack36.fWidth, (float*)param_4);
			sub_7A6790(auStack36.fWidth, param_4, auStack36.Pos);
		}
	}
	WIDELINE_TEXDATA texData = { 0x19A3A, {0xFFFFFFFF, 0xFFFFFFFF}, 1.0,1.0,1.0,0,0,1,0,0 };
	float floats[2] = {0.15f, 3};
	int colors[2] = { 0xFFFFFFFF, 0xFFFFFFFF };
	FunctionPointer(void, sub_407A00,(NJS_MODEL_SADX* model, float scale), 0x407A00);
	void OstandlightDisp(ObjectMaster* a1)
	{
		
		chaowk* v1; // edi
		Angle v2; // eax
		NJS_OBJECT* v3; // esi

		v1 = (chaowk*)a1->Data1;
		if (!MissedFrames)
		{
			int iVar6 = (int)v1;
			SetTextureToLevelObj();
			njPushMatrix(0);
			njTranslateV(0, &v1->entity.Position);
			v2 = v1->entity.Rotation.y;
			if (v2)
			{
				njRotateY(0, (unsigned __int16)v2);
			}
			sub_407A00((NJS_MODEL_SADX*)(*(int*)(iVar6 + 0xC)), 1.0);
			njPopMatrix(1u);

			njColorBlendingMode(0, 1);
			njColorBlendingMode(1,10);

			NJS_VECTOR vec = { 0.5f, 11.15f, 0 };
			njAddVector(&vec, &v1->entity.Position);

			
			Rotation3 rot;
			rot.z = *(int*)(iVar6 + 0x1c);
			rot.y = (*(int*)(iVar6 + 0x18) + 0x800);
			rot.x = (*(int*)(iVar6 + 0x14) + (0x38e - *(int*)(iVar6 + 8)));
			floats[1] = *(float*)(iVar6 + 0x34);
			DrawWideLineDC(&vec, &rot, floats, &texData, *(float*)(iVar6 + 0x30));
			//DrawWideLine3D(&vec, &rot, floats, colors, *(float*)(iVar6 + 0x30));
		}
		/*
		//There are two light beams in the model.
	//At the moment I don't know how the game selects the one to use (if it uses both).
	//So I just disable the vertices for the other beam.
	//Entity Rotation X is beam X rotation 
	//Entity Rotation Y is object Y rotation
	//Entity Rotation Z is ???
	//Entity Scale X is light+beam model Y rotation (in degrees)
	//Entity Scale Y is beam length 
	//Entity Scale Z is beam width
		int v2; // eax@2
		EntityData1* v1; // esi@1
		v1 = a1->Data1;
		//Stretch beam vertices
		attach_01828538_2.points[19].z = (float)v1->Scale.y; //Beam length
		attach_01828538_2.points[20].z = (float)v1->Scale.y; //Beam length
		attach_01828538_2.points[19].x = (float)(-1.0f * v1->Scale.z); //Beam width
		attach_01828538_2.points[20].x = (float)v1->Scale.z; //Beam width
		//Disable the other beam
		attach_01828538_2.points[23].x = 0;
		attach_01828538_2.points[23].y = 0;
		attach_01828538_2.points[23].z = 0;
		attach_01828538_2.points[24].x = 0;
		attach_01828538_2.points[24].y = 0;
		attach_01828538_2.points[24].z = 0;
		if (!MissedFrames)
		{
			SetTextureToLevelObj();
			njPushMatrix(0);
			njTranslateV(0, &v1->Position);
			//Rotate the main object
			v2 = v1->Rotation.y;
			if (v2)
			{
				njRotateY(0, (unsigned __int16)v2);
			}
			//Render the main object model
			sub_407A00(&attach_01828C4C, 1.0f);
			//Render the light part without the beam
			njTranslate(0, object_01828564.pos[0], object_01828564.pos[1], object_01828564.pos[2]);
			njRotateXYZ(0, object_01828564.ang[0] + *(Sint32*)&v1->CharIndex, object_01828564.ang[1], object_01828564.ang[2]);
			sub_4094D0(&attach_01828538, 4, 1.0f);
			//Rotate and render the beam
			njRotateX(0, v1->Rotation.x);
			auto BaseRotation = atan2(Camera_Data1->Position.x - v1->Position.x, Camera_Data1->Position.y - v1->Position.y);
			//This is hardcoded for now until I figure out how to rotate it properly
			if (CurrentAct == 0 && CurrentCharacter != 5) njRotateZ(0, NJM_RAD_ANG(BaseRotation));
			if (CurrentAct == 1) njRotateZ(0, NJM_RAD_ANG(-BaseRotation));
			if (CurrentAct == 2 || CurrentCharacter == 5) njRotateZ(0, 16384);
			sub_4094D0(&attach_01828538_2, 4, 1.0f);
			njPopMatrix(1u);
		}
		*/
	}
	DataPointer(NJS_OBJECT, unk_1C28CA4, 0x1C28CA4);
	void __cdecl OStandLight_(ObjectMaster* a1)
	{
		*(int*)&a1->Data1->CharIndex = (a1->Data1->Scale.x
			* 65536.0
			* 0.002777777777777778);
		Collision_Init(a1, (CollisionData*)0x1AC4664, 1, 4u);
		char* puVar1;
		float fVar2;
		char* puVar3;
		int iVar4;
		float* puVar5;
		float* puVar6;
		float uVar7;
		int entityData1 = (int)a1->Data1;
		
		iVar4 = (int)malloc(0x28);
		a1->Data1->Object = (NJS_OBJECT*)iVar4;
		if (iVar4 != 0) {
			puVar6 = *(float**)(entityData1 + 0xc);
			puVar5 = (float*)unk_1C28CA4.model;
			uVar7 = puVar5[1];
			*puVar6 = *puVar5;
			puVar6[1] = uVar7;
			uVar7 = puVar5[3];
			puVar6[2] = puVar5[2];
			puVar6[3] = uVar7;
			uVar7 = puVar5[5];
			puVar6[4] = puVar5[4];
			puVar6[5] = uVar7;
			uVar7 = puVar5[7];
			puVar6[6] = puVar5[6];
			puVar6[7] = uVar7;
			uVar7 = puVar5[9];
			puVar6[8] = puVar5[8];
			puVar6[9] = uVar7;
			*(short*)(*(int*)(entityData1 + 0xc) + 0x14) =
				*(short*)(*(int*)(entityData1 + 0xc) + 0x14) + -1;
		}
		
		fVar2 = 0.099999994f;
		//if (*(float*)(entityData1 + 0x30) < 0.099999994f) {
			*(float*)(entityData1 + 0x30) = 28.0f;
		//}
		//if (*(float*)(entityData1 + 0x34) < fVar2) {
			*(float*)(entityData1 + 0x34) = 3.0f;
		//}
		a1->MainSub = OStandLight_Main;
		a1->DisplaySub = OStandLight_Display;
		a1->DeleteSub = (ObjectFuncPtr)nullsub;
		
	}
	
	//Vector3, Vector3, float, float, int
	DataArray(MotionTableAction, ChaoAnimations, 0x36A94E8, 625);
	__declspec(dllexport) void Init(const char *path, const HelperFunctions* function)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		//WriteJump(OStandLight, OStandLight_);
		//WriteJump(OStandLight_Display, OstandlightDisp);
		PrintDebug("sizeof(ChaoData) = %d \n", sizeof(ChaoData));
		
		//transporter fix
		DataPointer(NJS_MODEL_SADX, transporterTest, 0x33CFC44);
		for (int i = 0; i < transporterTest.nbMeshset; i++)
			transporterTest.meshsets[i].vertcolor = nullptr; //disables vertcolor
		for (int i = 361; i < 365; i++)
			transporterTest.points[i].x = -11.705f; //fixes floating screen

		ChaoMain_Init();

		//cwe init on chao world load	
		WriteCall((void*)0x0715AE5, HookRegisterCWEData);

		//SADX tree progress speedup
		*(float*)0x034BBADC = 0.00005f;

		al_kinder_bm_Init();

		if (config->getBool("Chao World Extended", "DarkEye", false))
		{
			WriteCall((void*)0x00737505, DarkEyeHack);
		}

		//Sound restoration
		WriteJump((void*)0x00736E90, AL_IconSetOverwrite);
		WriteCall((void*)0x0073BC47, SwimSound);
		WriteCall((void*)0x0073C292, SwimLandSound);
		WriteCall((void*)0x0075E31F, RunFromPlayerOverwrite);
		WriteCall((void*)0x0073CD4D, ThinkOverwrite);
		WriteCall((void*)0x0075E169, ShiwerOverwrite);

		WriteCall((void*)0x00717D7B, Accessory_Load);
		WriteCall((void*)0x00717B2D, Accessory_Load);
		//WriteCall((void*)0x00717D7B, Accessory_Load);

		//not available for now, needs a huge rewrite
		if (config->getBool("Chao World Extended", "3DEmotion", true))
		{
			PrintDebug("3D Emotion Balls not supported for now");
			//WriteData((int*)0x0073704E, (int)AL_IconDrawSub_);
		}

		UseBrightChao = config->getBool("Chao World Extended", "BrightChao", false);

		if (config->getBool("Chao World Extended", "ShinyJewelEgg", true))
		{
			shinyjewelegg = true;
			WriteJump((void*)0x78AC80, EggColoring);
		}

		if (config->getBool("Chao World Extended", "ShinyJewelPC", true))
			PatchShinyJewelPC();
		if (config->getBool("Chao World Extended", "ShinyJewelGC", false))
			PatchShinyJewelGC();

		if (config->getBool("Chao World Extended", "ColorMixing", true))
		{
			//different color formats
			for (int i = 0; i < 1024; i += 4)
			{
				std::swap(patchedColors[i + 0], patchedColors[i + 2]);
			}
			WriteData((int*)0x0078AE9B, (int)&patchedColors[0]);
			WriteJump((void*)0x0071E490, AL_CreateChildGene);
		}

		//Crayon fix
		NJS_MDATA2* data2 = (NJS_MDATA2*)ChaoAnimations[328].NJS_MOTION->mdata;
		data2[11].p[1] = &stru_381B7A0;
		data2[11].nb[1] = data2[10].nb[1];

		Chao_Init();
		Toys_Init();
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };

}
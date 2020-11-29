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
		int v4; // ecx@6
		DataArray(int, off_389D780, 0x389D780, 4);
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
			v4 = dword_389D828[a2 - SADXEggColour_YellowShiny_MonoTone];
			goto LABEL_8;
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
			v4 = off_389D780[a2 + 1];
		LABEL_8:
			ColorChunkModel((int)v4);
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
			v4 = dword_088A3D8[a2 - SADXEggColour_Glass];
			ColorChunkModel((int)v4);
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
		PrintDebug("%d %d \n", pChildGene->Color1, pChildGene->Color2);
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

	DataArray(MotionTableAction, ChaoAnimations, 0x36A94E8, 625);
	__declspec(dllexport) void Init(const char *path, const HelperFunctions* function)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

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
			for (int i = 0; i < 1025; i += 4)
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
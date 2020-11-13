#include "SADXModLoader.h"
#include "motiontable.h"
#include "data/motion/alm_crayonfix.nam"

#include "al_kinder_bm.h"
#include "al_toy/alo_toy.h"
#include "chao.h"
extern "C"
{

	DataArray(MotionTableAction, ChaoAnimations, 0x36A94E8, 625);
	__declspec(dllexport) void Init()
	{
		DataPointer(NJS_MODEL_SADX, transporterTest, 0x33CFC44);
		for (int i = 0; i < transporterTest.nbMeshset; i++)
			transporterTest.meshsets[i].vertcolor = nullptr; //disables vertcolor
		for (int i = 361; i < 365; i++)
			transporterTest.points[i].x = -11.705f; //fixes floating screen

		//SADX tree progress speedup
		*(float*)0x034BBADC = 0.00005f;

		al_kinder_bm_Init();

		//Crayon fix
		NJS_MDATA2* data2 = (NJS_MDATA2*)ChaoAnimations[328].NJS_MOTION->mdata;
		data2[11].p[1] = &stru_381B7A0;
		data2[11].nb[1] = data2[10].nb[1];

		Chao_Init();
		Toys_Init();
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };

}
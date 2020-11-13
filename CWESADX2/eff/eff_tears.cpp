#include "eff_tears.h"
ParticleUserData cryingUserData = { 1, 0, 0, 8, 0.5, 0.99800003, -0.029999999, 0.0099999998, 0, 75000.0, 0, 0, 0, 0 };

NJS_TEXANIM cryingTexAnim[] =
{ {0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 78, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 79, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 80, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 81, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 82, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 83, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 84, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 85, 0} ,
};
NJS_SPRITE cryingPart = { {0,0,0}, 1,1,0, (NJS_TEXLIST*)0x0094A2A8, &cryingTexAnim[0] };
void CryingParticle_Display(ObjectMaster* a1)
{
	ParticleData* v2 = (ParticleData*)a1->Data1;
	if (v2)
	{
		njPushMatrixEx();
		njTranslateEx(&v2->position);
		//njRotateY(0, v2->rotY);
		//njScale(0, v2->scale, v2->scale, v2->scale);
		cryingPart.sx = v2->scale * 0.1;
		cryingPart.sy = v2->scale * 0.1;
		cryingPart.ang = v2->rotY;
		SetMaterialAndSpriteColor_Float(1, 0xA0 / 255.0f, 0x90 / 255.0f, 1);
		njDrawSprite3D_Queue(&cryingPart, v2->frame, NJD_SPRITE_COLOR | NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_ANGLE, QueuedModelFlagsB_SomeTextureThing);
		njPopMatrixEx();
	}
}
FunctionPointer(void, HeapFreeSADX, (LPVOID lpMem), 0x00780FB0);
FunctionPointer(void*, HeapAllocSADX, (int count, int size), 0x00780F90);
void CryingParticle_Delete(ObjectMaster* a1)
{
	if (a1->UnknownB_ptr)
	{
		HeapFreeSADX(a1->UnknownB_ptr);
		a1->UnknownB_ptr = 0;
	}
}
void CryingParticle_Main(ObjectMaster* a1)
{
	ParticleData* v2 = (ParticleData*)a1->Data1;
	ParticleUserData* v3 = &cryingUserData;
	v2->rotY += v2->rotYSpeed;
	v2->scale += 0.0099999998;
	v2->position.x += v2->velocity.x;
	v2->position.y += v2->velocity.y;
	v2->position.z += v2->velocity.z;
	v2->velocity.x *= v3->velocityLoss;
	v2->velocity.y *= v3->velocityLoss;
	v2->velocity.z *= v3->velocityLoss;

	v2->velocity.y += v3->gravity;

	v2->frame += v3->speed;
	if (v2->frame > v3->frames) {
		CheckThingButThenDeleteObject(a1);
		return;
	}
	a1->DisplaySub(a1);
}
void ParticleLoader(ObjectMaster *a1)
{
	a1->MainSub = CryingParticle_Main;
	a1->DisplaySub = CryingParticle_Display;
	//a1->DeleteSub = CryingParticle_Delete;
}
void CryingParticle_Load(NJS_VECTOR* vel, NJS_VECTOR* pos, float scale)
{
	ObjectMaster* particle = LoadObject(LoadObj_Data1, 3, ParticleLoader);
	
	if (particle)
	{
		ParticleData* v2 = (ParticleData*)particle->Data1;//(ParticleData*)HeapAllocSADX(1, sizeof(ParticleData));
		// = v2;
		ParticleUserData* v3 = &cryingUserData;
		//particle->UnknownA_ptr = v3;
		v2->position = *pos;
		v2->scale = scale;
		v2->velocity = *vel;
	}

}

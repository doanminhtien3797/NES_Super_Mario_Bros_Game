#pragma once
#include "GameObject.h"
#include "Mario.h"
#include "MapScene.h"



class COneSidePlatform : public CGameObject {

protected:
	int spriteId;
public:
	COneSidePlatform(float x, float y, int spriteId) : CGameObject(x, y) {
		this->spriteId = spriteId;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};
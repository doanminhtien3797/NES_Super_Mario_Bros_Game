#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Mario.h"

#define ID_ANI_BRICK_COIN 10000
#define ID_ANI_BRICK_EMPTY 10001

#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

#define BRICK_STATE_COIN 0
#define BRICK_STATE_EMPTY 1

class CBrick : public CGameObject {
protected:
	int state;
	int animId;
	int coin;
public:
	CBrick(float x, float y) : CGameObject(x, y) {
		state = 0;
		animId = ID_ANI_BRICK_COIN;
		coin = 1;
	}

	CBrick(float x, float y, int coin) : CGameObject(x, y) {
		this->state = state;
		this->animId = 0;
		this->coin = coin;

		if (coin > 0) {
			this->state = BRICK_STATE_COIN;
			this->animId = ID_ANI_BRICK_COIN;
		}
		else {
			this->state = BRICK_STATE_EMPTY;
			this->animId = ID_ANI_BRICK_EMPTY;
		}
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void OnHitByMario(CMario* mario);
};


class CDecor : public CGameObject {

protected:
	int spriteId;

public:
	CDecor(float x, float y, int spriteId) : CGameObject(x, y) {
		this->spriteId = spriteId;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};;
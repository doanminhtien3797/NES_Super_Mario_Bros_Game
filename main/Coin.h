#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_COIN 11000

#define	COIN_WIDTH 10
#define COIN_BBOX_WIDTH 10
#define COIN_BBOX_HEIGHT 16

#define COIN_BRICK_SPEED -0.18f
#define COIN_BRICK_LIFE_TIME 600
#define COIN_BRICK_GRAVITY 0.0005f

class CCoin : public CGameObject {
public:
	CCoin(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};

class CCoinBrick : public CGameObject {
protected: 
	float lifeTime;
	float speed;
public:
	CCoinBrick(float x, float y) : CGameObject(x, y) {
		this->lifeTime = 0;
		this->speed = COIN_BRICK_SPEED;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};
#pragma once
#include "GameObject.h"

#define MUSHROOM_BBOX_WIDTH  16
#define MUSHROOM_BBOX_HEIGHT 16

#define MUSHROOM_MOVE_SPEED 0.05f
#define MUSHROOM_GRAVITY	0
#define ID_ANI_MUSHROOM		80001

class CMushroom : public CGameObject
{

protected:
	float direction;
	float vx, vy;
	float ax, ay;

public:
	CMushroom(float x, float y, float direction) : CGameObject(x, y)
	{
		this->direction = direction;
		this->vx = MUSHROOM_MOVE_SPEED * direction;
		this->vy = 0;
		this->ax = 0;
		this->ay = MUSHROOM_GRAVITY;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnNoCollision(DWORD dt);
};


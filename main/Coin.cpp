#include "Coin.h"
#include "debug.h"


void CCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_COIN)->Render(x, y);

	//RenderBoundingBox();
}

void CCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - COIN_BBOX_WIDTH / 2;
	t = y - COIN_BBOX_HEIGHT / 2;
	r = l + COIN_BBOX_WIDTH;
	b = t + COIN_BBOX_HEIGHT;
}

void CCoinBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_COIN)->Render(x, y);
}

void CCoinBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	y += speed * dt;
	speed += COIN_BRICK_GRAVITY * dt;

	if (lifeTime > COIN_BRICK_LIFE_TIME) {
		this->Delete();
	}
	else {
		lifeTime += dt;
		DebugOut(L"dt = %f\n",dt);
	}
	CGameObject::Update(dt, coObjects);
}

void CCoinBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 0;
	b = 0;
}

#include "Brick.h"

void CBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BRICK)->Render(x, y);
	//RenderBoundingBox();
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - BRICK_BBOX_WIDTH/2;
	t = y - BRICK_BBOX_HEIGHT/2;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}

void CDecor::Render()
{
	CSprites::GetInstance()->Get(spriteId)->Draw(x, y);
	//RenderBoundingBox();
}

void CDecor::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = 0;
	t = 0;
	r = 0;
	b = 0;
}
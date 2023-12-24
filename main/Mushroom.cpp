#include "Mushroom.h"
#include "debug.h"

void CMushroom::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left   = x - MUSHROOM_BBOX_WIDTH / 2;
	top    = y - MUSHROOM_BBOX_HEIGHT / 2;
	right  = left + MUSHROOM_BBOX_WIDTH;
	bottom = top + MUSHROOM_BBOX_HEIGHT;
}

void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vx += ax * dt;
	vy += ay * dt;

	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMushroom::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CMushroom::Render()
{
	CSprites::GetInstance()->Get(ID_ANI_MUSHROOM)->Draw(x, y);
}

void CMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	DebugOut(L"Collision with mushroom\n");

	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
	}
	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = 0;
	}
}
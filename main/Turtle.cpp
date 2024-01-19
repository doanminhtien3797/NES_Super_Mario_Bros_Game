#include "Turtle.h"

CTurtle::CTurtle(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = TURTLE_GRAVITY;
	SetState(TURTLE_STATE_WALKING);
}

void CTurtle::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state != ID_ANI_TURTLE_WALKING)
	{
		left = x - TURTLE_BBOX_WIDTH / 2;
		top = y - TURTLE_BBOX_HEIGHT_DIE / 2;
		right = left + TURTLE_BBOX_WIDTH;
		bottom = top + TURTLE_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - TURTLE_BBOX_WIDTH / 2;
		top = y - TURTLE_BBOX_HEIGHT / 2;
		right = left + TURTLE_BBOX_WIDTH;
		bottom = top + TURTLE_BBOX_HEIGHT;
	}
}

void CTurtle::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CTurtle::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CTurtle*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

int CTurtle::CanHarm() {

	if (state == TURTLE_STATE_HIDE) {
		return false;
	}
	else {
		return slideTimer <= 0;
	}
}

void CTurtle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);

	switch (state) {
		case TURTLE_STATE_SLIDING:
			slideTimer -= dt;
			break;
	}
}


void CTurtle::Render()
{
	int aniId = ID_ANI_TURTLE_WALKING;
	if (state != TURTLE_STATE_WALKING)
	{
		aniId = ID_ANI_TURTLE_HIDE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y - 6);
	//RenderBoundingBox();
}

void CTurtle::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
		case TURTLE_STATE_SLIDING:
			slideTimer = TURTLE_SLIDE_TIMEOUT;
			break;

		case TURTLE_STATE_HIDE :
			vx = 0;
			vy = 0;
			break;

		case TURTLE_STATE_WALKING:
			vx = -TURTLE_WALKING_SPEED;
			break;
	}
}

void CTurtle::Slide(float direction) {

	int mul = direction < 0 ? 1 : -1;

	vx = TURTLE_SLIDING_SPEED * mul;
	vy = 0;

	SetState(TURTLE_STATE_SLIDING);
}

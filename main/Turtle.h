#include "GameObject.h"

#define TURTLE_GRAVITY 0.002f
#define TURTLE_WALKING_SPEED 0.03f
#define TURTLE_SLIDING_SPEED 0.1f

#define TURTLE_BBOX_HEIGHT 26
#define TURTLE_BBOX_WIDTH 18
#define TURTLE_BBOX_HEIGHT_DIE 12

#define TURTLE_SLIDE_TIMEOUT 1000

#define TURTLE_STATE_WALKING 100
#define TURTLE_STATE_SLIDING 200
#define TURTLE_STATE_HIDE 300

#define ID_ANI_TURTLE_WALKING 6000
#define ID_ANI_TURTLE_HIDE 6001

class CTurtle : public CGameObject
{
protected:
	float ax;
	float ay;

	float slideTimer;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	

public:
	CTurtle(float x, float y);
	virtual void SetState(int state);
	void Slide(float direction);
	int CanHarm();
};
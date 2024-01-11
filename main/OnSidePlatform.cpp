
#include "OneSidePlatform.h"
#include "Brick.h"


void COneSidePlatform::Render()
{
	CSprites::GetInstance()->Get(spriteId)->Draw(x, y);
}

void COneSidePlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	float mX, mY;
	
	CMario* mario = (CMario*)((LPMAPSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (mario != NULL) {

		mario->GetPosition(mX, mY);

		if (mY > y) {

			l = 0;
			t = 0;
			r = 0;
			b = 0;
		}
		else {
			l = x - BRICK_BBOX_WIDTH / 2;
			t = y - BRICK_BBOX_HEIGHT / 2;
			r = l + BRICK_BBOX_WIDTH;
			b = t + BRICK_BBOX_HEIGHT;
		}
	}
	

	
}
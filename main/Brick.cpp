#include "Brick.h"
#include "Coin.h"
#include "debug.h"
#include <iostream>
#include "PlayScene.h"
#include "Mario.h"
#include "Mushroom.h"

void CBrick::Render()
{
	CAnimations::GetInstance()->Get(animId)->Render(x, y);
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - BRICK_BBOX_WIDTH/2;
	t = y - BRICK_BBOX_HEIGHT/2;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}

void CBrick::OnHitByMario(CMario* mario)
{
	float mx, my;
	mario->GetPosition(mx, my);

	if (state != BRICK_STATE_EMPTY) {

		if (my > y && x - BRICK_BBOX_WIDTH / 2 <= mx && mx <= x + BRICK_BBOX_WIDTH / 2) {

			if (this->hasMushroom) {

				state = BRICK_STATE_EMPTY;
				animId = ID_ANI_BRICK_EMPTY;

				float direction = 1;
				if (x < mx) {
					direction = -1;
				}
			
				CMushroom* mushroom = new CMushroom(x, y - BRICK_BBOX_HEIGHT, direction);
				CPlayScene* playScene = (LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene();
				playScene->AddObject(mushroom);

			}
			else {
				coin--;

				CCoinBrick* coinBrick = new CCoinBrick(x, y - BRICK_BBOX_HEIGHT / 2);

				CPlayScene* playScene = (LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene();
				playScene->AddObject(coinBrick);

				CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
				mario->AddCoin();

				if (coin <= 0) {
					state = BRICK_STATE_EMPTY;
					animId = ID_ANI_BRICK_EMPTY;
				}
			}

			
			
		}
	}
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


void CObstacle::Render()
{
	CSprites::GetInstance()->Get(spriteId)->Draw(x, y);
}

void CObstacle::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BRICK_BBOX_WIDTH / 2;
	t = y - BRICK_BBOX_HEIGHT / 2;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}
#include "Brick.h"
#include "Coin.h"
#include "debug.h"
#include <iostream>
#include "PlayScene.h"

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

	//DebugOut(L"mario: %f %f\n", mx, my);
	//DebugOut(L"brick: %f %f\n", x, y);

	if (state != BRICK_STATE_EMPTY) {

		if (my > y && x - BRICK_BBOX_WIDTH / 2 <= mx && mx <= x + BRICK_BBOX_WIDTH / 2) {

			coin--;

			CCoinBrick* coinBrick = new CCoinBrick(x, y - BRICK_BBOX_HEIGHT / 2);

			CPlayScene* playScene = (LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene();
			playScene->AddObject(coinBrick);

			if (coin <= 0){
				state = BRICK_STATE_EMPTY;
				animId = ID_ANI_BRICK_EMPTY;
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
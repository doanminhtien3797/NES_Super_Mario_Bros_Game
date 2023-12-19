


#include "SceneMapKeyHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "MapScene.h"

void CSceneMapKeyHandler::OnKeyDown(int KeyCode)
{
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	CMario* mario = (CMario*)((LPMAPSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	switch (KeyCode)
	{
		case DIK_LEFTARROW:
			break;
		case DIK_RIGHTARROW:
			break;
		case DIK_UPARROW:	
			break;
		case DIK_DOWNARROW:
			break;
		case DIK_RETURN:
			break;
	}
}

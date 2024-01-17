


#include "SceneMapKeyHandler.h"

#include "debug.h"
#include "Game.h"

#define NEXT_SCENE 2

void CSceneMapKeyHandler::OnKeyDown(int KeyCode)
{

	
}
	
void CSceneMapKeyHandler::OnKeyUp(int KeyCode)
{
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
		CGame::GetInstance()->InitiateSwitchScene(NEXT_SCENE);
		break;
	}
}

void CSceneMapKeyHandler::KeyState(BYTE* states)
{

}
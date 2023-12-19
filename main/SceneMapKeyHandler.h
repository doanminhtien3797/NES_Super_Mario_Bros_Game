#include "Scene.h"

class CSceneMapKeyHandler : public CSceneKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CSceneMapKeyHandler(LPSCENE s) :CSceneKeyHandler(s) {};
};
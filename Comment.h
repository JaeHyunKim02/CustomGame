#pragma once
#include "cScene.h"
class cButton;
class Comment : public cScene
{
private:
	cTexture * m_BackGround;
	cFrame * m_PlayerFrame;
	Point Pos;
	Point m_TitleBgPos;
	bool b_Move;

	int WndState;
	cButton * m_GoTitle;

	cMouseCursor * m_Mouse;
	Point MousePoint;

public:
	int MyScore;
	int MyComment;
	int m_Comment;
	unsigned int nSeed = (unsigned)time(NULL);

	enum{
		GREAT,
		GOOD,
		BAD
	};
public:
	Comment();
	virtual ~Comment();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

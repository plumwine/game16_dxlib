#pragma once
#ifndef _TITLE_H
#define _TITLE_H
#include "BaseScene.h"

class Title : public BaseScene
{
public:
	Title();
	~Title();
	virtual void initialize() override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;
	virtual void shutdown() override;
	virtual bool isEnd() override;
	virtual std::string nextScene() override;
private:

};

#endif // !_TITLE_H

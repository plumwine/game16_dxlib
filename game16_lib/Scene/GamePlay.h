#pragma once
#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include "BaseScene.h"

class GamePlay : public BaseScene
{
public:
	GamePlay();
	~GamePlay();

	virtual void initialize() override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;
	virtual void shutdown() override;
	virtual bool isEnd() override;
	virtual std::string nextScene() override;
private:

};


#endif // !_GAMEPLAY_H


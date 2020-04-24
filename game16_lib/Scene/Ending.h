#pragma once
#ifndef _ENDING_H
#define _ENDING_H
#include "BaseScene.h"

class Ending : public BaseScene
{
public:
	Ending();
	~Ending();
	virtual void initialize() override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;
	virtual void shutdown() override;
	virtual bool isEnd() override;
	virtual std::string nextScene() override;
private:

};

#endif // !_ENDING_H
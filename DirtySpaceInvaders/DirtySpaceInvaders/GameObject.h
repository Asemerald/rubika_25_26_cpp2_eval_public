#pragma once

#include "Vector.h"

class PlayField;

class GameObject
{
public:
	char* m_objType = nullptr;
	Vector2D pos;
	unsigned char sprite;

	virtual ~GameObject() = default;
	virtual void Update(PlayField& world) {}
	virtual bool DecreaseHealth() { return true; }
};
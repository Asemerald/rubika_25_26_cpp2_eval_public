#include "AlienLaser.h"

#include "ConsoleRenderer.h"
#include "PlayField.h"

#include <string>

AlienLaser::AlienLaser()
{
	m_objType = new char[64];
	strcpy(m_objType, "AlienLaser");
	sprite = RS_AlienLaser;
}

AlienLaser::~AlienLaser()
{
	delete[] m_objType;
}

void AlienLaser::Update(PlayField& world)
{
	bool deleted = false;
	pos.y += 1.f;
	if (pos.y > world.bounds.y)
	{
		deleted = true;
	}

	GameObject* player = world.GetPlayerObject();
	if (player != nullptr && pos.IntCmp(player->pos))
	{
		world.RemoveObject(player);

		// Quit the game since the player died
		exit(0);
	}

	if (deleted)
	{
		world.DespawnLaser((GameObject*)this);
	}
}
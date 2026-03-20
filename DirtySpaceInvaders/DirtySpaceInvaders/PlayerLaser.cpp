#include "PlayerLaser.h"

#include "ConsoleRenderer.h"
#include "PlayField.h"

#include <string>

PlayerLaser::PlayerLaser()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerLaser");
	sprite = RS_PlayerLaser;
}

PlayerLaser::~PlayerLaser()
{
	delete[] m_objType;
}

void PlayerLaser::Update(PlayField& world)
{
	bool deleted = false;
	pos.y -= 1.f;
	if (pos.y < 0)
	{
		deleted = true;
	}

	if (!deleted)
	{
		for (GameObject* obj : world.GameObjects())
		{
			if (obj == this)
			{
				continue;
			}

			if (strcmp(obj->m_objType, "AlienShip") == 0 && pos.IntCmp(obj->pos))
			{
				deleted = true;
				if (obj->DecreaseHealth())
				{
					world.RemoveObject(obj);
				}
				break;
			}
		}
	}

	if (deleted)
	{
		world.DespawnLaser(this);
	}
}
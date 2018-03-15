#pragma once
#include "Ovo.h"

#include <string>
class Player:public Ovo
{
public:
	Player(std::string file, int spr_num_x, int spr_num_y, int spr_x, int spr_y, int x, int y);
	~Player();
	float moutSpeed{ 0.1f };
	void update( int dir, float time); //frame for anim, dir means direction

	float m_frame{ 0 };


	int dir = 0;
};


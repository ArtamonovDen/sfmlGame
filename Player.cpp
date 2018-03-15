#include "Player.h"


Player::Player(std::string file, int spr_num_x, int spr_num_y, int spr_x, int spr_y, int x, int y) :Ovo(file, spr_num_x, spr_num_y, spr_x, spr_y,x,y){

}



Player::~Player()
{
}

void Player::update ( int dir, float time) {

	


	//MOVING
	int dx, dy;
	switch (this->dir){
	case 0: dx = 1; dy = 0; spr_y = 2 * spr_h; break; //RIGHT
	case 1: dx = -1; dy = 0; spr_y = 1 * spr_h; break;//LEFT
	case 2: dx = 0; dy = 1; spr_y = 0 * spr_h; break; //DOWN
	case 3: dx = 0; dy = -1; spr_y = 3 * spr_h; break; //UP;
	default: break;
	}


	x+= dx * moutSpeed*time;
	y+= dy * moutSpeed*time;
	m_sprite.setPosition(x, y);

	////ANIMATION
	//m_frame += 0.05*time;
	//if (m_frame >= 3)
	//	m_frame = 0;

	//spr_x = spr_w*int(m_frame);
	//m_sprite.setTextureRect(sf::IntRect(spr_x, spr_y, spr_w, spr_h));

	//
	

	

}
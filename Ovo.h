#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Ovo
{
public:
	Ovo(std::string file,int spr_num_x, int spr_num_y, int spr_x, int spr_y, int x,int y);
	~Ovo();



	std::string m_file;
	sf::Sprite m_sprite;
	sf::Image m_image;

	int spr_x;//there number of sprite in pict(row and col) got in constructor
	int spr_y;// the location of sprite rectangle and its size

	int x;
	int y;//position
	sf::Texture m_texture;
protected:
	
	int spr_h;//
	int spr_w;//


	//sprite position(x,y)?
};


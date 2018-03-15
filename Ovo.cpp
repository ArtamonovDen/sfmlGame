#include "Ovo.h"

#include <iostream>

Ovo::Ovo(std::string file, int spr_num_x, int spr_num_y, int spr_x, int spr_y, int x, int y) : m_file(file), x(x), y(y)
{

	if (!m_image.loadFromFile(m_file)){
		std::cout << "Error in texture creation, " << m_file << std::endl;
		return;
	}
	
	spr_w = m_image.getSize().x / spr_num_x;//get the dimensions of one sprite
	spr_h = m_image.getSize().y / spr_num_y;//

	this->spr_x = spr_x * spr_w;
	this->spr_y = spr_y * spr_h;

	
	m_texture.loadFromImage(m_image);
	m_texture.setSmooth(true);
	m_texture.setRepeated(false);

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(spr_x, spr_y, spr_w, spr_h));
	m_sprite.setPosition(x, y);
	
}


Ovo::~Ovo()
{
}

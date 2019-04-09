#include "block.h"


void Block::build(PNG & im, int column, int width){	
	for(int x = 0; x< width; x++){
		vector<HSLAPixel> temp;
		for(unsigned y = 0; y< im.height(); y++){
			HSLAPixel *p = im.getPixel(x+column,y);
			temp.push_back(*p);
		}
		data.push_back(temp);
	}
	return ;
}

void Block::render(PNG & im, int column) const {
	for(int x =0; x<width(); x++){
		for(int y =0; y<height(); y++){
		*im.getPixel(x+column,y) = data[x][y];
		}
	}
}

void Block::greyscale(){
	for(int x=0;x<width();x++){
		for(int y=0;y<height();y++){
			data[x][y].s = 0;
		}
	}
}


int Block::width() const {
	return data.size();
}

int Block::height() const {
	return data[0].size();
}

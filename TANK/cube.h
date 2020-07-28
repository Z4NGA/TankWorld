#pragma once
#include <GL/freeglut.h>
#include <GL/SOIL.h>
#include <vector>
#include <iostream>
#include <string>
class cube {
public:
	cube(float fSeitenL);
	cube(float xLen, float yLen, float zLen);
	cube(float xLen, float yLen, float zLen, GLuint tx);
	cube(float xLen, float yLen, float zLen, std::vector<GLuint> txs);
};

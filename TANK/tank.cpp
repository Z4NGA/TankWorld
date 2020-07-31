#include "tank.h"
tank::tank() {
	generaltype = "tank";
	type = "tank";
	usable = true;
	inrange = false;
	tankoffset = 0; tankangle = 0; topangle = 0; cannonangle = 0;
	//dirx=1, diry=0, dirz = 0;
	xLen = 0;  yLen = 0; zLen = 0;
	xoffset = 0; yoffset = 0; zoffset = 0;
}
tank::tank(float x, float y, float z){
	tankoffset = 0; tankangle = 0; topangle = 0; cannonangle = 0;
	//dirx=1, diry=0, dirz = 0;
	xLen = x;  yLen = y; zLen = z;
	usable = true;
	inrange = false;
	xoffset = 0; yoffset = 0; zoffset = 0;
	type = "tank", generaltype = "tank";
	//i_xlen = x; i_ylen = y; i_zlen = z;
}
tank::~tank() {
//freeing the graphic memory from the loaded texture

}
/*void tank::reshape() {
	float extrasize = 0.1 * tank_x_offset+0.1*tank_y_offset + 0.1*tank_z_offset;
	xLen = i_xlen - extrasize * i_xlen ;
	yLen = i_ylen - extrasize * i_ylen ;
	zLen = i_zlen - extrasize * i_zlen ;
}*/
/*void tank::setposition(float x, float y, float z) {
	tank_x_offset = x; 
	tank_y_offset = y;
	tank_z_offset = z;
	
}*/
/*void tank::movetank(float offset) {
	//tankoffset += offset;
	tank_x_offset = tank_x_offset + dirx * offset;
	tank_y_offset = tank_y_offset + diry * offset;
	tank_z_offset = tank_z_offset + dirz * offset;
	
}*/
void tank::output_specs() {
	//std::cout << "tank_x_offset : " << tank_x_offset << " , tank_x_offset : " << tank_y_offset << " , tank_z_offset : " 
	//	<< tank_z_offset <<"\ntankAngle : "<<tankangle<<" , dirx : "<<dirx<<" , dirz : "<<dirz << std::endl;
	
}
/*void tank::turntank(float angle) {
	tankangle += angle;
	//angles need to be converted to radian 
	dirx = cos(tankangle*M_PI/180.);
	dirz = sin(tankangle*M_PI/180.);
}*/
void tank::turntop(float angle) {
	topangle += angle;
}
void tank::tiltcannon(float angle) {
	if(!((cannonangle>=45. && angle>0) || (cannonangle<=-15. && angle <0))) cannonangle += angle;
}
void tank::spawn() {
	//reshape();
	//core
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	//movetank
	//glTranslatef(tank_x_offset, tank_y_offset+0.41 , -tank_z_offset );//invert the z coords to fix to sync input
	glTranslatef(0. + xoffset, yLen / 2. + yoffset, 0. + zoffset);
	//aplying object roations 
	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);
	//turn tank
	//glRotatef(tankangle, 0., 1., 0.);
	
	drawcore();
	//bot
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0. + xoffset, yLen / 2. + yoffset, 0. + zoffset);
	//aplying object roations 
	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);
	glTranslatef(0., -0.3*yLen, 0.);
	drawbot();
	//wheel --connected to bot
	glTranslatef(0., -0.1*yLen, 0.);
	drawwheelpart(1); //pos 1 or 2 allowed

	//top
	glLoadIdentity();
	glPopMatrix();
	//turn top
	glPushMatrix();
	
	glTranslatef(0. + xoffset, yLen / 2. + yoffset, 0. + zoffset);
	//aplying object roations 
	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);
	glRotatef(topangle, 0., 1., 0.);
	glTranslatef(0., 0.25*yLen, 0.);
	drawtop();
	//cannon -- connected to  top
	
	glTranslatef(0.4*xLen, 0.1*yLen, 0.);
	glRotatef(cannonangle, 0., 0., 1.);
	glTranslatef(0.2 * xLen, 0., 0.);
	drawcannonpart();
}
void tank::drawcore() {
	glBindTexture(GL_TEXTURE_2D, green);
	bluecube(0.75 * xLen, 0.2*yLen, zLen * 0.6);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////		DRAWs THE TOP PART WITHOUT THE CANNON	/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tank::drawtop() {
	//cube(0.5 * xLen, 0.3 * yLen, 0.5 * zLen);
	float tempx= 0.8 * xLen, tempy= 0.28 * yLen, tempz = 0.5 * zLen;
	//////////////////////////////////////////////top side///////////////////////////////////////////////////////////
	//1
	glBindTexture(GL_TEXTURE_2D, green);
	glEnable(GL_TEXTURE_2D);
	glColor4f(1., 1., 1., 1.);
	glBegin(GL_QUADS);

	glTexCoord2f(1.0, 0.);
		glVertex3f(-tempx / 2. + tempx / 6., tempy / 2., tempz / 4.); 
		glTexCoord2f(0.0, 0.);
		glVertex3f(-tempx / 2. + tempx / 6., tempy / 2., -tempz / 4.); 
		glTexCoord2f(0.0, 1.);
		glVertex3f(0, tempy * 0.75, -tempz / 2.); 
		glTexCoord2f(1.0, 1.);
		glVertex3f(0, tempy * 0.75, tempz / 2.);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//2
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 0.);
		glVertex3f(0, tempy * 0.75, -tempz / 2.); glTexCoord2f(0.0, 0.);
		glVertex3f(0, tempy * 0.75, tempz / 2.);  glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 4., tempy *0.55, tempz / 2.); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., tempy *0.55, -tempz / 2.); 
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//3
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., tempy *0.55, tempz / 2.); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., tempy *0.55, -tempz / 2.);  glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy *0.5, -tempz * 0.15);  glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy *0.5, tempz * 0.15); 
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//4
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy *0.5, -tempz * 0.15); glTexCoord2f(1.0,1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy *0.5, tempz * 0.15); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., tempy / 2., tempz * 0.15); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., tempy / 2., -tempz * 0.15); 
	glEnd();

	//6
	glBegin(GL_QUADS);
		glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., -tempy / 8., tempz * 0.5);  glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., -tempy / 8., -tempz * 0.5); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., -tempy / 8., -tempz * 0.5); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., -tempy / 8., tempz * 0.5); 
	glEnd();

	glDisable(GL_TEXTURE_2D);
	//////////////////////////////////////////////// bot side//////////////////////////////////////////////////////
	glEnable(GL_TEXTURE_2D);
	//1
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(-tempx / 2. + tempx / 6., -tempy / 2., tempz / 4.);  glTexCoord2f(1.0, 1.);
		glVertex3f(-tempx / 2. + tempx / 6., -tempy / 2., -tempz / 4.); glTexCoord2f(0.0, 1.);
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); glTexCoord2f(0.0, 0.);
		glVertex3f(0, -tempy * 0.5, tempz / 2.); 
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); glTexCoord2f(1.0, 1.);
		glVertex3f(0, -tempy * 0.5, tempz / 2.); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 4., -tempy * 0.5, tempz / 2.); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz / 2.); 
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., -tempy /8., tempz / 2.); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., -tempy /8., -tempz / 2.);  glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.25, -tempz * 0.15); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.25, tempz * 0.15);  
	glEnd();
	//4
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy / 4., tempz *0.15); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy / 4., -tempz *0.15);  glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2. , tempy * 0.25, -tempz * 0.15); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2. , tempy * 0.25, tempz * 0.15);  
	glEnd();
	//5
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., -tempy * 0.5, tempz / 2.); glTexCoord2f(1.0,1.);
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz / 2.); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., -tempy * 0.25, -tempz * 0.5); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., -tempy * 0.25, tempz * 0.5);  
	glEnd();

	/////////////////////////////////////////////////////left side////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(-tempx / 2. + tempx / 6., tempy * 0.5, -tempz * 0.25); glTexCoord2f(1.0, 1.);
		glVertex3f(-tempx / 2. + tempx / 6., -tempy * 0.5 , -tempz * 0.25);  glTexCoord2f(0.0, 1.);
		glVertex3f(-tempx / 2. + tempx / 6., -tempy * 0.5 , tempz * 0.25); glTexCoord2f(0.0, 0.);
		glVertex3f(-tempx / 2. + tempx / 6., tempy * 0.5, tempz * 0.25);  
	glEnd();
	////////////////////////////////////////////////////right side/////////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 2., tempy * 0.5, -tempz *0.15); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 2., tempy * 0.5- tempz * 0.15, -tempz *0.15); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., tempy * 0.5- tempz * 0.15, tempz * 0.15); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., tempy * 0.5, tempz * 0.15);  
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 2., -tempy /8., -tempz * 0.5); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 2., -tempy /4. , -tempz * 0.5);  glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., -tempy /4. , tempz * 0.5); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., -tempy /8., tempz * 0.5);  
	glEnd();

	////////////////////////////////////////////////////front side///////////////////////////////////////////////////////
	//1
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(-tempx / 2. + tempx / 6., -tempy / 2., -tempz / 4.); glTexCoord2f(1.0, 1.);
		glVertex3f(-tempx / 2. + tempx / 6., tempy / 2., -tempz / 4.); glTexCoord2f(0.0, 1.);
		glVertex3f(0, tempy * 0.75, -tempz / 2.);  glTexCoord2f(0.0, 0.);
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); 
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(0, tempy * 0.75, -tempz / 2.); glTexCoord2f(1.0, 1.);
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz / 2.); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 4., tempy * 0.55, -tempz / 2.); 
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., tempy * 0.55, -tempz / 2.); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., -tempy /8., -tempz / 2.); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5 - tempz * 0.15, -tempz * 0.15); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5, -tempz * 0.15);
	glEnd();
	//4
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5, -tempz * 0.15); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5 - tempz * 0.15, -tempz * 0.15); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., tempy * 0.5 - tempz * 0.15, -tempz * 0.15); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., tempy / 2., -tempz * 0.15); 
	glEnd();
	//5
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., -tempy / 8., -tempz * 0.5); glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz * 0.5); glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., -tempy * 0.25, -tempz * 0.5); glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., -tempy / 8., -tempz * 0.5); 
	glEnd();


	/*glBegin(GL_POLYGON);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(-tempx / 2. + tempx / 6., -tempy / 2., -tempz / 4.); glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(-tempx / 2. + tempx / 6., tempy / 2., -tempz / 4.); glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
		glVertex3f(0, tempy * 0.75, -tempz / 2.); glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glEnd();
	glBegin(GL_POLYGON);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(0, tempy * 0.75, -tempz / 2.); glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz / 2.); glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(tempx / 4., tempy * 0.55, -tempz / 2.); glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glEnd();
	glBegin(GL_POLYGON);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(tempx / 4., tempy * 0.55, -tempz / 2.); glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(tempx / 4., -tempy * 0.15, -tempz / 2.); glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(tempx * 0.3, -tempy * 0.15, -tempz / 2.); glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5 - tempz * 0.2, -tempz * 0.15); glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5, -tempz * 0.15); glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
	glEnd();
	glBegin(GL_POLYGON);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(tempx / 4., -tempy * 0.15, -tempz / 2.); glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz / 2.); glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(tempx / 2. - tempx / 6., -tempy * 0.35, -tempz * 0.5); glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
		glVertex3f(tempx / 2. - tempx / 6., -tempy * 0.3, -tempz * 0.5); glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(tempx * 0.3, -tempy * 0.3, -tempz / 2.); glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(tempx * 0.3, -tempy * 0.15, -tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5, -tempz * 0.15); glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5-tempz*0.2, -tempz * 0.15); glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
		glVertex3f(tempx / 2., tempy * 0.5 - tempz * 0.2, -tempz * 0.15); glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
		glVertex3f(tempx / 2., tempy / 2., -tempz * 0.15); glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glEnd();*/
	/*glBegin(GL_TRIANGLE_STRIP);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(-tempx / 2. + tempx / 6., -tempy / 2., -tempz / 4.);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glVertex3f(-tempx / 2. + tempx / 6., tempy / 2., -tempz / 4.);
	glVertex3f(0, -tempy / 2., -tempz / 2.);
	glVertex3f(0, tempy / 2., -tempz / 2.);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
	glVertex3f(tempx / 4., -tempy / 2., -tempz / 2.);
	glVertex3f(tempx / 4., tempy / 2., -tempz / 2.);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glVertex3f(tempx / 2. - tempx / 6., -tempy / 4., -tempz * 0.1);
	glVertex3f(tempx / 2. - tempx / 6., tempy / 4., -tempz * 0.1);
	glEnd();*/
	////////////////////////////////////////////////////////////////////back side/////////////////////////////////////////
	tempz = -tempz;//invert
	//1
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(-tempx / 2. + tempx / 6., -tempy / 2., -tempz / 4.); 	glTexCoord2f(1.0, 1.);
		glVertex3f(-tempx / 2. + tempx / 6., tempy / 2., -tempz / 4.); 	glTexCoord2f(0.0, 1.);
		glVertex3f(0, tempy * 0.75, -tempz / 2.); 	glTexCoord2f(0.0, 0.);
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); 
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(0, tempy * 0.75, -tempz / 2.); 		glTexCoord2f(1.0, 1.);
		glVertex3f(0, -tempy * 0.5, -tempz / 2.); 	glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz / 2.);		glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 4., tempy * 0.55, -tempz / 2.);
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., tempy * 0.55, -tempz / 2.); 		glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., -tempy / 8., -tempz / 2.); 	glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5 + tempz * 0.15, -tempz * 0.15); 		glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5, -tempz * 0.15); 
	glEnd();
	//4
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5, -tempz * 0.15);		glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 2. - tempx / 6., tempy * 0.5 + tempz * 0.15, -tempz * 0.15);	glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., tempy * 0.5 + tempz * 0.15, -tempz * 0.15); 		glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., tempy / 2., -tempz * 0.15); 
	glEnd();
	//5
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.);
		glVertex3f(tempx / 4., -tempy / 8., -tempz * 0.5); 		glTexCoord2f(1.0, 1.);
		glVertex3f(tempx / 4., -tempy * 0.5, -tempz * 0.5); 	glTexCoord2f(0.0, 1.);
		glVertex3f(tempx / 2., -tempy * 0.25, -tempz * 0.5); 		glTexCoord2f(0.0, 0.);
		glVertex3f(tempx / 2., -tempy / 8., -tempz * 0.5); 
	glEnd();

	tempz = -tempz; //reset 
	glDisable(GL_TEXTURE_2D);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////		DRAWs THE DETAILED CANNON	/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tank::drawcannonpart() {//trying a  second way to draw cylinders laggy
	//cube(0.4 * xLen, 0.1 * yLen, 0.1 * zLen);
	float tempx = 0.4 * xLen, tempy = 0.1 * yLen, tempz = 0.1 * zLen,r=tempy/2.,r2=tempy*0.65;
	//1
	float y = 0, z = 0;
	glBegin(GL_LINE_LOOP);
	glColor4f(0.129, 0.203, 0.631, 1.0f); //blue
	for (float x = -tempx / 2.; x < (-tempx / 2. + 0.2 * tempx); x += (0.001 * tempx)) {
		for (float angle = 0.; angle < 360; angle += 1) {
			y = r * sin(angle);
			z = r * cos(angle);
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	//2
	glBegin(GL_LINE_LOOP);
	glColor4f(0.141, 0.152, 0.219, 1.0f);	//black
	for (float x = (-tempx / 2. + 0.2 * tempx); x < (-tempx / 2.+0.4*tempx); x += (0.001 * tempx)) {
		for (float angle = 0.; angle < 360; angle += 1) {
			//double layer shows depth
			y = r2 * sin(angle);
			z = r2 * cos(angle);
			glVertex3f(x, y, z);
			y = r * sin(angle);
			z = r * cos(angle);
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	//3
	glBegin(GL_LINE_LOOP);
	glColor4f(0.129, 0.203, 0.631, 1.0f); //blue
	for (float x = (-tempx / 2. + 0.4 * tempx); x < tempx / 6.; x += (0.001 * tempx)) {
		for (float angle = 0.; angle < 360; angle += 1) {
			y = r * sin(angle);
			z = r * cos(angle);
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	//4
	glBegin(GL_LINE_LOOP);
	glColor4f(0.141, 0.152, 0.219, 1.0f);	//black
	for (float x = tempx / 6.; x < tempx / 3.; x += (0.001 * tempx)) {
		for (float angle = 0.; angle < 360; angle += 1) {
			//double layer shows depth
			y = r2 * sin(angle);
			z = r2 * cos(angle);
			glVertex3f(x, y, z);
			y = r * sin(angle);
			z = r * cos(angle);
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	//5
	glBegin(GL_LINE_LOOP);
	glColor4f(0.129, 0.203, 0.631, 1.0f); //blue	
	for (float x = tempx / 3.; x < tempx / 2.-tempx*0.03; x += (0.001 * tempx)) {
		for (float angle = 0.; angle < 360; angle += 1) {
			y = r * sin(angle);
			z = r * cos(angle);
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	//6
	glBegin(GL_LINE_LOOP);
	glColor4f(0.141, 0.152, 0.219, 1.0f);	//black
	for (float x = tempx / 2. - tempx * 0.03; x < tempx / 2.; x += (0.001 * tempx)) {
		for (float angle = 0.; angle < 360; angle += 1) {
			//double layer shows depth
			y = r2 * sin(angle);
			z = r2 * cos(angle);
			glVertex3f(x, y, z);
			y = r * sin(angle);
			z = r * cos(angle);
			glVertex3f(x, y, z);
		}
	}
	glEnd();

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////		DRAWs THE BOT PART WITHOUT THE WHEELS	/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tank::drawbot() {
	glBindTexture(GL_TEXTURE_2D, blue);
	bluecube(xLen, 0.4 * yLen, zLen*0.6);
	
	
}
void tank::drawrims() {
	float tempx = xLen * 1.1, tempy = 0.2 * yLen, tempz = 0.2 * zLen;
	float x=0, y = 0,r =0;
	bool analogue = true;
	/*glLineWidth(2.);
	//small rim left
	glColor3f(0.5, 0., 0.);
	glTranslatef(-tempx/2.,tempy/4.,0.);
	r= tempy / 4.;
	glBegin(GL_LINE_LOOP);
	for (float z = -tempz / 4.; z < tempz / 4.; z += 0.002) {

		for (float angle = 0.; angle < 360.; angle += 0.1) {
			x = r * cos(angle);
			y = r * sin(angle);
			glVertex3f(x, y, z);
		}

	}
	glEnd();
	//mid part rims
	glColor3f(0., 0., 0.5);
	glTranslatef(tempy*0.5+tempy*0.1, -tempy / 4., 0.);//set the new draw position
	r = tempy / 2.;
	for (size_t i = 0; i < 5; i++)
	{
		glBegin(GL_LINE_LOOP); 
	for (float z = -tempz/4.; z < tempz/4.; z+=0.002){
		
		for (float angle = 0.; angle < 360.; angle+=0.1){
			x = r*cos(angle);
			y = r * sin(angle);
			glVertex3f(x, y, z);
		}
		
	}
	glEnd();
	glTranslatef(tempy+0.1*tempy, 0., 0.);
	}
	//small rim right
	glColor3f(0.5, 0., 0.);
	glTranslatef(-tempy/2., tempy / 4., 0.);
	r = tempy / 4.;
	glBegin(GL_LINE_LOOP);
	for (float z = -tempz / 4.; z < tempz / 4.; z += 0.002) {

		for (float angle = 0.; angle < 360.; angle += 0.1) {
			x = r * cos(angle);
			y = r * sin(angle);
			glVertex3f(x, y, z);
		}

	}
	glEnd();*/
	glColor3f(0., 0., 0.);
	/*for (float width = 0.; width <= 1; width += 0.05) {
		if (analogue) {
			glColor3f(0., 0., 0.);
			gluCylinder(gluNewQuadric(), tempy * 1.25 + tempy * width, tempy * 1.25 + tempy * width, tempz, 20, 10);
			analogue = !analogue;
		}
		else {
			glColor3f(1., 1., 1.);
			gluCylinder(gluNewQuadric(), tempy * 1.25 + tempy * width, tempy *1.25 + tempy * width, tempz, 20, 10);
			analogue = !analogue;
		}
	}*/

	//small left rim
	//axe
	
	glTranslatef(-tempx / 2., tempy / 4., tempz/2.);
	glColor3f(1., 0., 0.2);
	gluCylinder(gluNewQuadric(), tempy / 8, tempy / 8., tempz , 20, 10);
	glColor3f(0., 0.1, 0.7);
	gluCylinder(gluNewQuadric(), tempy / 4, tempy / 5., tempz / 2., 20, 10);
	glTranslatef(0.0, 0., tempz / 2.);
	gluCylinder(gluNewQuadric(), tempy / 5, tempy / 4., tempz / 2., 20, 10);
	glTranslatef(0.0, 0., -tempz / 2.);
	//mid rims
	glTranslatef(tempy *0.75, -tempy / 4., 0.);//set the new draw position
		
	for (size_t i = 0; i <8; i++)
	{
		analogue = true;
		//axe
		glColor3f(1., 0., 0.2);
		gluCylinder(gluNewQuadric(), tempy / 8 , tempy / 8. , tempz, 20, 10);
		for (float width = 0.; width <= 0.35; width += 0.01) {
			if (analogue) {
				glColor3f(0., 0., 1.);
				gluCylinder(gluNewQuadric(), tempy* 0.5-tempy*width, tempy / 3.-tempy*width, tempz / 2., 20, 10);
				analogue = !analogue;
			}
			else {
				glColor3f(0., 0., 0.);
				gluCylinder(gluNewQuadric(), tempy *0.5-tempy*width, tempy / 3. - tempy * width, tempz / 2., 20, 10);
				analogue = !analogue;
			}
		}
		analogue = true;
		glTranslatef(0.0, 0., tempz / 2.);
		for (float width = 0.; width <= 0.35; width += 0.01) {
			if (analogue) {
				glColor3f(0., 0., 1.);
				gluCylinder(gluNewQuadric(), tempy /3.- tempy * width, tempy / 2. - tempy * width, tempz / 2., 20, 10);
				analogue = !analogue;
			}
			else {
				glColor3f(0., 0., 0.);
				gluCylinder(gluNewQuadric(), tempy /3. - tempy * width, tempy / 2. - tempy * width, tempz / 2., 20, 10);
				analogue = !analogue;
			}
		}
		glTranslatef(0.0, 0., -tempz / 2.);
		glTranslatef(tempy + 0.1 * tempy, 0., 0.);
	}
	//small right rim
	glTranslatef(-tempy*0.4, tempy / 4., 0.);
	//axe
	glColor3f(1., 0., 0.2);
	gluCylinder(gluNewQuadric(), tempy / 8, tempy / 8., tempz, 20, 10);
	glColor3f(0., 0.1, 0.7);
	gluCylinder(gluNewQuadric(), tempy / 4, tempy / 5., tempz / 2., 20, 10);
	glTranslatef(0.0, 0., tempz / 2.);
	gluCylinder(gluNewQuadric(), tempy / 5, tempy / 4., tempz / 2., 20, 10);
	glTranslatef(0.0, 0., -tempz / 2.);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////		DRAWs THE DETAILED WHEELS	/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tank::bluecube(float xLen , float yLen, float zLen) {

	float texmax = 1.;

		glColor4f(1., 1., 1., 1.);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);   //Vorderseite
		glTexCoord2f(0., 0.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(texmax, 0.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(texmax, texmax);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(0., texmax);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glEnd();

		glBegin(GL_POLYGON);   //Rechte Seite
		glTexCoord2f(0., texmax);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(0., 0.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(texmax, 0.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(texmax, texmax);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glEnd();

		glBegin(GL_POLYGON);   //Rueckseite
		glTexCoord2f(texmax, 0.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(texmax, texmax);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(0., texmax);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(0., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glEnd();

		glBegin(GL_POLYGON);   //Linke Seite
		glTexCoord2f(0., texmax);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(texmax, texmax);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(texmax, 0.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(0., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glEnd();

		glBegin(GL_POLYGON);   //Deckflaeche
		glTexCoord2f(0., texmax);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(texmax, texmax);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(texmax, 0.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(0., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glEnd();

		glBegin(GL_POLYGON);   //Bodenflaeche
		glTexCoord2f(0., texmax);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(texmax, texmax);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2f(texmax, 0.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2f(0., 0.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);

}


void tank::drawchain(float xoffset,int pos) {
	float tempx = xLen * 1.1, tempy = 0.2 * yLen, tempz = 0.2 * zLen;
	glBindTexture(GL_TEXTURE_2D, blue);
	//section drawing chain
	/*position ip(0., 0.15 * tempy, 0.);
	static std::vector<position> vp{ ip,
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),
	ip.add(0.05 * tempx, 0., 0.),

	};//indicates the spawn position
	*/
	bool analogue = false; // bool value to contoro lthe colors 
	if (pos == 1) {
		//top horizantal section
		glTranslatef(0. + xoffset, 0.15 * tempy, 0.);
		for (float i = -0.5 * tempx; i < tempx * 0.5; i += 0.05 * tempx)
		{
			if (!analogue) {
				bluecube(0.05 * tempx, 0.15 * tempy, tempz ); analogue = !analogue;
			}
			else {
				bluecube(0.05 * tempx, 0.25 * tempy, tempz ); analogue = !analogue;
			}
			glTranslatef(0.05 * tempx, 0., 0.);
		}
		//right vertical section
		glTranslatef(0., 0., 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.02 * tempx, -0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.01 * tempx, -0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.01 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.02 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.02 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.02 * tempx, -0.11 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.03 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.03 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );

		//bottom horizantal section
		for (float i = 0.3 * tempx; i > -tempx * 0.5; i -= 0.05 * tempx)
		{
			if (!analogue) {
				bluecube(0.05 * tempx, 0.15 * tempy, tempz ); analogue = !analogue;
			}
			else {
				bluecube(0.05 * tempx, 0.25 * tempy, tempz ); analogue = !analogue;
			}
			glTranslatef(-0.05 * tempx, 0., 0.);
		}

		//left vertical sction
		glTranslatef(0., 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0., 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.05 * tempx, 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.05 * tempx, 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.05, 0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.0, 0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.0, 0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
	}
	else if (pos == 2) {
		//top horizantal section
		glTranslatef(0.015*tempx + xoffset, 0.15 * tempy, 0.);
		for (float i = -0.5 * tempx; i < tempx * 0.5; i += 0.05 * tempx)
		{
			if (!analogue) {
				bluecube(0.05 * tempx, 0.15 * tempy, tempz ); analogue = !analogue;
			}
			else {
				bluecube(0.05 * tempx, 0.25 * tempy, tempz ); analogue = !analogue;
			}
			glTranslatef(0.05 * tempx, 0., 0.);
		}
		//right vertical section
		glTranslatef(0., 0., 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.02 * tempx, -0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.01 * tempx, -0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.01 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.02 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.02 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.02 * tempx, -0.11 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.03 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.03 * tempx, -0.12 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );

		//bottom horizantal section
		for (float i = 0.3 * tempx; i > -tempx * 0.5; i -= 0.05 * tempx)
		{
			if (!analogue) {
				bluecube(0.05 * tempx, 0.15 * tempy, tempz ); analogue = !analogue;
			}
			else {
				bluecube(0.05 * tempx, 0.25 * tempy, tempz ); analogue = !analogue;
			}
			glTranslatef(-0.05 * tempx, 0., 0.);
		}

		//left vertical sction
		glTranslatef(0., 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0., 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.05 * tempx, 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.05 * tempx, 0.1 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(-0.05, 0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.0, 0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
		glTranslatef(0.0, 0.15 * tempy, 0.);
		bluecube(0.05 * tempx, 0.15 * tempy, tempz );
	}
	else {

	}
}
void tank::drawwheelpart(int pos) {
	pos = 2;
	float tempx = xLen * 1.1, tempy = 0.2 * yLen, tempz = 0.2 * zLen;
	////////////////////////    ***************************
	////////////////////////     *                       *
	////////////////////////	  **********************
	/*glBegin(GL_POLYGON);
		glColor4f(0.129, 0.203, 0.631, 1.0f); //blue
		glVertex3f(-0.5 * tempx, tempy * 0.5, tempz * 0.5); glColor4f(0.141, 0.152, 0.219, 1.0f);	//black
		glVertex3f(-0.5 * tempx, 0.3 * tempy, tempz * 0.5);
		glVertex3f(0.5 * tempx, 0.3 * tempy, tempz * 0.5); glColor4f(0.129, 0.631, 0.211, 1.0f);	//green
		glVertex3f(0.5 * tempx, 0.5 * tempy, tempz * 0.5);
	glEnd();
	//back
	glBegin(GL_POLYGON);
		glColor4f(0.129, 0.203, 0.631, 1.0f); //blue
		glVertex3f(-0.5 * tempx, tempy * 0.5, tempz * 0.5); glColor4f(0.141, 0.152, 0.219, 1.0f);	//black
		glVertex3f(-0.5 * tempx, 0.3 * tempy, tempz * 0.5);
		glVertex3f(0.5 * tempx, 0.3 * tempy, tempz * 0.5); glColor4f(0.129, 0.631, 0.211, 1.0f);	//green
		glVertex3f(0.5 * tempx, 0.5 * tempy, tempz * 0.5);
	glEnd();*/
	//pushing body modification to control the chains position
	glPushMatrix();
	//top
	//bot
	glTranslatef(0.05 * tempx, 0., 0.2 * zLen);
	drawrims();
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();

	/// //////////////////////////////////////
	
	glTranslatef(0. + xoffset, yLen / 2. + yoffset, 0. + zoffset);
	//aplying object roations 
	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);
	glTranslatef(0., -0.3 * yLen, 0.);
	glTranslatef(0., -0.1 * yLen, 0.);
	/// /////////////////////

	glTranslatef(0., -0.2*tempy, 0.4 * zLen);
	//glTranslatef(-0.8, 0.05, 0.1);

	//setting to get the chains to be drawn from the left side instead of center
	glTranslatef(-0.47 * tempx, 0.5 * tempy, 0.);
	//cube(xLen * 1.1, 0.2 * yLen, zLen * 0.2);
	drawchain(0,pos);
	//drawwheelcover(tempx,tempy,tempz);
	/////////////////////////////////////DRAWing the other side
	//////////////////////////////////////////////////////////////////
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	/// //////////////////////////////////////

	glTranslatef(0. + xoffset, yLen / 2. + yoffset, 0. + zoffset);
	//aplying object roations 
	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);
	glTranslatef(0., -0.3 * yLen, 0.);
	glTranslatef(0., -0.1 * yLen, 0.);
	/// /////////////////////
	glTranslatef(0.05 * tempx, 0., -0.6 * zLen);
	drawrims();

	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	/// //////////////////////////////////////

	glTranslatef(0. + xoffset, yLen / 2. + yoffset, 0. + zoffset);
	//aplying object roations 
	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);
	glTranslatef(0., -0.3 * yLen, 0.);
	glTranslatef(0., -0.1 * yLen, 0.);
	/// /////////////////////
	glTranslatef(0., -0.2 * tempy, -0.4 * zLen);
	glTranslatef(-0.47 * tempx, 0.5 * tempy, 0.);
	//cube(xLen * 1.1, 0.2 * yLen, zLen * 0.2);
	drawchain(0,pos);
	//drawwheelcover(tempx,tempy,tempz);
}
void tank::drawwheelcover(float tempx,float tempy,float tempz) {
	//float tempx = xLen, tempy = 0.2 * yLen, tempz = zLen * 0.6;
	//repeating left side 2 4 6 8

	glBegin(GL_POLYGON);
	glColor4f(0.129, 0.203, 0.631, 1.0f); //blue
	glVertex3f(-0.4 * tempx, tempy * 0.5, tempz * 0.55); glColor4f(0.141, 0.152, 0.219, 1.0f);	//black
	glVertex3f(-0.4 * tempx, 0., tempz * 0.55);
	glVertex3f(0.4 * tempx, 0., tempz * 0.55); glColor4f(0.129, 0.631, 0.211, 1.0f);	//green
	glVertex3f(0.4 * tempx, 0.5 * tempy, tempz * 0.55);
	glEnd();

	//repeating right side 3 5 7 9

	glBegin(GL_POLYGON);
	glColor4f(0.129, 0.203, 0.631, 1.0f); //blue
	glVertex3f(-0.4 * tempx, tempy * 0.5, -tempz * 0.55); glColor4f(0.141, 0.152, 0.219, 1.0f);	//black
	glVertex3f(-0.4 * tempx, 0., -tempz * 0.55);
	glVertex3f(0.4 * tempx, 0., -tempz * 0.55); glColor4f(0.129, 0.631, 0.211, 1.0f);	//green
	glVertex3f(0.4 * tempx, 0.5 * tempy, -tempz * 0.55);
	glEnd();
}
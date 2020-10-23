#include "rocket_truck.h"
rocket_truck::rocket_truck() {
	launcher_turn_angle=0., launcher_tilt_angle=0.;
	generaltype = "truck";
	type = "rocket_truck";
	usable = true;
	inrange = false;
	xLen = 0.f;  yLen = 0.f; zLen = 0.f;
	xoffset = 0; yoffset = 0; zoffset = 0;
	islauncher_open = false;
}
rocket_truck::rocket_truck(float x, float y, float z) {
	launcher_turn_angle, launcher_tilt_angle; 
	generaltype = "truck";
	type = "rocket_truck";
	usable = true;
	inrange = false;
	xLen = x;  yLen = y; zLen = z;
	xoffset = 0; yoffset = 0; zoffset = 0;
	islauncher_open = false;
}
void rocket_truck::spawn() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();

	//transformations
	glTranslatef(xoffset + 0., yoffset + (yLen / 2.), zoffset + 0.);

	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);

	draw_truck();
	draw_wheels_protections();
	//transformations
	draw_connection();
//transformations
	//drawing launcher from 00,0
	glRotatef(launcher_tilt_angle, 0., 0., 1.);
	glRotatef(launcher_turn_angle, 0., 1., 0.);
	draw_launcher();
	glRotatef(-launcher_turn_angle, 0., 1., 0.);
	glRotatef(-launcher_tilt_angle, 0., 0., 1.);
	//transformations goes to the loawest point and go up with radius
	glTranslatef(0., (xLen*0.8) / 9.-yLen/2., 0.);
	draw_wheels();
	//transformations
	
}
void rocket_truck::open_launcher() {
}
void rocket_truck::close_launcher() {
}
void rocket_truck::turn_launcher(float turnangle) {
	launcher_turn_angle += turnangle;
}
void rocket_truck::tilt_launcher(float tilt_angle) {
	launcher_tilt_angle += tilt_angle;
}
void rocket_truck::draw_truck() {
	//draws the core of the truck
	//////////////////////////////////////////////////////front 
	glColor4f(1., 1., 1.,1.);
	//1
	glBindTexture(GL_TEXTURE_2D, black);
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.1, 0.); glVertex3f(-xLen / 2. + xLen / 40., -yLen * 0.35, -zLen / 2.);
		glTexCoord2d(0., 0.);	glVertex3f(-xLen / 2., 0., -zLen / 2.);
		glTexCoord2d(0., 0.2);	glVertex3f(-xLen / 2., yLen/8., -zLen / 2.);
		glTexCoord2d(0.1, 1.);	glVertex3f(-xLen / 2. + xLen / 30., yLen / 2., -zLen / 2.);
		glTexCoord2d(1., 1.);	glVertex3f(-xLen / 8., yLen / 2., -zLen / 2.);
		glTexCoord2d(1., 0.);	glVertex3f(-xLen / 8., -yLen*0.35, -zLen / 2.);
		glEnd();
	glBindTexture(GL_TEXTURE_2D,grid_glass);
	//front glass 
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(-xLen*0.475, yLen/8., -zLen *0.51);
		glTexCoord2d(0., 1.); glVertex3f(-xLen / 2. + xLen / 30.+0.025*xLen, yLen*0.45, -zLen *0.51);
		glTexCoord2d(1., 1.); glVertex3f(-xLen / 8.-0.025*xLen, yLen*0.45, -zLen *0.51);
		glTexCoord2d(1., 0.); glVertex3f(-xLen / 8. - 0.025 * xLen, yLen/8., -zLen*0.51);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	//2
	glBindTexture(GL_TEXTURE_2D, black);
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 0.); glVertex3f(-xLen / 8.,yLen/8., -zLen / 2.);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 8., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(xLen / 2. + xLen / 8., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(1., 0.25); glVertex3f(xLen / 2. + xLen / 8., 0., -zLen / 2.);
			glTexCoord2d(0.25, 0.25); glVertex3f(0.,0., -zLen / 2.);
			glTexCoord2d(0.25, 0.); glVertex3f(0., yLen / 8., -zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	/////////////////////////////////////////////////////////back 
	zLen = -zLen;
	//1
	glBindTexture(GL_TEXTURE_2D, black);
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.1, 0.); glVertex3f(-xLen / 2. + xLen / 40., -yLen * 0.35, -zLen / 2.);
		glTexCoord2d(0., 0.);	glVertex3f(-xLen / 2., 0., -zLen / 2.);
		glTexCoord2d(0., 0.2);	glVertex3f(-xLen / 2., yLen/8., -zLen / 2.);
		glTexCoord2d(0.1, 1.);	glVertex3f(-xLen / 2. + xLen / 30., yLen / 2., -zLen / 2.);
		glTexCoord2d(1., 1.);	glVertex3f(-xLen / 8., yLen / 2., -zLen / 2.);
		glTexCoord2d(1., 0.);	glVertex3f(-xLen / 8., -yLen*0.35, -zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//2
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 0.); glVertex3f(-xLen / 8.,yLen/8., -zLen / 2.);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 8., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(xLen / 2. + xLen / 8., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(1., 0.25); glVertex3f(xLen / 2. + xLen / 8., 0., -zLen / 2.);
			glTexCoord2d(0.25, 0.25); glVertex3f(0.,0., -zLen / 2.);
			glTexCoord2d(0.25, 0.); glVertex3f(0., yLen / 8., -zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//back glass
	glBindTexture(GL_TEXTURE_2D, grid_glass);
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 0.); glVertex3f(-xLen * 0.475, yLen / 8., -zLen * 0.51);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 2. + xLen / 30. + 0.025 * xLen, yLen * 0.45, -zLen * 0.51);
			glTexCoord2d(1., 1.); glVertex3f(-xLen / 8. - 0.025 * xLen, yLen * 0.45, -zLen * 0.51);
			glTexCoord2d(1., 0.); glVertex3f(-xLen / 8. - 0.025 * xLen, yLen / 8., -zLen * 0.51);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	zLen = -zLen;//revert
	////////////////////////////////////////////////////////////////////////left
	glBindTexture(GL_TEXTURE_2D, black);
	//1
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 0.); glVertex3f(-xLen / 2. + xLen / 40., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 2., 0., -zLen / 2.);
			glTexCoord2d(1., 1.);	glVertex3f(-xLen / 2., 0., zLen / 2.);
			glTexCoord2d(1., 0.);	glVertex3f(-xLen / 2. + xLen / 40., -yLen*0.35, zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//2
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 2., 0., -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(-xLen / 2., yLen / 8., -zLen / 2.);
			glTexCoord2d(1., 0.); glVertex3f(-xLen / 2., yLen / 8., zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(-xLen / 2., 0., zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//3
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 2., yLen/8., -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(-xLen / 2. + xLen / 30., yLen / 2., -zLen / 2.);
			glTexCoord2d(1., 0.); glVertex3f(-xLen / 2. + xLen / 30., yLen / 2., zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(-xLen / 2., yLen/8., zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//left glass
	glBindTexture(GL_TEXTURE_2D, grid_glass);
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 0.); glVertex3f(-xLen *0.505, yLen*0.125, -zLen*0.475);
			glTexCoord2d(0., 1.); glVertex3f(-xLen *0.505 + xLen / 40., yLen*0.475, -zLen*0.475);
			glTexCoord2d(1., 1.);	glVertex3f(-xLen*0.505+ xLen / 40.,yLen*0.475, zLen *0.475);
			glTexCoord2d(1., 0.);	glVertex3f(-xLen *0.505, yLen*0.125, zLen *0.475);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	///////////////////////////////////////////////////////////////right
	//1
	glBindTexture(GL_TEXTURE_2D, black);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 1.); glVertex3f(-xLen / 8., yLen / 2., -zLen / 2.);
		glTexCoord2d(1., 1.); glVertex3f(-xLen / 8., -yLen*0.35, -zLen / 2.);
		glTexCoord2d(1., 0.); glVertex3f(-xLen / 8., -yLen*0.35, zLen / 2.);
		glTexCoord2d(0., 0.); glVertex3f(-xLen / 8., yLen / 2., zLen / 2.);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//2
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(0., 0., -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(0., yLen / 8., -zLen / 2.);
			glTexCoord2d(1., 0.); glVertex3f(0., yLen / 8., zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(0., 0., zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//3
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(xLen / 2. + xLen / 8., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(xLen / 2. + xLen / 8., 0., -zLen / 2.);
			glTexCoord2d(1., 0.); glVertex3f(xLen / 2. + xLen / 8., 0., zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(xLen / 2. + xLen / 8., -yLen*0.35, zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	/*//right glass
	glBindTexture(GL_TEXTURE_2D, grid_glass);
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(-xLen *0.1251, yLen *0.45, -zLen *0.45);
			glTexCoord2d(1., 1.); glVertex3f(-xLen *0.1251, yLen*0.15, -zLen*0.45);
			glTexCoord2d(1., 0.); glVertex3f(-xLen *0.1251, yLen*0.15, zLen *0.45);
			glTexCoord2d(0., 0.); glVertex3f(-xLen *0.1251, yLen *0.45, zLen *0.45);
		glEnd();
	glDisable(GL_TEXTURE_2D);*/
	//top
	glBindTexture(GL_TEXTURE_2D, black);
	//1
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 2. + xLen / 30., yLen / 2., -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(-xLen / 8., yLen / 2., -zLen / 2.);
			glTexCoord2d(1., 0.); glVertex3f(-xLen / 8., yLen / 2., zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(-xLen / 2. + xLen / 30., yLen / 2., zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//2
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(1., 0.); glVertex3f(0., yLen / 8., -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(-xLen / 8., yLen / 8., -zLen / 2.);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 8., yLen / 8., zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(0., yLen / 8., zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//3
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(0., 0., -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(xLen / 2. + xLen / 8., 0., -zLen / 2.);
			glTexCoord2d(1., 0.); glVertex3f(xLen / 2. + xLen / 8., 0.,zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(0., 0., zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	//bot
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0., 1.); glVertex3f(-xLen / 2. + xLen / 40., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(1., 1.); glVertex3f(xLen / 2. + xLen / 8., -yLen*0.35, -zLen / 2.);
			glTexCoord2d(1., 0.); glVertex3f(xLen / 2. + xLen / 8., -yLen*0.35, zLen / 2.);
			glTexCoord2d(0., 0.); glVertex3f(-xLen / 2. + xLen / 40., -yLen*0.35, zLen / 2.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//sounds ok

}
void rocket_truck::draw_doublewheel() {
	//first wheel
	//1first part
	xLen = 0.8 * xLen;
	glColor3f(0.5, 0.5, 0.5);
	gluCylinder(gluNewQuadric(), xLen / 27., xLen / 9., (zLen / 6.) * 0.1, 20, 10);
		//inside first part
		glColor3f(0.85, 0.85, 0.85);
		gluCylinder(gluNewQuadric(), xLen / 27.,0., (zLen / 6.) * 0.1, 20, 10);
	glTranslatef(0., 0., (zLen / 6.) * 0.1);
	//2 middle part 
	glColor3f(0., 0., 0.);
	gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., (zLen / 6.) * 0.8, 20, 10);
		//inside middle 
		glColor3f(0.3, 0.3, 0.3);
		gluCylinder(gluNewQuadric(), xLen / 27., xLen / 27., (zLen / 6.) * 0.8, 20, 10);
	glTranslatef(0., 0., (zLen / 6.) * 0.8);
	//3 second part
	glColor3f(0.5, 0.5, 0.5);
	gluCylinder(gluNewQuadric(), xLen / 9., xLen / 27., (zLen / 6.) * 0.1, 20, 10);
		//inside second part
		glColor3f(0.85, 0.85, 0.85);
		gluCylinder(gluNewQuadric(), 0.,xLen / 27., (zLen / 6.) * 0.1, 20, 10);
	glTranslatef(0., 0., (zLen / 6.) * 0.1);
	glTranslatef(0., 0., (zLen / 6.) * 0.03);
	//second wheel
	//1first part
	glColor3f(0.5, 0.5, 0.5);
	gluCylinder(gluNewQuadric(), xLen / 27., xLen / 9., (zLen / 6.) * 0.1, 20, 10);
		//inside first part
		glColor3f(0.85, 0.85, 0.85);
		gluCylinder(gluNewQuadric(), xLen / 27.,0., (zLen / 6.) * 0.1, 20, 10);
	glTranslatef(0., 0., (zLen / 6.) * 0.1);
	//2 middle part 
	glColor3f(0., 0., 0.);
	gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., (zLen / 6.) * 0.8, 20, 10);
		//inside middle 
		glColor3f(0.3, 0.3, 0.3);
		gluCylinder(gluNewQuadric(), xLen / 27., xLen / 27., (zLen / 6.) * 0.8, 20, 10);
	glTranslatef(0., 0., (zLen / 6.) * 0.8);
	//3
	glColor3f(0.5, 0.5, 0.5);
	gluCylinder(gluNewQuadric(), xLen / 9., xLen / 27., (zLen / 6.) * 0.1, 20, 10);
		//inside second part
		glColor3f(0.85, 0.85, 0.85);
		gluCylinder(gluNewQuadric(),0., xLen / 27., (zLen / 6.) * 0.1, 20, 10);
	glTranslatef(0., 0., (zLen / 6.) * 0.1);
	glTranslatef(0., 0., (zLen / 6.) * -2.1);//reset position
	xLen = 1.25 * xLen;
}
void rocket_truck::draw_wheels() {
	//given the position was reset to 0.f,0.f,0.f after the last part
	//first draw the rotation axe that holds the wheels
	glTranslatef(xLen / 2. - xLen / 8., 0., -zLen/2.);
	glColor4f(1., 1., 1., 1.);
	gluCylinder(gluNewQuadric(), xLen / 80., xLen / 80., zLen, 20, 10);
	glTranslatef( - xLen / 4., 0., 0.);
	glColor4f(1., 1., 1., 1.);
	gluCylinder(gluNewQuadric(), xLen / 80., xLen / 80., zLen, 20, 10);
	glTranslatef(-xLen / 2. ,0., 0.);
	glColor4f(1., 1., 1., 1.);
	gluCylinder(gluNewQuadric(), xLen / 80., xLen / 80., zLen, 20, 10);
	glTranslatef(0., 0., zLen / 2.); //and it resets the z position to 0.
	glRotatef(90., 0., 1., 0.);
	//glTranslatef(xLen / 2., 0., 0.);
	glColor4f(1., 1., 1., 1.);
	gluCylinder(gluNewQuadric(), xLen / 80., xLen / 80., xLen*0.8, 20, 10);
	glRotatef(-90, 0., -1, 0.);
	glTranslatef(0., 0., -zLen / 2.);
	//drawing wheels , each wheel made of 3 parts
	//1
	glColor3f(1., 1., 1.);
	//////////////////////////////////////////////////////////////////////////////////
	/// drawwing double wheels
	///////////////////////////////////////////////////////////////////////////////////
	glTranslatef(-xLen/8., 0., -zLen / 6.);
	draw_doublewheel();
	//gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., zLen / 8., 20, 10);
	//2
	glTranslatef(0., 0., zLen);
	//gonna be rplaced with another function for better graphics
	draw_doublewheel();
	//gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., zLen / 8., 20, 10);

	//3
	glTranslatef(-xLen / 2., 0., 0.);
	draw_doublewheel();
	//gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., zLen / 8., 20, 10);
	//4
	glTranslatef(0., 0., -zLen);
	draw_doublewheel();
	//gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., zLen / 8., 20, 10);
	//5
	glTranslatef(-xLen / 4., 0., 0.);
	draw_doublewheel();
	//gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., zLen / 8., 20, 10);
	//6
	glTranslatef(0., 0.,zLen);
	draw_doublewheel();
	//gluCylinder(gluNewQuadric(), xLen / 9., xLen / 9., zLen / 8., 20, 10);

}
void rocket_truck::draw_wheels_protections() {

}
void rocket_truck::draw_connection() {
	
}
void rocket_truck::draw_launcher() {
	float tempy=0., tempx=0.,oldtempx =0.,oldtempy=0.; 
/*	glBindTexture(GL_TEXTURE_2D, black);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2d(0., 0.); glVertex3f(-xLen / 8., yLen / 8., -zLen / 2.);
	glTexCoord2d(0., 1.); glVertex3f(-xLen / 8., -yLen * 0.35, -zLen / 2.);
	glTexCoord2d(1., 1.); glVertex3f(xLen / 2. + xLen / 8., -yLen * 0.35, -zLen / 2.);
	glTexCoord2d(1., 0.25); glVertex3f(xLen / 2. + xLen / 8., 0., -zLen / 2.);
	glTexCoord2d(0.25, 0.25); glVertex3f(0., 0., -zLen / 2.);
	glTexCoord2d(0.25, 0.); glVertex3f(0., yLen / 8., -zLen / 2.);
	glEnd();
	glDisable(GL_TEXTURE_2D);*/
	//////////////////////////////////////////////////////////////////////////////////////////////////1 //launcher
	//	FACES GOES LIKE F.BK.L.R.T.B
	glColor4f(1., 1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, blackalum);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 1.);   glVertex3f(xLen / 4., yLen / 2., -zLen * 0.499);
		glTexCoord2d(1., 1.);	glVertex3f(xLen/2., yLen / 2., -zLen * 0.499);
		glTexCoord2d(1., 0.);	glVertex3f(xLen/2.,0., -zLen * 0.499);
		glTexCoord2d(0., 0.);	glVertex3f(xLen/4, 0., -zLen * 0.499);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.);	glVertex3f(xLen/4., yLen / 2., zLen * 0.499);
		glTexCoord2d(0., 1.);	glVertex3f(xLen/2., yLen / 2., zLen * 0.499);
		glTexCoord2d(1., 1.);	glVertex3f(xLen/2.,0., zLen * 0.499);
		glTexCoord2d(1., 0.);	glVertex3f(xLen/4, 0., zLen * 0.499);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.);	glVertex3f(xLen / 4., yLen / 2., -zLen * 0.499);
		glTexCoord2d(0., 1.);	glVertex3f(xLen / 4, 0., -zLen * 0.499);
		glTexCoord2d(1., 1.);	glVertex3f(xLen / 4, 0., zLen * 0.499);
		glTexCoord2d(1., 0.);	glVertex3f(xLen / 4., yLen / 2., zLen * 0.499);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.);	glVertex3f(xLen / 2, yLen / 2., -zLen * 0.499);
		glTexCoord2d(0., 1.);	glVertex3f(xLen / 2, 0., -zLen * 0.499);
		glTexCoord2d(1., 1.);	glVertex3f(xLen / 2, 0., zLen * 0.499);
		glTexCoord2d(1., 0.);	glVertex3f(xLen / 2., yLen / 2., zLen * 0.499);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.);	glVertex3f(xLen / 4., yLen / 2., -zLen * 0.499);
		glTexCoord2d(0., 1.);	glVertex3f(xLen / 2., yLen / 2., -zLen * 0.499);
		glTexCoord2d(1., 1.);	glVertex3f(xLen / 2., yLen / 2., zLen * 0.499);
		glTexCoord2d(1., 0.);	glVertex3f(xLen / 4., yLen / 2., zLen * 0.499);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.);	glVertex3f(xLen / 2., 0., -zLen * 0.499);
		glTexCoord2d(0., 1.);	glVertex3f(xLen / 4, 0., -zLen * 0.499);
		glTexCoord2d(1., 1.);	glVertex3f(xLen / 4, 0., zLen * 0.499);
		glTexCoord2d(1., 0.);	glVertex3f(xLen / 2., 0., zLen * 0.499);
	glEnd();
	///////////////////////////////////////////////////////////////////////////////////////////////////2
	tempy = sin(105 * M_PI / 180.) * yLen / 2.;
	tempx = cos(105 * M_PI / 180.) * xLen / 4.;
	glBegin(GL_TRIANGLES);
		glTexCoord2d(0., 1.); glVertex3f(0. + xLen / 4., yLen / 2., -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx+xLen/4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4.,0., -zLen * 0.499);
	glEnd();
	glBegin(GL_TRIANGLES);
		glTexCoord2d(0., 1.); glVertex3f(0. + xLen / 4., yLen / 2., zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx+xLen/4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4.,0., zLen * 0.499);
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(0. + xLen / 4., yLen / 2., -zLen * 0.499);
		glTexCoord2d(0., 1.); glVertex3f(tempx+xLen/4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., yLen / 2., zLen * 0.499);
	glEnd();
	//no bot side
	oldtempx = tempx; oldtempy = tempy;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////3
	tempy = sin(120 * M_PI / 180.) * yLen / 2.;
	tempx = cos(120 * M_PI / 180.) * xLen / 4.;
	glBegin(GL_TRIANGLES);
		glTexCoord2d(0., 1.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., -zLen * 0.499);
	glEnd();
	glBegin(GL_TRIANGLES);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., zLen * 0.499);
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(0., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
	glEnd();
	oldtempx = tempx; oldtempy = tempy;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////4
	tempy = sin(135 * M_PI / 180.) * yLen / 2.;
	tempx = cos(135 * M_PI / 180.) * xLen / 4.;
	glBegin(GL_TRIANGLES);
		glTexCoord2d(0., 1.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., -zLen * 0.499);
	glEnd();
	glBegin(GL_TRIANGLES);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., zLen * 0.499);
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(0., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
	glEnd();
	oldtempx = tempx; oldtempy = tempy;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////5
	tempy = sin(150 * M_PI / 180.) * yLen / 2.;
	tempx = cos(150 * M_PI / 180.) * xLen / 4.;
	glBegin(GL_TRIANGLES);
		glTexCoord2d(0., 1.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., -zLen * 0.499);
	glEnd();
	glBegin(GL_TRIANGLES);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., zLen * 0.499);
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(0., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
	glEnd();
	oldtempx = tempx; oldtempy = tempy;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////6
	tempy = sin(165 * M_PI / 180.) * yLen / 2.;
	tempx = cos(165 * M_PI / 180.) * xLen / 4.;
	glBegin(GL_TRIANGLES);
		glTexCoord2d(0., 1.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., -zLen * 0.499);
	glEnd();
	glBegin(GL_TRIANGLES);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., zLen * 0.499);
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(0., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
	glEnd();
	oldtempx = tempx; oldtempy = tempy;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
	tempy = sin(180 * M_PI / 180.) * yLen / 2.;
	tempx = cos(180 * M_PI / 180.) * xLen / 4.;
	glBegin(GL_TRIANGLES);
		glTexCoord2d(0., 1.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., -zLen * 0.499);
	glEnd();
	glBegin(GL_TRIANGLES);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(0. + xLen / 4., 0., zLen * 0.499);
	glEnd();
	
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, -zLen * 0.499);
		glTexCoord2d(0., 1.); glVertex3f(tempx + xLen / 4., tempy, -zLen * 0.499);
		glTexCoord2d(1., 1.); glVertex3f(tempx + xLen / 4., tempy, zLen * 0.499);
		glTexCoord2d(1., 0.); glVertex3f(oldtempx + xLen / 4., oldtempy, zLen * 0.499);
	glEnd();
	oldtempx = tempx; oldtempy = tempy;
	glDisable(GL_TEXTURE_2D);
}
void rocket_truck::draw_rockets() {
}

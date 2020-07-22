#include "cube.h"
cube::cube(float fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT	
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();
	return;
}
cube::cube(float xLen, float yLen, float zLen, GLuint tx) {
	float texmax = 1.;
	glBindTexture(GL_TEXTURE_2D, tx);
	
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
void cube(float xLen, float yLen, float zLen) {
	glBegin(GL_POLYGON);   //Vorderseite
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT	
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glEnd();
	return;
}
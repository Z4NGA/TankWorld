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
cube::cube(float xLen, float yLen, float zLen) {
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
cube::cube(float xLen, float yLen, float zLen, std::vector<GLuint> txs) {
	//draws a cube with the given face textures
	//textures should be front / right / back / left /top /bot
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
	glBindTexture(GL_TEXTURE_2D, txs[0]);
	glEnable(GL_TEXTURE_2D); 
		glBegin(GL_POLYGON);   //Vorderseite
		glTexCoord2d(0., 0.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(0., 1.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(1., 1.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(1., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glEnd();
	
	glBindTexture(GL_TEXTURE_2D, txs[1]);

		glBegin(GL_POLYGON);   //Rechte Seite
		glTexCoord2d(0., 0.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(0., 1.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(1., 1.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(1., 0.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glEnd();
	glBindTexture(GL_TEXTURE_2D, txs[2]);

		glBegin(GL_POLYGON);   //Rueckseite
		glTexCoord2d(0., 0.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(0., 1.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(1., 1.); glTexCoord2d(0., 0.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(1., 0.); 
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glEnd();
	glBindTexture(GL_TEXTURE_2D, txs[3]);
	
		glBegin(GL_POLYGON);   //Linke Seite
		glTexCoord2d(0., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(0., 1.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(1., 1.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(1., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glEnd();
	glBindTexture(GL_TEXTURE_2D, txs[4]);

		glBegin(GL_POLYGON);   //Deckflaeche
		glTexCoord2d(0., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(0., 1.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(1., 1.);
		glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(1., 0.);
		glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
		glEnd();
	glBindTexture(GL_TEXTURE_2D, txs[5]);
 
		glBegin(GL_POLYGON);   //Bodenflaeche
		glTexCoord2d(0., 0.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(0., 1.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
		glTexCoord2d(1., 1.);
		glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glTexCoord2d(1., 0.);
		glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
		glEnd();

	glDisable(GL_TEXTURE_2D);
	return;
}
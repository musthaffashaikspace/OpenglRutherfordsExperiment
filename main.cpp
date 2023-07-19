#include<stdio.h>
#include<windows.h>
#include<cmath>
#include <GL/glut.h>
GLfloat alpharaycolor[]={0,0,1,1};
GLfloat scaraycolor[]={0,1,0,1};
GLfloat refraycolor[]={1,0,0,1};
GLfloat znscolor[]={0.753,0.753,0.753,1.0};
GLfloat alphasourcecolor[]={0.6,0.3,0,1.0};
GLfloat foilcolor[]={1,1,0,1};
GLfloat light_position[] = { 1,4,-4,1 };
GLfloat light_intensity[]= {0.7,0.7,0.7,1.0};
GLfloat viewer[]={1,5,-4};
int opt=1;

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0); // Set display-window color to white.
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode (GL_PROJECTION); // Set projection parameters.
    glLoadIdentity();
    gluOrtho2D (0.0, 2000.0, 0.0, 1000.0);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_NORMALIZE);
}

void threedinit()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    GLfloat ambientLight[] = { 1.0, 1.0, 1.0, 1.0 }; // Bright ambient light
    GLfloat diffuseLight[] = { 1.0, 1.0, 1.0, 1.0 }; // Bright diffuse light

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);

    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.333, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
void cube3d()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,alphasourcecolor);
        glPushMatrix();
            glTranslated(1.5,0,0);
            glScaled(0.1,0.1,0.1);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();
}
void goldfoil3d()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, foilcolor);
        glPushMatrix();
            glTranslated(0,0,0);
            glScaled(0.05,0.7,0.7);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();
}
void ZincScreen3d()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glRotatef(-20,0,1,0);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, znscolor);
        glPushMatrix();
            glTranslated(0,0,-1.02);
            glScaled(0.2,0.5,0.02);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();

    //2

    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glRotatef(+20,0,1,0);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, znscolor);
        glPushMatrix();
            glTranslated(-0.25,0,-1);
            glScaled(1,0.5,0.02);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();

    //3

    glRotatef(-20,0,1,0);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, znscolor);
        glPushMatrix();
            glTranslated(-1.05,0,-0.2);
            glScaled(0.02,0.5,1);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();

    //4

    glRotatef(+20,0,1,0);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, znscolor);
        glPushMatrix();
            glTranslated(-1.09,0,0.45);
            glScaled(0.02,0.5,1);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();

    //5

    glRotatef(+40,0,1,0);
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, znscolor);
        glPushMatrix();
            glTranslated(-1.45,0,+0.55);
            glScaled(0.01,0.5,1);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();
}

void alpharay3d(GLfloat x,GLfloat sx)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, alpharaycolor);
        glPushMatrix();
            glTranslated(x,0,0);
            glScaled(sx,0.015,0.01);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();
    glFlush();
}
void scaray3d(GLfloat x,GLfloat sx)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, scaraycolor);
        glPushMatrix();
            glTranslated(x,0,0);
            glScaled(sx,0.015,0.01);
            glutSolidCube(1);
        glPopMatrix();
    glPopAttrib();
    glFlush();
}
void refray3d()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, refraycolor);
        glPushMatrix();
            glTranslated(0.5,0,0.5);
            glutSolidSphere(0.04,30,30);
        glPopMatrix();
    glPopAttrib();
    glFlush();
}
void write_title_text(int x, int y, float r, float g, float b, char *string)
{
  glColor3f( r, g, b);
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
  glEnd();
}


void write_text(int x, int y, float r, float g, float b, char *string)
{
  glColor3f( r, g, b);
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
  }
  glEnd();
}


void circle(GLfloat x, GLfloat y, GLdouble radius) {
	float x2, y2;
	float angle;
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	for (angle = 0.0; angle < 6.3; angle += 0.01)
	{
		x2 = x + sin(angle)*radius;
		y2 = y + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}


void arc(GLfloat x, GLfloat y, GLdouble radius, GLfloat i, GLfloat j) {
	//i is intial angle,j is final angle of arc
	float x2, y2;
	float angle;
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);
	for (angle = i; angle <= j; angle += 0.01)
	{
		x2 = x + sin(angle)*radius;
		y2 = y + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}


void draw_atom_orbit(GLfloat x, GLfloat y, GLdouble radius, GLfloat i, GLfloat j) {
	//i is intial angle,j is final angle of arc
	float x2, y2;
	float angle;
	glLineWidth(2.0);
	glBegin(GL_LINE_STRIP);
	for (angle = i; angle <= j; angle += 0.01)
	{
		x2 = x + sin(angle)*radius;
		y2 = y + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}


void display_ZnsScreen(GLfloat x, GLfloat y, GLdouble radius, GLfloat i, GLfloat j) {
	//i is intial angle,j is final angle of arc
	float x2, y2;
	float angle;
	glLineWidth(10.0);
	glColor3f (0.6, 0.8, 0.9);
	glBegin(GL_LINE_STRIP);
	for (angle = i; angle <= j; angle += 0.01)
	{
		x2 = x + sin(angle)*radius;
		y2 = y + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}


void draw_alpha_ray(GLfloat x,GLfloat y)
{
    glColor3f(0,0,1);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(250,500);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}


void draw_reflected_alpha_particle(GLfloat x,GLfloat y)
{
    glPointSize(1);
    glColor3f(1,0,0);
    circle(x,y,5);
    glFlush();
    glEnd();
}


void draw_scattered_rays(void)
{
    glLineWidth(2);
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(1007,500);//60 degree
    glVertex2f(1300,846.416);
    glVertex2f(1007,500);//30 degree
    glVertex2f(1446.410,700);
    glVertex2f(1007,500);//45 degree
    glVertex2f(1382.84,782.842);
    glVertex2f(1007,500);//85 degree
    glVertex2f(1134.8622,898.8778);
    //-ve axes
    glVertex2f(1007,500);//-60 degree
    glVertex2f(1300,153.58);

    glVertex2f(1007,500);//-40 degree
    glVertex2f(1406.4177,242.884);

    glVertex2f(1007,500);//-80 degree
    glVertex2f(1169.4592,106.0768);


    glEnd();
    glFlush();

}


void display_cube()
{
    write_text(130,430,1,1,1,"AlphaRaySource");
    glColor3f (0.6, 0.3, 0.0);
    glBegin (GL_POLYGON);
    glVertex2i (200, 475);
    glVertex2i (250, 475);
    glVertex2i (250, 525);
    glVertex2i (200, 525);
    glEnd ( );

}


void display_glass_slit()
{
    write_text(365,390,1,1,1,"Glass Slit");
    glColor3f (0.9, 0.9, 1.0); // Set line segment color to green.
    glBegin (GL_POLYGON);
    glVertex2i (400, 508);
    glVertex2i (405, 508);
    glVertex2i (405, 570);
    glVertex2i (400, 570);
    glEnd ( );

    glBegin (GL_POLYGON);
    glVertex2i (400, 492);
    glVertex2i (405, 492);
    glVertex2i (405, 430);
    glVertex2i (400, 430);
    glEnd ( );

}


void display_gold_foil(void)
{
    write_text(940,420,1,1,1,"Gold Foil");
    glColor3f (1.0, 0.843, 0.0); // Set line segment color to green.
    glBegin (GL_POLYGON);
    glVertex2i (1000, 450);
    glVertex2i (1005, 450);
    glVertex2i (1005, 550);
    glVertex2i (1000, 550);
    glEnd ( );
}

void topviewinfo(void)
{
    glPointSize(1);
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(1600,950);
    glVertex2f(1900,950);
    glVertex2f(1600,920);
    glVertex2f(1900,920);
    glVertex2f(1600,890);
    glVertex2f(1900,890);
    glEnd();
    write_text(1600,860,1,1,1,"Scattered Rays");
    glColor3f(1,0,0);
    circle(1700,750,20);
    write_text(1580,690,1,1,1,"Reflected Alpha Particle");
    glFlush();
}


void draw_nucleus(void)
{
    glColor3f(0,0,1);
    circle(1000,500,100);
    write_text(960,500,1,1,1,"NUCLEUS");
    glFlush();
}


void drawatomskeleton(void)
{
    draw_nucleus();
    glColor3f(1,1,1);
    draw_atom_orbit(1000,500,200,0,8);
    draw_atom_orbit(1000,500,350,0,8);
    draw_atom_orbit(1000,500,470,0,8);
    glFlush();
}


void drawelectron(int radius,int angle)
{
    float theta=(angle*3.14)/180;
    glColor3f(1,0,0);
    circle(1000+radius*cos(theta),500+radius*sin(theta),10);
    glEnd();
    glFlush();
}


void display(void)
{
    init();
    glClearColor(0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    write_title_text(700,700,1,0,0,"RUTHERFORDS EXPERIMENT");
    write_title_text(700,600,0,0,1,"Kriti Srivatsava(1BI20CS095)");
    write_title_text(700,500,0,0,1,"Musthaffa Shaik(1BI20CS112)");
    write_text(700,400,0,0,0,"1.Top View");
    write_text(1000,400,0,0,0,"2.Atom View");
    write_text(700,300,0,0,0,"3.3D View");
    write_title_text(750,200,0,0,0,"MAXIMIZE THE SCREEN!");
    write_title_text(10,100,0,0,0,"'a' move camera left");
    write_title_text(400,100,0,0,0,"'b' move camera right");
    write_title_text(900,100,0,0,0,"'w' move camera up");
    write_title_text(1400,100,0,0,0,"'s' move camera down");
    write_title_text(1000,40,0,0,0,"'y' before reflection");
    write_title_text(600,40,0,0,0,"'n' after reflection");
    glFlush();
}


void Topview(void)
{
    init();
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    display_cube();
    display_glass_slit();
    display_gold_foil();
    display_ZnsScreen(1100,500,400,0,4.2);
    display_ZnsScreen(1100,500,400,5,8);
    write_text(1550,500,1,1,1,"Zinc Sulphide Screen");
    for(float i=0;i<736;i+=0.1)
    {
        draw_alpha_ray(260+i,500);
    }
    glLineWidth(2);
    draw_scattered_rays();
    for(float i=990;i>260;i-=0.7)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        display_cube();
        display_glass_slit();
        display_gold_foil();
        display_ZnsScreen(1100,500,400,0,4.2);
        display_ZnsScreen(1100,500,400,5,8);
        write_text(1550,500,1,1,1,"Zinc Sulphide Screen");
        draw_scattered_rays();
        draw_reflected_alpha_particle(i,500);
    }
    write_text(10,900,1,1,1,"1.Continue  2.AtomView     3.3D View");
    write_text(10,850,1,1,1,"Press Any Key To Go Back");
    topviewinfo();
    glFlush ( ); // Process all OpenGL routines as quickly as possible.
}


void Atomview(void)
{
    init();
    glClearColor(0,0,0,0);
    int theta=0;
    int i=0;
    while(i++<1)
    {
        for(float theta=0;theta<360;theta+=0.2)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            drawatomskeleton();
            drawelectron(200,theta);
            drawelectron(350,theta);
            drawelectron(470,theta);
            glColor3f(1,1,1);
            arc(1700,700,40,0,8);
            write_text(1750,700,1,1,1,"electron orbit");
            glColor3f(1,0,0);
            circle(1700,600,30);
            write_text(1750,600,1,1,1,"electron");
            glutSwapBuffers();

        }
        write_text(1550,500,1,1,1,"Screen Refresh Rate: 60Hz");
        write_text(10,900,1,1,1,"1.TopView    2.Continue   3.3D View");
        write_text(10,850,1,1,1,"Press Any Key To Go Back");

    }
    glFlush();
}

void ThreeDview()
{
    glClearColor(0,0,0,1);
    threedinit();
    if(opt==1)
    {
        threedinit();
        cube3d();
        goldfoil3d();
        alpharay3d(0.74,1.48);
        ZincScreen3d();
        glFlush();
    }
    else
    {
        threedinit();
        cube3d();
        goldfoil3d();
        scaray3d(-0.55,-1);
        ZincScreen3d();
        glRotated(30,0,1,1);
        scaray3d(-0.55,-1);
        glRotated(-30,0,1,1);
        scaray3d(-0.55,-1);
        refray3d();
        glFlush();
    }

}
void Normalkey(unsigned char key, int x, int y)
{
    if(key=='1')Topview();
    if(key=='2')Atomview();
    if(key=='3')ThreeDview();
	if(key == 'd') {viewer[0]-= 1.0;ThreeDview();}
    if(key == 'a') {viewer[0]+= 1.0;ThreeDview();}
    if(key == 's') {viewer[1]-= 1.0;ThreeDview();}
    if(key == 'w') {viewer[1]+= 1.0;ThreeDview();}
    if(key=='y'){opt=1;ThreeDview();}
    if(key=='n'){opt=2;ThreeDview();}
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv); // Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set display mode.
    glutInitWindowPosition (0, 0); // Set top-left display-window position.
    glutInitWindowSize (1200, 600); // Set display-window width and height.
    glutCreateWindow ("Alpha Ray Scattering Experiment"); // Create displaywindow.
    init ( ); // Execute initialization procedure.
    glutDisplayFunc (display);
    glutKeyboardFunc(Normalkey);
    glutMainLoop ( );
}



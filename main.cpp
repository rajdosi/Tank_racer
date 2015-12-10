#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
bool* keyStates = new bool[256];
float xvalue=-5.0;
int bflag=0;
void bomb(float, float);
void reset();
void show();
void score();
void hangman();
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

/********Keypress functionalities****************/
void keyOperations (void) {
if (keyStates['a'])
	{ // If the 'a' key has been pressed// Perform 'a' key operations
		 //ch='a';
		if((xvalue-0.4)>-6.0)
		xvalue-=0.2;
	}
if (keyStates[27])
	{ // If the 'a' key has been pressed// Perform 'esc' key operations
		   exit(0);
	}
if (keyStates['d'])
	{ // If the 'a' key has been pressed// Perform 'd' key operations
		 //ch='d';
		if((xvalue+0.6)<=-2.0)
		xvalue+=0.2;
	}
if (keyStates['A'])
	{ // If the 'a' key has been pressed// Perform 'A' key operations
		 //ch='A';
		if((xvalue-0.4)>-6.0)
		xvalue-=0.2;
	}
if (keyStates['D'])
	{ // If the 'a' key has been pressed// Perform 'D' key operations
		 //ch='D';
		if((xvalue+0.6)<=-2.0)
		xvalue+=0.2;
	}

if (keyStates[' '])
	{	bflag=1;
	}
}

/*******Displaying tank according to coordinates************/
void tank(float x, float y)
{
	glBegin(GL_QUADS);
		glColor3f(0.5, 0.4, 0.35);
		glVertex3f(x, y, 0.0f);
		glVertex3f(x, y+0.5f, 0.0f);
		glVertex3f(x-0.2, y+0.5f, 0.0f);
		glVertex3f(x-0.2f, y, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.5, 0.4, 0.35);
		glVertex3f(x+0.4, y, 0.0f);
		glVertex3f(x+0.4, y+0.5f, 0.0f);
		glVertex3f(x+0.2, y+0.5f, 0.0f);
		glVertex3f(x+0.2, y, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.89, 0.65, 0.40);
		glVertex3f(x+0.2, y+0.1f, 0.0f);
		glVertex3f(x+0.2, y+0.4f, 0.0f);
		glVertex3f(x, y+0.4f, 0.0f);
		glVertex3f(x, y+0.1f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.74, 0.54, 0.34);
		glVertex3f(x+0.15, y+0.4f, 0.0f);
		glVertex3f(x+0.15, y+0.7f, 0.0f);
		glVertex3f(x+0.05, y+0.7f, 0.0f);
		glVertex3f(x+0.05, y+0.4f, 0.0f);
	glEnd();
}
/*******Enemy tank view*******************/
void tanke(float x, float y)
{
	glBegin(GL_QUADS);
		glColor3f(0.7, 0.4, 0.35);
		glVertex3f(x, y, 0.0f);
		glVertex3f(x, y+0.5f, 0.0f);
		glVertex3f(x-0.2, y+0.5f, 0.0f);
		glVertex3f(x-0.2f, y, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.7, 0.4, 0.35);
		glVertex3f(x+0.4, y, 0.0f);
		glVertex3f(x+0.4, y+0.5f, 0.0f);
		glVertex3f(x+0.2, y+0.5f, 0.0f);
		glVertex3f(x+0.2, y, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.7, 0.5, 0.35);
		glVertex3f(x+0.2, y+0.1f, 0.0f);
		glVertex3f(x+0.2, y+0.4f, 0.0f);
		glVertex3f(x, y+0.4f, 0.0f);
		glVertex3f(x, y+0.1f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.74, 0.54, 0.34);
		glVertex3f(x+0.15, y+0.4f, 0.0f);
		glVertex3f(x+0.15, y+0.7f, 0.0f);
		glVertex3f(x+0.05, y+0.7f, 0.0f);
		glVertex3f(x+0.05, y+0.4f, 0.0f);
	glEnd();
}
float yvalue=0.0;

/***********Displaying bomb at correct place**************/
void bomb(float x, float y)
{
	glBegin(GL_QUADS);
		glColor3f(2.37, 2.02, 0.3);
		glVertex3f(x+0.15, yvalue+y+0.75f, 0.0f);
		glVertex3f(x+0.15, yvalue+y+0.9f, 0.0f);
		glVertex3f(x+0.05, yvalue+y+0.9f, 0.0f);
		glVertex3f(x+0.05, yvalue+y+0.75f, 0.0f);
	glEnd();
	yvalue+=1.0 ;
	if(yvalue+y>4.0)
	{
			yvalue=0.0;
			bflag=0;
	}
}

float a=5.0, b=1.0, c=-3.0 ;
void road()
{

//************Road*************************
	glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(-6.0f, -5.0f, 0.0f);
		glVertex3f(-6.0f, 5.0f, 0.0);
		glVertex3f(-2.0f, 5.0f, 0.0);
		glVertex3f(-2.0f, -5.0f, 0.0);
	glEnd();

//************Stripes On the Road***********
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-4.1f, a-2, 0.0f);
		glVertex3f(-4.1f, a, 0.0);
		glVertex3f(-3.9f, a, 0.0);
		glVertex3f(-3.9f, a-2, 0.0);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-4.1f, b-2, 0.0f);
		glVertex3f(-4.1f, b, 0.0);
		glVertex3f(-3.9f, b, 0.0);
		glVertex3f(-3.9f, b-2, 0.0);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-4.1f, c-2, 0.0f);
		glVertex3f(-4.1f, c, 0.0);
		glVertex3f(-3.9f, c, 0.0);
		glVertex3f(-3.9f, c-2, 0.0);
	glEnd();
	//******************tank body******************
	a--, b--, c--;
	if(a-1<=-7)
	{
		a=5;
	}
	if(b-1<=-7)
	{
		b=5;
	}
	if(c-1<=-7)
	{
		c=5;
	}




}

float enemyy1=5.0, enemyx1=-3.2 ;
float enemyy2=6.0, enemyx2=-5.0 ;
float enemyy3=10.0, enemyx3=-4.0 ;
float enemyy4=9.0, enemyx4=-5.75 ;
float enemyy5=9.0, enemyx5=-2.5 ;
int e1=0, e2=0, e3=0, e4=0, e5=0;
int de1=0, de2=0, de3=0, de4=0, de5=0;
int chanc=30001;
int scorev=0;
//float inc = 0.0005;
int dcount=0;
void renderScene1(void) {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 0.0f, 10.0f,
				0.0f, 0.0f,  0.0f,
				0.0f, 1.0f,  0.0f);
	road();
	keyOperations();

	score();
	hangman();
	if(chanc<=10)
	{	show();
		chanc++;
	}
	else
	{	/*
		if(dcount==4)
		{	exit(0);
		}*/

		if((xvalue>=enemyx1-0.4)&&(xvalue<=enemyx1+0.4))
		{
			if((-3.0>enemyy1)&&(de1==0))
			{	dcount++;
				reset();
				chanc=0;
			}
		}
		if((xvalue>=enemyx2-0.4)&&(xvalue<=enemyx2+0.4))
		{
			if((-3.0>enemyy2)&&(de2==0))
			{	dcount++;
				reset();
				chanc=0;
			}
		}
		if((xvalue>=enemyx3-0.4)&&(xvalue<=enemyx3+0.4))
		{
			if((-3.0>enemyy3)&&(de3==0))
			{	dcount++;
				reset();
				chanc=0;
			}
		}
		if((xvalue>=enemyx4-0.4)&&(xvalue<=enemyx4+0.4))
		{
			if((-3.0>enemyy4)&&(de4==0))
			{	dcount++;
				reset();
				chanc=0;
			}
		}
		if((xvalue>=enemyx5-0.4)&&(xvalue<=enemyx5+0.4))
		{
			if((-3.0>enemyy5)&&(de5==0))
			{	dcount++;
				reset();
				chanc=0;
			}
		}



		tank(xvalue,-3.5);
		if(bflag==1)
		{
			bomb(xvalue,-3.5);
		}



		if((xvalue>=enemyx1-0.2)&&(xvalue<=enemyx1+0.4))
		{
			if(yvalue-3.5>enemyy1)
			{	e1=1;
				bflag=0;
				yvalue=0.0;
				de1=1;
				scorev++;
				enemyy1=5.0;
			}
		}
		if(e1==0)
		tanke(enemyx1,enemyy1);
		enemyy1-=0.08 ;
		if(enemyy1<-3.6)
		{	de1=1;
		}
		if(enemyy1<=-5.0)
		{
			enemyy1=5.0;
			e1=0;
			de1=0;
		}


		if((xvalue>=enemyx2-0.2)&&(xvalue<=enemyx2+0.4))
		{
			if(yvalue-3.5>enemyy2)
			{	e2=1;
			bflag=0;
			yvalue=0.0;
			de2=1;
			scorev++;
			}
		}
		if(e2==0)
		tanke(enemyx2,enemyy2);
		enemyy2-=0.1 ;
		if(enemyy2<-3.6)
		{	de2=1;
		}
		if(enemyy2<=-5.0)
		{
			enemyy2=5.0;
			e2=0;
			de2=0;
		}

		if((xvalue>=enemyx3-0.2)&&(xvalue<=enemyx3+0.4))
		{
			if(yvalue-3.5>enemyy3)
			{	e3=1;
			bflag=0;
			yvalue=0.0;
			de3=1;
			scorev++;
			}
		}
		if(e3==0)
		tanke(enemyx3,enemyy3);
		enemyy3-=0.1 ;
		if(enemyy3<-3.6)
		{	de3=1;
		}
		if(enemyy3<=-5.0)
		{
			enemyy3=5.0;
			e3=0;
			de3=0;
		}


		if((xvalue>=enemyx4-0.2)&&(xvalue<=enemyx4+0.4))
		{
			if(yvalue-3.5>enemyy4)
			{	e4=1;
				bflag=0;
				yvalue=0.0;
				de4=1;
				scorev++;
			}
		}
		if(e4==0)
		tanke(enemyx4,enemyy4);
		enemyy4-=0.08 ;
		if(enemyy4<-3.6)
		{	de4=1;
		}
		if(enemyy4<=-5.0)
		{
			enemyy4=5.0;
			e4=0;
			de4=0;
		}

		if((xvalue>=enemyx5-0.2)&&(xvalue<=enemyx5+0.4))
		{
			if(yvalue-3.5>enemyy5)
			{	e5=1;
				bflag=0;
				yvalue=0.0;
				de5=1;
				scorev++;
			}
		}
		if(e5==0)
		tanke(enemyx5,enemyy5);
		enemyy5-=0.09 ;
		if(enemyy5<-3.6)
		{	de5=1;
		}
		if(enemyy5<=-5.0)
		{
			enemyy5=5.0;
			e5=0;
			de5=0;
		}
	}
	glutSwapBuffers();
}

char str[25];
void show()
{	glColor3f(0,1,0);
	glRasterPos3f(0,0,0);
	if(scorev==100)
	{
		sprintf(str,"Congo You Won The Game!!!!   ");
		for(int i=0;i<25;i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
		glRasterPos3f(0,-0.4,0);
		sprintf(str,"Press esc to exit!!!!   ");
		for(int i=0;i<25;i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
	}
		else{
		if (dcount<4)
		{
			sprintf(str,"Chance left : %d  ",4-dcount);
			for(int i=0;i<25;i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
		}
		else
		{
			sprintf(str,"!!! Game Over !!!");
			for(int i=0;i<25;i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
			chanc=0;
		}
	}
}


void score()
{
	if(scorev==1000)
	{
		glColor3f(1,0,0);
		glRasterPos3f(-7.3,3.9,0);
		sprintf(str,"Congo You Won The Game!!!!   ");
		for(int i=0;i<25;i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
		chanc=0;
	}
	else{
		glColor3f(1,0,0);
		glRasterPos3f(-7.3,3.9,0);
		sprintf(str,"Score : %d       ",scorev);
		for(int i=0;i<25;i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
		float ly=3.3 ;
		for(int i=0; i<3-dcount; i++)
		{
			tank(-1.5,ly);
			ly-=0.7;
		}
	}
}

void reset()
{	enemyy1=5.0;
	enemyy2=6.0;
	enemyy3=10.0;
	enemyy4=9.0;
	enemyy5=9.0;
	e1=0; e2=0; e3=0; e4=0; e5=0;

}

int flipdl=0;
float dl=0.0;
void hangman()
{
	//head
	if(dcount>=1)
	{
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		for(int i=0; i<100; i++)
		{
			glVertex3f(2.5+0.5*cos(i*3.6*3.14/180), 1+0.5*sin(i*3.6*3.14/180), 0);
		}
	glEnd();
	}
	if(dcount>=2)
	{
	//neck
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(2.7,1,0);
		glVertex3f(2.7,0.25,0);
		glVertex3f(2.3,0.25,0);
		glVertex3f(2.3,1,0);
	glEnd();
	//body
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		//glVertex3f(1.75,0.19,0);
		glVertex3f(2,0.25,0);
		glVertex3f(3,0.25,0);
		//glVertex3f(3.25,0.19,0);
		glVertex3f(3,-1.75,0);
		glVertex3f(2,-1.75,0);
	glEnd();
	//hands
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(2,0.25,0);
		glVertex3f(2,-0.2,0);
		glVertex3f(1.25,-0.28,0);
		glVertex3f(1.25,0.19,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(3,0.25,0);
		glVertex3f(3,-0.2,0);
		glVertex3f(3.75,-0.28,0);
		glVertex3f(3.75,0.19,0);
	glEnd();
	}
	if(dcount==3)
	{
	//legs
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(2.95,-1.75,0);
		glVertex3f(3.2,-2.75,0);
		glVertex3f(2.95,-2.75,0);
		glVertex3f(2.7,-1.75,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(2.05,-1.75,0);
		glVertex3f(1.8,-2.75,0);
		glVertex3f(2.05,-2.75,0);
		glVertex3f(2.3,-1.75,0);
	glEnd();
	}
	if(dcount>=4)
	{
	//Dancing legs
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(2.95,-1.75,0);
		glVertex3f(3.2-dl,-2.75,0);
		glVertex3f(2.95-dl,-2.75,0);
		glVertex3f(2.7,-1.75,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(2.05,-1.75,0);
		glVertex3f(1.8+dl,-2.75,0);
		glVertex3f(2.05+dl,-2.75,0);
		glVertex3f(2.3,-1.75,0);
	glEnd();
	if(dl>=0.25)
	{
		flipdl=1;
	}
	if(dl<=0.0)
	{
		flipdl=0;
	}
	if(flipdl==0)
	{
		dl+=0.02;
	}
	else
	{
		dl-=0.02;
	}

	//hanging rope
	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		for(int i=0; i<100; i++)
		{
			glVertex3f(2.5+0.75*cos(i*3.6*3.14/180), 1+0.75*sin(i*3.6*3.14/180), 0);
		}
		for(int i=0; i<100; i++)
		{
			glVertex3f(2.5+0.74*cos((i+1)*3.6*3.14/180), 1+0.74*sin((i+1)*3.6*3.14/180), 0);
		}
	glEnd();
	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(2.5,1.74,0);
		glVertex3f(2.5,5,0);
	glEnd();
	}
}


float cont=100.0, rate=0.0 ;
float rate1=0.0;
void renderScene(int x)
{
	renderScene1();
	glutTimerFunc(cont-rate,renderScene, 2);
	if(keyStates['w']==true)
	{
		rate=90;
		rate1+=0.05;
	}
	else
	{
		rate=rate1;
	}
	if(rate<=90.0)
	{
	rate1+=0.05;
	}
}

void keyPressed (unsigned char key, int x, int y) {
keyStates[key] = true; // Set the state of the current key to pressed
}

void keyUp (unsigned char key, int x, int y) {
	if(key!=37 && key!='r')
keyStates[key] = false; // Set the state of the current key to not pressed
}

int main(int argc, char **argv) {

	keyStates['a'] = false; /// Clear KeyStates
    keyStates['d'] = false;
    keyStates['A'] = false;
    keyStates['r'] = false;
    keyStates['D'] = false;
    keyStates[27] = false;
    keyStates[' ']= false;
	keyStates['w']= false;
	keyStates['W']= false;
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,640);
	glutCreateWindow("Tank Game");
	glutFullScreen();
	renderScene(0);
	// register callbacks
	glutDisplayFunc(renderScene1);
	glutReshapeFunc(changeSize);
	//glutIdleFunc(renderScene1);

	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}

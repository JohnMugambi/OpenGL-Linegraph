//Eddie Muiruri SCT212-0561/2018
//John Mugambi	SCT212-0209/2018

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;
//Declaring the daily earings from monday to saturday
int monday_earning, tuesday_earning, wednesday_earning, thursday_earning, friday_earning, saturday_earning;

void init()
{
	//set drawing color
	glColor3f(0.0f, 0.0f, 0.0f);	
	glOrtho(0, 500, 0, 500, -1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}
//Function to draw the pixels for the x and y axis
void draw_pixel(int x, int y)
{
	glColor3f(1, 1, 0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

//Function to draw the x axis using the Bresenham algorithm
void LineBresDrawXAxis(int xstart, int ystart, int xend, int yend)
{
	int dx = fabs(xend - xstart); //chenge in x
	int dy = fabs(yend - ystart); //change in y
	int twody = 2 * dy, twodyminusdx = 2 * (dy - dx); //twody for for p < 0 and twodyminusdx for p >= 0
	int p = 2 * dy - dx;  //p is the Decision Parameter
	int x, y;

	if (xstart > xend)
	{
		x = xend;
		y = yend;
		xend = xstart;
	}
	else
	{
		x = xstart;
		y = ystart;
	}
	draw_pixel(x, y);
	while (x < xend) //until you reach the last x value
	{
		x++;
		//get both case1 and case2
		if (p < 0)
			p += twody;
		else
		{
			y++;
			p += twodyminusdx;
		}
		draw_pixel(x, y);
	}


}

//Function to draw the y axis using the Bresenham algorithm
void LineBresDrawYAxis(int xstart, int ystart, int xend, int yend)
{
	int dx = fabs(xend - xstart); //cahenge in x
	int dy = fabs(yend - ystart); //change in y
	int twody = 2 * dy, twodyminusdx = 2 * (dy - dx); //twody for for p < 0 and twodyminusdx for p >= 0
	int p = 2 * dy - dx;  //p is the Decision Parameter
	int x, y;

	if (xstart > xend)
	{
		x = xend;
		y = yend;
		xend = xstart;

	}
	else
	{
		x = xstart;
		y = ystart;

	}
	draw_pixel(x, y);


	while (y < yend) //until you reach the last x value
	{

		//get both case1 and case2
		if (p < 0)
			p += twody;
		else
		{
			y++;
			p += twodyminusdx;

		}

		draw_pixel(x, y);

	}


}

//Function for drawing text and labeling the x and y axis
void drawText(const char* text, int length, int x, int y) {

	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	//glLoadIdentity();
	glOrtho(0, 500, 0, 500, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);

	for (int i = 0; i < length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);

	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);

}

//Function for drawing the asterisks for at the data points
void draw_asterisk(int astr_x, int astr_y){
	//initialize the asterisk center point
	//which is also the data point
	int x = astr_x;
	int y = astr_y;

	glLineWidth(1.0);

	//drawing the lines of the asterisk from the data points
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x - 5, y);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x, y - 10);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x, y + 10);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x + 5, y);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x + 5, y + 5);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x - 5, y - 5);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x - 5, y + 5);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x + 5, y - 5);
	glEnd();

	glFlush();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);

	//My X axis
	LineBresDrawXAxis(50, 100, 470, 100);
	//Day text label 
	const char* text = "Days";
	int len = strlen(text);
	drawText(text, len, 250, 50);

	//*****
	//My Y axis
	LineBresDrawYAxis(50, 100, 50, 490);
	//KSH label text
	const char* yAxisText = "Ksh";
	int ylen = strlen(yAxisText);
	drawText(yAxisText, ylen, 20, 300);

	//*******
	//Y axis labeling points
	const char* no0 = "0";
	int no0len = strlen(no0);
	drawText(no0, no0len, 35, 100);

	const char* no1 = "100";
	int no1len = strlen(no1);
	drawText(no1, no1len, 35, 132.5);

	const char* no2 = "200";
	int no2len = strlen(no2);
	drawText(no2, no2len, 35, 165);

	const char* no3 = "300";
	int no3len = strlen(no3);
	drawText(no3, no3len, 35, 197.5);

	const char* no4 = "400";
	int no4len = strlen(no4);
	drawText(no4, no4len, 35, 230);

	const char* no5 = "500";
	int no5len = strlen(no5);
	drawText(no5, no5len, 35, 262.5);

	const char* no6 = "600";
	int no6len = strlen(no6);
	drawText(no6, no6len, 35, 295);

	const char* no7 = "700";
	int no7len = strlen(no7);
	drawText(no7, no7len, 35, 327.5);

	const char* no8 = "800";
	int no8len = strlen(no8);
	drawText(no8, no8len, 35, 360);

	const char* no9 = "900";
	int no9len = strlen(no9);
	drawText(no9, no9len, 35, 392.5);

	const char* no10 = "1000";
	int no10len = strlen(no10);
	drawText(no10, no10len, 35, 425);

	const char* no11 = "1100";
	int no11len = strlen(no11);
	drawText(no11, no11len, 35, 457.5);


	//X axis Labelling
	const char* mon = "Mon";
	int monlen = strlen(mon);
	drawText(mon, monlen, 120, 90);

	const char* tue = "Tue";
	int tuelen = strlen(tue);
	drawText(tue, tuelen, 190, 90);

	const char* wed = "Wed";
	int wedlen = strlen(wed);
	drawText(wed, wedlen, 260, 90);

	const char* thur = "Thur";
	int thurlen = strlen(thur);
	drawText(thur, thurlen, 330, 90);

	const char* fri = "Fri";
	int frilen = strlen(fri);
	drawText(fri, frilen, 400, 90);

	const char* sat = "Sat";
	int satlen = strlen(sat);
	drawText(sat, satlen, 470, 90);


	//taking the user earning input and calculating its desired y coordinate according to our graph
	int new_monday_earning = 100 + (32.5 * (monday_earning / 100));
	int new_tuesday_earning = 100 + (32.5 * (tuesday_earning / 100));
	int new_wednesday_earning = 100 + (32.5 * (wednesday_earning / 100));
	int new_thursday_earning = 100 + (32.5 * (thursday_earning / 100));
	int new_friday_earning = 100 + (32.5 * (friday_earning / 100));
	int new_saturday_earning = 100 + (32.5 * (saturday_earning / 100));

	//draw asterix at the data points
	draw_asterisk(120, new_monday_earning);
	draw_asterisk(190, new_tuesday_earning);
	draw_asterisk(260, new_wednesday_earning);
	draw_asterisk(330, new_thursday_earning);
	draw_asterisk(400, new_friday_earning);
	draw_asterisk(470, new_saturday_earning);


	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glPointSize(2.0);			//a dot is 4x4
	glVertex2i(120, new_monday_earning);
	glVertex2i(190, new_tuesday_earning);
	glEnd();

	glBegin(GL_LINES);
	glPointSize(2.0);//a dot is 4x4
	glVertex2i(190, new_tuesday_earning);
	glVertex2i(260, new_wednesday_earning);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(260, new_wednesday_earning);
	glVertex2i(330, new_thursday_earning);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(330, new_thursday_earning);
	glVertex2i(400, new_friday_earning);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(400, new_friday_earning);
	glVertex2i(470, new_saturday_earning);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	//request input for the daily earnings
	cout << "*****Gashororo Daily Earnings******" << endl;
	cout << "Enter earnings: \n" << endl;
	monday_earning = 500.1;
	cout << "\n Monday earning: (500)" << monday_earning << endl;
	tuesday_earning = 850;
	cout << "\n Tuesday earning: (850) " << tuesday_earning << endl;
	wednesday_earning = 600;
	cout << "\n Wednesday earning: (600)" << wednesday_earning << endl;
	thursday_earning = 570;
	cout << "\n Thursday earning: (570)"<< thursday_earning <<endl;
	friday_earning = 1000;
	cout << "\n Friday earning: (1000)" << friday_earning << endl;
	saturday_earning = 1020;
	cout << "\n Saturday earning: (1020)" << saturday_earning << endl;


	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1200, 650);
	glutCreateWindow("Gachororo Line Graph");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();

	return 0;
}

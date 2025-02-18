#include <stdio.h>
#include <windows.h>
#include <math.h> // Для fabs()

#define EPSILON 0.05f  

void chelovek(int i, int j);


int Length = 120;
int Width = 40;
char pole[40][121];  
void gotoxy(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j, l;
    float t=0.01;
    float z = 0;
    float b1, b2, angle;
    float xc1, yc1, xc2, yc2, xT1, xT2, yT1, yT2, R, r, sqrt_term, d, k1, k2, l1, l2, TEMP;
    float x = (float)j / Length * 2.0f - 1.0f;
    float y = (float)i / Width * 2.0f - 1.0f;
    r=0.10;
    while(1){
        for (i = 0; i < Width; i++) {
            for (j = 0; j < Length; j++) {
                pole[i][j] = ' ';
            }
            pole[i][Length] = '\0';  
        }

        for (i = 0; i < Width; i++) {
            for (j = 0; j < Length; j++) {
                x= ((float)j / Length * 2.0f - 1.0f);
                y= -((float)i /  Width * 2.0f - 1.0f);
                x*=1/0.33333f*1/2.0f;
                xc1=cos(t)/2;
                yc1=sin(t)/2;
                yc2=sin(t)/2+sin(2*t)/2;
                xc2=cos(t)/2+cos(2*t)/2;
                if((x-xc1)*(x-xc1)+(y-yc1)*(y-yc1)<r) {
                    pole[i][j] = '@';
                }
                if((x-xc2)*(x-xc2)+
                  (y-yc2)*(y-yc2)<0.02) {
                 pole[i][j] = 'o';
                }
                d = sqrt((xc2 - xc1) * (xc2 - xc1) + (yc2 - yc1) * (yc2 - yc1));
                sqrt_term = sqrt(d * d - r * r);
                xT1 = xc1 + r * ((xc2 - xc1) * (r / d) + (yc2 - yc1) * sqrt_term / (d * r));
                xT2 = xc1 + r * ((xc2 - xc1) * (r / d) - (yc2 - yc1) * sqrt_term / (d * r));
                yT1 = yc1 + r * ((yc2 - yc1) * (r / d) - (xc2 - xc1) * sqrt_term / (d * r));
                yT2 = yc1 + r * ((yc2 - yc1) * (r / d) + (xc2 - xc1) * sqrt_term / (d * r));

                k1 = (yT1 - yc2) / (xT1 - xc2);
                k2 = (yT2 - yc2) / (xT2 - xc2);
                b1 = yc2 - k1 * xc2;
                b2 = yc2 - k2 * xc2;
                
                if(fabs(y-k1*x-b1)<EPSILON) {
                    pole[i][j] = '@';

                }
                if(fabs(y-k2*x-b2)<EPSILON) {

                    pole[i][j] = '.';

                }
            }
        }
        for (i = 0; i < Width; i++) {
            printf("%s\n", pole[i]);
        }
        t+=0.05f;
        Sleep(50);
    }

        return 0;
}


void chelovek(int i, int j) {
        pole[i][j] = '@';   
        pole[i + 1][j] = '|'; 
        pole[i + 1][j - 1] = '/';  
        pole[i + 1][j + 1] = '\\'; 
        pole[i + 2][j - 1] = '/';  
        pole[i + 2][j + 1] = '\\'; 
}
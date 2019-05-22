/*
                             
                             MiniGolfCompanion
                                    BY
                                  EYEBALL
                                   
                                   V 1.0
                                   
*/
#include "gfx.h"

#include <Arduboy2.h>

Arduboy2 arduboy;
Sprites sprites;

byte man2SpriteNum = 0;

String player[6] = {("PLAYER_1"), ("PLAYER_2"), ("PLAYER_3"), ("PLAYER_4"), ("PLAYER_5"), ("PLAYER_6")};

char abc[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int tim = 0;

uint8_t i = 0;
uint8_t j = 0;
uint8_t k = 0;
uint8_t l = 0;
uint8_t m = 0;
uint8_t n = 0;

uint8_t scr = 0;

uint8_t r = 0;
uint8_t s = 0;

uint8_t tot[6];

uint8_t num[2][18] = {
                   {2, 14, 26, 38, 50, 62, 74, 86, 98, 110, 122, 2, 14, 26, 38, 50, 62, 74},
                   {37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 53, 53, 53, 53, 53, 53, 53}
                   };

uint8_t tabel[2][18] = {
                   {0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 0, 12, 24, 36, 48, 60, 72},
                   {34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 50, 50, 50, 50, 50, 50, 50}
                   };

uint8_t tabel2[2][6] = {
                   {12, 30, 48, 66, 84, 102},
                   {-1, 0, 1, 2, 3, 4}
                   };

uint8_t tabel3[2][8] = {
                   {14, 20, 26, 32, 38, 44, 50, 56},
                   {1, 0, 0, 0, 0, 0, 0, 0}             // use for hole
                   };

uint8_t score[6][18];

void setup() {
  arduboy.begin();
  arduboy.clear();
  titel();
}

void loop() {
  if (!arduboy.nextFrame())
  return;
  arduboy.pollButtons();
  arduboy.clear();

  switch (scr){
    case 0:
      players();
      break;
    case 1:
      playName();
      break;
    case 2:
      scoreboard();
      tim++;
      break;
    case 3:
      win();
      break;
      }

    if(arduboy.justPressed(B_BUTTON)) {
      if (scr >= 3){
         scr = 2;
        }
      else {
        scr++;
        }
      }
    if(arduboy.pressed(B_BUTTON + LEFT_BUTTON)) {
         scr = 0;
        }
}

void titel(){
  arduboy.drawBitmap(0, 0, Intro, 128, 64, WHITE);
  arduboy.display();
  delay(4000);
}
    
void players(){
  if(arduboy.justPressed(LEFT_BUTTON)) {
      if(k > 0) {
        k -= 1;
      }
      else{
        k = 5;
      }
    }

    if(arduboy.justPressed(RIGHT_BUTTON)) {
      if(k < 5){
        k += 1;
      }
      else{
        k = 0;
        }
    }
    
  if(arduboy.justPressed(A_BUTTON)) {
      s = tabel2[1][k];
      
      }
  
  arduboy.clear();
  arduboy.setCursor(10, 20);
  arduboy.print("HOWE MANY PLAYERS ?");
  arduboy.setCursor(14, 40);
  arduboy.print("1  2  3  4  5  6");

  arduboy.drawBitmap(tabel2[0][k], 37, cusor, 9, 12, WHITE);
    
  arduboy.display();
}

void playName(){
     if(arduboy.justPressed(LEFT_BUTTON)) {
      if(m > 0) {
        m -= 1;
      }
      else{
        m = 7;
      }
    }

    if(arduboy.justPressed(RIGHT_BUTTON)) {
      if(m < 7){
        m += 1;
      }
      else{
        m = 0;
        }
    }

    if(arduboy.justPressed(UP_BUTTON)) {
      if(n >= 25){
        n = 0;
        }
        n++;
        }
    
    if(arduboy.justPressed(DOWN_BUTTON)) {
      if(n <= 0){
        n = 25;
        }
        n--;
        }

      if(arduboy.justPressed(A_BUTTON)) {
      

      }
      
  arduboy.clear();

  arduboy.setCursor(tabel3[0][m], 44);
  arduboy.print('_');
    
  arduboy.setCursor(10, 20);
  arduboy.print("PLAYER NAME: ?");
  arduboy.setCursor(14, 40);
  arduboy.print(player[0]);

  arduboy.display();


}

void scoreboard(){
    arduboy.clear();

if (tim >= 500){
    man();
}
arduboy.drawBitmap(77, 20, bana, 50, 8, WHITE);
sprites.drawPlusMask(108, 8, man2_plus_mask, man2SpriteNum);

    arduboy.setCursor(0, 4);
    arduboy.print(player[r]);
    
    arduboy.setCursor(1,21);
    arduboy.print("HOLE: ");
    arduboy.setCursor(38, 21);
    arduboy.print(tabel3[1][0]);

    arduboy.drawBitmap(tabel[0][i], tabel[1][j], cusor, 9, 12, WHITE);

  for (uint8_t n = 0; n <= 17; n++){
    arduboy.setCursor(num[0][n], num[1][n]);
    arduboy.print(score[r][n]);
    }
 
  arduboy.drawLine(0, 17, 50, 17, WHITE);
  arduboy.drawLine(0, 32, 128, 32, WHITE);
  arduboy.drawLine(0, 47, 128, 47, WHITE);
  arduboy.drawLine(0, 63, 128, 63, WHITE);

  arduboy.drawLine(10, 32, 10, 64, WHITE);
  arduboy.drawLine(22, 32, 22, 64, WHITE);
  arduboy.drawLine(34, 32, 34, 64, WHITE);
  arduboy.drawLine(46, 32, 46, 64, WHITE);
  arduboy.drawLine(58, 32, 58, 64, WHITE);
  arduboy.drawLine(70, 32, 70, 64, WHITE);
  arduboy.drawLine(82, 32, 82, 64, WHITE);
  arduboy.drawLine(94, 32, 94, 47, WHITE);
  arduboy.drawLine(106, 32, 106, 47, WHITE);
  arduboy.drawLine(118, 32, 118, 47, WHITE);


  tot[r] = (score[r][0] + score[r][1] + score[r][2] + score[r][3] + score[r][4] + score[r][5] + score[r][6]
             + score[r][7] + score[r][8] + score[r][9] + score[r][10] + score[r][11] + score[r][12]
              + score[r][13] + score[r][14] + score[r][15] + score[r][16] + score[r][17]);
  
    arduboy.setCursor(85,53);
    arduboy.print("TOT: ");
    arduboy.setCursor(110,53);
    arduboy.print(tot[r]);
    arduboy.display();

  if(arduboy.justPressed(LEFT_BUTTON)) {
      if(i > 0) {
        i -= 1;
      }
      if(j > 0){
        j -= 1;
      }
      if(tabel3[1][0] > 1){
        tabel3[1][0]--;
        }
      else{
        i = 17;
        j = 17;
        tabel3[1][0] = 18;       
      }
    }

    if(arduboy.justPressed(RIGHT_BUTTON)) {
      if(i < 17){
        i += 1;
      }
      if(j < 17){
        j += 1;
        }
      if(tabel3[1][0] < 18){
        tabel3[1][0]++;
        }  
      else{
        i = 0;
        j = 0;
        tabel3[1][0] = 1;
        }
    }

    if(arduboy.justPressed(UP_BUTTON)) {
      if(score[r][i] >= 7){
        score[r][i] = 0;
        }
        score[r][i]++;
        }
    
    if(arduboy.justPressed(DOWN_BUTTON)) {
      if(score[r][i] <= 1){
        score[r][i] = 8;
        }
        score[r][i]--;
        }
  
   if(arduboy.justPressed(A_BUTTON)) {
      if(r <= s){
        r++;
        }
        else{
          r = 0;
          }
      }
}

void win(){
  arduboy.clear();
  arduboy.drawBitmap(0, 0, Winner, 128, 64, WHITE);

  arduboy.setCursor(50, 5);
  arduboy.print(player[0]);arduboy.print("  ");arduboy.print(tot[0]);
  arduboy.setCursor(50, 15);
  arduboy.print(player[1]);arduboy.print("  ");arduboy.print(tot[1]);
  arduboy.setCursor(50, 25);
  arduboy.print(player[2]);arduboy.print("  ");arduboy.print(tot[2]);
  arduboy.setCursor(50, 35);
  arduboy.print(player[3]);arduboy.print("  ");arduboy.print(tot[3]);
  arduboy.setCursor(50, 45);
  arduboy.print(player[4]);arduboy.print("  ");arduboy.print(tot[4]);
  arduboy.setCursor(50, 55);
  arduboy.print(player[5]);arduboy.print("  ");arduboy.print(tot[5]);
  arduboy.display();
}

void man(){
  if (arduboy.everyXFrames(7)) {
    man2SpriteNum++;
    }
  if (man2SpriteNum > 16) {
    man2SpriteNum = 0;
    tim = 0; 
    }
}

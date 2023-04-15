
#include <stdint.h>              // funciones 
#include <ili9341_8_bits_fast.h> // pantalla tft
#include "bitmaps.h"             // archivo de bitmaps 


int x = 0; // movimiento horizontal 

void setup()
{
  //usamos los PUSH de la tiva para el movimiento con pullup interno
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);

  //configuracion de la comunicacion serial 
  Serial.begin(9600);
  Serial.println("Iniciando pantalla...");

  //inicia la pantalla
  lcdInit(); //inicializacion de la lcd 
  lcdClear(BLACK); //color del fondo 
  
  //título 
  LCD_Print("L7-IE305410", 70, 50, 2, WHITE, BLACK); //lab7-electrónica digital 2
  LCD_Print("LAUNCH", 110, 20, 2, WHITE, BLACK); 
    
  //estrellas de manera aleatoria en toda la pantalla
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
  FillRect(random(0,320), random(0,240), 2, 2, WHITE);
}


void loop()
{
//mover hacia la derecha 

  delay(5); 
  while ((digitalRead(PUSH1) == LOW) && (x < 320 - 23))
  { //revisamos si se presiona o no  
    delay(5); 
    int ast_index = (x/5)%6; // velocidad
    LCD_Sprite(x++, 148, 30, 26, ast_run, 1, ast_index, 1, 0); // imagen
    V_line( x - 1, 148, 30, BLACK); //sin rastro
    }
 
//mover hacia la izquierda
  delay(5);
  while ((digitalRead(PUSH2) == LOW) && (x > 0))
  { //revisamos si se presiona o no  
    delay(5); 
    int ast_index = (x/5)%6; // velocidad
    LCD_Sprite(x--, 148, 30, 26, ast_run, 1, ast_index, 0, 0); // imagen
    V_line( x + 23, 148, 30, BLACK); //sin rastro
    }
 }

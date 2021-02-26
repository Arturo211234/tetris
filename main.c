#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "blocks.h"


int main(){
 int16_t field[FIELD_WIDTH][FIELD_HEIGHT];
 int16_t test[] = {0, 0, 0, 0, 0, 0, 0, 0};
 int16_t current_vector[] = {1, 1};
 
 for(uint16_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i++){
  test[i] = t_block[i]; 
 }

 puts("\n\nField Test:\n");
 
 for(uint16_t i = 0; i < FIELD_WIDTH; i++){
  for(uint16_t j = 0; j < FIELD_HEIGHT; j++){
   field[i][j] = 0;
  }
 }

 for(uint16_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i += DIMENSIONS){
  field[current_vector[0] + test[i]][current_vector[1] + test[i+1]] = 1;
 }


 puts("Field Before:\n");
 for(uint16_t i = 0; i < FIELD_WIDTH; i++){
  putchar('[');
  for(uint16_t j = 0; j < FIELD_HEIGHT; j++){
   printf("%d, ", field[i][j]);
  }
  puts("]");
 }

 for(uint16_t i = 0; i < FIELD_WIDTH; i++){
  for(uint16_t j = 0; j < FIELD_HEIGHT; j++){
   field[i][j] = 0;
  }
 }

 move(current_vector, test, field, 2, 0);
 for(uint16_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i += DIMENSIONS){
  field[current_vector[0] + test[i]][current_vector[1] + test[i+1]] = 1;
 } 
 puts("Field After:\n");

 for(uint16_t i = 0; i < FIELD_WIDTH; i++){
  putchar('[');
  for(uint16_t j = 0; j < FIELD_HEIGHT; j++){
   printf("%d, ", field[i][j]);
  }
  puts("]");
 }


}


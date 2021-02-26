int16_t t_block[]       = {-1, 0, 0, 0, 0, 1, 1, 0};

int16_t left_l_block[]  = {-1, 1, -1, 0, 0, 0, 1, 0};

int16_t right_l_block[] = {1, 1, -1, 0, 0, 0, 1, 0};

int16_t square_block[]  = {0, 0, 0, 1, 1, 0, 1, 1};

int16_t long_block[]    = {-2, 0, -1, 0, 0, 0, 1, 0};

int16_t right_z_block[] = {-1, -1, 0, -1, 0, 0, 1, 0};

int16_t left_z_block[]  = {-1, 0, 0, 0, 0, -1, 1, -1};

#define BLOCK_SIZE    4
#define DIMENSIONS    2
#define FIELD_WIDTH   10
#define FIELD_HEIGHT  40



void rotate(int16_t *current){
 int16_t rotated_array[BLOCK_SIZE * DIMENSIONS];
 for(uint8_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i+= DIMENSIONS){
  rotated_array[i] = current[i+1] * -1;
  rotated_array[i+1] = current[i];
 }
 for(uint8_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i+= DIMENSIONS){
  current[i] = rotated_array[i];
  current[i+1] = rotated_array[i+1];
 }
}

void move(int16_t *current_vector, int16_t *block, int16_t field[FIELD_WIDTH][FIELD_HEIGHT], uint8_t x_axis, uint8_t y_axis){
 /* 0 = no movement, 1 = left on the x_axis or down on the y_axis depending on which one isn't 0, 2 = right on the x_axis*/
 if(x_axis == 1){
  for(uint16_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i += DIMENSIONS){
   if((current_vector[0] + block[i] - 1) < 0){
    return;
   }
  }
  
  for(uint16_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i += DIMENSIONS){
   if((field[current_vector[0] + block[i] - 1][current_vector[1] + block[i+1]]) != 0){
    return;
   }
  }
 
 current_vector[0] = current_vector[0] - 1;
 
 }

 if(x_axis == 2){
  for(uint16_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i += DIMENSIONS){
   if((current_vector[0] + block[i] + 1) > FIELD_WIDTH){
    return;
   }
  }
  
  for(uint16_t i = 0; i < (BLOCK_SIZE * DIMENSIONS); i += DIMENSIONS){
   if((field[current_vector[0] + block[i] + 1][current_vector[1] + block[i+1]]) != 0){
    return;
   }
  }
 
 current_vector[0] = current_vector[0] + 1;
 
 }

 if(y_axis == 1){
  current_vector[1] = current_vector[1] - 1;
 }

}


#ifndef LOADCELL_H_
#define LOADCELL_H_

const int LOADCELL1_DOUT_PIN = 33;//26 //5Kg
const int LOADCELL1_SCK_PIN = 32;//27


void LoadCell1_ini (void);
float LoadCell1_data(void);

#endif

#ifndef WEIGHT_H
#define WEIGHT_H

#include "HX711.h"


/// Số lượng cảm biến khối lượng
#define LOADCELL_NUM 4

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN[LOADCELL_NUM] = {0,1,2,3};
const int LOADCELL_SCK_PIN = 4;

/// Các giá trị thu được từ hx711, dạng thô
extern long loadcell_values[LOADCELL_NUM];

void setup_hx711();

void loop_hx711();

#endif
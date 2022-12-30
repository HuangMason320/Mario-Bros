#include "global.h"

// variables for global usage
const float FPS = 30.0;
const int WIDTH = 4000;
const int HEIGHT = 1000;
int window=1;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_next_window = false;

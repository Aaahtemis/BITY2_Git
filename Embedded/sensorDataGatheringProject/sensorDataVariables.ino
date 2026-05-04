
#define IR_ADDRESS 0x00

#define IR_UP    0x18
#define IR_DOWN  0x52
#define IR_RIGHT 0x5A
#define IR_LEFT  0x08
#define IR_OK    0x1C

#define IR_1    0x45
#define IR_2    0x46
#define IR_3    0x47
#define IR_4    0x44
#define IR_5    0x40
#define IR_6    0x43
#define IR_7    0x07
#define IR_8    0x15
#define IR_9    0x09
#define IR_0    0x19

#define IR_STAR 0x16
#define IR_HASH 0x0D
/*
 * SECOND:
 * IR button to command mapping for better reading. IR buttons should only referenced here.
 */
#define COMMAND_ON              IR_UP
#define COMMAND_OFF             IR_DOWN
#define COMMAND_INCREASE_BLINK  IR_RIGHT
#define COMMAND_DECREASE_BLINK  IR_LEFT

#define COMMAND_START           IR_OK
#define COMMAND_STOP            IR_HASH
#define COMMAND_RESET           IR_STAR
#define COMMAND_BLINK           IR_0
#define COMMAND_TONE1           IR_1

#define COMMAND_TONE2           IR_2
#define COMMAND_TONE3           IR_3
//#define            IR_4
//#define            IR_5
//#define            IR_6
//#define            IR_7
//#define            IR_8
//#define            IR_9

#define SYM_DEBUG 0

#define TABLE_SIZE 211
#define MAX_ID_LENGTH 6


#ifndef V_TYPE
#define V_TYPE
typedef union {
   int ivalue;
   char cvalue;
   double dvalue;
} VALUE;
#endif

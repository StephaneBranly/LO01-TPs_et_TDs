#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


#define MAXC 40
#define MAXSIZE 4096


typedef struct
{
    float a,b,l,s,e;
} param;


typedef struct
{
    char comment[MAXC];
    int nbpts;
    float *time;
    float *value;
} trace;

void askName(char*);
int askValue();
void askSlot(trace**, trace*);

int simuTrace(float, float, param*, trace*);
int printTrace(trace*);
void expeTrace(trace*);
float errorTrace(trace*, trace*);

int saveTraceBin(char*, trace*);
int readTraceBin(char*, trace*);

int saveTraceTxt(char*, trace*);
int readTraceTxt(char*, trace*);

#endif // FONCTIONS_H_INCLUDED

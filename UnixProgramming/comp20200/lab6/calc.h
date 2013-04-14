#define MAXVAL 100

extern int sp;
extern double val[MAXVAL];

extern int getch(void);
extern void ungetch(int);
/* getop*/
extern int getop(char s[]);
/*push*/
extern void push(double f);
/*pop*/
extern double pop(void);

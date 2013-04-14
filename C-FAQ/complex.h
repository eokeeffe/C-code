/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 14.11)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

typedef struct {
	double real;
	double imag;
	} complex;

extern complex cpx_make(double, double);
extern complex cpx_add(complex, complex);
extern complex cpx_subtract(complex, complex);
extern complex cpx_multiply(complex, complex);

extern char *cpx_print(char *, complex);


#define Real(c) (c).real
#define Imag(c) (c).imag

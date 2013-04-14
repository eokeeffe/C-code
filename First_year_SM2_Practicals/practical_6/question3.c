/*Evan O'Keeffe
  10324289
  practical6 question3
*/
int i, j = 25;
int *pi , *pj = &j;
.....
*pj = j + 5;
i= *pj + 5;
pi = pj ;
*pi = i + j;
Suppose each integer quantity occupies 2 bytes of memory.
If the value assigned to i begins at(hexadecimal) address F9C and the value assigned to j begins at address F9E,then

(a)Whatvalue is represented by &i?
59C
(b)What value is represented by &j?
F9E
(c)What value is assigned to pj?
F9E
(d)What value is assigned to *pj?
65
(e)What value is assigned to i?
35
(f)What value is represented by pi?
F9E
(g)What final value is assigned to*pi?
65
(h)What value is represented by(pi+2)?
FA0=F9E+2
(i)What value is represented by the expression(*pi+2)? 
65+2
(j) What value is represented by the expression*(pi+2)?
unspecified
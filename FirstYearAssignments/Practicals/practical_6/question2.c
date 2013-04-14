/*Evan O'Keeffe
  10324289
  practical6 question2
*/
char u, v = ' A ' ;
char *pu, *pv = &v;
......
*pv = v + 1;
u = *pv + 1;
pu = &u;
Suppose each character occupies
1 byte of memory. If the value assigned to u is stored in (hexadecimal) address F8C and the value assigned to v is stored in address
F8D,then 

(a)What value is represented by &v?
F8D

(b) What value is assigned to pv?
F8C

(c)What value is represented by *pv?
A+1

(d)What value is assigned to u?
(A+1)+1

(e) What value is represented by &u?
F8C

(f)What value is assigned to pu?
F8C

(g)What value is represented by *pu?
(A+1)+1
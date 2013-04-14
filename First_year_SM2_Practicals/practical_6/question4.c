/*Evan O'Keeffe
  10324289
  practical6 question4
*/
float a = 0.001, b = 0,003;
float c, *pa, *pb;
pa = &a;
*pa = 2 * a;
pb = &b;
c = 3 * (*pb - *pa);
Suppose each floating-­-point number occupies 4 bytes of memory. If value assigned to a begins at (hexadecimal) address 1130, the value assigned
to b begins at address 1134, the value assigned c begins at 1138,then 

(a)What value is assigned to &a?
1130
(b)What value is assigned to&b?
1134
(c)What value is assigned to &c?
1138
(d) What value is assigned to pa?
1130
(e)What value is represented by *pa?
0.001
(f)What value is represented by&(*pa)?
1130
(g) What value is assigned to pb? 
1134
(h) What value is represented by *pb?
0,003
(i)What value is assigned to c?
-0.003
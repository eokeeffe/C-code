#ifndef A_H__
#define A_H__

struct STRUCT_DLL 
{
   int  count_int;
   int* ints;
   char ME;
};

int myFunc
(
    int                an_int,
    char*              string_filled_in_dll,
    struct STRUCT_DLL* struct_dll
);

#endif
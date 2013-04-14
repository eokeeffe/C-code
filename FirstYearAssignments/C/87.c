/*Evan O'Keeffe
  10324289
  This program is one where i started to look at WINAPI's
  All im doing here is creating a box with the message in*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
LPSTR lpCmdLine, int nCmdShow)
{
MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK);
return 0;
}
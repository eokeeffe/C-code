#!/usr/bin/perl
#########################################
#Evan O'Keeffe
#10324289
#
#Setup Script for the program
#follows the steps from the assignement
#########################################

system("gcc -c convert.c io.c");
system("ar -rcs libconvert.a convert.o io.o");
system("gcc -o convert_x_y main_x_y.c -L. -lconvert");
system("gcc -o convert_y_x main_y_x.c -L. -lconvert");

#!/usr/bin/perl -w
###############################
# Evan O'Keeffe 10324289
# This is my program indexer
# it gets the program name 
# and also shows the comments I left
# to explain what they do
###############################
print "please enter the name of your Index\n";
$name=<STDIN>;

print "Please enter the file extension in .file format\n";
$prefix=<STDIN>;

open (FH,">$name");
@files = <*$prefix>;#search only files with this prefix
undef($evanwrotethisprogram="");
foreach $evanwrotethisprogram (@files) 
{  
   $/="*/";
   print FH $evanwrotethisprogram . "\n";
   open FH1,"<$evanwrotethisprogram";
   do{print FH <FH1>."\n\n";}until{$/}
} 
close FH;
close FH1;

print "Thank you , your file has now been written\n";
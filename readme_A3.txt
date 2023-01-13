Name: Nabeel Abu-Mahfouz
Student ID: 1104136
ASSIGNMENT #: 4

================================================================================

Brief Description:

- This program takes as input a fully parenthesized, arithmetic expression of binary operators(+,-,*,/), and converts the expression into a binary expression tree.
- This input is taken in at the command line as a character string without any spaces in it.

================================================================================

Example of command line arguement(s) using example string in A3:

1. make
2. ./A3 "(((x1+5.12)∗(x2−7.68))/x3)"

================================================================================

Sample output based on command line arguements above:

root@DESKTOP-4MO0DJ7:~/cis2520/A3# ./A3 "(((x1+5.12)*(x2-7.68))/x3)"
Please Select a Menu Option:

1.Preorder

2.Postorder

3. Exit

1




PREORDER: / * + x1 5.12 - x2 7.68 x3 



Please Select a Menu Option:

1.Preorder

2.Postorder

3. Exit

2




POSTORDER: x1 5.12 + x2 7.68 - * x3 / 



Please Select a Menu Option:

1.Preorder

2.Postorder

3. Exit

3


Goodbye :)!

root@DESKTOP-4MO0DJ7:~/cis2520/A3# 


================================================================================

NOTE!!!:
IF YOU COPY PASTE A LINE INTO THE COMMAND LINE, IT MAY MESS UP FORMATTING OF ALPHA NUMERIC CHARACTERS (pay attention to *):

Input with copy pasting from a notepad:

root@DESKTOP-4MO0DJ7:~/cis2520/A3# ./A3 "(((x1+5.12)∗(x2−7.68))/x3)"
Segmentation fault



Input WITHOUT copy pasting from a notepad:

root@DESKTOP-4MO0DJ7:~/cis2520/A3# ./A3 "(((x1+5.12)*(x2-7.68))/x3)"
Please Select a Menu Option:

1.Preorder

2.Postorder

3. Exit

================================================================================

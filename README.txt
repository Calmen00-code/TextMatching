This is a program that will replace any matching pattern substring in a string.

How to run the program: 

./text "The String" <substring> <replace string> <color 1> <color2>

./textIndex "The String" <substring> <replace string> <color 1> <color2> 
(This will show index of current character below)

substring: String exists in the whole string that will need to be replaced
replace string: String that will replace substring
color 1: color that will highlight the substring
color 2: color that will highlight the replace string

-------------------------------------------------------------------------------------------------------

To get an idea of how the program works, run the examples below and refer to the output

EXAMPLES 1:
./text "This tea is good!" tea biscuit red green

EXAMPLES 2:
./text "Alex is Alex" Alex Benjamin red green

EXAMPLES 3:
./text "he is helicopter" he she red green

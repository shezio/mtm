#!/bin/bash
for i in {1..3};do 
	if [[ $i == 1 ]]
	then
		./my_string<all_funcs > my_string_output
		echo -e "\nEnd of file all_funcs" >> my_string_output
	else
		./my_string<all_func$i >> my_string_output
		echo -e "\nEnd of file all_func"$i >> my_string_output
	fi
	echo -e "\\n" >> my_string_output
done

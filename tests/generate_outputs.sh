#!/bin/bash


#param1 run arguments
#param2 suffix
generate_outputs() {
    test_data=$(ls test_data)
    for file in $test_data ; do
	tail $1 test_data/$file > posix_tail_out/$file$2
	../tail $1 test_data/$file > my_tail_out/$file$2
    done
}


generate_outputs "-n 5" "_n_5"
generate_outputs "" ""
generate_outputs "-n +3" "_n_+3"
generate_outputs "-n +9" "_n_+9"

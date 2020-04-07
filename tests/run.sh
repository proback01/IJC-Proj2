#!/bin/bash

./generate_outputs.sh

diff -q my_tail_out/ posix_tail_out/

if [ $? = 0 ] ; then
    echo "Success!"
fi

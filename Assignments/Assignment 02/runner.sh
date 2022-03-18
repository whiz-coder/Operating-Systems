#!/bin/bash
x=1

while [ $x -le 50 ]
do
        (time ./hello2 > /dev/null)  &>> hello2.txt
        (time ./hello  > /dev/null)  &>> hello.txt
  x=$(( $x + 1 ))

done

avg_time() {
    #
    # usage: avg_time n command ...
    #
    n=$1; shift
    (($# > 0)) || return                   #  if no command given
    for ((i = 0; i < n; i++)); do
        { time -p "$@" &>/dev/null; } 2>&1 # ignore the output of the command
                                           # collect time's output in stdout
    done | awk '
        /user/ { user = user + $2; nu++ }

        END    {
                 if (nu>0) printf("user %f\n", user/nu);
               }'
}

echo -e "Average Time Of hello"
avg_time 50 ./hello

echo -e "Average Time Of hello2"
avg_time 50 ./hello2

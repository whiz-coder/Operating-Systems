#!/bin/bash

avg_time() {
    #
    # usage: avg_time n command ...
    #
    n=$1; shift
    (($# > 0)) || return                   # bail if no command given
    for ((i = 0; i < n; i++)); do
        { time -p "$@" &>/dev/null; } 2>&1 # ignore the output of the command
                                           # but collect time's output in stdout
    done | awk '
        /user/ { user = user + $2; nu++ }

        END    {
                 if (nu>0) printf("user %f\n", user/nu);
               }'
}

echo -e "Threads Average Running Time "
avg_time 50 ./thread-handler

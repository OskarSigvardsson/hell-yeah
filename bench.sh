#!/usr/bin/env bash

function bench {
	timelimit -q -t5 -T5 "$2" | pv -c -F "%a <= $1" > /dev/null
}

bench "GNU yes                          " yes
bench "Using printf                     " ./build/hell-yeah-printf
bench "Using fwrite                     " ./build/hell-yeah-fwrite
bench "Using write syscall, non-buffered" ./build/hell-yeah-non-buffer
bench "Using write syscall, buffered    " ./build/hell-yeah-buffer

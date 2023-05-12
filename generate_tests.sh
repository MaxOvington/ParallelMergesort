#!/bin/bash
RANDOM=$$

# for size in 10000 20000 50000 100000 200000 500000 1000000 2000000 5000000 10000000 20000000 50000000
#     do echo $size >> Tests/$size-numbers.txt; 
#     for (( i = 0; i < $size; i++ )) 
#         do echo $RANDOM >> Tests/$size-numbers.txt; 
#     done;
# done;

for FILE in Tests/*.txt; do
    echo Running Non-Parallel Mergesort for test: $FILE
    time ./NonParallel/main < $FILE
    echo Running Parallel Mergesort for test: $FILE
    time ./Parallel/main < $FILE
done
#!/bin/sh

if  [ $# -ne 2 ]; then
    echo "Error: Two arguemnts required!"
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]; then
    echo "Error: Path $filesdir is not a directory."
    exit 1
fi

file_count=$(find "$filesdir" -type f | wc -l)

matching_lines_count=$(find "$filesdir" -type f -exec grep -c "$searchstr" {} + | awk -F: '{sum += $2} END {print sum}')

echo "The number of files are $file_count and the number of matching lines are $matching_lines_count"

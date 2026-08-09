sed -E  's/ +/\n/g' words.txt | sed -E '/^ *$/d' | sort | uniq -c | sort -nr |awk '{print $2 " " $1}'

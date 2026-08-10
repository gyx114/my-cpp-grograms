col=`awk 'END{print NF}' file.txt`
for((i=1;i<=$col;i++));do
    awk "NR!=1{printf \" \"} {printf \$$i} END {printf\"\\n\"}" file.txt;
done

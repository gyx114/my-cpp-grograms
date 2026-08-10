# awk 'NR==10{print $0}' file.txt

# grep -n "" file.txt | sed -E -n 's/^10://p'

# 获取文件总行数
# cat file.txt | wc -l

# line=`cat file.txt | wc -l`
# if (($line >= 10)); then
#     head -n 10 file.txt | tail -n 1
# fi

sed -n '10p' file.txt

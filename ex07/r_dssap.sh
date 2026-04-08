cat /etc/passwd | awk -F : '{print $1}'| sed -n 'n;p' | rev | sort -r | paste -sd ", " | sed 's/$/./' | sed -n "${FT_LINE1},${FT_LINE2}p"

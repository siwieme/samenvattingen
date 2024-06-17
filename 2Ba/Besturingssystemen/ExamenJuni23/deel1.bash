find /media/wieme -type f -name "pass*" -size +100c -exec ls -lh {} \; > output 2>&1
a="You only live twice, once when you are born and once when you look death in the face"
wc -w <<< a
echo "
SEARCH
"
for ((i=0;i<14;i++)) {
echo "ADD
$i
$i$i
$i$i$i$i$i$i
$(($i*424242))
secret!
SEARCH
$i
"
}
echo "SEARCH
1
hoge
EXIT"

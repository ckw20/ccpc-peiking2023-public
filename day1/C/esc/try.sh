for((i=86;i<=100;++i)) do
    try=1
    while [[ ! -s log.txt ]]; do
        echo i=$i,try=$try
        ./gen $i 0 4 > $i.in
        ./std < $i.in > $i.ans
        ./col < $i.in > $i.out
        diff $i.out $i.ans > log.txt
        try=$((try+1))
    done
    rm log.txt
done
g++ -std=c++11 main.cpp -o main.out
echo "Algorithm,Size,Cycle,Time,Memory" >> result.csv
for len in 1000000 2000000 4000000 6000000 8000000 10000000 20000000 30000000 40000000 50000000
do
    for i in {0..10}
    do
        let cycle=$len/10*$i
        for j in {1..20}
        do
            gtime -f"RUNNING,$len,$cycle,%e,%M" ./main.out 0 $len $cycle 2>> result.csv
            gtime -f"REVERSE,$len,$cycle,%e,%M" ./main.out 1 $len $cycle 2>> result.csv
            gtime -f"POINTSELF,$len,$cycle,%e,%M" ./main.out 2 $len $cycle 2>> result.csv
        done
    done
done
#For making an array of ints
from random import randint

n = 1500

with open("arrayOfInts.h", mode="w", encoding="utf-8") as f:
    f.write(f"int intArray[{n}] = {{")
    for i in range(n):   
        if i%(n/20)==0:
            f.write("\n")
        if i == n-1:
            f.write(f"{randint(1,1000000)}")
        elif i==0:
            f.write(f"50000,")
        else:
            f.write(f"{randint(1,1000000)},")
    f.write("\n};")
            
            
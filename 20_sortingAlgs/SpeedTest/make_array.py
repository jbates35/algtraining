import random

if __name__ =="__main__":
    rand_list = [random.randint(1, 1_000_000) for _ in range(500000)]
    with open('generatedarray.h', 'w') as f:
        f.write('int genArr[] = {')
        for i in range(len(rand_list)):
            f.write(f'{rand_list[i]:d}')
            if i != len(rand_list) - 1:
                f.write(',') 
        f.write('};')

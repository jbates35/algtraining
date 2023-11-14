# Extracurricular - Speed Test
## Speed tests with each algorithm from this chapter on an array of 50,000 entries 
### Description:
Per my curiosity, I wanted to see how fast each algorithm is. I designed a speed test which I could use to test each algorithm.

I noticed the radix was quite a bit slower than I expected, so I created an alternate method for sorting through the array. Instead of using linked lists, I made an array that stored the values that I resized after a while. It cut down the sorting time drastically.

```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/SpeedTest
```
### Example:
Just run the command once built.
```bash
$ ./SpeedTest
```
This should give you:
```
Bubble Sort: 3756979.000000 us
Is sorted? Yes
Insertion Sort: 534768.000000 us
Is sorted? Yes
Selection Sort: 606474.000000 us
Is sorted? Yes
Quick Sort: 3799.000000 us
Is sorted? Yes
Merge Sort I: 4343.000000 us
Is sorted? No
Merge Sort R: 4597.000000 us
Is sorted? Yes
Count Sort: 2324.000000 us
Is sorted? Yes
Radix Sort: 5425.000000 us
Is sorted? Yes
Radix Sort Alt: 945.000000 us
Is sorted? Yes
Shell Sort: 6923.000000 us
Is sorted? Yes

```

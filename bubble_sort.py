## filename: bubble_sort.py
import random
rng = 20 # default value
rng = int(input("Please input a value of range: "))
lst = [random.randrange(0, rng) for idx in range(rng)]

# bubble sort
times = rng
copy_lst = lst[:]
for i in range(times):
    for seq in range(rng - 1):
        if lst[seq] > lst[seq + 1]:
            tmp = lst[seq]
            lst[seq] = lst[seq + 1]
            lst[seq + 1] = tmp
    rng-=1

# print the original-list and sorted-list
print("=" * 40)
print("The original-list:\n", copy_lst)
print("The sorted-list:\n", lst)
copy_lst.sort()
print("Compare with result sorted by list.sort():\n", copy_lst)
print("Is the sort-algorithm right?\n", copy_lst == lst)
print("--> THIS IS BUBBLE SORT! <--")
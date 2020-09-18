## filename: shell_sort.py
import random
rng = 20 # default value
rng = int(input("Please input a value of range: "))
lst = [random.randrange(0, rng) for idx in range(rng)]

# shell sort
copy_lst = lst[:]
gap = rng // 2
while gap >= 1:
    for i in range(gap):
        for idx in range(i+gap, rng, gap):
            for seq in range(i, idx, gap):
                if lst[idx] <= lst[seq]:
                    tmp = lst[idx]
                    lst[seq+gap:idx+gap:gap] = lst[seq:idx:gap]
                    lst[seq] = tmp
                    break
    gap //= 2
                
# print the original-list and sorted-list
print("=" * 40)
print("The original-list:\n", copy_lst)
print("The sorted-list:\n", lst)
copy_lst.sort()
print("Compare with result sorted by list.sort():\n", copy_lst)
print("Is the sort-algorithm right?\n", lst == copy_lst)
print("--> THIS IS SHELL SORT! <--")                        
## filename: selection_sort.py
import random
rng = 20 # default value
rng = int(input("Please input a value of range: "))
lst = [random.randrange(0, rng) for idx in range(rng)]

# selection sort
sort_lst = []
copy_lst = lst[:]
for i in range(rng):
    sort_lst.append(lst[0])
    for seq in range(len(lst)):
        if lst[seq] < sort_lst[i]:
            sort_lst[i] = lst[seq]
    else:
        lst.pop(lst.index(sort_lst[i]))
        
# print the original-list and sorted-list
print("=" * 40)
print("The original-list:\n", copy_lst)
print("The sorted-list:\n", sort_lst)
copy_lst.sort()
print("Compare with result sorted by list.sort():\n", copy_lst)
print("Is the sort-algorithm right?\n", copy_lst == sort_lst)
print("--> THIS IS SELECTION SORT! <--")
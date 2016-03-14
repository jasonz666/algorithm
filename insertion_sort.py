# filename: insertion_sort.py
import random
rng = 20 # default value
rng = int(input("Please input a value of range: "))
lst = [random.randrange(0, rng) for idx in range(rng)]

# insertion sort
sort_lst = lst[:1]
for idx in range(1, rng):
    for i in range(idx):
        if lst[idx] <= sort_lst[i]:
            sort_lst.insert(i, lst[idx])
            break
    else:
        sort_lst.append(lst[idx])

# print the original-list and sorted-list
print("=" * 40)
print("The original-list:\n", lst)
print("The sorted-list:\n", sort_lst)
lst.sort()
print("Compare with result sorted by list.sort():\n", lst)
print("Is the sort-algorithm right?\n", lst == sort_lst)
print("--> THIS IS INSERTION SORT! <--")
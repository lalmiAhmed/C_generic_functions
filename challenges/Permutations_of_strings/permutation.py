the_list = ['A', 'B', 'C']


def is_sorted(my_list):
    sorted_ref = sorted(my_list)
    for i, el in enumerate(sorted_ref):
        if el != my_list[i]:
            return False
    return True

# get the sorted list 
sort_list = sorted(the_list)

# find the current cursor:
cursor = the_list[0]
rest_list = the_list[the_list.index(cursor)+1:]
# check if the rest is sorted
if is_sorted(rest_list):
    rest_list.reverse()



print(list(cursor)+rest_list)
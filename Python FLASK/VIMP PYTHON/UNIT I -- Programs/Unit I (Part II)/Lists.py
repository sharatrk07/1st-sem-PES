# # Create a list with 3 elements and print it
# l = [1, 2, 3]
# print(l)

# # Check the length
# n = len(l)
# print('Length of the list: '+str(n))

# # Print elements individually
# print(l[0])
# print(l[1])
# print(l[2])
# # print(l[3]) # Error: List index is out of range

# # Modification of list items
# l[0] = 100
# l[1] = 200
# l[2] = 300
# print(l)

# l1 = list()
# print(type(l1))

# # l[3] = 100 # Error: List index out of range

# # append(): Add an element at the end of the list
# l.append(100)
# print(l)
# print(len(l))

# # Heterogeneous
# l.append('Hello')
# print(l)

# l.append([10, 20])
# print(l)

# # Delete elements
# # pop(): The last item in the list
# removed_element = l.pop()
# print(l)
# print(removed_element)

# removed_element = l.pop(3) # pop(Position_value)
# print(l)
# print(removed_element)

# # Insert
# l.insert(2, 1000) # insert(position, value)
# print(l)

# l.insert(0, 0)
# print(l)

# l1 = [1, 1, 2, 2, 3]
# print(l1)
# # Check the number of times element 1 is repeated in the list l1
# # count(element): int
# print('Element 1 has repeated: '+str(l1.count(1))+' times')

# l3 = [1, 2, 3, 4, 5]
# print('Index of 5 in l3: '+str(l3.index(5)))

# # Remove element 3 from l3
# l3.pop(l3.index(3))


# for i in l3:
# 	print('Element: '+str(i))


# l = [1, 2, 3, 4, 5]
# l2 = []
# for i in l:
# 	# v = i * i
# 	l2.append(i * i)
# print(l)
# print(l2)

n = int(input('Enter the number of elements: '))
l = []
l2 = []
for i in range(0, n):
	ele = int(input('Element: '))
	l.append(ele)
	l2.append(ele**2)
print(l)
# l2 = []
# for i in l:
# 	l2.append(i**2)
print(l2)














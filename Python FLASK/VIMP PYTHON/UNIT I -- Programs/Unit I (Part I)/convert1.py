# Convert from any base to base 10

b, n, d= int(input("Enter base: ")), input("Enter number: "), 0
# n1 = str(n)
for i in n:
	if(int(n)<0 or int(i)>=b):
		print("Invalid input")
		exit()
for i in range(len(n)-1, -1, -1):
	# print(n[i])
	d += int(n[len(n)-i-1]) * (b ** i)
print(d)
	
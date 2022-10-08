import math as mt

# Function Ternary Search
def ternarySearch(l, r, key, ar):

	if (r >= l):

		mid1 = l + (r - l) //3
		mid2 = r - (r - l) //3

		if (ar[mid1] == key):
			return mid1
		
		if (ar[mid2] == key):
			return mid2
		
		if (key < ar[mid1]):

			return ternarySearch(l, mid1 - 1, key, ar)
		
		elif (key > ar[mid2]):

			return ternarySearch(mid2 + 1, r, key, ar)
		
		else:

			return ternarySearch(mid1 + 1,
								mid2 - 1, key, ar)
		
	return -1

# Main function
def main():
    arr = []
    n = int(input("Enter the number of elements: "))
    print("Enter the elements: ")
    for i in range(0, n):
        x = int(input())
        arr.append(x)

    x = int(input("Enter the number to search: "))

    # Function call
    result = ternarySearch(0, n-1, x, arr)
    
    if result != -1:
        print("Element is present at index", str(result))
    else:
        print("Element is not present in array")

# Main function execution
if __name__ == "__main__":
    main()

# Binary Search function
def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
 
    while low <= high:
        mid = (high + low) // 2
 
        if arr[mid] < x:
            low = mid + 1
 
        elif arr[mid] > x:
            high = mid - 1
 
        else:
            return mid
 
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
    result = binary_search(arr, x)
    
    if result != -1:
        print("Element is present at index", str(result))
    else:
        print("Element is not present in array")

# Main function execution
if __name__ == "__main__":
    main()

''' 
  Practice Problems
  https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/
'''
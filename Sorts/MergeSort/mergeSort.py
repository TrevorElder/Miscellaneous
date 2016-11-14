##  Author: Trevor Elder
##  Date: 11/13/16



def mergeSort(toSort):
    sortedList = []
    left = []
    right = []
    leftPos = 0
    rightPos = 0



##  Go down the tree
    if len(toSort) > 1:
        left = mergeSort(toSort[:len(toSort)//2])
        right = mergeSort(toSort[len(toSort)//2:])
    else:
        return toSort


##  Go up the tree
    while ( leftPos + rightPos < len(left) + len(right) ):
        ##  I don't like the conditions of this if, will fix later
        if not(len(left) == leftPos) and (rightPos == len(right) or left[leftPos] < right[rightPos]):
            sortedList.append(left[leftPos])
            leftPos += 1
        else:
            sortedList.append(right[rightPos])
            rightPos += 1



    return sortedList;





def sortTest():
    toSortA = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    toSortAKey = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    if toSortAKey != mergeSort(toSortA):
        print("Error...")
        print(toSortAKey)
        print(mergeSort(toSortA))
    else:
        print("worked!!!")

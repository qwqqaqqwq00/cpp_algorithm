def qs(arr:list[int], le: int, ri: int):
    if le > ri: return []
    tmp = arr[le]
    i = le
    j = ri
    while i < j:
        while arr[j] >= tmp and j > i:
            j-=1
        while arr[i] <= tmp and j > i:
            i+=1
        if j > i:
            arr[i], arr[j] = arr[j], arr[i]
    arr[le], arr[i] = arr[i], arr[le]
    nar = qs(arr, le, i-1) + [arr[i]] + qs(arr, i+1,ri)
    return nar

# arr = [2,-1,0,1,3,1,3,5,6,8,9]
arr = [7, 2, 9, 4, 5, 8, 3, 1]
print(qs(arr, 0, len(arr)-1))
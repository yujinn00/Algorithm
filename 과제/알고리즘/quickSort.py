def quickSort(arr):
  if len(arr) <= 1:
    return arr

  pivot = arr[len(arr) // 2]
  left, middle, right = [], [], []

  for i in arr:
    if i < pivot:
      left.append(i)
    elif i == pivot:
      middle.append(i)
    else:
      right.append(i)

  return quickSort(left) + middle + quickSort(right)

with open("inupt_quick_sort.txt", "r") as file:
  arr = []

  for i in file.readlines():
    arr.append(int(i.strip()))

  print(quickSort(arr))
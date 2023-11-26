def downHeap(arr, i, n):
  bigger = i
  leftChild = 2 * i + 1
  rightChild = 2 * i + 2

  if leftChild < n and arr[leftChild] > arr[bigger]:
    bigger = leftChild

  if rightChild < n and arr[rightChild] > arr[bigger]:
    bigger = rightChild

  if bigger != i:
    arr[i], arr[bigger] = arr[bigger], arr[i]
    downHeap(arr, bigger, n)

def heapSort(arr):
  n = len(arr)

  for i in range(n // 2 - 1, -1, -1):
    downHeap(arr, i, n)

  for i in range(n - 1, 0, -1):
    arr[0], arr[i] = arr[i], arr[0]
    downHeap(arr, 0, i)

  return arr

arr = []

with open('input.txt', 'r') as file:
  for line in file:
    arr.append(int(line.strip()))

with open('output.txt', 'w') as file:
  for num in heapSort(arr):
    file.write(f"{num}\n")

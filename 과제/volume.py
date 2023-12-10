import numpy as np
import pandas as pd
import time

def load_data(path):
  data = pd.read_csv(path, header=None).values[1:].T
  return data

def compute_volume(matrix):
  return np.sqrt(np.abs(np.linalg.det(matrix @ matrix.T)))

def find_max_volume(data):
  selected_vectors = []
  selected_indexes = []

  for _ in range(20):
    max_volume = -1
    max_index = -1

    for i in range(data.shape[0]):
      if i not in selected_indexes:
        temp_vectors = selected_vectors.copy()
        temp_vectors.append(data[i])
        volume = compute_volume(np.array(temp_vectors))

        if volume > max_volume:
          max_volume = volume
          max_index = i

    selected_vectors.append(data[max_index])
    selected_indexes.append(max_index)

  return max_volume, selected_indexes

start_time = time.time()
data = load_data("input.csv")
max_volume, selected_indexes = find_max_volume(data)
end_time = time.time()

print("Max volume : ", max_volume)
print("Selected indexes : ", selected_indexes)
print("Running time : ", end_time - start_time, "seconds")
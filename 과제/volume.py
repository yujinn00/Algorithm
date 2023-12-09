import numpy as np
import time
import pandas as pd

# CSV 파일에서 데이터를 불러옵니다.
data = pd.read_csv('input.csv', header=None).values[1:].T

# 볼륨을 계산하는 함수를 정의합니다.
def compute_volume(matrix):
    return np.sqrt(np.abs(np.linalg.det(matrix @ matrix.T)))

# 볼륨이 가장 큰 행렬을 찾는 함수를 정의합니다.
def find_max_volume(data):
    max_volume = 0
    max_index = -1
    for i in range(data.shape[0]):
        volume = compute_volume(data[i:i+20])
        if volume > max_volume:
            max_volume = volume
            max_index = i
    return max_volume, max_index

# 본격적인 계산을 시작합니다.
start_time = time.time()
max_volume, max_index = find_max_volume(data)
end_time = time.time()

# 결과를 출력합니다.
print("Max volume : ", max_volume)
print("Index : ", max_index)
print("Running time : ", end_time - start_time, "seconds")

# Max volume :  33153164156.72865
# Index :  7474
# Running time :  0.11171841621398926 seconds
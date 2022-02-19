import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('/Users/avarlamov/2semester_cpp/CPP_labs/1st_lab/data.csv')

size = df['size']
steps = df['steps']


plt.plot(size, steps)

plt.xlabel('Размера поля')
plt.ylabel('Количество шагов')

plt.show()
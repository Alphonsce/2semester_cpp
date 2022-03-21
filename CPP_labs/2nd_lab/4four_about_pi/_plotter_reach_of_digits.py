import pandas as pd
import numpy as np
# import seaborn as sns
import matplotlib.pyplot as plt

paths_arctan = ['_files_reach_of_digits/dig_arctan0.csv', '_files_reach_of_digits/dig_arctan1.csv',
'_files_reach_of_digits/dig_arctan2.csv.csv', '_files_reach_of_digits/dig_arctan3.csv', '_files_reach_of_digits/dig_arctan4.csv']

paths_other = ['_files_reach_of_digits/dig_euler.csv', '_files_reach_of_digits/dig_gauss.csv', '_files_reach_of_digits/dig_ramanujancsv']

paths = paths_arctan + paths_other

sp = None
plt.figure(figsize=(30, 30))
for path in paths_other:
    # sp = plt.subplot(3, 2, paths.index(path) + 1)
    df = pd.read_csv(path)
    plt.plot(df.iter, df.pi)
    plt.plot(df.iter, np.pi + df.iter * 0, color='red')

    plt.show()
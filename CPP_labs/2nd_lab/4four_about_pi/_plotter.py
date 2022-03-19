import pandas as pd
import numpy as np
# import seaborn as sns
import matplotlib.pyplot as plt

paths_arctan = ['_files/arctan0.csv', '_files/arctan1.csv',
'_files/arctan2.csv', '_files/arctan3.csv', '_files/arctan4.csv']

paths_other = ['_files/euler.csv', '_files/gauss.csv', '_files/ramanujan.csv']

paths = paths_arctan + paths_other

sp = None
plt.figure(figsize=(30, 30))
for path in paths_other:
    # sp = plt.subplot(3, 2, paths.index(path) + 1)
    df = pd.read_csv(path)
    plt.plot(df.iter, df.pi)
    plt.plot(df.iter, np.pi + df.iter * 0, color='red')

    plt.show()
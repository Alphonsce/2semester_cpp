import pandas as pd
import numpy as np
# import seaborn as sns
import matplotlib.pyplot as plt

paths_arctan = ['_files/arctan0.csv', '_files/arctan1.csv',
'_files/arctan2.csv', '_files/arctan3.csv', '_files/arctan4.csv']

paths_other = ['_files/euler.csv', '_files/gauss.csv', '_files/ramanujan.csv', '_files/leibnitz.csv', '_files/viete.csv']

labels_arctan = ['arctan(1)', 'arctan(1/2)+arctan(1/3)', '4arctan(1/5)-arctan(1/239)',
        '6arctan(1/8)+2arctan(1/57)+arctan(1/239)',
        '44arctan(1/59)+7arctan(1/239)-12arctan(1/682)+24arctan(1/12943)'
]

labels_other = ['Euler', 'Gauss', 'Ramanujan', 'Leibnitz', 'Viete']

sp = None
sp = plt.subplot(1, 2, 1)
for path in paths_arctan:
    df = pd.read_csv(path)
    plt.plot(df.iter, df.pi, label=labels_arctan[paths_arctan.index(path)])

plt.title('Раложения $\pi/4$ через разложение арктангенса')
plt.grid(alpha=0.5)
plt.legend(loc='lower center')

sp = plt.subplot(1, 2, 2)
for path in paths_other:
    # sp = plt.subplot(3, 2, paths.index(path) + 1)
    df = pd.read_csv(path)
    plt.plot(df.iter, df.pi, label=labels_other[paths_other.index(path)])

plt.title('Раложения $\pi/4$ другими методами')
plt.grid(alpha=0.5)
plt.legend(loc='lower center')

plt.show()
import pandas as pd
import numpy as np
# import seaborn as sns
import matplotlib.pyplot as plt

paths_arctan = [
    '_files_reach_of_digits/dig_arctan0.csv',
    '_files_reach_of_digits/dig_arctan1.csv',
    '_files_reach_of_digits/dig_arctan2.csv',
    # '_files_reach_of_digits/dig_arctan3.csv',
    # '_files_reach_of_digits/dig_arctan4.csv'
]

paths_other = [
    '_files_reach_of_digits/dig_euler.csv',
    '_files_reach_of_digits/dig_gauss.csv',
    # '_files_reach_of_digits/dig_ramanujancsv',
    '_files_reach_of_digits/dig_leibnitz.csv',
    '_files_reach_of_digits/dig_viete.csv',
]

labels_arctan = [
    'arctan(1)',
    'arctan(1/2)+arctan(1/3)',
    '4arctan(1/5)-arctan(1/239)',
    # '6arctan(1/8)+2arctan(1/57)+arctan(1/239)',
    # '44arctan(1/59)+7arctan(1/239)-12arctan(1/682)+24arctan(1/12943)'
]

labels_other = [
    'Euler',
    'Gauss',
    # 'Ramanujan',
    'Leibnitz', 
    'Viete']

labels = labels_arctan + labels_other
paths = paths_arctan + paths_other

sp = None
for path in paths:
    df = pd.read_csv(path)
    plt.scatter(df.iter, df.digits)

    plt.xlabel('Количество итераций')
    plt.ylabel('Количество знаков после запятой')
    plt.title(labels[paths.index(path)])
    plt.grid(alpha=0.5)
    plt.legend(loc='lower center')
    plt.show()
import pandas as pd
import numpy as np
# import seaborn as sns
import matplotlib.pyplot as plt

paths_arctan = [
    '_files_reach_of_digits/dig_arctan0.csv',
    '_files_reach_of_digits/dig_arctan1.csv',
    '_files_reach_of_digits/dig_arctan2.csv.csv',
    '_files_reach_of_digits/dig_arctan3.csv',
    '_files_reach_of_digits/dig_arctan4.csv'
]

paths_other = [
    '_files_reach_of_digits/dig_euler.csv',
    '_files_reach_of_digits/dig_gauss.csv',
    '_files_reach_of_digits/dig_ramanujancsv']

labels_arctan = [
        'arctan(1)',
        'arctan(1/2)+arctan(1/3)',
        '4arctan(1/5)-arctan(1/239)',
        '6arctan(1/8)+2arctan(1/57)+arctan(1/239)',
        '44arctan(1/59)+7arctan(1/239)-12arctan(1/682)+24arctan(1/12943)'
]

labels_other = ['Euler', 'Gauss', 'Ramanujan', 'Leibnitz', 'Viete']


sp = None
for path in paths_other:
    # sp = plt.subplot(3, 2, paths.index(path) + 1)
    df = pd.read_csv(path)
    plt.plot(df.iter, df.pi)
    plt.plot(df.iter, np.pi + df.iter * 0, color='red')

    plt.show()
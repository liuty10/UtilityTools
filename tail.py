# importing module
from pandas import *
from statistics import mean
import sys
import numpy as np

csvfile = sys.argv[1]
if 'RTT' in csvfile:
    column_name = 'RTT'
elif 'displayFPS' in csvfile:
    column_name = 'displayFPS'
else:
    print("wrong file name")
    print(csvfile)
    sys.exit(1)

# reading CSV file
data = read_csv(csvfile)
 
# converting column data to list
values = data[column_name].tolist()
values.sort()
 
# printing list data
print(values)
print(column_name)
print("len: ", len(values))
print("mean: ", mean(values))
print("percentile-1: ", np.percentile(values, 1))
print("percentile-99: ", np.percentile(values, 99))



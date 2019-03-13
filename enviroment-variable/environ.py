import os
name = os.environ.get('HOME')
print(name)
try:  
   cgr_benchmark_path = os.environ["CGR_BENCHMARK_PATH"]
except KeyError: 
   print("Please set the environment variable CGR_BENCHMARK_PATH")
   print("eg. export $CGR_BENCHMARK_PATH=PATH_TO_CGR_BENCHMARK")
   exit(1)

print(cgr_benchmark_path)

import random
num = random.randrange(500,1000)
query = random.randrange(num,2000)
window = random.randrange(10,num)
print num,window, query
arr = ["?","!"]
string = ""
for i in range(0,num):
  string = string + str(random.randrange(0,2))+" "
print string
string = ""
for i in range(0,query):
  string = string+arr[random.randrange(0,2)]
print string

import re
file = open("in","r")

class num(int):
    def __sub__ (self, a):
        return num(int(self)*int(a))

    def __add__ (self, a):
        return num(int(self)+int(a))


ans=0
for i in file:
    i=i.strip('\n')
    i=i.replace('*','-')
    i=re.sub('(\d+)', r'num(\1)', i)
    print(i)
    ans+=eval(i)

print(ans)
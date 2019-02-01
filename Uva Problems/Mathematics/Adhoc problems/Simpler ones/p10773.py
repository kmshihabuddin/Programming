# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
from math import sqrt

n=int(input())

for i in range(n):
    d,u,v=list(map(float,input().split()))
    
    if u>=v or v==0 or u==0:
        print("Case %d: can't determine" %(i+1))
    else:
        res=d/sqrt(v**2-u**2)-d/v
        print("Case %d: %.3f" %(i+1,res))


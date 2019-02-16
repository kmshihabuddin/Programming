# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 00:37:07 2019

@author: Shihab
"""

from sys import stdin

for line in stdin:
    a=list(map(int,line.split()))
    n=a[0]
    res=[False]*(n-1)
    
    for i in range(1,len(a)-1):
        if abs(a[i]-a[i+1])<=n-1:
            res[abs(a[i]-a[i+1])-1]=True
    
    if all(res):
        print("Jolly")
    else:
        print("Not jolly")
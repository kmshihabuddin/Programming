# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 00:10:26 2019

@author: Shihab
"""

t=int(input())

for case in range(t):
    input()
    ind=list(map(int,input().split()))
    nums=input().split()
    
    res=[0]*len(nums)
    for i in range(len(ind)):
        res[ind[i]-1]=nums[i]
    
    print("\n".join(res))
    if case!=t-1:
        print("")
    

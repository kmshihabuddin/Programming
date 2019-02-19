# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 19:15:57 2019

@author: Shihab
"""

t=int(input())

for case in range(t):
    inputs=input().split()
    print("Case "+str(case+1)+": "+inputs[len(inputs)//2])
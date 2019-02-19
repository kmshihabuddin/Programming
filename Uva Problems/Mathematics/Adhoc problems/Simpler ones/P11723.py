# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 18:56:26 2019

@author: Shihab
"""
from math import ceil

road,n=map(int,input().split())
case=1

while n or road:
    if road>27*n:
        print("Case "+str(case)+": impossible")
    else:
        print("Case "+str(case)+": "+str(int(ceil((road-n)/n))))
        
    road,n=map(int,input().split())
    case+=1
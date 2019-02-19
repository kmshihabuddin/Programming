# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 19:23:53 2019

@author: Shihab
"""

from sys import stdin

input_lines=stdin.read().splitlines()

print('PERFECTION OUTPUT')

for line in input_lines:
    inputs=list(map(int,line.split()))
    for n in inputs:
        Sum=1
        var=2
        while var*var<=n:
            if n%var==0:
                Sum+=var
                if var!=n//var:
                    Sum+=n//var
            var+=1
        
        num_s=str(n).rjust(5)+'  '
        
        if n==0:
            break
        
        if Sum==n and n!=1:
            print(num_s+'PERFECT')
        elif Sum<n or n==1:
            print(num_s+'DEFICIENT')
        else:
            print(num_s+'ABUNDANT')
        

print('END OF OUTPUT')

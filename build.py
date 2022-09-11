#!/usr/bin/python3
import os


name = 'a.out'
path = 'sauce'
files = ['arraylist', 'hashtable', 'main']

out = ''
compiler = 'gcc'

for f in files:
    out += f'{path}/{f}.c '

os.system(f'{compiler} -o {name} {out}')
os.system(f'./{name}')


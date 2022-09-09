#!/usr/bin/python3
import os


name = 'main'
files = ['hashtable', 'main']

out = ''
compiler = 'gcc'

for f in files:
    out += f'{f}.c '

os.system(f'{compiler} -o {name} {out}')
os.system(f'./{name}')


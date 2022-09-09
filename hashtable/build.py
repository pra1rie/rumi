#!/usr/bin/python3
import os


name = 'main'
files = ['hashtable', 'main']

out = ''
compiler = 'gcc'

if not os.path.exists('obj/'):
    os.mkdir('obj/')

for f in files:
    out += f'{f}.c '

os.system(f'{compiler} -o {name} {out}')
os.system('rm -rf obj/')
os.system(f'./{name}')


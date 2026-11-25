#!/usr/bin/env python3
# Recompila unidades por parte de su nombre y deja el objeto listo para enlazar. Ejecutar desde port/. Avisa con "fallo" si no compila.
import json,subprocess,shutil,re,sys,os
W3DP=os.environ.get('W3DP','/tmp/w3dp')
os.environ['W3D_TMP']=W3DP
L=json.load(open('../analysis/recovery-ledger.json'))['functions']
want=sys.argv[1:]
srcs=sorted({f['source'] for f in L if any(w in f['source'] for w in want)})
for s in srcs:
    r=subprocess.run(['python3','tools/lift/cc_one.py',s,'4'],capture_output=True,text=True)
    if r.stdout.strip().endswith('rc 0'): shutil.copy(W3DP+'/one.o',W3DP+'/objs/'+re.sub(r'[^\w]','_',s)+'.o')
    else: print('fallo',s,r.stdout[-300:])
print('compiladas',len(srcs))

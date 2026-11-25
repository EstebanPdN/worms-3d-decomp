import json,sys,glob,os,subprocess
f=max(glob.glob(os.path.expanduser('~/Library/Logs/DiagnosticReports/worms3d-*.ips')),key=os.path.getmtime)
t=open(f).read(); h,b=t.split('\n',1); d=json.loads(b)
print(os.path.basename(f), d['exception'], d.get('termination',{}).get('indicator'))
th=[x for x in d['threads'] if x.get('triggered')][0]
imgs=d['usedImages']
print('x0-3',[hex(r['value']) for r in th['threadState']['x'][:4]],'far',hex(th['threadState'].get('far',{}).get('value',0)), 'lr',hex(th['threadState']['lr']['value']))
base=[i for i in imgs if i.get('name')=='worms3d'][0]['base']
addrs=[]
for fr in th['frames'][:14]:
    img=imgs[fr['imageIndex']]
    print(img.get('name'),hex(img['base']+fr['imageOffset']),fr.get('symbol',''),fr.get('symbolLocation',''))

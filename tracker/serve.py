#!/usr/bin/env python3
"""Serve only the tracker folder, rebuilding metadata when project inputs change."""
from functools import partial
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from threading import Lock
import argparse
import json
import importlib
import build_data as mapper
import sys

from build_data import ROOT, OUT

lock = Lock()
last_inputs = None


def signature():
    paths = [ROOT / 'analysis/recovery-ledger.json', ROOT / 'source/recovered/refined/functions.jsonl',
             ROOT / 'tracker/build_data.py', ROOT / 'tracker/estimate-basis.json', ROOT / 'original/extracted/sys/main.dol']
    paths += sorted((ROOT / 'analysis/receipts').glob('*.json'))
    paths += sorted((ROOT / 'source/matching').glob('*'))
    return [(str(p), p.stat().st_mtime_ns, p.stat().st_size) for p in paths if p.is_file()]


def update():
    global last_inputs, mapper
    with lock:
        current = signature()
        if current != last_inputs:
            mapper = importlib.reload(mapper)
            mapper.build()
            last_inputs = current


class Handler(SimpleHTTPRequestHandler):
    def do_GET(self):
        if self.path.split('?')[0] == '/progress.json':
            try:
                update()
            except Exception as error:
                print(f'Metadata update rejected: {error}', file=sys.stderr)
                payload = json.dumps({'error': 'Los datos actuales no superan la verificación. Revisa los registros del proyecto.'}).encode()
                self.send_response(503)
                self.send_header('Content-Type', 'application/json; charset=utf-8')
                self.send_header('Content-Length', str(len(payload)))
                self.end_headers()
                self.wfile.write(payload)
                return
        super().do_GET()

    def list_directory(self, path):
        self.send_error(403)
        return None

    def end_headers(self):
        self.send_header('Cache-Control', 'no-store')
        self.send_header('X-Content-Type-Options', 'nosniff')
        super().end_headers()


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--port', type=int, default=8786)
    args = parser.parse_args()
    update()
    server = ThreadingHTTPServer(('127.0.0.1', args.port), partial(Handler, directory=str(OUT)))
    print(f'Worms 3D tracker: http://127.0.0.1:{server.server_port}', flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        server.server_close()

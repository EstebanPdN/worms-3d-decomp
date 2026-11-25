#!/usr/bin/env python3
"""Export the hosted tracker without original files or private paths."""

import argparse
import hashlib
import json
import shutil
from pathlib import Path

from build_data import OUT, ROOT, build

# The public interface has one canonical copy in tracker/dist/.
STATIC_ASSETS = (
    'index.html', 'style.css', 'hero.css', 'app.js', 'hero.js',
    'forge-progress.html', 'forge-progress.js',
    'assets/logo.png', 'assets/logo-hd.png', 'assets/wallpaper.png', 'assets/gamecube.png',
    'assets/weapon-atlas.png', 'assets/menu-medallions-originals.png',
    'assets/LilitaOne-Regular.ttf', 'assets/LilitaOne-OFL.txt',
    'assets/Nunito-Variable.ttf', 'assets/Nunito-OFL.txt',
    'assets/wpd_binoculars.png', 'assets/wpd_programmers.png',
)
PUBLIC_FIELDS = (
    'schema', 'updated_at', 'fingerprint', 'game', 'version', 'summary',
    'sections', 'parts', 'inventory', 'data_sections', 'bss', 'scope',
)
RECORD_FIELDS = (
    'address', 'name', 'ranges', 'bytes', 'state', 'module', 'inferred',
    'description',
)


def export(*, data_only=False, assets_only=False):
    """Separate verified number updates from intentional interface changes.

    FUTUROS AGENTES: para actualizar cifras usa --data-only. No cambies HTML,
    CSS, tipografía, colores ni plantillas. --assets-only conserva la instantánea.
    """
    if data_only and assets_only:
        raise ValueError('Choose data-only or assets-only, not both.')

    target = ROOT / 'tracker/site/dist'
    if data_only and any(not (target / name).is_file() for name in STATIC_ASSETS):
        raise FileNotFoundError('Export the complete site once before using --data-only.')
    if assets_only and not (target / 'progress.json').is_file():
        raise FileNotFoundError('Export the complete site once before using --assets-only.')

    # A visual edit must not rebuild or change the verified progress snapshot.
    data = None if assets_only else build()
    target.mkdir(parents=True, exist_ok=True)
    (target / 'assets').mkdir(exist_ok=True)
    site = target.parent
    if not data_only:
        for filename in STATIC_ASSETS:
            shutil.copy2(OUT / filename, target / filename)
            # Assets are data; do not publish migration-added executable bits.
            (target / filename).chmod(0o644)
        shutil.copy2(ROOT / 'tracker/SITE_README.md', site / 'README.md')
        shutil.copy2(ROOT / 'AI_DEVELOPMENT.md', site / 'AI_DEVELOPMENT.md')
        (site / '.gitignore').write_text('.DS_Store\n.openai/local/\n')
    if assets_only:
        print('Interface exported; existing progress.json preserved.')
        return

    # Only allowlisted metadata leaves the private recovery workspace.
    public = {key: data[key] for key in PUBLIC_FIELDS}
    public['records'] = []
    for record in data['records']:
        clean = {key: record[key] for key in RECORD_FIELDS}
        clean['source'] = Path(record['source']).name if record['source'] else None
        clean['receipt'] = Path(record['receipt']).name if record['receipt'] else None
        public['records'].append(clean)
    public['scripts_count'] = len(data['scripts'])
    public['resources'] = {'files': data['resources']['files']}
    public['history'] = [
        {key: item[key] for key in ('timestamp', 'exact_bytes', 'exact_functions')}
        for item in data['history']
    ]
    payload = json.dumps(public, separators=(',', ':'), ensure_ascii=False) + '\n'
    assert '/Users/' not in payload and 'original/extracted' not in payload
    (target / 'progress.json').write_text(payload)

    # Only this folder is uploaded. Recovery sources and original files stay out.
    files = [
        str(path.relative_to(site))
        for path in site.rglob('*')
        if path.is_file() and '.git' not in path.parts
    ]
    receipt = dict(
        files=files,
        progress_sha256=hashlib.sha256(payload.encode()).hexdigest(),
        exact_functions=public['summary']['exact_functions'],
        exact_bytes=public['summary']['exact_bytes'],
        original_game_files_uploaded=False,
        recovered_game_source_uploaded=False,
        absolute_local_paths_uploaded=False,
        publishing_authorization='Owner explicitly requested publishing the tracker on 2026-10-19.',
    )
    (ROOT / 'tracker/docs/site-export.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(receipt, indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument(
        '--data-only', action='store_true',
        help='Update verified numbers without copying interface files.',
    )
    mode.add_argument(
        '--assets-only', action='store_true',
        help='Update interface files without rebuilding progress data.',
    )
    args = parser.parse_args()
    export(data_only=args.data_only, assets_only=args.assets_only)

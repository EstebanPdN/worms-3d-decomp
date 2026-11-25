#!/usr/bin/env python3
"""Build a local, byte-complete progress map. Never copy executable contents."""
from pathlib import Path
from collections import Counter
from datetime import datetime, timezone
import hashlib
import heapq
import json
import struct
import math
import sys

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'tracker/dist'
sys.path.insert(0, str(ROOT / 'tools'))
from reference_proof_history import verify_reference_proof


def read(path):
    return json.loads((ROOT / path).read_text())


def digest(path):
    return hashlib.sha256((ROOT / path).read_bytes()).hexdigest()


def function_descriptions():
    """Reviewed English summaries of recovered bodies, never inferred labels."""
    descriptions = {}
    for line in (ROOT / 'tracker/function-descriptions.tsv').read_text().splitlines():
        if not line or line.startswith('#'):
            continue
        symbol, description = line.split('\t', 1)
        assert symbol not in descriptions, f'Duplicate description: {symbol}'
        assert description.strip(), f'Empty description: {symbol}'
        descriptions[symbol] = description
    return descriptions


RATE_WINDOW_HOURS = 4.0


def recent_rate(exact_bytes, total_bytes, worked_hours, window=RATE_WINDOW_HOURS):
    """Verified bytes gained per worked hour over the last `window` worked hours.

    The series is the (worked hours, exact bytes) pair after each recorded
    interval in analysis/receipts/project-hours; the window start is
    interpolated between the two receipts around it."""
    series = sorted({(a['worked_hours'], a['exact_bytes']) for a in
                     (json.loads(p.read_text())['after'] for p in (ROOT/'analysis/receipts/project-hours').glob('*.json'))}
                    | {(worked_hours, exact_bytes)})
    start = worked_hours - window
    if series[0][0] > start:
        return None
    before = max(p for p in series if p[0] <= start)
    after = min(p for p in series if p[0] >= start)
    start_bytes = before[1] if after[0] == before[0] else \
        before[1] + (after[1] - before[1]) * (start - before[0]) / (after[0] - before[0])
    rate = (exact_bytes - start_bytes) / window
    if rate <= 0:
        return None
    return dict(window_worked_hours=window, start_worked_hours=round(start, 2),
                start_percent=round(start_bytes / total_bytes * 100, 3),
                bytes_per_hour=round(rate), percent_per_hour=round(rate / total_bytes * 100, 2),
                remaining_hours=round((total_bytes - exact_bytes) / rate, 1),
                overall_percent_per_hour=round(exact_bytes / total_bytes * 100 / worked_hours, 2),
                method=('Linear projection from the verified instruction bytes gained in the last '
                        f'{window:g} worked hours (interpolated from the recorded hour receipts). That window '
                        'includes one-time bulk routes (recurring-shape generation, automatic m2c corrections) and '
                        'the output of parallel agents working during those hours. The remaining code is mostly '
                        'unique functions, and the CodeWarrior SDK and MusyX blocks need a compiler that is not in '
                        'the toolchain, so the real pace is likely to fall. Not a deadline.'))


def time_estimate(exact_bytes, total_bytes):
    basis = read('tracker/estimate-basis.json')
    owner = basis.get('owner_estimate')
    if owner:
        if owner.get('method') == 'overall_average':
            hours = round(owner['worked_hours'] * max(0, total_bytes - exact_bytes) / exact_bytes, 1)
            return dict(hours=hours, continuous_days=math.ceil(hours / 24),
                        kind='overall_average_projection', basis_updated_at=owner['updated_at'],
                        worked_hours=owner['worked_hours'], worked_hours_approximate=True,
                        worked_hours_source='Approximate hours reported by the project owner',
                        explanation='Linear projection using all accumulated work hours divided by total verified instruction-byte coverage. Assumes the overall average pace continues; approximate, not a deadline.',
                        recent_rate=None)
        return dict(hours=owner['remaining_hours'],
                    continuous_days=math.ceil(owner['remaining_hours'] / 24),
                    kind='owner_approximate_estimate', basis_updated_at=owner['updated_at'],
                    worked_hours=owner['worked_hours'], worked_hours_approximate=True,
                    worked_hours_source='Approximate hours reported by the project owner',
                    explanation=owner.get('explanation', 'Approximate remaining work estimated by the project owner; not a deadline.'),
                    recent_rate=owner.get('recent_rate'))
    assert 0 < basis['exact_bytes'] <= basis['total_bytes'] and basis['active_seconds'] > 0
    anchor = basis.get('projection_anchor')
    if anchor:
        assert anchor['exact_bytes'] == exact_bytes, 'Record project hours after a coverage change'
        assert basis['active_seconds'] >= anchor['active_seconds']
        raw_hours = max(0, anchor['remaining_hours'] -
                        (basis['active_seconds'] - anchor['active_seconds']) / 3600)
        hours = round(raw_hours, 1)
    else:
        bytes_per_hour = basis['exact_bytes'] / (basis['active_seconds'] / 3600)
        raw_hours = max(0, total_bytes - exact_bytes) / bytes_per_hour
        hours = int(math.floor(raw_hours / 50 + .5) * 50)
    return dict(hours=hours, continuous_days=math.ceil(hours / 24),
                kind='rough_active_work_projection', basis_updated_at=basis['captured_at'],
                worked_hours=basis['worked_hours'],
                worked_hours_approximate=basis['worked_hours_approximate'],
                worked_hours_source=basis['worked_hours_source'],
                explanation=basis['method'],
                recent_rate=recent_rate(exact_bytes, total_bytes, basis['worked_hours']))


def integrated_lifetime_evidence():
    """Publish a bounded behavioral milestone without changing byte coverage."""
    path = 'analysis/receipts/actor-lifetime-registry-behavior-audit.json'
    if not (ROOT / path).is_file():
        return None
    audit = read(path)
    assert audit['positive_mismatches'] == 0 and audit['added_exact_instruction_bytes'] == 0
    assert audit['whole_game_rebuilt'] is False and audit['physical_3ds_verified'] is False
    assert audit['verifier_sha256'] == digest('tests/test_actor_lifetime_registry.py')
    assert audit['lifetime_contract_sha256'] == digest('tests/test_actor_lifetime.py')
    assert audit['fixture_sha256'] == digest('analysis/fixtures/actor-lifetime-registry.json')
    assert audit['generation_receipt_sha256'] == digest('analysis/receipts/actor-lifetime-registry-oracle-generation.json')
    assert audit['legacy_receipt_sha256'] == digest('analysis/validation/actor-lifetime/positive/receipt.json')
    assert audit['legacy_data_sha256'] == digest('analysis/validation/actor-lifetime/positive/comparison.jsonl')
    generation = read('analysis/receipts/actor-lifetime-registry-oracle-generation.json')
    for key in ['template', 'generator', 'output']:
        assert generation[key + '_sha256'] == digest(generation[key])
    for label, proof in audit['raw_receipts'].items():
        assert proof['sha256'] == digest(proof['path'])
        raw = read(proof['path'])
        assert not raw['failures'] and raw['cases_completed'] == raw['cases_expected'] == audit['positive_cases']
        assert raw['mismatches'] == (0 if label == 'positive' else audit['compiled_controls'][label])
        assert raw['data_sha256'] == digest(Path(proof['path']).with_name('comparison.jsonl'))
        assert raw['script_sha256'] == generation['output_sha256']
        for source in raw['sources']:
            proof = verify_reference_proof(source['receipt'], source['sha256'])
            assert source['elf_sha256'] == proof['linked_elf_sha256'] == digest('build/lua-game-modules/' + proof['module'] + '/linked.elf')
        for prefix in ['', 'registry_']:
            if not raw.get(prefix + 'candidate_receipt'):
                continue
            candidate_path = raw[prefix + 'candidate_receipt']
            assert raw[prefix + 'candidate_receipt_sha256'] == digest(candidate_path)
            candidate = read(candidate_path)
            assert raw[prefix + 'candidate_elf_sha256'] == candidate['elf_sha256'] == digest(candidate['elf'])
            assert candidate['config_sha256'] == digest(candidate['config'])
            assert candidate['compile_receipt_sha256'] == digest(candidate['compile_receipt'])
            for source, expected in read(candidate['compile_receipt'])['source_inputs'].items():
                assert digest(source) == expected
    return dict(positive_cases=audit['positive_cases'], positive_mismatches=0,
        previous_lifetime_cases_preserved=audit['previous_lifetime_cases_preserved'],
        compiled_control_rejections=audit['compiled_controls'], added_exact_instruction_bytes=0,
        whole_game_equivalence=False, audit_sha256=digest(path))


def handle_cleanup_evidence():
    path = 'analysis/receipts/handle-cleanup-behavior-audit.json'
    if not (ROOT / path).is_file():
        return None
    audit = read(path)
    assert audit['positive_mismatches'] == 0 and audit['added_exact_instruction_bytes'] == 324
    assert audit['whole_game_rebuilt'] is False and audit['lifetime_integration_verified'] is False
    assert audit['verifier_sha256'] == digest('tests/test_handle_cleanup.py')
    assert audit['fixture_sha256'] == digest('analysis/fixtures/handle-cleanup.json')
    for label, witness in audit['raw_receipts'].items():
        assert witness['sha256'] == digest(witness['path'])
        raw = read(witness['path'])
        assert not raw['failures'] and raw['cases_completed'] == raw['cases_expected'] == audit['positive_cases']
        assert raw['mismatches'] == (0 if label == 'positive' else audit['compiled_controls'][label])
        assert raw['data_sha256'] == digest(Path(witness['path']).with_name('comparison.jsonl'))
        assert raw['script_sha256'] == digest('tools/ghidra-scripts/CompareWormsHandleCleanup.java')
        for source in raw['sources']:
            proof = verify_reference_proof(source['receipt'], source['sha256'])
            assert source['elf_sha256'] == proof['linked_elf_sha256'] == digest('build/lua-game-modules/handle_cleanup/linked.elf')
            assert proof['compile_receipt_sha256'] == digest(proof['compile_receipt'])
            for file, expected in read(proof['compile_receipt'])['source_inputs'].items():
                assert digest(file) == expected
        if raw.get('candidate_receipt'):
            assert raw['candidate_receipt_sha256'] == digest(raw['candidate_receipt'])
            candidate = read(raw['candidate_receipt'])
            assert raw['candidate_elf_sha256'] == candidate['elf_sha256'] == digest(candidate['elf'])
            assert candidate['config_sha256'] == digest(candidate['config'])
            assert candidate['compile_receipt_sha256'] == digest(candidate['compile_receipt'])
            for file, expected in read(candidate['compile_receipt'])['source_inputs'].items():
                assert digest(file) == expected
    return dict(positive_cases=audit['positive_cases'], positive_mismatches=0,
        compiled_control_rejections=audit['compiled_controls'],
        native_memcpy_executions=audit['positive_source_body_execution_counts']['native_memcpy'],
        lifetime_integration_verified=False, whole_game_equivalence=False,
        audit_sha256=digest(path))


def integrated_handles_evidence():
    path = 'analysis/receipts/actor-lifetime-handles-behavior-audit.json'
    if not (ROOT / path).is_file():
        return None
    audit = read(path)
    assert audit['positive_mismatches'] == 0 and audit['added_exact_instruction_bytes'] == 0
    assert audit['whole_game_rebuilt'] is False and audit['physical_3ds_verified'] is False
    assert audit['verifier_sha256'] == digest('tests/test_actor_lifetime_handles.py')
    assert audit['registry_contract_sha256'] == digest('tests/test_actor_lifetime_registry.py')
    assert audit['standalone_handle_contract_sha256'] == digest('tests/test_handle_cleanup.py')
    assert audit['fixture_sha256'] == digest('analysis/fixtures/actor-lifetime-handles.json')
    gp = 'analysis/receipts/actor-lifetime-handles-oracle-generation.json'
    assert audit['generation_receipt_sha256'] == digest(gp)
    generation = read(gp)
    # Reuse the verifier's exact two-edit bridge; the historical generated
    # contract and all behavioral assertions remain hash-pinned.
    sys.path.insert(0, str(ROOT / 'tests'))
    from test_actor_lifetime_handles import verify_contract_template
    verify_contract_template(generation)
    for key in ['template', 'generator', 'output', 'contract_output']:
        assert generation[key + '_sha256'] == digest(generation[key])
    assert audit['parent_receipt_sha256'] == digest('analysis/validation/actor-lifetime-registry/positive/receipt.json')
    assert audit['parent_data_sha256'] == digest('analysis/validation/actor-lifetime-registry/positive/comparison.jsonl')
    for label, witness in audit['raw_receipts'].items():
        assert witness['sha256'] == digest(witness['path'])
        raw = read(witness['path'])
        assert not raw['failures'] and raw['cases_expected'] == raw['cases_completed'] == audit['positive_cases']
        assert raw['mismatches'] == (0 if label == 'positive' else audit['compiled_controls'][label])
        assert raw['data_sha256'] == digest(Path(witness['path']).with_name('comparison.jsonl'))
        assert raw['script_sha256'] == generation['output_sha256']
        for source in raw['sources']:
            proof = verify_reference_proof(source['receipt'], source['sha256'])
            assert source['elf_sha256'] == proof['linked_elf_sha256'] == digest('build/lua-game-modules/' + proof['module'] + '/linked.elf')
            assert proof['compile_receipt_sha256'] == digest(proof['compile_receipt'])
            for file, expected in read(proof['compile_receipt'])['source_inputs'].items():
                assert digest(file) == expected
        for prefix in ['', 'registry_', 'handle_']:
            if not raw.get(prefix + 'candidate_receipt'): continue
            assert raw[prefix + 'candidate_receipt_sha256'] == digest(raw[prefix + 'candidate_receipt'])
            candidate = read(raw[prefix + 'candidate_receipt'])
            assert raw[prefix + 'candidate_elf_sha256'] == candidate['elf_sha256'] == digest(candidate['elf'])
            assert candidate['config_sha256'] == digest(candidate['config'])
            assert candidate['compile_receipt_sha256'] == digest(candidate['compile_receipt'])
            for file, expected in read(candidate['compile_receipt'])['source_inputs'].items():
                assert digest(file) == expected
    return dict(positive_cases=audit['positive_cases'], positive_mismatches=0,
        previous_registry_cases_preserved=audit['previous_registry_cases_preserved'],
        original_lifetime_cases_preserved=audit['original_lifetime_cases_preserved'],
        compiled_control_rejections=audit['compiled_controls'],
        native_handle_cleanup_executions=audit['source_body_execution_counts']['handle_cleanup'],
        native_memcpy_executions=audit['source_body_execution_counts']['handle_native_memcpy'],
        added_exact_instruction_bytes=0, whole_game_equivalence=False, audit_sha256=digest(path))


def partition(sections, records):
    """Priority overlay: proven source, bounded behavior, inference, uncovered.

    Keep every inferred range in records. Overlaps get one deterministic display
    owner, never extra area or extra completed bytes.
    """
    result = []
    for section in sections:
        start, end = section['start'], section['end']
        events = {}
        for idx, record in enumerate(records):
            for left, right in record['ranges']:
                a, b = max(start, left), min(end, right)
                if a < b:
                    key = (record['priority'], -record['address'], idx, b)
                    events.setdefault(a, []).append(key)
                    events.setdefault(b, [])
        points = sorted({start, end, *events})
        active = []
        for a, b in zip(points, points[1:]):
            for key in events.get(a, []):
                heapq.heappush(active, key)
            while active and active[0][3] <= a:
                heapq.heappop(active)
            owner = active[0][2] if active else -1
            if result and result[-1][1] == a and result[-1][2] == owner:
                result[-1][1] = b
            else:
                result.append([a, b, owner])
    return result


def reviewed_mixed_reference_evidence():
    """Prefer the new frozen code/data image while retaining historical gates."""
    current_receipt = 'analysis/receipts/current-code-data-mixed-owner-audit.json'
    expanded_receipt = 'analysis/receipts/all-admitted-mixed-owner-audit.json'
    if (ROOT / current_receipt).is_file():
        from current_code_data_mixed_evidence import summary
        receipt = current_receipt
    elif (ROOT / expanded_receipt).is_file():
        from all_admitted_mixed_evidence import summary
        receipt = expanded_receipt
    else:
        from mixed_reference_evidence import summary
        receipt = 'analysis/receipts/mixed-reference-owner-audit.json'
    result = summary(ROOT)
    assert result == read(receipt), 'Mixed owner receipt differs from recomputed gate'
    assert result['independent_review'].startswith('PASS'), 'Mixed review must finish before publication'
    assert result['status'] == 'passed', 'Mixed evidence must pass before publication'
    return result



def reviewed_fixed15670_mixed_evidence():
    """Additional frozen-image metadata; historical mixed gates still run above."""
    from fixed15670_mixed_evidence import summary
    result = summary(ROOT)
    assert result == read('analysis/receipts/fixed15670-mixed-owner-audit.json'), 'Fixed15670 owner receipt differs'
    assert result['status'] == 'passed' and result['evidence_scope'] == 'fixed15670_I1_I2', 'Fixed15670 gate must pass'
    assert result['canonical_counts_consumed'] is False and result['old_gates_replaced'] is False, 'Fixed15670 scope must stay separate'
    return result


def native_construction_evidence():
    """Expose only owner-bound finite construction evidence, without area credit."""
    receipt = 'analysis/receipts/native-construction-behavior-owner-audit.json'
    if not (ROOT / receipt).is_file():
        return None
    from native_construction_behavior import summary
    result = summary(ROOT)
    assert result == read(receipt), 'Construction owner receipt differs from recomputed gate'
    assert result['status'] == 'bounded-pass', 'Construction owner reproduction must finish before publication'
    assert result['owner_reproduction'].startswith('PASS'), 'Construction owner reproduction must pass'
    assert result['added_exact_functions'] == result['added_exact_instruction_bytes'] == result['added_behavior_area_bytes'] == 0
    return result


def build():
    ledger = read('analysis/recovery-ledger.json')
    audit = read('analysis/receipts/source-proof-audit.json')
    dol = (ROOT / 'original/extracted/sys/main.dol').read_bytes()
    original_hash = hashlib.sha256(dol).hexdigest()
    assert original_hash == ledger['original_sha256'] == audit['original_sha256']
    for proof in audit['proofs']:
        assert digest(proof['receipt']) == proof['receipt_sha256'], f'Stale exact proof: {proof["receipt"]}'
        linked = read(proof['receipt'])
        if linked.get('compile_receipt'):
            assert digest(linked['compile_receipt']) == linked['compile_receipt_sha256']
            compiled = read(linked['compile_receipt'])
            for input_path, input_hash in compiled.get('source_inputs', {}).items():
                assert digest(input_path) == input_hash, f'Stale exact source: {input_path}'
    sections = []
    for i in range(7):
        start = struct.unpack_from('>I', dol, 0x48 + i * 4)[0]
        size = struct.unpack_from('>I', dol, 0x90 + i * 4)[0]
        if size:
            sections.append(dict(name=f'.text{i}', start=start, end=start+size, bytes=size,
                                 file_offset=struct.unpack_from('>I', dol, i*4)[0]))
    total = sum(s['bytes'] for s in sections)
    records = []
    inferred = [json.loads(line) for line in (ROOT / 'source/recovered/refined/functions.jsonl').read_text().splitlines()]
    for f in inferred:
        address = int(f['address'], 16)
        records.append(dict(address=address, name=f['name'], ranges=[[int(a, 16), int(b, 16)+1] for a, b in f['ranges_inclusive']],
                            bytes=f['body_bytes'], state='pending', module='Unclassified', priority=2,
                            source=None, receipt=None, calls=len(f.get('calls', [])), inferred=True))
    exact_intervals = []
    for f in ledger['functions']:
        assert f.get('exact_linked_match', f.get('exact_match')) is True
        a, b = int(f['address'], 16), int(f['address'], 16)+f['bytes']
        assert any(s['start'] <= a < b <= s['end'] for s in sections)
        section = next(s for s in sections if s['start'] <= a < b <= s['end'])
        offset = section['file_offset']+a-section['start']
        assert hashlib.sha256(dol[offset:offset+f['bytes']]).hexdigest() == f['body_sha256']
        assert f['receipt'] in {p['receipt'] for p in audit['proofs']}
        linked = read(f['receipt'])
        if f['source'].endswith('/random.c'):
            assert digest(f['source']) == linked['source_sha256']
        exact_intervals.append((a, b))
        records.append(dict(address=a, name=f.get('name', f.get('symbol')), ranges=[[a, b]], bytes=f['bytes'], state='exact',
                            module=Path(f['source']).name, priority=0, source=f['source'], receipt=f['receipt'],
                            calls=None, inferred=False))
    exact_intervals.sort()
    assert all(a[1] <= b[0] for a, b in zip(exact_intervals, exact_intervals[1:]))
    exact = sum(b-a for a, b in exact_intervals)
    assert exact == audit['verified_reference_instruction_bytes']
    assert len(exact_intervals) == audit['source_functions_with_exact_reference_byte_match']

    # These audits certify bounded tests, not full-game equivalence. The candidate
    # and its source hash must still agree with the recorded audit/build inputs.
    behavior_specs = [
        ('actor_dispatch', 'actor-dispatch-behavior-audit.json'),
        ('actor_table_dispatch', 'actor-dispatch-behavior-audit.json'),
        ('actor_broadcast', 'actor-broadcast-behavior-audit.json'),
        ('actor_registration', 'actor-registration-behavior-audit.json'),
        ('actor_destruction', 'actor-destruction-behavior-audit.json'),
        ('task_scheduler', 'task-scheduler-behavior-audit.json'),
        ('task_groups', 'task-groups-behavior-audit.json'),
        ('task_heap_push', 'task-heap-behavior-audit.json'),
        ('task_heap_adjust', 'task-heap-behavior-audit.json'),
        ('task_heap_pop', 'task-heap-behavior-audit.json'),
        ('script_messages', 'send-message-behavior-audit.json'),
        ('script_float_messages', 'typed-message-behavior-audit.json'),
        ('script_int_messages', 'typed-message-behavior-audit.json'),
        ('script_string_messages', 'typed-message-behavior-audit.json'),
        ('script_error_report', 'script-error-behavior-audit.json'),
        ('engine_log', 'engine-log-behavior-audit.json'),
        ('engine_log_channel', 'engine-log-behavior-audit.json'),
        ('engine_log_prepare', 'engine-log-behavior-audit.json'),
        ('message_arena_init', 'message-arena-behavior-audit.json'),
        ('message_arena_open', 'message-arena-behavior-audit.json'),
        ('message_arena_reserve', 'message-arena-behavior-audit.json'),
        ('native_temporary_allocate', 'temporary-heap-behavior-owner-audit.json'),
    ]
    by_entry = {r['address']: r for r in records if r['inferred']}
    behavior_evidence = []
    for module, audit_name in behavior_specs:
        path = f'analysis/receipts/{module}-source-candidate.json'
        if not (ROOT / path).exists():
            continue
        candidate, proof = read(path), read(f'analysis/receipts/{audit_name}')
        a = int(candidate['original_entry'], 16)
        f = by_entry.get(a)
        if not f:
            continue
        compile_proof = read(candidate['compile_receipt'])
        assert digest(candidate['compile_receipt']) == candidate['compile_receipt_sha256']
        assert compile_proof['compiled'] is True
        for input_path, input_hash in compile_proof['source_inputs'].items():
            assert digest(input_path) == input_hash, f'Stale source input: {input_path}'
        # Record exact input receipt hashes. Freshness is surfaced separately;
        # this map doesn't promote behavioral experiments to exact coverage.
        behavior_evidence.append(dict(module=module, address=a, audit=audit_name,
                                     candidate_sha256=digest(path), audit_sha256=digest(f'analysis/receipts/{audit_name}')))
        source = compile_proof.get('source', compile_proof.get('source_file'))
        if not isinstance(source, str):
            source = None
        records.append(dict(address=a, name=candidate['function'], ranges=f['ranges'], bytes=f['bytes'],
                            state='behavior', module=module, priority=1, source=source,
                            receipt=f'analysis/receipts/{audit_name}', calls=f['calls'], inferred=False))

    descriptions = function_descriptions()
    for record in records:
        record['description'] = descriptions.get(record['name']) if record['state'] in ['exact','behavior'] else None
        if record['state'] == 'exact':
            assert record['description'], f'Missing recovered-source description: {record["name"]}'

    parts = partition(sections, records)
    assert sum(b-a for a, b, _ in parts) == total
    for s in sections:
        relevant = [p for p in parts if s['start'] <= p[0] < s['end']]
        assert relevant[0][0] == s['start'] and relevant[-1][1] == s['end']
        assert all(a[1] == b[0] for a, b in zip(relevant, relevant[1:]))
    assert sum(b-a for a, b, i in parts if i >= 0 and records[i]['state'] == 'exact') == exact

    # The inventory retains inferred duplicates as separate hypotheses; display
    # geometry is an exclusive partition. Proven entries replace same-entry
    # inferred names in the searchable primary inventory only.
    primary = {}
    for i, r in enumerate(records):
        old = primary.get(r['address'])
        if old is None or r['priority'] < records[old]['priority']:
            primary[r['address']] = i
    status_bytes = Counter()
    for a, b, i in parts:
        status_bytes[records[i]['state'] if i >= 0 else 'unmapped'] += b-a
    # Finder metadata is retained locally but is not an extracted game asset.
    files = sorted(p for p in (ROOT / 'original/extracted').rglob('*')
                   if p.is_file() and p.name != '.DS_Store')
    file_types = Counter(p.suffix.lower() or '(sin extensión)' for p in files)
    lua = [dict(path=str(p.relative_to(ROOT / 'original/extracted')), bytes=p.stat().st_size,
                state='original_script') for p in files if p.suffix.lower() == '.lua']
    extra_executables = [str(p.relative_to(ROOT / 'original/extracted')) for p in files
                         if p.suffix.lower() in {'.dol', '.rel', '.rso', '.elf'}]
    data_sections = []
    for i in range(11):
        start = struct.unpack_from('>I', dol, 0x64+i*4)[0]
        size = struct.unpack_from('>I', dol, 0xac+i*4)[0]
        if size:
            data_sections.append(dict(name=f'.data{i}', address=start, bytes=size, state='pending'))
    bss = dict(address=struct.unpack_from('>I', dol, 0xd8)[0], bytes=struct.unpack_from('>I', dol, 0xdc)[0])
    file_inventory = [dict(path=str(p.relative_to(ROOT / 'original/extracted')), bytes=p.stat().st_size,
                           kind=p.suffix.lower() or '(sin extensión)', state='preserved_original') for p in files]
    integrated_lifetime = integrated_lifetime_evidence()
    handle_cleanup = handle_cleanup_evidence()
    integrated_handles = integrated_handles_evidence()
    # Revalidate the canonical compiled allocator against both retained machine
    # runs. This is bounded behavioral evidence and never exact-byte credit.
    from temporary_heap_behavior import verify as verify_temporary_heap
    temporary_heap = verify_temporary_heap()
    assert temporary_heap == read('analysis/receipts/temporary-heap-behavior-owner-audit.json')
    from temporary_owner_behavior import verify as verify_temporary_owner
    temporary_owner = verify_temporary_owner()
    assert temporary_owner == read('analysis/receipts/temporary-owner-behavior-owner-audit.json')
    from native_slot_behavior import verify as verify_native_slots
    native_slots = verify_native_slots()
    assert native_slots == read('analysis/receipts/native-slot-behavior-owner-audit.json')
    from native_buffer_behavior import verify as verify_native_buffer
    native_buffer = verify_native_buffer()
    assert native_buffer == read('analysis/receipts/native-buffer-behavior-owner-audit.json')
    from current_request_evidence import transfer_summary as request_transfer_summary
    request_transfer = request_transfer_summary(ROOT)
    assert request_transfer == read('analysis/receipts/request-transfer-behavior-owner-audit.json')
    from binary_reference_evidence import summary as binary_reference_summary
    binary_reference = binary_reference_summary(ROOT)
    assert binary_reference == read('analysis/receipts/binary-reference-owner-audit.json')
    from current_request_evidence import storage_summary as request_storage_summary
    request_storage = request_storage_summary(ROOT)
    assert request_storage == read('analysis/receipts/request-storage-behavior-owner-audit.json')
    mixed_reference = reviewed_mixed_reference_evidence()
    fixed15670_mixed = reviewed_fixed15670_mixed_evidence()
    native_construction = native_construction_evidence()
    from source_owned_data_evidence import summary as source_data_summary
    source_data_replay = source_data_summary(ROOT)
    fingerprint = hashlib.sha256(json.dumps(dict(ledger=digest('analysis/recovery-ledger.json'),
        audit=digest('analysis/receipts/source-proof-audit.json'), behavior=behavior_evidence,
        exporter=digest('source/recovered/refined/functions.jsonl'), mapper=digest('tracker/build_data.py'),
        descriptions=digest('tracker/function-descriptions.tsv'), estimate_basis=digest('tracker/estimate-basis.json'),
        integrated_lifetime=integrated_lifetime, handle_cleanup=handle_cleanup,
        integrated_handles=integrated_handles,
        temporary_heap=temporary_heap,
        temporary_owner=temporary_owner,
        native_slots=native_slots,
        native_buffer=native_buffer,
        request_transfer=request_transfer,
        binary_reference=binary_reference,
        request_storage=request_storage,
        mixed_reference=mixed_reference,
        fixed15670_mixed=fixed15670_mixed,
        native_construction=native_construction,
        source_data_replay=source_data_replay,
        files=file_inventory), sort_keys=True).encode()).hexdigest()
    previous = {}
    target = OUT / 'progress.json'
    if target.exists():
        previous = json.loads(target.read_text())
    generated = previous.get('updated_at') if previous.get('fingerprint') == fingerprint else datetime.now(timezone.utc).isoformat()
    history_path = ROOT / 'tracker/history.json'
    history = json.loads(history_path.read_text()) if history_path.exists() else []
    if not history or history[-1]['fingerprint'] != fingerprint:
        history.append(dict(timestamp=generated, exact_bytes=exact, exact_functions=len(exact_intervals), fingerprint=fingerprint))
        history_path.write_text(json.dumps(history, indent=2)+'\n')
    for r in records:
        r.pop('priority')
    data = dict(schema=1, updated_at=generated, fingerprint=fingerprint,
                game='Worms 3D', version='GameCube PAL · GWMP8P · rev. 0', original_sha256=original_hash,
                summary=dict(total_bytes=total, exact_bytes=exact, exact_functions=len(exact_intervals),
                             percent=exact/total*100, inferred_functions=len(inferred), status_bytes=dict(status_bytes),
                             game_rebuilt=False, native_3ds=False, time_estimate=time_estimate(exact,total),
                             actor_lifetime_registry=integrated_lifetime, handle_cleanup=handle_cleanup,
                             actor_lifetime_handles=integrated_handles,
                             temporary_heap=temporary_heap,
                             temporary_owner=temporary_owner,
        native_slots=native_slots,
        native_buffer=native_buffer,
        request_transfer=request_transfer,
        binary_reference=binary_reference,
        request_storage=request_storage,
        mixed_reference=mixed_reference,
        fixed15670_mixed=fixed15670_mixed,
        native_construction=native_construction,
        source_data_replay=source_data_replay,
                             owned_data_bytes=audit['owned_initialized_data_bytes']),
                sections=sections, records=records, parts=parts, inventory=sorted(primary.values(), key=lambda i:records[i]['address']),
                data_sections=data_sections, bss=bss, scripts=lua,
                resources=dict(files=len(files), types=dict(file_types), executable_files=extra_executables, inventory=file_inventory),
                history=history, evidence=dict(ledger_sha256=digest('analysis/recovery-ledger.json'),
                    audit_sha256=digest('analysis/receipts/source-proof-audit.json'), behavioral=behavior_evidence),
                scope='Every DOL text byte appears exactly once. Function boundaries are inferred unless exact-proven. Behavior marks are bounded experiment evidence, excluded from exact coverage. Data, BSS, Lua scripts and resources are separate inventories. No complete game build or 3DS acceptance.')
    OUT.mkdir(exist_ok=True)
    temporary = OUT / 'progress.json.tmp'
    temporary.write_text(json.dumps(data, separators=(',', ':'), ensure_ascii=False)+'\n')
    temporary.replace(target)
    receipt = dict(timestamp=generated, fingerprint=fingerprint, total_bytes=total, partition_bytes=sum(b-a for a,b,_ in parts),
                   exact_bytes=exact, exact_functions=len(exact_intervals), inferred_functions=len(inferred),
                   parts=len(parts), status_bytes=dict(status_bytes), primary_functions=len(primary),
                   all_text_bytes_accounted=True, double_counted_bytes=0, original_contents_copied=False,
                   coverage_percent=exact/total*100, scope=data['scope'])
    (ROOT / 'tracker/docs/mapping-audit.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps(receipt, indent=2))
    return data


if __name__ == '__main__':
    build()

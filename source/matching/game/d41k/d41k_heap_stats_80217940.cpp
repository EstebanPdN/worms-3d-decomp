/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/
/* Upstream: Graphviz 2.40.1 lib/vmalloc/vmstat.c, "Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94." */
// GWMP8P rev0 0x80217940. Vmalloc's vmstat with a walker callback: locks the
// heap unless it is in trust mode, clears the statistics, then walks the
// pool free list and every segment, counting busy and free blocks and their
// sizes, reporting each block to the callback.
struct Free { Free *next; };
struct Block { int w0; unsigned size; int w8; int w12; char data[8]; };
struct Segment { int w0; Segment *next; int w8; int size; char *end; int w20; struct Tail *tail; };
struct Tail { int w0; int size; };
struct Vmdata { unsigned flags; int w4; int unit; Segment *seg; Free *freeList; };
struct Heap { char pad[48]; Vmdata *info; };
struct Vmstat { int n_busy; int n_free; int s_busy; int s_free; unsigned m_busy; unsigned m_free; int n_seg; int extent; };
typedef void (*Walker)(Heap *, void *, unsigned, int);
extern "C" int w3d_d41k_heap_stats_80217940(Heap *h, Vmstat *s, Walker cb) {
    Vmdata *info = h->info;
    if (s == 0) return -1;
    unsigned flags = info->flags;
    if ((flags & 1) == 0) {
        if (flags & 8192) return -1;
        info->flags = flags | 8192;
    }
    s->n_busy = s->n_free = 0;
    s->s_busy = s->s_free = s->m_busy = s->m_free = 0;
    s->n_seg = 0;
    s->extent = 0;
    unsigned size;
    unsigned fw = info->flags;
    if (fw & 256) s->n_busy = 0; else { if ((fw & 128) != 0 && (size = info->unit) != 0) {
        Free *fl = info->freeList;
        size = (size + 7) & ~7;
        if (fl != 0) {
            do {
                if (cb) cb(h, fl, size, 1);
                s->n_free++;
                fl = fl->next;
            } while (fl != 0);
        }
    }
    }
    for (Segment *seg = info->seg; seg != 0; seg = seg->next) {
        char *p = (char *)seg + 32;
        s->n_seg++;
        s->extent += seg->size;
        char *end = seg->end - 8;
        unsigned fl = info->flags;
        if (fl & 1600) {
            if (p < end) {
                do {
                    unsigned word = ((Block *)p)->size;
                    size = word & ~7;
                    if ((word & 5) != 1) {
                        if (size > s->m_free) s->m_free = size;
                        s->s_free += size;
                        s->n_free++;
                        if (cb) cb(h, p, size, 1);
                    } else {
                        char *data = p + 8;
                        if (info->flags & 512) {
                            size = ((Block *)p)->w12;
                            data = p + 24;
                        } else if (info->flags & 1024) {
                            size = ((Block *)(size + (unsigned)p))->size;
                        }
                        if (size > s->m_busy) s->m_busy = size;
                        if (cb) cb(h, data, size, 0);
                        s->s_busy += size;
                        s->n_busy++;
                    }
                    p += (((Block *)p)->size & ~7) + 8;
                } while (p < end);
            }
        } else if (fl & 256) {
            Tail *t = seg->tail;
            if (t != 0) size = t->size + 8; else size = 0;
            if (size) {
                s->s_free += size;
                s->n_free++;
            }
            size = (end - p) - size;
            if (size) {
                s->s_busy += size;
                s->n_busy++;
            }
        } else if ((fl & 128) && size != 0) {
            s->n_busy += (unsigned)(end - p) / size;
        }
    }
    if ((info->flags & 128) && size != 0) {
        int n = s->n_busy - s->n_free;
        s->n_busy = n;
        if (n > 0) { int unit = info->unit; s->m_busy = unit; s->s_busy = unit * n; }
        n = s->n_free;
        if (n > 0) { int unit = info->unit; s->m_free = unit; s->s_free = unit * n; }
    }
    info->flags &= ~8192;
    return 0;
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41m_lens_flare_update_800bf320)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
call_80126384 = 0x80126384;
cast_80341584 = 0x80341584;
cast_8034380c = 0x8034380c;
clock_801264fc = 0x801264fc;
colours_80189760 = 0x80189760;
flare_801797b4 = 0x801797b4;
from44_801f74d0 = 0x801f74d0;
invert_801f76e0 = 0x801f76e0;
kinds_80189828 = 0x80189828;
one_80382e4c = 0x80382e4c;
position_ctor_80343740 = 0x80343740;
positions_80189518 = 0x80189518;
query_801262c0 = 0x801262c0;
query_80126524 = 0x80126524;
resize_8018920c = 0x8018920c;
sqrt_802e82c0 = 0x802e82c0;
sun_8044b688 = 0x8044b688;
trace_800b0824 = 0x800b0824;
uvs_8018963c = 0x8018963c;
SECTIONS {
  .text.d41m_lens_flare_update_800bf320 0x800bf320 : { *(.text.d41m_lens_flare_update_800bf320) }
  .rodata 0x80382e50 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; hits_804b1764 = .;
    . = 0x24; scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

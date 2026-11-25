/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_trail_update_800f1f70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
colours_80189760 = 0x80189760;
flags_80189704 = 0x80189704;
memset = 0x802eefe0;
positions_80189518 = 0x80189518;
probe_800f235c = 0x800f235c;
push_800f2810 = 0x800f2810;
remove_800f287c = 0x800f287c;
set_vectors_8018993c = 0x8018993c;
sizes_8018963c = 0x8018963c;
sqrt_802e82c0 = 0x802e82c0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d29c_trail_update_800f1f70 0x800f1f70 : { *(.text.d29c_trail_update_800f1f70) }
  .rodata 0x8038c430 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

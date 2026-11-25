/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_input_process_800f8dcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
alloc_fallback_803413d8 = 0x803413d8;
can_accept_800f899c = 0x800f899c;
forward_8020b680 = 0x8020b680;
ids_80240bf8 = 0x80240bf8;
key_8041aa68 = 0x8041aa68;
record_vtable_80410500 = 0x80410500;
release_802134fc = 0x802134fc;
values_80240cc8 = 0x80240cc8;
SECTIONS {
  .text.d24c_input_process_800f8dcc 0x800f8dcc : { *(.text.d24c_input_process_800f8dcc) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; sink_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28j_resolve_conflicts_801993f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
atexit_802ed7e0 = 0x802ed7e0;
drop_8019ab0c = 0x8019ab0c;
dtor_801993c8 = 0x801993c8;
fallback_803413d8 = 0x803413d8;
lbl_8045ccac = 0x8045ccac;
memmove_802eeef4 = 0x802eeef4;
release_802134fc = 0x802134fc;
SECTIONS {
  .text.d28j_resolve_conflicts_801993f8 0x801993f8 : { *(.text.d28j_resolve_conflicts_801993f8) }
  .sdata 0x804b02ec (NOLOAD) : {
    . = 0x0; guard_804b02ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

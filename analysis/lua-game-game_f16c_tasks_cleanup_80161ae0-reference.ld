/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f16c_tasks_cleanup_80161ae0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arrayfree_801fe240 = 0x801fe240;
base_801628ec = 0x801628ec;
find_80161ffc = 0x80161ffc;
free_802134fc = 0x802134fc;
prepare_80162480 = 0x80162480;
range_80455244 = 0x80455244;
vtable_804117c8 = 0x804117c8;
SECTIONS {
  .text.f16c_tasks_cleanup_80161ae0 0x80161ae0 : { *(.text.f16c_tasks_cleanup_80161ae0) }
  .sdata 0x804ab498 (NOLOAD) : {
    . = 0x0; count_804ab498 = .;
    . = 0x8; active_804ab4a0 = .;
    . = 0xc; names_804ab4a4 = .;
    . = 0x10; records_804ab4a8 = .;
    . = 0x14; array_804ab4ac = .;
    . = 0x18; array_804ab4b0 = .;
    . = 0x1c; array_804ab4b4 = .;
    . = 0x20; array_804ab4b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

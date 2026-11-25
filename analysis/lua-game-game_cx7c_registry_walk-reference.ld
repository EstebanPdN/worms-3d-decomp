/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7c_registry_refresh_80355690)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx7c_entry_refresh_801a7ed8 = 0x801a7ed8;
cx7c_registry_80362444 = 0x80362444;
cx7c_registry_first_8020fe00 = 0x8020fe00;
cx7c_registry_next_8020fe18 = 0x8020fe18;
SECTIONS {
  .text.w3d_cx7c_registry_refresh_80355690 0x80355690 : { *(.text.w3d_cx7c_registry_refresh_80355690) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

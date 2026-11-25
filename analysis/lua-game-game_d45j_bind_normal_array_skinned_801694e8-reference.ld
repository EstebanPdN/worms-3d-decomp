/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(bind_normal_array_skinned_801694e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
DCFlushRange = 0x802fa988;
GXSetArray = 0x80307d88;
f8c_skin_normal_801a15f8 = 0x801a15f8;
skin_type_80363654 = 0x80363654;
w3d_auto_8016808c = 0x8016808c;
w3d_cc17b_temp_alloc_8016a21c = 0x8016a21c;
SECTIONS {
  .text.bind_normal_array_skinned_801694e8 0x801694e8 : { *(.text.bind_normal_array_skinned_801694e8) }
  .rodata 0x803a5030 : { *(.rodata) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

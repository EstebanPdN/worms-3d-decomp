/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_aim_tweaks_construct_80021514)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_string_8036c014 = 0x8036c014;
w3d_string_8036c024 = 0x8036c024;
w3d_vtable_8040dd48 = 0x8040dd48;
SECTIONS {
  .text.k5a_aim_tweaks_construct_80021514 0x80021514 : { *(.text.k5a_aim_tweaks_construct_80021514) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

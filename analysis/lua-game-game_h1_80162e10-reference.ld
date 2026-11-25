/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_registry_owner_construct_80162e10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_s20_init_registry_8016130c = 0x8016130c;
w3d_vtable_80411908 = 0x80411908;
w3d_vtable_80411940 = 0x80411940;
SECTIONS {
  .text.w3d_h1_registry_owner_construct_80162e10 0x80162e10 : { *(.text.w3d_h1_registry_owner_construct_80162e10) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_sda_registry_owner_804b178c = .;
    . = 0x104; w3d_sda_registry_state_804b1890 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

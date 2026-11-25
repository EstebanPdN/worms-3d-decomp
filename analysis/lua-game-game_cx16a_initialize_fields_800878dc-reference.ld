/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16a_initialize_fields_800878dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_801628b0 = 0x801628b0;
vtable_8040f120 = 0x8040f120;
SECTIONS {
  .text.w3d_cx16a_initialize_fields_800878dc 0x800878dc : { *(.text.w3d_cx16a_initialize_fields_800878dc) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; singleton_804aab4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

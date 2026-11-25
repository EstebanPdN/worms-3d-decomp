/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_tagged_construct_801b2c4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_construct_802109dc = 0x802109dc;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_type_80413be8 = 0x80413be8;
w3d_type_80414478 = 0x80414478;
w3d_vtable_804143f0 = 0x804143f0;
w3d_vtable_80414430 = 0x80414430;
SECTIONS {
  .text.w3d_tagged_construct_801b2c4c 0x801b2c4c : { *(.text.w3d_tagged_construct_801b2c4c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

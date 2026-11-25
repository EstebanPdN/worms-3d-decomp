/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_bind_services_80348570)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_descriptor_80413a68 = 0x80413a68;
cx9c_descriptor_80413c78 = 0x80413c78;
cx9c_descriptor_804163f8 = 0x804163f8;
cx9c_lookup_8020b680 = 0x8020b680;
SECTIONS {
  .text.w3d_cx9c_bind_services_80348570 0x80348570 : { *(.text.w3d_cx9c_bind_services_80348570) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

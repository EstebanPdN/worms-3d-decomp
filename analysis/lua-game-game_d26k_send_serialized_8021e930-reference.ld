/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_send_serialized_8021e930)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
create_80208aac = 0x80208aac;
key_80418f78 = 0x80418f78;
lookup_8020b680 = 0x8020b680;
SECTIONS {
  .text.w3d_d26k_send_serialized_8021e930 0x8021e930 : { *(.text.w3d_d26k_send_serialized_8021e930) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

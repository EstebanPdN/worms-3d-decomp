/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_payload_ctor_800ea180)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_80161014 = 0x80161014;
origin_8045e788 = 0x8045e788;
string_default_803426b8 = 0x803426b8;
vtable_804101f8 = 0x804101f8;
SECTIONS {
  .text.d24c_payload_ctor_800ea180 0x800ea180 : { *(.text.d24c_payload_ctor_800ea180) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

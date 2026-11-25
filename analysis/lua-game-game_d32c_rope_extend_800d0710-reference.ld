/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(grow__4RopePC3VecT1)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_80212fd4 = 0x80212fd4;
count_80178c48 = 0x80178c48;
drain_800d0058 = 0x800d0058;
finish_800d00f0 = 0x800d00f0;
memcpy_802eee50 = 0x802eee50;
middle_8043ae20 = 0x8043ae20;
one_8038815c = 0x8038815c;
probe_800d066c = 0x800d066c;
read_80178df0 = 0x80178df0;
release_802134fc = 0x802134fc;
rescale_800d1628 = 0x800d1628;
sqrt_802e82c0 = 0x802e82c0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.grow__4RopePC3VecT1 0x800d0710 : { *(.text.grow__4RopePC3VecT1) }
  .rodata 0x80388160 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

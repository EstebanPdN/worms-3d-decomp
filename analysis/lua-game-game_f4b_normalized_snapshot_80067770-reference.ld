/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f4b_normalized_snapshot_80067770)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801613f0 = 0x801613f0;
name_8015f5a0 = 0x8015f5a0;
one_8037a0f0 = 0x8037a0f0;
post_8016239c = 0x8016239c;
refresh_800bd920 = 0x800bd920;
sqrt_802e82c0 = 0x802e82c0;
value_8040db38 = 0x8040db38;
vector_8043ae38 = 0x8043ae38;
zero_8037a0ec = 0x8037a0ec;
SECTIONS {
  .text.f4b_normalized_snapshot_80067770 0x80067770 : { *(.text.f4b_normalized_snapshot_80067770) }
  .sdata 0x804ad5d4 (NOLOAD) : {
    . = 0x0; name_804ad5d4 = .;
    . = 0x4180; queue_804b1754 = .;
    . = 0x41b0; ready_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

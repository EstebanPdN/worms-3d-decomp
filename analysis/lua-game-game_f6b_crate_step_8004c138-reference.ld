/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f6b_crate_step_8004c138)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801613f0 = 0x801613f0;
down_803772b0 = 0x803772b0;
finish_8015fd1c = 0x8015fd1c;
get_80178df0 = 0x80178df0;
height_803772b8 = 0x803772b8;
name_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
property_80377118 = 0x80377118;
step_803772b4 = 0x803772b4;
target_803772a8 = 0x803772a8;
up_803772ac = 0x803772ac;
value_8040db38 = 0x8040db38;
write_800fc3b0 = 0x800fc3b0;
SECTIONS {
  .text.f6b_crate_step_8004c138 0x8004c138 : { *(.text.f6b_crate_step_8004c138) }
  .sdata 0x804ad360 (NOLOAD) : {
    . = 0x0; name_804ad360 = .;
    . = 0x43f4; queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

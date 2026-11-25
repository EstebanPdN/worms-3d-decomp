/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29j_diagnose_gp_hang_801683c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802fb7ac = 0x802fb7ac;
fn_803069fc = 0x803069fc;
fn_8030ce10 = 0x8030ce10;
SECTIONS {
  .text.d29j_diagnose_gp_hang_801683c4 0x801683c4 : { *(.text.d29j_diagnose_gp_hang_801683c4) }
  .rodata 0x803a4eac : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

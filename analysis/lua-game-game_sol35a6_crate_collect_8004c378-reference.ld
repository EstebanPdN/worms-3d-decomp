/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a6_crate_collect_8004c378)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f_803772ec = 0x803772ec;
fn_8004c598 = 0x8004c598;
fn_8004c670 = 0x8004c670;
fn_8004c814 = 0x8004c814;
fn_800a82f0 = 0x800a82f0;
fn_800e5ca4 = 0x800e5ca4;
fn_800fc3b0 = 0x800fc3b0;
fn_800fc6dc = 0x800fc6dc;
fn_8015f5a0 = 0x8015f5a0;
fn_8015fd1c = 0x8015fd1c;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
name_80376ed4 = 0x80376ed4;
name_80377118 = 0x80377118;
name_803772cc = 0x803772cc;
name_803772dc = 0x803772dc;
table_8040db38 = 0x8040db38;
SECTIONS {
  .text.sol35a6_crate_collect_8004c378 0x8004c378 : { *(.text.sol35a6_crate_collect_8004c378) }
  .sdata 0x804ad358 (NOLOAD) : {
    . = 0x0; cache_804ad358 = .;
    . = 0x58; cache_804ad3b0 = .;
    . = 0x43fc; pool_804b1754 = .;
    . = 0x4430; engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

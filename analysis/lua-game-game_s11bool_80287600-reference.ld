/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80287600)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC43C = 0x800fc43c;
fn_8010A8E0 = 0x8010a8e0;
fn_80129878 = 0x80129878;
fn_8015F5A0 = 0x8015f5a0;
fn_80160E34 = 0x80160e34;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
lbl_803CF594 = 0x803cf594;
lbl_803CF5A4 = 0x803cf5a4;
lbl_803CF5B0 = 0x803cf5b0;
SECTIONS {
  .text.w3d_auto_80287600 0x80287600 : { *(.text.w3d_auto_80287600) }
  .sdata 0x804b0bbc (NOLOAD) : {
    . = 0x0; lbl_804B0BBC = .;
    . = 0xb98; lbl_804B1754 = .;
    . = 0xbcc; lbl_804B1788 = .;
    . = 0xc34; lbl_804B17F0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

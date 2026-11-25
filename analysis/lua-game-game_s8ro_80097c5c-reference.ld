/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_recovered_80097c5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800AFE58 = 0x800afe58;
fn_800FC43C = 0x800fc43c;
fn_801265A4 = 0x801265a4;
fn_80161014 = 0x80161014;
fn_80209920 = 0x80209920;
fn_802134FC = 0x802134fc;
lbl_80380078 = 0x80380078;
lbl_8040F390 = 0x8040f390;
SECTIONS {
  .text.s8_recovered_80097c5c 0x80097c5c : { *(.text.s8_recovered_80097c5c) }
  .text.s8_recovered_8009b3d4 0x8009b3d4 : { *(.text.s8_recovered_8009b3d4) }
  .text.s8_recovered_800b0100 0x800b0100 : { *(.text.s8_recovered_800b0100) }
  .text.s8_recovered_800b12f0 0x800b12f0 : { *(.text.s8_recovered_800b12f0) }
  .sdata 0x804aabe8 (NOLOAD) : {
    . = 0x0; lbl_804AABE8 = .;
    . = 0x31fc; lbl_804ADDE4 = .;
    . = 0x545c; lbl_804B0044 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

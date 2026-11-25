/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_bound_80108040)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80106AFC = 0x80106afc;
fn_8015F518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_80360CF0 = 0x80360cf0;
lbl_80361110 = 0x80361110;
lbl_80399B38 = 0x80399b38;
lbl_80399B50 = 0x80399b50;
lbl_80399B64 = 0x80399b64;
lbl_80399B74 = 0x80399b74;
lbl_803E83FC = 0x803e83fc;
SECTIONS {
  .text.s8_bound_80108040 0x80108040 : { *(.text.s8_bound_80108040) }
  .sdata 0x804aafb4 (NOLOAD) : {
    . = 0x0; lbl_804AAFB4 = .;
    . = 0x4240; lbl_804AF1F4 = .;
    . = 0x4244; lbl_804AF1F8 = .;
    . = 0x4248; lbl_804AF1FC = .;
    . = 0x424c; lbl_804AF200 = .;
    . = 0x4250; lbl_804AF204 = .;
    . = 0x4254; lbl_804AF208 = .;
    . = 0x4258; lbl_804AF20C = .;
    . = 0x425c; lbl_804AF210 = .;
    . = 0x4260; lbl_804AF214 = .;
    . = 0x4264; lbl_804AF218 = .;
    . = 0x426c; lbl_804AF220 = .;
    . = 0x4274; lbl_804AF228 = .;
    . = 0x427c; lbl_804AF230 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800ba66c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b93dc = 0x800b93dc;
fn_8015f518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_803608d0 = 0x803608d0;
lbl_803617d0 = 0x803617d0;
lbl_803828e0 = 0x803828e0;
lbl_803828ec = 0x803828ec;
lbl_80382900 = 0x80382900;
lbl_80382914 = 0x80382914;
lbl_80382928 = 0x80382928;
lbl_8038292c = 0x8038292c;
lbl_803e7f2c = 0x803e7f2c;
SECTIONS {
  .text.s8_static_init_800ba66c 0x800ba66c : { *(.text.s8_static_init_800ba66c) }
  .sdata 0x804ae518 (NOLOAD) : {
    . = 0x0; lbl_804ae518 = .;
    . = 0x8; lbl_804ae520 = .;
    . = 0x10; lbl_804ae528 = .;
    . = 0x18; lbl_804ae530 = .;
    . = 0x20; lbl_804ae538 = .;
    . = 0x28; lbl_804ae540 = .;
    . = 0x30; lbl_804ae548 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

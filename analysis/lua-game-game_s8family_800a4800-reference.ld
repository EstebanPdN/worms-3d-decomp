/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800a4800)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a41d4 = 0x800a41d4;
fn_8015f518 = 0x8015f518;
fn_801629f8 = 0x801629f8;
lbl_80360750 = 0x80360750;
lbl_803618f0 = 0x803618f0;
lbl_80380ef0 = 0x80380ef0;
lbl_80380f04 = 0x80380f04;
lbl_80380f10 = 0x80380f10;
lbl_80380f1c = 0x80380f1c;
lbl_80380f30 = 0x80380f30;
lbl_80380f44 = 0x80380f44;
lbl_80380f60 = 0x80380f60;
lbl_803e7e4c = 0x803e7e4c;
SECTIONS {
  .text.s8_static_init_800a4800 0x800a4800 : { *(.text.s8_static_init_800a4800) }
  .sdata 0x804aac34 (NOLOAD) : {
    . = 0x0; lbl_804aac34 = .;
    . = 0x3588; lbl_804ae1bc = .;
    . = 0x358c; lbl_804ae1c0 = .;
    . = 0x3590; lbl_804ae1c4 = .;
    . = 0x3594; lbl_804ae1c8 = .;
    . = 0x3598; lbl_804ae1cc = .;
    . = 0x359c; lbl_804ae1d0 = .;
    . = 0x35a0; lbl_804ae1d4 = .;
    . = 0x35a4; lbl_804ae1d8 = .;
    . = 0x35a8; lbl_804ae1dc = .;
    . = 0x35ac; lbl_804ae1e0 = .;
    . = 0x35b4; lbl_804ae1e8 = .;
    . = 0x35bc; lbl_804ae1f0 = .;
    . = 0x35c4; lbl_804ae1f8 = .;
    . = 0x35cc; lbl_804ae200 = .;
    . = 0x35d4; lbl_804ae208 = .;
    . = 0x35dc; lbl_804ae210 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

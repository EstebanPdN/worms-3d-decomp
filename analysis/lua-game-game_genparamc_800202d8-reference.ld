/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_derived_messages_800202d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_8016115cPvN21ii = 0x8016115c;
__16W3dType_801629f8PvN21ii = 0x801629f8;
fn_8001c770 = 0x8001c770;
fn_8003dd0c = 0x8003dd0c;
fn_8015f518 = 0x8015f518;
lbl_8035fa60 = 0x8035fa60;
lbl_80360000 = 0x80360000;
lbl_80361860 = 0x80361860;
lbl_803618f0 = 0x803618f0;
lbl_8036ba6c = 0x8036ba6c;
lbl_8036ba80 = 0x8036ba80;
lbl_8037469c = 0x8037469c;
lbl_803746ac = 0x803746ac;
lbl_803e76c0 = 0x803e76c0;
lbl_803e7a08 = 0x803e7a08;
SECTIONS {
  .text.w3d_sinit_derived_messages_800202d8 0x800202d8 : { *(.text.w3d_sinit_derived_messages_800202d8) }
  .text.w3d_sinit_derived_messages_8003f028 0x8003f028 : { *(.text.w3d_sinit_derived_messages_8003f028) }
  .sdata 0x804aa784 (NOLOAD) : {
    . = 0x0; lbl_804aa784 = .;
    . = 0x1c0; lbl_804aa944 = .;
    . = 0x2194; lbl_804ac918 = .;
    . = 0x2198; lbl_804ac91c = .;
    . = 0x219c; lbl_804ac920 = .;
    . = 0x21a0; lbl_804ac924 = .;
    . = 0x21a4; lbl_804ac928 = .;
    . = 0x21a8; lbl_804ac92c = .;
    . = 0x21ac; lbl_804ac930 = .;
    . = 0x21b0; lbl_804ac934 = .;
    . = 0x21b4; lbl_804ac938 = .;
    . = 0x21b8; lbl_804ac93c = .;
    . = 0x21c0; lbl_804ac944 = .;
    . = 0x2a04; lbl_804ad188 = .;
    . = 0x2a08; lbl_804ad18c = .;
    . = 0x2a0c; lbl_804ad190 = .;
    . = 0x2a10; lbl_804ad194 = .;
    . = 0x2a14; lbl_804ad198 = .;
    . = 0x2a18; lbl_804ad19c = .;
    . = 0x2a1c; lbl_804ad1a0 = .;
    . = 0x2a20; lbl_804ad1a4 = .;
    . = 0x2a24; lbl_804ad1a8 = .;
    . = 0x2a28; lbl_804ad1ac = .;
    . = 0x2a30; lbl_804ad1b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

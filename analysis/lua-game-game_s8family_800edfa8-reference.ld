/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_initialize_800edfa8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800EA0AC = 0x800ea0ac;
fn_8015F518 = 0x8015f518;
fn_8016115C = 0x8016115c;
lbl_80360E10 = 0x80360e10;
lbl_80361860 = 0x80361860;
lbl_8038B710 = 0x8038b710;
lbl_8038B720 = 0x8038b720;
lbl_8038B738 = 0x8038b738;
lbl_8038B748 = 0x8038b748;
lbl_8038B760 = 0x8038b760;
lbl_8038B77C = 0x8038b77c;
lbl_8038b6a0 = 0x8038b6a0;
lbl_8038b6b0 = 0x8038b6b0;
lbl_8038b6c0 = 0x8038b6c0;
lbl_8038b6cc = 0x8038b6cc;
lbl_8038b6dc = 0x8038b6dc;
lbl_8038b6ec = 0x8038b6ec;
lbl_8038b6fc = 0x8038b6fc;
lbl_803E823C = 0x803e823c;
SECTIONS {
  .text.s8_initialize_800edfa8 0x800edfa8 : { *(.text.s8_initialize_800edfa8) }
  .sdata 0x804aaef4 (NOLOAD) : {
    . = 0x0; lbl_804AAEF4 = .;
    . = 0x3fd8; lbl_804AEECC = .;
    . = 0x3fdc; lbl_804AEED0 = .;
    . = 0x3fe0; lbl_804AEED4 = .;
    . = 0x3fe4; lbl_804AEED8 = .;
    . = 0x3fe8; lbl_804AEEDC = .;
    . = 0x3fec; lbl_804AEEE0 = .;
    . = 0x3ff0; lbl_804AEEE4 = .;
    . = 0x3ff4; lbl_804AEEE8 = .;
    . = 0x3ff8; lbl_804AEEEC = .;
    . = 0x3ffc; lbl_804AEEF0 = .;
    . = 0x4004; lbl_804AEEF8 = .;
    . = 0x400c; lbl_804AEF00 = .;
    . = 0x4014; lbl_804AEF08 = .;
    . = 0x401c; lbl_804AEF10 = .;
    . = 0x4024; lbl_804AEF18 = .;
    . = 0x402c; lbl_804AEF20 = .;
    . = 0x4034; lbl_804AEF28 = .;
    . = 0x403c; lbl_804AEF30 = .;
    . = 0x4044; lbl_804AEF38 = .;
    . = 0x404c; lbl_804AEF40 = .;
    . = 0x4054; lbl_804AEF48 = .;
    . = 0x405c; lbl_804AEF50 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

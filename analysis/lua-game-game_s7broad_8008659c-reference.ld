/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8008659c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8007F95C = 0x8007f95c;
fn_800840F0 = 0x800840f0;
fn_80086160 = 0x80086160;
fn_80086288 = 0x80086288;
fn_80086324 = 0x80086324;
SECTIONS {
  .text.w3d_auto_8008659c 0x8008659c : { *(.text.w3d_auto_8008659c) }
  .sdata 0x804adb14 (NOLOAD) : {
    . = 0x0; lbl_804ADB14 = .;
    . = 0x8; lbl_804ADB1C = .;
    . = 0xc; lbl_804ADB20 = .;
    . = 0x10; lbl_804ADB24 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

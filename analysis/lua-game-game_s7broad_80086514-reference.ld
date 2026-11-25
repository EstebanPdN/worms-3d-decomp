/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80086514)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8007F278 = 0x8007f278;
fn_8007FA08 = 0x8007fa08;
fn_80085FF8 = 0x80085ff8;
fn_80086288 = 0x80086288;
fn_80086324 = 0x80086324;
SECTIONS {
  .text.w3d_auto_80086514 0x80086514 : { *(.text.w3d_auto_80086514) }
  .sdata 0x804adb20 (NOLOAD) : {
    . = 0x0; lbl_804ADB20 = .;
    . = 0x4; lbl_804ADB24 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

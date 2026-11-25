/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_screen_fade_800c770c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800c7c84 = 0x800c7c84;
fn_80173df0 = 0x80173df0;
fn_8018d35c = 0x8018d35c;
fn_8018d434 = 0x8018d434;
SECTIONS {
  .text.w3d_d25h_screen_fade_800c770c 0x800c770c : { *(.text.w3d_d25h_screen_fade_800c770c) }
  .rodata 0x80387a34 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

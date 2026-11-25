/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_debug_resize_80216330)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8021573c = 0x8021573c;
fn_80215be4 = 0x80215be4;
fn_80215c58 = 0x80215c58;
fn_80215e10 = 0x80215e10;
fn_80215fd8 = 0x80215fd8;
fn_80216154 = 0x80216154;
fn_80216638 = 0x80216638;
lbl_80400768 = 0x80400768;
SECTIONS {
  .text.w3d_d28k_debug_resize_80216330 0x80216330 : { *(.text.w3d_d28k_debug_resize_80216330) }
  .sdata 0x804aba74 (NOLOAD) : {
    . = 0x0; lbl_804aba74 = .;
    . = 0x4c50; lbl_804b06c4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

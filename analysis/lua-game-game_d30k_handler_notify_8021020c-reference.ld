/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_handler_notify_8021020c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80210610 = 0x80210610;
lbl_80463be0 = 0x80463be0;
SECTIONS {
  .text.w3d_d30k_handler_notify_8021020c 0x8021020c : { *(.text.w3d_d30k_handler_notify_8021020c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

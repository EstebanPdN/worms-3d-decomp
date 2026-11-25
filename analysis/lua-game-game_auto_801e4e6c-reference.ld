/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801e4e6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801E43C8 = 0x801e43c8;
fn_801E45F0 = 0x801e45f0;
fn_801E4FCC = 0x801e4fcc;
fn_801E507C = 0x801e507c;
fn_801E5FD4 = 0x801e5fd4;
fn_801E6BBC = 0x801e6bbc;
fn_80322838 = 0x80322838;
SECTIONS {
  .text.w3d_auto_801e4e6c 0x801e4e6c : { *(.text.w3d_auto_801e4e6c) }
  .text.w3d_auto_801e5dfc 0x801e5dfc : { *(.text.w3d_auto_801e5dfc) }
  .sdata 0x804ab85c (NOLOAD) : {
    . = 0x0; lbl_804AB85C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

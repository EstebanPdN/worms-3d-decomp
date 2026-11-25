/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10b_dispatch_message_80161ce8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80161dd0 = 0x80161dd0;
fn_801623dc = 0x801623dc;
fn_80162480 = 0x80162480;
fn_8016293c = 0x8016293c;
SECTIONS {
  .text.w3d_k10b_dispatch_message_80161ce8 0x80161ce8 : { *(.text.w3d_k10b_dispatch_message_80161ce8) }
  .sdata 0x804ab4ac (NOLOAD) : {
    . = 0x0; lbl_804ab4ac = .;
    . = 0x4; lbl_804ab4b0 = .;
    . = 0x8; lbl_804ab4b4 = .;
    . = 0xc; lbl_804ab4b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

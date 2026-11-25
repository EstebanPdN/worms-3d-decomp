/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10b_hold_timeout_801fddac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802f7694 = 0x802f7694;
fn_80300ab8 = 0x80300ab8;
SECTIONS {
  .text.w3d_k10b_hold_timeout_801fddac 0x801fddac : { *(.text.w3d_k10b_hold_timeout_801fddac) }
  .sdata 0x804ab93c (NOLOAD) : {
    . = 0x0; lbl_804ab93c = .;
    . = 0x4; lbl_804ab940 = .;
    . = 0x8; lbl_804ab944 = .;
    . = 0xc; lbl_804ab948 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

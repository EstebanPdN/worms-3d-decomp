/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_sinit_801ea774)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e89b8 = 0x801e89b8;
fn_801e89c0 = 0x801e89c0;
fn_801e8a88 = 0x801e8a88;
fn_801e9f78 = 0x801e9f78;
fn_801ea44c = 0x801ea44c;
fn_801ea6c8 = 0x801ea6c8;
fn_801ea6d0 = 0x801ea6d0;
fn_80200af8 = 0x80200af8;
fn_802097ec = 0x802097ec;
fn_8020fbd0 = 0x8020fbd0;
lbl_80365788 = 0x80365788;
lbl_803b09ec = 0x803b09ec;
lbl_803b0bb4 = 0x803b0bb4;
lbl_803ea0a4 = 0x803ea0a4;
lbl_803ea0c0 = 0x803ea0c0;
lbl_8045e080 = 0x8045e080;
lbl_8045e08c = 0x8045e08c;
lbl_8045e0a4 = 0x8045e0a4;
lbl_8045e0b0 = 0x8045e0b0;
lbl_8045e0e0 = 0x8045e0e0;
lbl_8045e124 = 0x8045e124;
SECTIONS {
  .text.w3d_cc17c_sinit_801ea774 0x801ea774 : { *(.text.w3d_cc17c_sinit_801ea774) }
  .sdata 0x804b0580 (NOLOAD) : {
    . = 0x0; lbl_804b0580 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

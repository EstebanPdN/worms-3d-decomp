/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24k_gauge_setup_80265d34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
border_803cb5a0 = 0x803cb5a0;
fn_800fc1b0 = 0x800fc1b0;
fn_800fd62c = 0x800fd62c;
fn_8015f5a0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80165254 = 0x80165254;
fn_80178df0 = 0x80178df0;
fn_802663dc = 0x802663dc;
fn_802672cc = 0x802672cc;
fn_8026836c = 0x8026836c;
fn_802683b8 = 0x802683b8;
fn_80268568 = 0x80268568;
fn_802b0b84 = 0x802b0b84;
fn_80342a74 = 0x80342a74;
SECTIONS {
  .text.w3d_d24k_gauge_setup_80265d34 0x80265d34 : { *(.text.w3d_d24k_gauge_setup_80265d34) }
  .rodata 0x803cb5b4 : { *(.rodata) }
  .sdata 0x804b0aac (NOLOAD) : {
    . = 0x0; message_804b0aac = .;
    . = 0x8; message_804b0ab4 = .;
    . = 0xcdc; root_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

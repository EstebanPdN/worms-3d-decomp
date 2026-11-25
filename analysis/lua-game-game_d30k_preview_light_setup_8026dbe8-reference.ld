/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_preview_light_setup_8026dbe8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4TextPCc = 0x8020bb54;
fn_8015adf4 = 0x8015adf4;
fn_80165254 = 0x80165254;
fn_80182408 = 0x80182408;
fn_80182410 = 0x80182410;
fn_8020b680 = 0x8020b680;
fn_8020c5c4 = 0x8020c5c4;
fn_802e82c0 = 0x802e82c0;
fn_80341588 = 0x80341588;
fn_80343584 = 0x80343584;
lbl_803cbd18 = 0x803cbd18;
lbl_803cbd84 = 0x803cbd84;
lbl_80414a90 = 0x80414a90;
SECTIONS {
  .text.w3d_d30k_preview_light_setup_8026dbe8 0x8026dbe8 : { *(.text.w3d_d30k_preview_light_setup_8026dbe8) }
  .rodata 0x803cbd90 : { *(.rodata) }
  .sdata 0x804b17ec (NOLOAD) : {
    . = 0x0; lbl_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

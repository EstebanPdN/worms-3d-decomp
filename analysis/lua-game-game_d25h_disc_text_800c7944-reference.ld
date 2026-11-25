/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_disc_text_800c7944)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
fn_800c7c40 = 0x800c7c40;
fn_8018c5b0 = 0x8018c5b0;
fn_8018c938 = 0x8018c938;
fn_80343580 = 0x80343580;
lbl_803879f8 = 0x803879f8;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d25h_disc_text_800c7944 0x800c7944 : { *(.text.w3d_d25h_disc_text_800c7944) }
  .rodata 0x80387a40 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
